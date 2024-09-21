#include "Main.h"

INT WINAPI WinMain(_In_ HINSTANCE hInstance, _In_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdline, _In_ INT nShowCmd) {
	//MessageBox(NULL, "Hello!", "Program3", MB_OK);
	WNDCLASS windowClass = { 0 };

	windowClass.lpfnWndProc = &WindowProc;
	windowClass.hInstance = hInstance;
	windowClass.lpszClassName = "TestWindowProject";

	RegisterClass(&windowClass);

	HWND hWnd = CreateWindowEx(0, "TestWindowProject", "TestWindow", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	if (hWnd == NULL) {
		MessageBox(NULL, "Window Couldn't Be Created Successfully!", "WindowProgram", MB_OK);
		ExitProcess(1);
	}
	ShowWindow(hWnd, nShowCmd);

	// Button [Show The Non-Centralising And Centralising Examples To Extend The Articles Further By A Bit]
	RECT rect = { 0 };
	GetWindowRect(hWnd, &rect);
	INT width = rect.right - rect.left;
	INT height = rect.bottom - rect.top;
	//HWND hWndButton = CreateWindowEx(0, "BUTTON", "Button", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, width / 2 - (70 / 2), height / 2 - (40 / 2), 70, 40, hWnd, NULL, (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);
	HWND hWndButton = CreateWindowEx(0, "BUTTON", "Button", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 235, 234, 70, 40, hWnd, NULL, (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (GetMessage(&msg, NULL, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}