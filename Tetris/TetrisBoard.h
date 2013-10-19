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
	bool requestDrawing();

	void setGameInfoText(wstring input);

	wstring getGameInfoText();

	void leftMove();
	void rightMove();
	void turnRight();
	void turnLeft();

	void gameStateCheak();
	void pause();

	~TetrisBoard(void);

private:

	int BoardWidth;
	int BoardHeight;

	bool isFallingFinised;
	bool isStarted;
	bool isPaused;

	int locationX;
	int locationY;

	BlockShape *pieceShape;
	BlockShape::TetrisBlocks board[220];

	int countLinesRemoved;

	wstring gameInfoText;

	//이하 함수
	void repeatAction();
	void dropDown();
	void oneLineDown();
	void clearBoard();
	void pieceDropped();
	void newPiece();
	bool tryMove(BlockShape * movePiece, int newX, int newY);
	void removeFullLines();
	//블록 그리기 함수
};

class ttimer{
public:
	ttimer(void (*repeatAction), int repeatTime);
	void start();
	void stop();
private:
	typedef void (*funtion)();
};

