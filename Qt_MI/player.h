#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>
#include <QTimer>

class player : public QObject, public QGraphicsRectItem {
	Q_OBJECT	//Add Q_object to be able to handle slots (for timer)
public:
	void keyPressEvent(QKeyEvent* event);
	void keyReleaseEvent(QKeyEvent* event);
	player();

private:
	const int playerMoveDelay = 10;	//delay between moves in ms
	QTimer* timer;
	QSet<int> keysPressed;
	void movePlayer();
	void collisionDetection(int X, int Y);

private slots:

};
#endif
