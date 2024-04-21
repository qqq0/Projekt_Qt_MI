#pragma once
#include "sprite.h"
#include <vector>
#include<queue>

/**
* \brief class enemy
*
* The class is responsible for operations related to enemies, it is a child class of sprite
* It contains metods related to enemy logic like pathfinding and choosing target positions while patroling the tarain and chasing the player.
* 
* 
*/

class enemy : public sprite
{
public:
	static const QColor defaultColor;
	/**
	* @brief creates enemy as child of sprite
	*
	* @param x and y position of enemy
	*/
	enemy(int x, int y);
	/**
	* @brief controlls following (with set speed) and creating paths  
	*
	* @param chase - true if enemy should chase player
	* @param player X and Y position of a player for pathfinding during while chasing
	*/
	void moveEnemy(bool chase, int playerX, int playerY);
	/**
	* @brief calculates manhattan distance from player to point
	*
	* @param x and y position of a point that we want to calculate distance to
	* 
	* @return calculated distance
	*/
	int distanceTo(int ToX, int ToY);
	/**
	* @brief chooses a point on a map to go to ensureing that it is within maxTargetDistance
	*
	* @param width - width of a map
	* @param height - height of a map
	*/
	void chooseTarget(int width,int height);
	/**
	* @brief deleates all contents if pathX and pathY
	*/
	void clearPath();
	/**
	* @brief sets enemy movement speed
	*
	* @param value of speed (how often to skip moves relative to player)
	*/
	void setSpeed(int s);
private:
	void path();
	bool possitionValid(int x, int y);
	int distanceTo(int ToX, int ToY, int FromX, int FromY);
	
	const int maxTargetDistanece = 200; //set maximum distance (lower number improwes speed of searching for paths)
	
	struct node {
		int X;
		int Y;
		int F;
		int G;
		int H;
		node* parent;	// parrent node

		struct node(int nX, int nY, int nF, int nG, int nH, node* nparent)
			: X(nX), Y(nY), F(nF), G(nG), H(nH), parent(nparent) {}

		bool operator<(const node& other) const {	//overload operator for sorting in priority_queue
			return F > other.F;
		}

	};

	void updateClosedSetImage(const std::vector<std::vector<bool>>& closedSet, QImage& image);
	void updateOpenSetImage(const std::vector<node>& openSet, QImage& image);

	const int refreashRate = 10;	//how many steps between path updates while chasing
	int refreashCnt = 0;
	int targetX;
	int targetY;
	int i = 0;
	int j = 0;
	int prevI = 0;
	int speedI = 0;
	int speed = 1;	//skiping move every speed number steps 

	const int pathStep = 10; //ammount of pixels per move

	std::vector<int> pathX;
	std::vector<int> pathY;
	
	std::vector<int> prevPathX;
	std::vector<int> prevPathY;

};

