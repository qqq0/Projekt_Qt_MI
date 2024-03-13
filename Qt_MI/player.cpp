#include "player.h"
#include <QDebug>
#include <QTimer>

player::player() {
	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &player::movePlayer);
}

void player::keyPressEvent(QKeyEvent* event)
{
	if (event->isAutoRepeat()) {
		return;
	}

	keysPressed += event->key();	// add key to set of pressed keys when pressed
	
	if (!timer->isActive()) {
		timer->start(playerMoveDelay);
	}

	qDebug() << "key press detected";
}

void player::keyReleaseEvent(QKeyEvent* event)
{
	if (event->isAutoRepeat()) {
		return;
	}
	keysPressed -= event->key();	// remove key from set of pressed keys when released

	if (keysPressed.isEmpty()) {
		timer->stop();
	}

	qDebug() << "key release detected";
}


void player::movePlayer() {
	if (keysPressed.contains(Qt::Key_Left)) {
		setPos(x() - 1, y());

	}
	if (keysPressed.contains(Qt::Key_Right)) {
		setPos(x() + 1, y());

	}
	if (keysPressed.contains(Qt::Key_Up)) {
		setPos(x(), y() - 1);
	}
	if (keysPressed.contains(Qt::Key_Down)) {
		setPos(x(), y() + 1);
	}
}
