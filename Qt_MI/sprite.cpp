#include "sprite.h"

bool sprite::collisionDetection() {
	QList<QGraphicsItem*> collidingItems = scene()->collidingItems(this);

	for (QGraphicsItem* item : collidingItems) {
		// check if item is sprite subclass
		if (dynamic_cast<sprite*>(item) != nullptr) {	
			return true;
		}
		
		// check if wall
		if (typeid(*item) == typeid(QGraphicsRectItem)) {	
			return true;
		}
	}
	return false;
}

sprite::sprite(int x, int y, QBrush col)
{
	setBrush(col);
	setRect(0, 0, SIZE, SIZE);
	setSpritePos(x, y);
}

/// <summary>
/// Render entity position
/// Revert position if collision detected
/// </summary>
void sprite::render() {

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

void sprite::setSpritePos(int x, int y) {
	setPos(x, y);
	this->x = x;
	this->y = y;
	prevX = x;
	prevY = y;
}

/// <summary>
/// Update internal coordinates
/// </summary>
void sprite::move(int x, int y) {
	this->x = x;
	this->y = y;
};
