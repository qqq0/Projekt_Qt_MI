#include "player.h"
#include <QDebug>
#include <QTimer>
#include <QPainter>
#include <QgraphicsScene>

player::player() {
	setBrush(QBrush(Qt::blue));
	setRect(0, 0, 20, 20);
	
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

}


void player::movePlayer() {
	
	int prevX, prevY;
	prevX = x();
	prevY = y();

	if (keysPressed.contains(Qt::Key_Left)) {
		setPos(x() - 1, y());

	}
	if (keysPressed.contains(Qt::Key_Right)) {
		setPos(x() + 1, y());


	}
	collisionDetection(prevX, y());

	if (keysPressed.contains(Qt::Key_Up)) {
		setPos(x(), y() - 1);
	}
	if (keysPressed.contains(Qt::Key_Down)) {
		setPos(x(), y() + 1);
	}

	collisionDetection(x(), prevY);
	
}

void player::collisionDetection(int X,int Y) {
	QList<QGraphicsItem*> collidingItems = scene()->collidingItems(this);

	for (QGraphicsItem* item : collidingItems) {
		if (typeid(*item) == typeid(QGraphicsRectItem)) {
			qDebug() << "colision detected";
			setPos(X, Y);
		}

	}
}

	