#include "Main.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	/*case WM_SIZE:
		INT width = LOWORD(lParam) / 2 - (70 / 2);
		INT height = HIWORD(lParam) / 2 - (40 / 2);

		HWND hWndChild = GetWindow(hWnd, GW_CHILD);
		SetWindowPos(hWndChild, NULL, width, height, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
		return DefWindowProc(hWnd, uMsg, wParam, lParam); */
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_PAINT:
		PAINTSTRUCT ps;
		ZeroMemory(&ps, sizeof(ps));
		HDC hdc = BeginPaint(hWnd, &ps);

		// All painting occurs between BeginPaint and EndPaint.
		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

		EndPaint(hWnd, &ps);
		return 0;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		return 0;
	case WM_COMMAND:
		if (HIWORD(wParam) == BN_CLICKED) {
			MessageBox(NULL, "Message From Button Click!", "Message", MB_ICONINFORMATION | MB_OK);
		}
		return 0;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
}