#include "player.h"
#include <QDebug>
#include <QTimer>
#include <QPainter>
#include <QgraphicsScene>

const QColor player::defaultColor = QColor(Qt::blue);

void player::keyPressEvent(QKeyEvent* event)
{
	if (event->isAutoRepeat()) {
		return;
	}

	keysPressed += event->key();	// add key to set of pressed keys when pressed
	
	//if (!timer->isActive()) {
	//	timer->start(playerMoveDelay);
	//}

}

void player::keyReleaseEvent(QKeyEvent* event)
{
	if (event->isAutoRepeat()) {
		return;
	}
	keysPressed -= event->key();	// remove key from set of pressed keys when released

	//if (keysPressed.isEmpty()) {
	//	timer->stop();
	//}

}

// update internal coordinates based on key press
void player::movePlayer() {
	int newX = x;
	int newY = y;

	if (keysPressed.contains(Qt::Key_Left)) {
		newX--;
	}
	if (keysPressed.contains(Qt::Key_Right)) {
		newX++;
	}
	if (keysPressed.contains(Qt::Key_Up)) {
		newY--;
	}
	if (keysPressed.contains(Qt::Key_Down)) {
		newY++;
	}

	move(newX, newY);
}

player::player(int x, int y) : sprite(x, y, player::defaultColor)
{
}

bool player::exitLvl() {
	if (x > 20 && x < 30 && y>270 && y<290) {	//exit coordiantes
		return true;
	}
	else {
		return false;
	}
}

void player::getPlayerPos(int* getX, int* getY) {
	*getX = x;
	*getY = y;
}
