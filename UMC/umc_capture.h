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
	// Description: 初始化截图环境
	//************************************
	void InitializeDC();

	//************************************
	// Method:    ReadBimapInfo
	// FullName:  UMCCapture::ReadBimapInfo
	// Access:    public 
	// Returns:   BITMAPINFO
	// Description: 读取BMP 信息
	//************************************
	BITMAPINFO ReadBimapInfo();

	//************************************
	// Method:    ReadBimapHeader
	// FullName:  UMCCapture::ReadBimapHeader
	// Access:    public 
	// Returns:   BITMAPFILEHEADER
	// Description: 读取BMP 头部信息
	//************************************
	BITMAPFILEHEADER ReadBimapHeader();

	//************************************
	// Method:    ReadBimapData
	// FullName:  UMCCapture::ReadBimapData
	// Access:    public 
	// Returns:   void*
	// Description: 读取BMP 数据
	//************************************
	void* ReadBimapData();

	//************************************
	// Method:    SaveToFile
	// FullName:  UMCCapture::SaveToFile
	// Access:    public 
	// Returns:   bool
	// Parameter: char filename[]
	// Description: 保存到本地磁盘
	//************************************
	bool SaveToFile(char filename[]);

	int GetPitch();

private:
	HDC  m_hScreenDC;       
	HDC  m_hmemDC;          
    
	int m_wdith;
	int m_height;
};

