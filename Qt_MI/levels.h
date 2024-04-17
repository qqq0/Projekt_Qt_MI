#pragma once
#ifndef LEVELS_H
#define LEVELS_H

#include <QGraphicsRectItem>
#include <QGraphicsItemGroup>

class levels : public QGraphicsRectItem {

public:
	levels();
	~levels();
	void addWalls(QGraphicsScene* scene,int lvl);

private:
	QGraphicsItemGroup* wallGroup = nullptr;
	//int lvl = 0;
};
#endif
