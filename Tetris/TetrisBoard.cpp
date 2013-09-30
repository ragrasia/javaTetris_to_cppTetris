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
	tetristimer = new TetrisTimer(this->repeatAction, 600);
	tetristimer->start();

	gameInfoText = L"�غ�";
	clearBoard();
}

void TetrisBoard::repeatAction(){
	if(isFallingFinised){
		isFallingFinised = false;
		newPiece();		
	} else{
		oneLineDown();
	}
}

int TetrisBoard::squareWidth() {
	int widthSize;
	return widthSize / BoardWidth;
}

int TetrisBoard::squareHeight() {
	int heightSize;
	return heightSize / BoardHeight;
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
