#include "entity.h"



bool entity::collisionDetection() {
	QList<QGraphicsItem*> collidingItems = scene()->collidingItems(this);

	for (QGraphicsItem* item : collidingItems) {
		if (typeid(*item) == typeid(QGraphicsRectItem)) {
			
			return true;
		}

	}
	return false;
}

entity::entity(int x, int y)
{
	setBrush(QBrush(Qt::blue));
	setRect(0, 0, SIZE, SIZE);
	setEntityPos(x, y);
}

/// <summary>
/// Render entity position
/// Revert position if collision detected
/// </summary>
void entity::render() {

	setPos(x, prevY);
	if (collisionDetection()) {
		setPos(prevX, y);
		x = prevX;
	}

	setPos(x, y);
	if (collisionDetection()) {
		setPos(x, prevY);
		y = prevY;
	}

	prevX = x;
	prevY = y;
};

void entity::setEntityPos(int x, int y) {
	setPos(x, y);
	this->x = x;
	this->y = y;
	prevX = x;
	prevY = y;
}

/// <summary>
/// Update internal coordinates
/// </summary>
void entity::move(int x, int y) {
	this->x = x;
	this->y = y;
};
