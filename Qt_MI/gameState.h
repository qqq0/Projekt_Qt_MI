#pragma once
#include <QgraphicsScene>
#include <QgraphicsTextItem>
#include <qbrush.h>
#include <QFont>


class gameState : public QGraphicsTextItem
{
public:
	gameState(QGraphicsScene* scene);
	void render(QGraphicsScene* scene);
	void changeScoreBy(int change);
	void kill();
	bool continueGame();

private:
	const QFont font;
	int life = 3;
	int score = 100;
	QGraphicsTextItem* scoreText = nullptr;
	QGraphicsTextItem* lifeText = nullptr;
	
};
