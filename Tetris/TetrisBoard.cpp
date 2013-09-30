#include "TetrisBoard.h"

TetrisBoard::TetrisBoard(void)
{
	//초기화
	isFallingFinised = false;
	isStarted = false;
	isPaused = false;
	locationX = 0;
	locationY = 0;
	countLinesRemoved = 0;

	//포커스 가져오기
	pieceShape = new BlockShape();
	//타이머 객체 설정

	gameInfoText = L"준비";
}

void TetrisBoard::setGameInfoText(wstring input)
{
	gameInfoText = input;
}

wstring TetrisBoard::getGameInfoText()
{
	return gameInfoText;
}

TetrisBoard::~TetrisBoard(void)
{
}
