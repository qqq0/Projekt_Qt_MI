#include "gameState.h"

gameState::gameState(QGraphicsScene* scene) : font("arial", 12) {

	scoreText = new QGraphicsTextItem("Score:  " + QString::number(score));
	scoreText->setFont(font);
	scene->addItem(scoreText);

	lifeText = new QGraphicsTextItem("Score:  " + QString::number(life));
	lifeText->setFont(font);
	lifeText->setPos(735, 0);
	scene->addItem(lifeText);

}

void gameState::render(QGraphicsScene* scene) {
	
	scene->removeItem(scoreText);
	scene->removeItem(lifeText);
	scene->addItem(scoreText);
	scene->addItem(lifeText);

	if (scoreText) {
		scoreText->setPlainText("Score:  " + QString::number(score));
	}

	if (lifeText) {
		lifeText->setPlainText("<3:  " + QString::number(life));
	}


}

void gameState::changeScoreBy(int change) {
	score += change;
}

void gameState::kill() {
	life--;
	score -= 20;
}

bool gameState::continueGame() {
	if (life > 0) {
		return true;
	}
	else {
		return false;
	}
}

void gameState::resetGame() {
	life = startLife;
	score = startScore;
	lvl = 1;
}

void gameState::nextLvl() {
	lvl++;
}

int gameState::getLvl() {
	return lvl;
}