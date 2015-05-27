#define UNICODE
#pragma comment(lib,"imm32")
#include<windows.h>

TCHAR szClassName[] = TEXT("Window");

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static HWND hEdit[5];
	switch (msg)
	{
	case WM_CREATE:
		hEdit[0] = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), 0, WS_VISIBLE | WS_CHILD | WS_TABSTOP | ES_AUTOHSCROLL | ES_UPPERCASE, 10, 10, 64, 30, hWnd, 0, ((LPCREATESTRUCT)lParam)->hInstance, 0);
		hEdit[1] = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), 0, WS_VISIBLE | WS_CHILD | WS_TABSTOP | ES_AUTOHSCROLL | ES_UPPERCASE, 10 + 64 + 10, 10, 64, 30, hWnd, 0, ((LPCREATESTRUCT)lParam)->hInstance, 0);
		hEdit[2] = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), 0, WS_VISIBLE | WS_CHILD | WS_TABSTOP | ES_AUTOHSCROLL | ES_UPPERCASE, 10 + 64 + 10 + 64 + 10, 10, 64, 30, hWnd, 0, ((LPCREATESTRUCT)lParam)->hInstance, 0);
		hEdit[3] = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), 0, WS_VISIBLE | WS_CHILD | WS_TABSTOP | ES_AUTOHSCROLL | ES_UPPERCASE, 10 + 64 + 10 + 64 + 10 + 64 + 10, 10, 64, 30, hWnd, 0, ((LPCREATESTRUCT)lParam)->hInstance, 0);
		hEdit[4] = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), 0, WS_VISIBLE | WS_CHILD | WS_TABSTOP | ES_AUTOHSCROLL | ES_UPPERCASE, 10 + 64 + 10 + 64 + 10 + 64 + 10 + 64 + 10, 10, 64, 30, hWnd, 0, ((LPCREATESTRUCT)lParam)->hInstance, 0);
		SendMessage(hEdit[0], EM_LIMITTEXT, 29, 0);
		SendMessage(hEdit[1], EM_LIMITTEXT, 5, 0);
		SendMessage(hEdit[2], EM_LIMITTEXT, 5, 0);
		SendMessage(hEdit[3], EM_LIMITTEXT, 5, 0);
		SendMessage(hEdit[4], EM_LIMITTEXT, 5, 0);
		ImmAssociateContext(hEdit[0], 0);
		ImmAssociateContext(hEdit[1], 0);
		ImmAssociateContext(hEdit[2], 0);
		ImmAssociateContext(hEdit[3], 0);
		ImmAssociateContext(hEdit[4], 0);
		break;
	case WM_COMMAND:
		if (HIWORD(wParam) == EN_UPDATE)
		{
			TCHAR szInputLicenseKey[30];
			int nStartChar, nEndChar;

			if ((HWND)lParam == hEdit[0])
			{
				GetWindowText((HWND)lParam, szInputLicenseKey, 30);
				SendMessage((HWND)lParam, EM_GETSEL, (WPARAM)&nStartChar, (LPARAM)&nEndChar);
				if ((nStartChar == 5) && (nEndChar == 5))
				{
					SetFocus(hEdit[1]);
					SendMessage(hEdit[1], EM_SETSEL, 0, -1);
				}
				else if ((nStartChar == 29) && (nEndChar == 29)) // 11111-22222-33333-44444-55555
				{
					szInputLicenseKey[5] = 0;
					szInputLicenseKey[11] = 0;
					szInputLicenseKey[17] = 0;
					szInputLicenseKey[23] = 0;
					szInputLicenseKey[29] = 0;
					SetWindowText(hEdit[0], szInputLicenseKey);
					SetWindowText(hEdit[1], &szInputLicenseKey[6]);
					SetWindowText(hEdit[2], &szInputLicenseKey[12]);
					SetWindowText(hEdit[3], &szInputLicenseKey[18]);
					SetWindowText(hEdit[4], &szInputLicenseKey[24]);
					SetFocus(hEdit[4]);
					const DWORD dwLength = GetWindowTextLength(hEdit[4]);
					SendMessage(hEdit[4], EM_SETSEL, dwLength, dwLength);
				}
				else if ((nStartChar == 25) && (nEndChar == 25)) // 1111122222333334444455555
				{
					szInputLicenseKey[25] = 0;
					SetWindowText(hEdit[4], &szInputLicenseKey[20]);
					szInputLicenseKey[20] = 0;
					SetWindowText(hEdit[3], &szInputLicenseKey[15]);
					szInputLicenseKey[15] = 0;
					SetWindowText(hEdit[2], &szInputLicenseKey[10]);
					szInputLicenseKey[10] = 0;
					SetWindowText(hEdit[1], &szInputLicenseKey[5]);
					szInputLicenseKey[5] = 0;
					SetWindowText(hEdit[0], &szInputLicenseKey[0]);
					SetFocus(hEdit[4]);
					const DWORD dwLength = GetWindowTextLength(hEdit[4]);
					SendMessage(hEdit[4], EM_SETSEL, dwLength, dwLength);
				}
			}
			else if ((HWND)lParam == hEdit[1])
			{
				GetWindowText((HWND)lParam, szInputLicenseKey, 30);
				SendMessage((HWND)lParam, EM_GETSEL, (WPARAM)&nStartChar, (LPARAM)&nEndChar);
				if ((nStartChar == 5) && (nEndChar == 5))
				{
					SetFocus(hEdit[2]);
					SendMessage(hEdit[2], EM_SETSEL, 0, -1);
				}
				else if ((nStartChar == 0) && (nEndChar == 0))
				{
					SetFocus(hEdit[0]);
					const DWORD dwLength = GetWindowTextLength(hEdit[0]);
					SendMessage(hEdit[0], EM_SETSEL, dwLength, dwLength);
				}
			}
			else if ((HWND)lParam == hEdit[2])
			{
				GetWindowText((HWND)lParam, szInputLicenseKey, 30);
				SendMessage((HWND)lParam, EM_GETSEL, (WPARAM)&nStartChar, (LPARAM)&nEndChar);
				if ((nStartChar == 5) && (nEndChar == 5))
				{
					SetFocus(hEdit[3]);
					SendMessage(hEdit[3], EM_SETSEL, 0, -1);
				}
				else if ((nStartChar == 0) && (nEndChar == 0))
				{
					SetFocus(hEdit[1]);
					const DWORD dwLength = GetWindowTextLength(hEdit[1]);
					SendMessage(hEdit[1], EM_SETSEL, dwLength, dwLength);
				}
			}
			else if ((HWND)lParam == hEdit[3])
			{
				GetWindowText((HWND)lParam, szInputLicenseKey, 30);
				SendMessage((HWND)lParam, EM_GETSEL, (WPARAM)&nStartChar, (LPARAM)&nEndChar);
				if ((nStartChar == 5) && (nEndChar == 5))
				{
					SetFocus(hEdit[4]);
					SendMessage(hEdit[4], EM_SETSEL, 0, -1);
				}
				else if ((nStartChar == 0) && (nEndChar == 0))
				{
					SetFocus(hEdit[2]);
					const DWORD dwLength = GetWindowTextLength(hEdit[2]);
					SendMessage(hEdit[2], EM_SETSEL, dwLength, dwLength);
				}
			}
			else if ((HWND)lParam == hEdit[4])
			{
				SendMessage((HWND)lParam, EM_GETSEL, (WPARAM)&nStartChar, (LPARAM)&nEndChar);
				if ((nStartChar == 0) && (nEndChar == 0))
				{
					SetFocus(hEdit[3]);
					const DWORD dwLength = GetWindowTextLength(hEdit[3]);
					SendMessage(hEdit[3], EM_SETSEL, dwLength, dwLength);
				}
			}
		}
		break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return(DefDlgProc(hWnd, msg, wParam, lParam));
	}
	return 0;
}

EXTERN_C void __cdecl WinMainCRTStartup()
{
	MSG msg;
	HINSTANCE hInstance = GetModuleHandle(0);
	WNDCLASS wndclass = { 0, WndProc, 0, DLGWINDOWEXTRA, hInstance, 0, LoadCursor(0, IDC_ARROW), 0, 0, szClassName };
	RegisterClass(&wndclass);
	HWND hWnd = CreateWindow(szClassName, TEXT("ライセンスキー入力"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, 0, 0, hInstance, 0);
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);
	while (GetMessage(&msg, 0, 0, 0))
	{
		if (!IsDialogMessage(hWnd, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	ExitProcess(msg.wParam);
}

#if _DEBUG
void main(){}
#endif
