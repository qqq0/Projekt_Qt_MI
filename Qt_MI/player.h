#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>

class player : public QGraphicsRectItem {
public:
	void keyPressEvent(QKeyEvent* event);

private:
	QTimer* timer;

private slots:
	void timerOutEvent();
};
#endif
