/*!
 * \file umc_canvas.h
 *
 * \author chendaole
 * \date 七月 2018
 *
 *  使用qtwidget 窗口中嵌入 sdl 画布
 */
#pragma once

#include <QWidget>
#include <windows.h>
#include <vector>
#include <iostream>
#include <mutex>
#include <utility>

#ifdef _DEBUG
#include <QDebug>
#endif

#include "ui_umc_stage.h"
#include "umc_base_sprite.h"
#include "umc_stage_mediator.h"
extern "C"
{
#include "SDL.h"
#include "SDL_image.h"
}

#define  FPS 20

using namespace std;

class UMCStage : public QWidget
{
	Q_OBJECT

public:
	typedef vector<UMCBaseSprite*> SpriteVector;
	typedef pair<UMCBaseSprite*, UMCDistrictType> EventTargetType;

	enum EventType
	{
		None,
		Drag,
		Resize,
	};

public:
	UMCStage(QWidget *parent = Q_NULLPTR);
	~UMCStage();
	void setObjectName(const QString &name);

	//************************************
	// Method:    SDLRegister
	// FullName:  UMCStage::SDLRegister
	// Access:    public 
	// Returns:   void
	// Description: SDL模块注册
	//************************************
	void SDLRegister();
	void Load(UMCStageMediator* mediator);

	SpriteVector* GetSurfaceVector();

	void AddSprite(UMCBaseSprite* layer);

	//************************************
	// Method:    SDLRenderThread
	// FullName:  UMCStage::SDLMainThread
	// Access:    public static 
	// Returns:   int
	// Parameter: void * data
	// Description: SDL渲染线程
	//************************************
	static int SDLRenderThread(void* data);

	//************************************
	// Method:    SDLEventThread
	// FullName:  UMCStage::SDLEventThread
	// Access:    public static 
	// Returns:   int
	// Parameter: void * data
	// Description: SDL事件处理线程
	//************************************
	static int SDLEventThread(void* data);

	//************************************
	// Method:    HandleCaptureThread
	// FullName:  UMCStage::HandleCaptureThread
	// Access:    public static 
	// Returns:   bool
	// Parameter: void * data
	// Description: SDL 画面抓取线程
	//************************************
	static int SDLCaptureThread(void* data);

	//************************************
	// Method:    HandleSDLEvent
	// FullName:  UMCStage::HandleSDLEvent
	// Access:    public static 
	// Returns:   int
	// Parameter: SDL_Event & event
	// Description: 处理画布用户操作事件
	//************************************
	static int HandleSDLEvent(UMCStage* widget, SDL_Event& event);

	//************************************
	// Method:    HandleSDLDraw
	// FullName:  UMCStage::HandleSDLDraw
	// Access:    public static 
	// Returns:   bool
	// Parameter: void * data
	// Description: 处理画布绘图
	//************************************
	static bool HandleSDLDraw(UMCStage* widget);

protected:
	//************************************
	// Method:    findLayer
	// FullName:  UMCStage::findLayer
	// Access:    protected 
	// Returns:   UMCStage::LayerData*
	// Parameter: uint x
	// Parameter: uint y
	// Description: 根据坐标查找元素层
	//************************************
	EventTargetType GetEventTarget(int x, int y);
	

private:
	Ui::UMCStage ui;

private:
	SDL_Window*   m_pWin;
	SDL_Renderer* m_pRenderer;

	SDL_Thread*  m_pSDLRenderThread;
	SDL_Thread*  m_pSDLEventThread;
	SDL_Thread*  m_pSDLCaptureThread;
	bool         m_isLiveThread;

	SpriteVector*  m_pSpriteVector; //画布数据
	mutex   m_layerVectorMutex; //画布数据锁
};
