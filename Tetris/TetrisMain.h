#pragma once

#include <Windows.h>
#include <time.h>

#include"TetrisBoard.h"


TetrisBoard board;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM IParam);
