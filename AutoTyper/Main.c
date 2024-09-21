#include <Windows.h>
#include <WinBase.h>
#include <WinUser.h>
#include <Richedit.h>

LPSTR ToMultiByte(LPWSTR lpWideStr) {
	INT strSize = WideCharToMultiByte(CP_ACP, 0, lpWideStr, -1, NULL, 0, NULL, NULL);
	LPSTR lpStr = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, strSize);
	WideCharToMultiByte(CP_ACP, 0, lpWideStr, -1, lpStr, strSize, NULL, NULL);
	return lpStr;
}

VOID WINAPI AutoType(HWND editWnd, LPSTR message) {
	INT len = lstrlen(message);
	LPSTR msg = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, len + 1);
	
	for (INT j = 0; j < (len + 1); j++) {
		msg[j] = message[j];
		Sleep(200);
		SendMessage(editWnd, WM_SETTEXT, 0, msg);
	}
}

VOID WINAPI AutoTypeAlt(HWND editWnd, LPSTR message) {
	SetForegroundWindow(editWnd);
	INT len = lstrlen(message);
	INPUT ip, relIp;
	ZeroMemory(&ip, sizeof(ip));
	ZeroMemory(&relIp, sizeof(relIp));
	ip.type = relIp.type = INPUT_KEYBOARD;
	relIp.ki.dwFlags = KEYEVENTF_KEYUP;

	for (INT j = 0; j < (len + 1); j++) {
		ip.ki.wVk = relIp.ki.wVk = VkKeyScan(message[j]);
		SendInput(1, &ip, sizeof(INPUT));
		Sleep(50);
		SendInput(1, &relIp, sizeof(INPUT));
		Sleep(150);
	}
}

VOID WINAPI NotepadAutoType(BOOL useAlternativeMethod) {
	HWND hWnd = FindWindow("Notepad", NULL);
	HWND editWnd = FindWindowEx(hWnd, NULL, "Edit", NULL);
	if (!useAlternativeMethod) AutoType(editWnd, "Hello! How Are You? Hope You Are Well.");
	else AutoTypeAlt(editWnd, "Hello! How Are You? Hope You Are Well.");
}

VOID WINAPI WordpadAutoType() {
	LPWSTR richEditClassW = MSFTEDIT_CLASS;
	LPSTR richEditClass = ToMultiByte(richEditClassW);
	HWND hWnd = FindWindow("WordPadClass", NULL);
	HWND editWnd = FindWindowEx(hWnd, NULL, richEditClass, NULL);
	AutoType(editWnd, "Hello! How Are You? Hope You Are Well.");
}

INT WINAPI WinMain(_In_ HINSTANCE hInstance, _In_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdline, _In_ INT nShowCmd) {
	NotepadAutoType(TRUE);
	//WordpadAutoType();
}