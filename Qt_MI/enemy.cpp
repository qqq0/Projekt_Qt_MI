#include "enemy.h"
#include <qdebug.h>
#include <algorithm>

const QColor enemy::defaultColor = QColor(Qt::red);

enemy::enemy(int x, int y) : sprite(x, y, enemy::defaultColor)
{
}

void enemy::moveEnemy(bool chase,int playerX,int playerY) {

	if (rand() % 100 > speed){	// skip moves to slow down enemy
		return;
	}

	if (chase) {
		if (refreashCnt == refreashRate) {
			refreashCnt = 0;
			targetX = playerX;
			targetY = playerY;
			path();
			i = 0;
		}else{
			refreashCnt++;
		}
		
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
	//dist = (int)sqrt((x - ToX) * (x - ToX) + (y - ToY) * (y - ToY));
	//return dist;
	dist = abs(x - ToX) + abs(y - ToY);
	return dist;
}

void enemy::chooseTarget(int width, int height) {

	int minX = 20;
	int maxX = width - 40;
	int minY = 20;
	int maxY = height - 40;

	do {
		targetX = minX + rand() % (maxX - minX + 1);
		targetY = minY + rand() % (maxY - minY + 1);
	} while (!possitionValid(targetX, targetY));
	

}

struct node{
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

bool enemy::possitionValid(int x, int y) {
	setPos(x, y);

	if (collisionDetection()) {
		setPos(prevX, prevY);
		return false;
	}
	else {
		setPos(prevX, prevY);
		return true;
	}
}

int enemy::distanceTo(int ToX, int ToY,int FromX, int FromY) {
	int dist;
	dist = abs(FromX - ToX) + abs(FromY - ToY);
	return dist;
}

void enemy::path() {
	
	//A* algorithm
	pathX.clear();
	pathY.clear();

	std::priority_queue<node> openSet;
	std::vector<std::vector<bool>> closedSet(800, std::vector<bool>(600, false));
	std::vector<std::vector<node*>> cameFrom(800, std::vector<node*>(600, nullptr));

	node start(x, y, 0, 0, distanceTo(targetX, targetY), nullptr);
	openSet.push(start);
	while (!openSet.empty()) {
		node current = openSet.top();
		openSet.pop();

		//path reconstruction
		if (current.X == targetX && current.Y == targetY) {
			while (current.parent != nullptr) {
				pathX.push_back(current.X);
				pathY.push_back(current.Y);
				current = *(current.parent);
			}
			std::reverse(pathX.begin(), pathX.end());
			std::reverse(pathY.begin(), pathY.end());

			return;
		}

		closedSet[current.X][current.Y] = true;
		
		//check neighbor nodes
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i == 0 && j == 0) {
					continue;
				}

				int newX = current.X + i;
				int newY = current.Y + j;
				//check if node creates a collision
				if (possitionValid(newX,newY)) {
					int checkG = current.G + 1;
					int checkH = distanceTo(targetX,targetY,newX, newY);
					int checkF = checkG + checkH;

					//if not alredy added, add node to set and update parrent
					if (!closedSet[newX][newY] || (checkF < current.F)) {
						if (!closedSet[newX][newY]) {
							openSet.push(node(newX, newY, checkF, checkG, checkH, new node(current)));
							cameFrom[newX][newY] = new node(current);
						}
					}


				}
			}
		}
	}
}



