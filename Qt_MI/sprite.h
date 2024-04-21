#pragma once
#include <QgraphicsScene>
#include <QGraphicsRectItem>

/**
* \brief class sprite
*
* The class is responsible for operations related to movable entieties it is a parent class of player and enemy.
* It contains metods related to movment and rendering of the objects.
*
*/

class sprite : public QObject, public QGraphicsRectItem
{
public:
	static const int SIZE = 20;
	/**
	* @brief creates text labels for displaing data
	*
	* @param x and y possition of sprite
	* @param sprite color
	*/
	sprite(int x, int y,QBrush col);
	/**
	* @brief changes the position of sprite to x and y and reverses it if new position is in the wall
	*/
	void render();
	/**
	* @brief changes x and y position of sprite
	* 
	* @param x and y position to move to
	*/
	void move(int x,int y);
	/**
	* @brief changes the position of sprite to x,y and previous position prevX and prevY to x,y
	* 
	* @position x and y cordinates of position to set sprite to
	*/
	void setSpritePos(int x, int y);

protected:
	/**
	* @brief checks if sprite is coliding with the walls
	* 
	* @return returns true if sprite rect is overlaping with level walls
	*/
	bool collisionDetection();
	int x, y;
	int prevX, prevY;
};

