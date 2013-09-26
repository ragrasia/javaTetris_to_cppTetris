#include"TetrisMain.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR nCmdLine, int nCmdShow)
{
	const wchar_t CLASS_NAME[] = L"WindowClass";

	WNDCLASS wc = { }; // <- ������ ȭ���� ���¿� ���� ���� �ϴ� �κ��̴�.
	wc.lpfnWndProc = WindowProc; // <- ȭ���� ����� �����ϴ� �κ�
	wc.hCursor = LoadCursor(NULL, IDC_CROSS);
	wc.lpszClassName = CLASS_NAME;
	wc.hInstance = hInstance; 
	RegisterClass(&wc);

	RECT rectWindow;
	//GetWindowRect(�������� ȭ���� hwnd, ������ �����ϴ� rect ��ü)
	GetWindowRect(GetDesktopWindow(), &rectWindow);

	LONG width = 300;
	LONG height = 500;

	LONG x = LONG((rectWindow.right - width) / 2);
	LONG y = LONG((rectWindow.bottom - height) / 2);

	HWND hwnd = CreateWindowEx( //WNDCLASS ��ü�� ������ ��� ������ �߰��Ͽ� ȭ���� �����Ѵ�.
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
	PeekMessage�Լ��� GetMessage�� ����ϴ�. �Ѱ��� �ٸ����� wRemoveMsg �̴�.

	GetMessage ���ᰡ �ƴ� �̻� �׻� true�� ��ȯ�ϸ� �޼����� ������ ��ٸ���.
	PeekMessage �޼����� ������ false�� ��ȯ�Ѵ�.
	- �����÷��״� PM_NOREMOVE, PM_REMOVE�� �ִµ� PM_NOREMOVE  �޽��� ť���� �޽����� �������� �ʴ´�.
	PM_REMOVE��   �޽��� ť���� �޽����� ���� ��κ��� ���� �޽���ť���� �޽����� �����Ѵ�.
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
			//TODO Ű �Է� ó�� 
		}return 0;

	case WM_DESTROY:PostQuitMessage(0); return 0;
	case WM_PAINT: //WM_PAINT�� �ٸ� �޽����ʹ� �޸� �׸��� ���ٰ� �ϴ��� �޽��� ó���ڵ带 ����ξ �ȵȴ�.
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
			if(MessageBox(hwnd, L"�����մϱ�?", L"exit", MB_OKCANCEL) == IDOK)
				DestroyWindow(hwnd);
		}return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, IParam);
}
