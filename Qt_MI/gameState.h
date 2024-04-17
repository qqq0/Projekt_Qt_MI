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
	void resetGame();
	void nextLvl();
	int getLvl();

private:
	const QFont font;
	const int startLife = 3;
	const int startScore = 100;
	int life = startLife;
	int score = startScore;
	int lvl = 0;
	QGraphicsTextItem* scoreText = nullptr;
	QGraphicsTextItem* lifeText = nullptr;
	
};
