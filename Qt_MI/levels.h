#pragma once
#ifndef LEVELS_H
#define LEVELS_H

#include <QGraphicsRectItem>
#include <QGraphicsItemGroup>

/**
* \brief class levels
*
* The class is responsible for creating and adding walls to scene
*
*/

class levels : public QGraphicsRectItem {

public:
	/**
	* @brief creates levels object
	*/
	levels();
	/**
	* @brief deletes levels object
	*/
	~levels();
	/**
	* @brief adds level walls to scene
	* 
	* @param secene to add walls to 
	* @param lvl what set of walls to add
	*/
	void addWalls(QGraphicsScene* scene,int lvl);

private:
	QGraphicsItemGroup* wallGroup = nullptr;
};
#endif
