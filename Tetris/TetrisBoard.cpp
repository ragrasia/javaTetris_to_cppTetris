#include "TetrisBoard.h"

TetrisBoard::TetrisBoard(void)
{
}

void TetrisBoard::setName(wstring input)
{
	name = input;
}

wstring TetrisBoard::getName()
{
	return name;
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
