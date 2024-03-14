#pragma once
#include <QgraphicsScene>
#include <QGraphicsRectItem>

class entity : public QObject, public QGraphicsRectItem
{
public:
	static const int SIZE = 20;

	entity(int x, int y);
	void render();
	void move(int x,int y);
	void setEntityPos(int x, int y);

protected:
	bool collisionDetection();
	int x, y;
	int prevX, prevY;
};

