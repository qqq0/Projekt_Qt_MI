#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>
#include "sprite.h"

/**
* \brief class palyer
*
* The class is responsible for operations related to player, it is a child class of sprite
* It conatains metods related to controlling player keybord inputs
*
*/

class player : public sprite {
public:
	static const QColor defaultColor;
	/**
	* @brief checks if palyer is in exit position
	*
	* @return true if player is in exit coordinates
	*/
	bool exitLvl();
	/**
	* @brief moves player based on keys pressed
	*/
	void movePlayer();
	/**
	* @brief creates palyer as child of sprite
	*
	* @param x and y position of player
	*/
	player(int x, int y);
	/**
	* @brief returns current x and y position of player
	*
	* @param pointer to store x and y position of player
	*/
	void getPlayerPos(int* getX, int* getY);
private:
	QSet<int> keysPressed;
	void keyPressEvent(QKeyEvent* event);
	void keyReleaseEvent(QKeyEvent* event);


private slots:

};
#endif
