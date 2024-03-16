#include "enemy.h"

const QColor enemy::defaultColor = QColor(Qt::red);

enemy::enemy(int x, int y) : sprite(x, y, enemy::defaultColor)
{
}

void enemy::moveEnemy() {
	int newX = x;
	int newY = y;

	newX = newX + rand()%11-5;
	newY = newY + rand()%11-5;

	move(newX, newY);

}