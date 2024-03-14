#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>
#include <QTimer>
#include "entity.h"

class player : public entity {
	Q_OBJECT	//Add Q_object to be able to handle slots (for timer)
public:
	void keyPressEvent(QKeyEvent* event);
	void keyReleaseEvent(QKeyEvent* event);
	bool exitLvl();
	void movePlayer();
	player(int x, int y);

private:
	const int playerMoveDelay = 10;	//delay between moves in ms
	//QTimer* timer;
	QSet<int> keysPressed;
	//void movePlayer();
	//void collisionDetection(int X, int Y);


private slots:

};
#endif
