#include "TetrisBoard.h"

TetrisBoard::TetrisBoard(void)
{
	//�ʱ�ȭ
	BoardHeight = 22;
	BoardWidth = 10;
	isFallingFinised = false;
	isStarted = false;
	isPaused = false;
	locationX = 0;
	locationY = 0;
	countLinesRemoved = 0;

	//��Ŀ�� ��������
	pieceShape = new BlockShape();
	//tetristimer = new TetrisTimer(this->repeatAction, 600);
	//tetristimer->start();

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
	int widthSize = 1;
	return widthSize / BoardWidth;
}

int TetrisBoard::squareHeight() {
	int heightSize = 1;
	return heightSize / BoardHeight;
}

BlockShape::TetrisBlocks TetrisBoard::shapeAt(int x, int y){
	return board[(y * BoardWidth) + x];
}

void TetrisBoard::start(){
	if(isStarted){
		return;
	}
	isStarted = true;
	isFallingFinised = false;
	countLinesRemoved = 0;
	clearBoard();

	newPiece();
	//Ÿ�̸� ��ŸƮ
}

void TetrisBoard::pause(){
	if(!isStarted){
		return;
	}

	isPaused = !isPaused;

	if(isPaused){
		//Ÿ�̸� ����
		setGameInfoText(L"����");
	}else{
		//Ÿ�̸� ����
		setGameInfoText(L"score : "+ countLinesRemoved);
	}
	requestDrawing();
}

bool TetrisBoard::requestDrawing(){
	return true;
}

void TetrisBoard::dropDown(){
	int newY = locationY;
	while (newY > 0){
		if(!tryMove(pieceShape, locationX, newY -1))
			break;
		--newY;
	}
	pieceDropped();
}

void TetrisBoard::oneLineDown(){
	if(!tryMove(pieceShape, locationX, locationY -1))
		pieceDropped();
}

void TetrisBoard::clearBoard(){
	for(int i = 0; i < BoardHeight * BoardWidth; i++){
		board[i] = BlockShape::NoShape;
	}
}

void TetrisBoard::pieceDropped(){
	for(int i = 0; i < 4; ++i){
		int x = locationX + pieceShape->getX(i);
		int y = locationY + pieceShape->getY(i);
		board[(y * BoardWidth) + x] = pieceShape->getShape();
	}
	removeFullLines();

	if(!isFallingFinised){
		newPiece();
	}
}

void TetrisBoard::newPiece() {
	pieceShape->setRandomShape();

	locationX = BoardWidth / 2 + 1;
	locationY = BoardHeight - 1 + pieceShape->minY();

	if(!tryMove(pieceShape, locationX, locationY)){
		pieceShape->setShape(BlockShape::NoShape);
		//Ÿ�̸� ����
		isStarted = false;
		setGameInfoText(L"game over");
	}
}

bool TetrisBoard::tryMove(BlockShape *newPiece, int newX, int newY){
	for(int i = 0; i < 4;i++){
		int x = newX + newPiece->getX(i);
		int y = newY - newPiece->getY(i);

		if (x < 0 || x >= BoardWidth || y < 0 || y >= BoardHeight) {
			return false;
		}

		// �ٸ� ��Ʈ���� ��ϰ� �浹�ϴ� �� Ȯ��
		if (shapeAt(x, y) != BlockShape::NoShape) {
			return false;
		}
	}

	pieceShape = newPiece;
	locationX = newX;
	locationY = newY;
	requestDrawing();
	return true;
}

void TetrisBoard::removeFullLines(){
	int countFullLines = 0; // �� �޼ҵ� ������ �����ϴ� ������ ��

	for (int checkHeight = BoardHeight - 1; checkHeight >= 0; --checkHeight) {
		bool lineIsFull = true;// ���ο� ���� ����

		// �ش��ϴ� ���ο��� �ϳ��� �� ����� �ִ��� Ȯ��
		for (int checkWidth = 0; checkWidth < BoardWidth; ++checkWidth) {
			if (shapeAt(checkWidth, checkHeight) == BlockShape::NoShape) {
				lineIsFull = false;
				break;
			}
		}

		if (lineIsFull) {
			++countFullLines;
			// ������ ���� ���� ����� �Ʒ��� �̵�
			for (int k = checkHeight; k < BoardHeight - 1; ++k) {
				for (int j = 0; j < BoardWidth; ++j) {
					board[(k * BoardWidth) + j] = shapeAt(j, k + 1);
				}
			}
		}
	}

	if (countFullLines > 0) {
		countLinesRemoved += countFullLines;
		setGameInfoText(L"score : " + countLinesRemoved);
		isFallingFinised = true;
		pieceShape->setShape(BlockShape::NoShape);
		requestDrawing();
	}
}

void TetrisBoard::setGameInfoText(wstring input)
{
	gameInfoText = input;
}

wstring TetrisBoard::getGameInfoText()
{
	return gameInfoText;
}

void TetrisBoard::leftMove(){
	TetrisBoard::tryMove(pieceShape, locationX - 1, locationY);
}
void TetrisBoard::rightMove(){
	TetrisBoard::tryMove(pieceShape, locationX + 1, locationY);
}
void TetrisBoard::turnLeft(){
	TetrisBoard::tryMove(pieceShape->rotateLeft(), locationX, locationY);
}
void TetrisBoard::turnRight(){
	TetrisBoard::tryMove(pieceShape->rotateRight(), locationX, locationY);
}
void TetrisBoard::gameStateCheak(){
	if(!isStarted || pieceShape->getShape() == BlockShape::NoShape){
		return;
	}

	if(isPaused){
		return;
	}
}
TetrisBoard::~TetrisBoard(void)
{
}
