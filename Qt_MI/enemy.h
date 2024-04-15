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
	void clearPath();
private:
	void path();
	bool possitionValid(int x, int y);
	int distanceTo(int ToX, int ToY, int FromX, int FromY);
	
	const int maxTargetDistanece = 200; //set maximum distance (lower number improwes speed of searching for paths)
	
	struct node {
		int X;
		int Y;
		int F;
		int G;
		int H;
		node* parent;	// parrent node

		struct node(int nX, int nY, int nF, int nG, int nH, node* nparent)
			: X(nX), Y(nY), F(nF), G(nG), H(nH), parent(nparent) {}

		bool operator<(const node& other) const {	//overload operator for sorting in priority_queue
			return F > other.F;
		}

	};

	void updateClosedSetImage(const std::vector<std::vector<bool>>& closedSet, QImage& image);
	void updateOpenSetImage(const std::vector<node>& openSet, QImage& image);

	const int refreashRate = 10;
	int refreashCnt = 0;
	int targetX;
	int targetY;
	int i = 0;
	int j = 0;
	int prevI = 0;
	int speedI = 0;
	int speed = 1;	

	const int pathStep = 10; //ammount of pixels per move

	std::vector<int> pathX;
	std::vector<int> pathY;
	
	std::vector<int> prevPathX;
	std::vector<int> prevPathY;

};

