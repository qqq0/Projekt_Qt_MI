#pragma once
#include "sprite.h"
class enemy : public sprite
{
public:
	static const QColor defaultColor;
	enemy(int x, int y);
	void moveEnemy();
private:
	
};

