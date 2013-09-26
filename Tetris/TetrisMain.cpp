#include"TetrisMain.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR nCmdLine, int nCmdShow)
{
	const wchar_t CLASS_NAME[] = L"WindowClass";

	WNDCLASS wc = { }; // <- 구현할 화면의 형태에 대해 정의 하는 부분이다.
	wc.lpfnWndProc = WindowProc; // <- 화면의 기능을 구현하는 부분
	wc.hCursor = LoadCursor(NULL, IDC_CROSS);
	wc.lpszClassName = CLASS_NAME;
	wc.hInstance = hInstance; 
	RegisterClass(&wc);

	RECT rectWindow;
	//GetWindowRect(얻으려는 화면의 hwnd, 정보를 저장하는 rect 객체)
	GetWindowRect(GetDesktopWindow(), &rectWindow);

	LONG width = 300;
	LONG height = 500;

	LONG x = LONG((rectWindow.right - width) / 2);
	LONG y = LONG((rectWindow.bottom - height) / 2);

	HWND hwnd = CreateWindowEx( //WNDCLASS 객체를 가지고 몇몇 설정을 추가하여 화면을 구성한다.
		0,
		CLASS_NAME,
		L"Tetris!",
		WS_OVERLAPPEDWINDOW,
		x, y, width, height,
		NULL, NULL, hInstance, NULL);

	if(hwnd == 0)
	{
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	nCmdShow = 1;

	MSG msg = { };
	bool onLoop = true;

	board = TetrisBoard();
	board.setGameInfoText(L"new board");

	/* 
	PeekMessage함수는 GetMessage와 비슷하다. 한가지 다른점은 wRemoveMsg 이다.

	GetMessage 종료가 아닌 이상 항상 true를 반환하며 메세지가 없으면 기다린다.
	PeekMessage 메세지가 없으면 false을 반환한다.
	- 제거플래그는 PM_NOREMOVE, PM_REMOVE이 있는데 PM_NOREMOVE  메시지 큐에서 메시지를 제거하지 않는다.
	PM_REMOVE이   메시지 큐에서 메시지를 제거 대부분의 경우는 메시지큐에서 메시지를 제거한다.
	*/
	while(onLoop){
		if(msg.message == WM_QUIT)
		{
			onLoop = false;
		}
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM IParam)
{
	switch(uMsg)
	{
	case WM_KEYDOWN:
		{
			//TODO 키 입력 처리 
		}return 0;

	case WM_DESTROY:PostQuitMessage(0); return 0;
	case WM_PAINT: //WM_PAINT는 다른 메시지와는 달리 그릴게 없다고 하더라도 메시지 처리코드를 비워두어선 안된다.
		{
			HDC hdc;
			PAINTSTRUCT ps;

			wstring text = board.getGameInfoText();

			hdc = BeginPaint(hwnd, &ps);
			TextOut(hdc, 100, 100, (LPCWSTR)text.c_str(), text.size());
			EndPaint(hwnd, &ps);
		}return 0;
	case WM_CLOSE:
		{
			if(MessageBox(hwnd, L"종료합니까?", L"exit", MB_OKCANCEL) == IDOK)
				DestroyWindow(hwnd);
		}return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, IParam);
}
