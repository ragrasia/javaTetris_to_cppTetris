#include "TetrisBoard.h"

TetrisBoard::TetrisBoard(void)
{
	//�ʱ�ȭ
	isFallingFinised = false;
	isStarted = false;
	isPaused = false;
	locationX = 0;
	locationY = 0;
	countLinesRemoved = 0;

	//��Ŀ�� ��������
	pieceShape = new BlockShape();
	//Ÿ�̸� ��ü ����

	gameInfoText = L"�غ�";
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
