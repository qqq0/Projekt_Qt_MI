#pragma once
#include <QgraphicsScene>
#include <QgraphicsTextItem>
#include <qbrush.h>
#include <QFont>

/**
* \brief class gameState
* 
* The class is responsible for operations related to game state variables like score, life and lvl.
* It contains metods for modifing and displaing the stored data.
* 
*/

class gameState : public QGraphicsTextItem
{
public:

	/**
	* @brief creates text labels for displaing data
	* 
	* @param scene to draw on
	*/
	gameState(QGraphicsScene* scene);	
	/**
	* @brief displays life and score 
	*
	* @param scene to draw on
	*/
	void render(QGraphicsScene* scene);
	/**
	* @brief modifies score variable
	*
	* @param ammount to add to the score
	*/
	void changeScoreBy(int change);
	/**
	* @brief lower player life by 1
	*/
	void kill();
	/**
	* @brief checks if the mage should continue (player is alive)
	*
	* @return true if player life >0
	*/
	bool continueGame();
	/**
	* @brief resets all game variables to their default values
	*/
	void resetGame();
	/**
	* @brief increases leve by 1 to go to the nex level
	*/
	void nextLvl();
	/**
	* @brief gets current level
	*
	* @return returns lvl variable
	*/
	int getLvl();
	/**
	* @brief checks if player won the game [player is on the lastLvl]
	*
	* @return returns true if lvl is equal to the last Lvl
	*/
	bool gameWin();
	/**
	* @brief gets current score
	*
	* @return returns score variable
	*/
	int getScore();

private:
	const QFont font;
	const int startLife = 3;
	const int startScore = 100;
	int life = startLife;
	int score = startScore;
	int lvl = 0;
	const int lastLvl = 6;
	QGraphicsTextItem* scoreText = nullptr;
	QGraphicsTextItem* lifeText = nullptr;
	
};
