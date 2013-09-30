#pragma once
#include <string>
#include "BlockShape.h"
#include "TetrisTimer.h"

using namespace std;

class TetrisBoard
{
public:

	TetrisBoard(void);

	int squareWidth();
	int squareHeight();
	
	BlockShape::TetrisBlocks shapeAt(int x, int y);
	void start();
	bool requestDrawing();

	void setGameInfoText(wstring input);

	wstring getGameInfoText();

	~TetrisBoard(void);

private:

	const int BoardWidth = 10;
	const int BoardHeight = 22;

	TetrisTimer *tetristimer;

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
	void repeatAction();
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

