/*!
 * \file umc_canvas.h
 *
 * \author chendaole
 * \date ���� 2018
 *
 *  ʹ��qtwidget ������Ƕ�� sdl ����
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
	// Description: SDLģ��ע��
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
	// Description: SDL��Ⱦ�߳�
	//************************************
	static int SDLRenderThread(void* data);

	//************************************
	// Method:    SDLEventThread
	// FullName:  UMCStage::SDLEventThread
	// Access:    public static 
	// Returns:   int
	// Parameter: void * data
	// Description: SDL�¼������߳�
	//************************************
	static int SDLEventThread(void* data);

	//************************************
	// Method:    HandleCaptureThread
	// FullName:  UMCStage::HandleCaptureThread
	// Access:    public static 
	// Returns:   bool
	// Parameter: void * data
	// Description: SDL ����ץȡ�߳�
	//************************************
	static int SDLCaptureThread(void* data);

	//************************************
	// Method:    HandleSDLEvent
	// FullName:  UMCStage::HandleSDLEvent
	// Access:    public static 
	// Returns:   int
	// Parameter: SDL_Event & event
	// Description: �������û������¼�
	//************************************
	static int HandleSDLEvent(UMCStage* widget, SDL_Event& event);

	//************************************
	// Method:    HandleSDLDraw
	// FullName:  UMCStage::HandleSDLDraw
	// Access:    public static 
	// Returns:   bool
	// Parameter: void * data
	// Description: ��������ͼ
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
	// Description: �����������Ԫ�ز�
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

	SpriteVector*  m_pSpriteVector; //��������
	mutex   m_layerVectorMutex; //����������
};
