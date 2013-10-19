#pragma once
#include <stdlib.h>
#ifndef __time_h__
#define __time_h__
#include <time.h>
#endif // !__time_h__ 중복 헤더 선언 처리


class BlockShape
{
public:

	enum TetrisBlocks
	{
		NoShape, ZShape, SShape, LineShape, TShape, SquareShape, LShape, MirroredLShape
	};

	BlockShape(void);
	~BlockShape(void);

	void setShape(TetrisBlocks shape);
	void setRandomShape();

	TetrisBlocks getShape();

	int getX(int i);
	int getY(int i);
	void setX(int i, int x);
	void setY(int i, int y);
	int minX();
	int minY();

	BlockShape rotateRight();
	BlockShape rotateLeft();
private:
	TetrisBlocks nowShape;
	int coords[4][2];
};

