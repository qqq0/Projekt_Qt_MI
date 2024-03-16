#pragma once
#include <QgraphicsScene>
#include <QGraphicsRectItem>

class sprite : public QObject, public QGraphicsRectItem
{
public:
	static const int SIZE = 20;

	sprite(int x, int y,QBrush col);
	void render();
	void move(int x,int y);
	void setSpritePos(int x, int y);

protected:
	bool collisionDetection();
	int x, y;
	int prevX, prevY;
};

