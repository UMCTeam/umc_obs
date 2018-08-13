#pragma once
#include <windows.h>
#include <tchar.h>

#include "umc_define.h"

class UMCCapture
{
public:
	UMCCapture();
	~UMCCapture();

#define BIT_COUNT 32

public:
	//************************************
	// Method:    InitializeDC
	// FullName:  UMCCapture::InitializeDC
	// Access:    public 
	// Returns:   void
	// Description: ��ʼ����ͼ����
	//************************************
	void InitializeDC();

	//************************************
	// Method:    ReadBimapInfo
	// FullName:  UMCCapture::ReadBimapInfo
	// Access:    public 
	// Returns:   BITMAPINFO
	// Description: ��ȡBMP ��Ϣ
	//************************************
	BITMAPINFO ReadBimapInfo();

	//************************************
	// Method:    ReadBimapHeader
	// FullName:  UMCCapture::ReadBimapHeader
	// Access:    public 
	// Returns:   BITMAPFILEHEADER
	// Description: ��ȡBMP ͷ����Ϣ
	//************************************
	BITMAPFILEHEADER ReadBimapHeader();

	//************************************
	// Method:    ReadBimapData
	// FullName:  UMCCapture::ReadBimapData
	// Access:    public 
	// Returns:   void*
	// Description: ��ȡBMP ����
	//************************************
	void* ReadBimapData();

	//************************************
	// Method:    SaveToFile
	// FullName:  UMCCapture::SaveToFile
	// Access:    public 
	// Returns:   bool
	// Parameter: char filename[]
	// Description: ���浽���ش���
	//************************************
	bool SaveToFile(char filename[]);

	int GetPitch();

private:
	HDC  m_hScreenDC;       
	HDC  m_hmemDC;          
    
	int m_wdith;
	int m_height;
};

