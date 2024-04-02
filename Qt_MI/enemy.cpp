#include "enemy.h"
#include <qdebug.h>
#include <algorithm>
#include <qimage.h>
#include <qlabel.h>
#include <qapplication.h>

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




// Function to update the closed set image
void enemy::updateClosedSetImage(const std::vector<std::vector<bool>>& closedSet, QImage& image) {
	// Set pixels corresponding to closed set
	for (int i = 0; i < closedSet.size(); ++i) {
		for (int j = 0; j < closedSet[i].size(); ++j) {
			if (closedSet[i][j]) {
				image.setPixel(i, j, qRgb(0, 0, 255)); // Set pixel to black
			}
			else {
				image.setPixel(i, j, qRgb(255, 255, 255)); // Set pixel to white
			}
		}
	}
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			image.setPixel(targetX + i, targetY + j, qRgb(255, 0, 0));
		}
	}
	
}

void enemy::updateOpenSetImage(const std::vector<node>& openSet, QImage& image) {
	// Set pixels corresponding to nodes in the open set
	for (const auto& node : openSet) {
		image.setPixel(node.X+1, node.Y, qRgb(255, 0, 0)); // Set pixel to green
	}
}




void enemy::path() {
	
	//A* algorithm
	pathX.clear();
	pathY.clear();

	//std::priority_queue<node> openSet;
	std::vector<node> openSet;
	std::vector<std::vector<bool>> closedSet(800, std::vector<bool>(600, false));

	bool update = false;

	node start(x, y, 0, 0, distanceTo(targetX, targetY), nullptr);
	openSet.push_back(start);



	QImage image(800, 600, QImage::Format_RGB32);
	QLabel label;
	int c = 0;


	while (!openSet.empty()) {
		std::sort(openSet.begin(), openSet.end());
		node current = openSet.back();
		openSet.pop_back();


		
		if (c >= 10) {
			c = 0;
			updateClosedSetImage(closedSet, image);
			updateOpenSetImage(openSet, image);

			// Display the updated image
			label.setPixmap(QPixmap::fromImage(image));
			label.show();
			qApp->processEvents();
		}else {
			c++;
		}
		



		//path reconstruction
		if ((abs(current.X - targetX) <=5) && (abs(current.Y - targetY) <=5)) {
		//if (current.X == targetX && current.Y == targetY) {
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
		for (int i = -5; i <= 5; i+=5) {
			for (int j = -5; j <= 5; j+=5) {
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

							update = false;

							for (auto& n : openSet) {
								if (n.X == newX && n.Y == newY) {
									
									if (checkF <= n.F) {
										
										update = true;
										if (checkF == n.F) continue;
										n.F = checkF;
										n.G = checkG;
										n.H = checkH;
										n.parent = new node(current);
									}
								}
							}
							
							if (!update) {
								openSet.push_back(node(newX, newY, checkF, checkG, checkH, new node(current)));
							}
							
							
							//cameFrom[newX][newY] = new node(current);
						}
					}


				}
			}
		}
	}
}



