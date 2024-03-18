#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>
#include <QTimer>
#include "sprite.h"

class player : public sprite {
	Q_OBJECT	//Add Q_object to be able to handle slots (for timer)
public:
	
	bool exitLvl();
	void movePlayer();
	player(int x, int y);
	static const QColor defaultColor;
	void getPlayerPos(int* getX, int* getY);
private:
	//QTimer* timer;
	QSet<int> keysPressed;
	//void movePlayer();
	//void collisionDetection(int X, int Y);
	void keyPressEvent(QKeyEvent* event);
	void keyReleaseEvent(QKeyEvent* event);


private slots:

};
#endif
