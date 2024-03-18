#include "enemy.h"

const QColor enemy::defaultColor = QColor(Qt::red);

enemy::enemy(int x, int y) : sprite(x, y, enemy::defaultColor)
{
}

void enemy::moveEnemy(bool chase,int playerX,int playerY) {

	if (rand() % 100 > speed){	// skip moves to slow down enemy
		return;
	}

	if (chase) {
		targetX = playerX;
		targetY = playerY;
		path();
		i = 0;
	}else if(pathX.size() <= i || pathY.size() <= i) {
		chooseTarget(800, 600);	// zmieniæ wymiary na sta³e przekazywane do enemy
		path();
		i = 0;
	}

	if (pathX.size() > i && pathY.size() > i) {
		int newX = pathX[i];
		int newY = pathY[i];
		move(newX, newY);
		i++;
	}

}

int enemy::distanceTo(int ToX, int ToY) {
	int dist;
	dist = (int)sqrt((x - ToX) * (x - ToX) + (y - ToY) * (y - ToY));
	return dist;
}

void enemy::chooseTarget(int width, int height) {

	int minX = 20;
	int maxX = width - 40;
	int minY = 20;
	int maxY = height - 40;

	targetX = minX + rand() % (maxX - minX + 1);
	targetY = minY + rand() % (maxY - minY + 1);
}

void enemy::path() {
	int tmpX = x;
	int tmpY = y;

	pathX.clear();
	pathY.clear();

	while ((targetX != tmpX) || (targetY != tmpY)) {

		if (targetX != tmpX) {
			if (targetX > tmpX) {
				tmpX++;
			}
			else if (targetX < tmpX) {
				tmpX--;
			}
		}
		pathX.push_back(tmpX);

		if (targetY != tmpY) {
			if (targetY > tmpY) {
				tmpY++;
			}
			else if (targetY < tmpY) {
				tmpY--;
			}
		}
		pathY.push_back(tmpY);

	}


}