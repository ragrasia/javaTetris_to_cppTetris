#pragma once
#include <string>
#include "BlockShape.h"

using namespace std;

class TetrisBoard
{
public:

	TetrisBoard(void);

	void setName(wstring input);

	wstring getName();

	void setGameInfoText(wstring input);

	wstring getGameInfoText();

	~TetrisBoard(void);

private:

	wstring name;
	
	wstring gameInfoText;
};

