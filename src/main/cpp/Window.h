#ifndef WINDOW_H
#define WINDOW_H

#include <Windows.h>


extern HINSTANCE ghInst;
extern const LPCTSTR lpClassName;
extern HWND hDlgCurrent;


extern int winWidth;
extern int winHeight;

void onResize(HINSTANCE hInstance);

LRESULT CALLBACK mainWndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);









#endif