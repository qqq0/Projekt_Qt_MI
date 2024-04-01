#pragma once
#include "sprite.h"
#include <vector>
#include<queue>

class enemy : public sprite
{
public:
	static const QColor defaultColor;
	enemy(int x, int y);
	void moveEnemy(bool chase, int playerX, int playerY);
	int distanceTo(int ToX, int ToY);
	void chooseTarget(int width,int haight);
private:
	void path();
	bool possitionValid(int x, int y);
	int distanceTo(int ToX, int ToY, int FromX, int FromY);

	const int refreashRate = 20;
	int refreashCnt = 0;
	int targetX;
	int targetY;
	int i = 0;
	int speed = 50;	// movement speed as % of player speed max 100%

	std::vector<int> pathX;
	std::vector<int> pathY;


};

