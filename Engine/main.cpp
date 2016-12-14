/******************************************************************************/
/*!
  \file   main.cpp
  \author Matt Casanova
  \par    email: mcasanov\@digipen.edu
  \date   27/12/2011
  \author Yunhyeok Choi
  \par    email: yunhyeokchoi.digipen\@gmail.com
  \date   20/8/2016
  \brief  
    This is the entry point into the simple C++ game engine & game application. 
*/
/******************************************************************************/
#include "StageManager.h"
#include "DebugTools.h"

LRESULT	CALLBACK WndProc(HWND hWnd,		 /*Window handler*/
												 UINT Msg,			 /*Msg type*/
												 WPARAM wParam, /*Addtional datas*/
												 LPARAM lParam)
{
	switch (Msg)
	{
		/*close the application*/
	case WM_DESTROY:
	{
		/*close it*/
		PostQuitMessage(WM_QUIT);
		break;
	}

	default:
		/*process leftover messages*/
		return DefWindowProc(hWnd, Msg, wParam, lParam);
	}

	return 0;
}

/******************************************************************************/
/*!
	Window's entry point; 
	Update the stage manager, 
	until a player prompts a shutdown of the application.

	\param hInstance
		A handle to the instance
	\param hPrevInstance
		It is always zero in Win32 programs
	\param lpCmdLine
		The command line for the application, excluding the program name.
	\param nCmdShow
		Controls how the window is to be shown.
	\return
		0 if successfully shutted down the application.
*/
/******************************************************************************/
int WINAPI WinMain(HINSTANCE hInstance,
									 HINSTANCE hPrevInstance,
									 LPSTR lpCmdLine,
									 int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	UNREFERENCED_PARAMETER(nCmdShow);

	//WNDCLASSEX adds only a slight feature to the WNDCLASS class
	WNDCLASSEX wndClass;
	/*The size, in bytes, of this structure. Set this member to sizeof(WNDCLASSEX).*/
	wndClass.cbSize = sizeof(WNDCLASSEX);
	/*
		If a user moves a window or changes its size, I would need
		the window to be redrawn.
		To redraw the window horizontally, CS_HREDRAW.
		To redraw the window vertically, CS_VREDRAW
	*/
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	/*The name of the Window procedure function should be assigned here.*/
	wndClass.lpfnWndProc = WndProc;
	/*extra memory for the class*/
	wndClass.cbClsExtra = 0;
	/*extra memory for the application to use*/
	wndClass.cbWndExtra = 0;
	/*Large (usually 32x32) icon shown when the user presses Alt+Tab*/
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	/*Icon Small*/
	wndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	/*Cursor*/
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	/*Background brush to set the color of our window*/
	/*Set this to NULL to make the application do no background erase.*/
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	/*call my own designed menu*/
	wndClass.lpszMenuName = NULL;
	/*
		Unique name to identify the class with.
		To create a window, you must provide the name of the class.
	*/
	const LPCWSTR className = L"MyClass";
	wndClass.lpszClassName = className;
	/*
		Creating an application is same as creating an instance.
		To communicate with the WinMain function, give it hInstance.
	*/
	wndClass.hInstance = hInstance;

	RegisterClassEx(&wndClass);

	const int windowWidth = 300;
	const int windowHeight = 300;
	const LPCWSTR windowName = L"Simple Window";

	//Handle to a Window being created
	HWND hWnd = CreateWindow(className,
													 /*The window caption*/
													 windowName,
													 /*The style of the window*/
													 WS_OVERLAPPEDWINDOW,
													 /*
														 X position of the top left corner of the window.
														 Top left of the monitor is (0, 0)
													 */
													 CW_USEDEFAULT,
													 /*Y position of the top left corner of the window*/
													 CW_USEDEFAULT,
													 /*Width of the window*/
													 windowWidth,
													 /*Height of the window*/
													 windowHeight,
													 /*Handle to the parent window*/
													 NULL,
													 /*Handle to the menu*/
													 NULL,
													 hInstance,
													 /*
														 A pointer to a value to be passed to the window through the CREATESTRUCT structure (lpCreateParams member)
														 pointed to by the lParam param of the WM_CREATE message.
													 */
													 NULL);

	/*displays the window*/
	ShowWindow(hWnd, nCmdShow);
	
	/*
		https://msdn.microsoft.com/en-us/library/windows/desktop/dd145167(v=vs.85).aspx
		The UpdateWindow function updates the client area of the specified window,
		by sending a WM_PAINT message to the window if the window's update region is not empty. 
		The function sends a WM_PAINT message directly to the window procedure of the specified window, 
		bypassing the application queue. 
		If the update region is empty, no message is sent.
	*/
	UpdateWindow(hWnd);

  StageManager stageManager;
  
  stageManager.Init();
  
  stageManager.Update();
  
  stageManager.Shutdown();

	return 0;
}