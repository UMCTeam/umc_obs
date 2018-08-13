#include "umc_capture.h"

UMCCapture::UMCCapture()
{
	InitializeDC();
}


UMCCapture::~UMCCapture()
{
	ReleaseDC(0, m_hScreenDC);
	DeleteDC(m_hmemDC);
}

void UMCCapture::InitializeDC()
{
	m_hScreenDC = CreateDC(L"DISPLAY", NULL, NULL, NULL);
	m_hmemDC = CreateCompatibleDC(m_hScreenDC);
	// 显示器屏幕的宽和高
	m_wdith = GetDeviceCaps(m_hScreenDC, HORZRES);
	m_height = GetDeviceCaps(m_hScreenDC, VERTRES);

}

BITMAPINFO UMCCapture::ReadBimapInfo()
{
	BITMAPINFO bmInfo;
	// 添充 BITMAPINFO 结构
	ZeroMemory(&bmInfo, sizeof(BITMAPINFO));
	bmInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmInfo.bmiHeader.biWidth = SCREEN_X;
	bmInfo.bmiHeader.biHeight = SCREEN_Y;
	bmInfo.bmiHeader.biPlanes = 1;
	bmInfo.bmiHeader.biBitCount = BIT_COUNT;
	bmInfo.bmiHeader.biCompression = BI_RGB;
	return bmInfo;
}

BITMAPFILEHEADER UMCCapture::ReadBimapHeader()
{
	BITMAPINFO bmInfo = ReadBimapInfo();
	DWORD nBitsOffset;
	DWORD lImageSize;
	DWORD lFileSize;
	BITMAPFILEHEADER bmHeader;

	ZeroMemory(&bmHeader, sizeof(BITMAPFILEHEADER));
	nBitsOffset = sizeof(BITMAPFILEHEADER) + bmInfo.bmiHeader.biSize;
	lImageSize =
		((((bmInfo.bmiHeader.biWidth * bmInfo.bmiHeader.biBitCount) + 31) & ~31) >> 3)
		* bmInfo.bmiHeader.biHeight;
	lFileSize = nBitsOffset + lImageSize;
	bmHeader.bfType = 'B' + ('M' << 8);
	bmHeader.bfSize = lFileSize;
	bmHeader.bfOffBits = nBitsOffset;

	return bmHeader;
}

void* UMCCapture::ReadBimapData()
{
	HBITMAP hBitmap;
	HBITMAP hOldBM;
	
	BITMAPINFO bmInfo = ReadBimapInfo();

	hBitmap = CreateCompatibleBitmap(m_hScreenDC, m_wdith, m_height);
	// 将BITMAP选择入内存DC。
	hOldBM = (HBITMAP)SelectObject(m_hmemDC, hBitmap);
	// BitBlt屏幕DC到内存DC，根据所需截取的获取设置参数
	BitBlt(m_hmemDC, 0, 0, m_wdith, m_height, m_hScreenDC, 0, 0, SRCCOPY);
	// 将旧的BITMAP对象选择回内存DC，返回值为被替换的对象，既所截取的位图
	hBitmap = (HBITMAP)SelectObject(m_hmemDC, hOldBM);

	// 为位图数据申请内存空间
	// 位图数据大小
	DWORD dwBitmapArraySize;
	dwBitmapArraySize = ((((m_wdith * 32) + 31) & ~31) >> 3)* m_height;
	//void* lpvpxldata = malloc(dwBitmapArraySize);
	void* lpvpxldata = HeapAlloc(GetProcessHeap(), HEAP_NO_SERIALIZE, dwBitmapArraySize);
	ZeroMemory(lpvpxldata, dwBitmapArraySize);

	GetDIBits(m_hmemDC, hBitmap, 0, bmInfo.bmiHeader.biHeight,
		lpvpxldata, &bmInfo, DIB_RGB_COLORS);
	
	DeleteObject(hBitmap);
	DeleteObject(hOldBM);

	return lpvpxldata;
}

bool UMCCapture::SaveToFile(char filename[])
{
	HANDLE hbmfile;
	DWORD dwWritten;

	BITMAPINFO bmInfo = ReadBimapInfo();
	BITMAPFILEHEADER header = ReadBimapHeader();
	void* lpvpxldata = ReadBimapData();

	hbmfile = CreateFileA(filename,
		GENERIC_WRITE,
		FILE_SHARE_WRITE,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (hbmfile == INVALID_HANDLE_VALUE)
	{
		MessageBoxA(NULL, "create file error", "error", MB_OK);
	}

	WriteFile(hbmfile, &header, sizeof(BITMAPFILEHEADER), &dwWritten, NULL);
	WriteFile(hbmfile, &bmInfo, sizeof(BITMAPINFO), &dwWritten, NULL);
	WriteFile(hbmfile, lpvpxldata, header.bfSize - header.bfOffBits, &dwWritten, NULL);
	CloseHandle(hbmfile);
	return 0;
}

int UMCCapture::GetPitch()
{
	BITMAPINFO bmInfo = ReadBimapInfo();
	return (((bmInfo.bmiHeader.biBitCount >> 3) * bmInfo.bmiHeader.biWidth + 3) >> 2) << 2;
}

