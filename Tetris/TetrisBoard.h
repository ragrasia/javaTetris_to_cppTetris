#pragma once
#include <string>
#include "BlockShape.h"

using namespace std;

class TetrisBoard
{
public:

	TetrisBoard(void);

	int squareWidth();
	int squareHeight();
	
	BlockShape::TetrisBlocks shapeAt(int x, int y);
	void start();
	//그리기 요청 함수

	void setGameInfoText(wstring input);

	wstring getGameInfoText();

	~TetrisBoard(void);

private:

	const int BoardWidth = 10;
	const int BoardHeight = 22;

	// 타이머 객체

	bool isFallingFinised;
	bool isStarted;
	bool isPaused;

	int locationX;
	int locationY;

	BlockShape *pieceShape;
	BlockShape::TetrisBlocks board[BoardWidth * BoardHeight];

	int countLinesRemoved;
	
	wstring gameInfoText;

	//이하 함수

	void pause();
	void dropDown();
	void oneLineDown();
	void clearBoard();
	void pieceDropped();
	void newPiece();
	bool tryMove(BlockShape movePiece, int newX, int newY);
	void removeFullLines();
	//블록 그리기 함수

};

