#include "BlockShape.h"

BlockShape::BlockShape(void){
	setShape(NoShape);
}

void BlockShape::setShape(TetrisBlocks shape)
{

	int coordsTable[8][4][2] = {
		{ { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } }, 
		{ { 0, -1 }, { 0, 0 }, { -1, 0 }, { -1, 1 } },
		{ { 0, -1 }, { 0, 0 }, { 1, 0 }, { 1, 1 } },
		{ { 0, -1 }, { 0, 0 }, { 0, 1 }, { 0, 2 } },
		{ { -1, 0 }, { 0, 0 }, { 1, 0 }, { 0, 1 } },
		{ { 0, 0 }, { 1, 0 }, { 0, 1 }, { 1, 1 } },
		{ { -1, -1 }, { 0, -1 }, { 0, 0 }, { 0, 1 } },
		{ { 1, -1 }, { 0, -1 }, { 0, 0 }, { 0, 1 } } 
	};

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 2; j++){
			coords[i][j] = coordsTable[shape][i][j];
		}
	}

	nowShape = shape;
}
void BlockShape::setRandomShape(){
	srand((unsigned)time(NULL));
	int x = 1 + rand() % 7;
	TetrisBlocks val = static_cast<TetrisBlocks>(x);
	setShape(val);
}
BlockShape::TetrisBlocks BlockShape::getShape(){
	return nowShape;
}
int BlockShape::getX(int i){
	return coords[i][0];
}
int BlockShape::getY(int i){
	return coords[i][1];
}
void BlockShape::setX(int i, int x){
	coords[i][x];
}
void BlockShape::setY(int i, int y){
	coords[i][y];
}
int BlockShape::minX(){
	int min = coords[0][0];
	for(int i = 0; i < 4; i++){
		if(min > coords[i][0]){
			min = coords[i][0];
		}
	}
	return min;
}
int BlockShape::minY(){
	int min = coords[0][1];
	for(int i = 0; i < 4; i++){
		if(min > coords[i][1]){
			min = coords[i][1];
		}
	}
	return min;
}
BlockShape *BlockShape::rotateRight(){
	if (nowShape == SquareShape){
		BlockShape square;
		square.setShape(SquareShape);
		return &square;
	}

	BlockShape result = BlockShape();
	result.setShape(nowShape);

	for (int i = 0; i < 4; ++i) {
		result.setX(i, getY(i));
		result.setY(i, -getX(i));
	}
	return &result;
}
BlockShape *BlockShape::rotateLeft(){
	if (nowShape == SquareShape){
		BlockShape square;
		square.setShape(SquareShape);
		return &square;
	}

	BlockShape result = BlockShape();
	result.setShape(nowShape);

	for (int i = 0; i < 4; ++i) {
		result.setX(i, -getY(i));
		result.setY(i, getX(i));
	}
	return &result;
}

BlockShape::~BlockShape(void){
}