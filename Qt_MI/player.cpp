#include "player.h"
#include <QDebug>
#include <QTimer>
#include <QPainter>
#include <QgraphicsScene>

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

/// <summary>
/// Update internal coordinates based on key press
/// </summary>
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

player::player(int x, int y) : entity(x, y)
{
}

bool player::exitLvl() {
	if (x > 20 && x < 25 && y>275 && y<285) {	//exit coordiantes
		return true;
	}
	else {
		return false;
	}
}

	