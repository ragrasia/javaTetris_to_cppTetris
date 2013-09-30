#pragma once

class TetrisTimer
{
private:

public:
	TetrisTimer(void (*funtion) , int repeatTime);
	void start();
	void stop();
	~TetrisTimer(void);
};

