#include "levels.h"
#include <QBrush>
#include <QPen>
#include <QtWidgets>


levels::levels() {

}

void levels::addWalls(QGraphicsScene* scene)
{
    if (wallGroup != nullptr) {
        scene->removeItem(wallGroup);
        delete wallGroup;
        wallGroup = nullptr;
    };
    wallGroup = new QGraphicsItemGroup();
    
    
    switch (lvl)
    {
    case 0:
        wallGroup->addToGroup(scene->addRect(0, 0, 800, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(0, 0, 20, 600, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(0, 580, 800, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(780, 0, 20, 600, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        break;
    case 1:
        wallGroup->addToGroup(scene->addRect(0, 0, 800, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(0, 0, 20, 600, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(0, 580, 800, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(780, 0, 20, 600, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(200, 200, 400, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(200, 400, 400, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(0, 280, 20, 20, QPen(Qt::NoPen), QBrush(Qt::green)));
        break;
    default:
        wallGroup->addToGroup(scene->addRect(0, 0, 800, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(0, 0, 20, 600, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(0, 580, 800, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(780, 0, 20, 600, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        break;
    }
    scene->addItem(wallGroup);
}

void levels::nextLvl() {
    lvl++;
}