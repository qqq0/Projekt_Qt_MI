#pragma once
#ifndef LEVELS_H
#define LEVELS_H

#include <QGraphicsRectItem>
#include <QGraphicsItemGroup>

class levels : public QGraphicsRectItem {

public:
	levels();
	void addWalls(QGraphicsScene* scene);
	void nextLvl();
private:
	QGraphicsItemGroup* wallGroup = nullptr;
	int lvl = 0;
};
#endif
