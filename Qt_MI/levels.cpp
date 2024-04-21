#include "levels.h"
#include <QBrush>
#include <QPen>
#include <QtWidgets>


levels::levels() {

}

void levels::addWalls(QGraphicsScene* scene,int lvl)
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
        // Boundary walls
        wallGroup->addToGroup(scene->addRect(0, 0, 800, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(0, 0, 20, 600, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(0, 580, 800, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(780, 0, 20, 600, QPen(Qt::NoPen), QBrush(Qt::darkGray)));

        // Level-specific obstacles
        wallGroup->addToGroup(scene->addRect(200, 200, 400, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(200, 400, 400, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));

        //debuging pathfinding
        /*
        wallGroup->addToGroup(scene->addRect(720, 302, 150, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(720, 250, 20, 100, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(720, 259, 150, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        */

        // EXIT
        wallGroup->addToGroup(scene->addRect(0, 280, 20, 20, QPen(Qt::NoPen), QBrush(Qt::green)));
        break;

    case 2:
        // Boundary walls
        wallGroup->addToGroup(scene->addRect(0, 0, 800, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(0, 0, 20, 600, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(0, 580, 800, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(780, 0, 20, 600, QPen(Qt::NoPen), QBrush(Qt::darkGray)));

        // Level-specific obstacles
        wallGroup->addToGroup(scene->addRect(70, 100, 300, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(70, 480, 300, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(100, 120, 20, 100, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(680, 380, 20, 100, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(250, 220, 300, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(250, 360, 300, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));


        // EXIT
        wallGroup->addToGroup(scene->addRect(0, 280, 20, 20, QPen(Qt::NoPen), QBrush(Qt::green)));
        break;
    case 3:
        // Boundary walls
        wallGroup->addToGroup(scene->addRect(0, 0, 800, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(0, 0, 20, 600, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(0, 580, 800, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(780, 0, 20, 600, QPen(Qt::NoPen), QBrush(Qt::darkGray)));

        // Level-specific obstacles
        wallGroup->addToGroup(scene->addRect(100, 530, 200, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(100, 250, 200, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(500, 250, 200, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(100, 70, 20, 180, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(680, 350, 20, 180, QPen(Qt::NoPen), QBrush(Qt::darkGray)));

        // EXIT
        wallGroup->addToGroup(scene->addRect(0, 280, 20, 20, QPen(Qt::NoPen), QBrush(Qt::green)));
        break;
    case 4:
        // Boundary walls
        wallGroup->addToGroup(scene->addRect(0, 0, 800, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(0, 0, 20, 600, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(0, 580, 800, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(780, 0, 20, 600, QPen(Qt::NoPen), QBrush(Qt::darkGray)));

        // Level-specific obstacles
        wallGroup->addToGroup(scene->addRect(200, 430, 400, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(200, 150, 400, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(220, 170, 20, 200, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(560, 230, 20, 200, QPen(Qt::NoPen), QBrush(Qt::darkGray)));

        // EXIT
        wallGroup->addToGroup(scene->addRect(0, 280, 20, 20, QPen(Qt::NoPen), QBrush(Qt::green)));
        break;
    case 5:
        // Boundary walls
        wallGroup->addToGroup(scene->addRect(0, 0, 800, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(0, 0, 20, 600, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(0, 580, 800, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(780, 0, 20, 600, QPen(Qt::NoPen), QBrush(Qt::darkGray)));

        // Level-specific obstacles
        wallGroup->addToGroup(scene->addRect(100, 100, 600, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(100, 480, 600, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(380, 120, 20, 100, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(380, 380, 20, 100, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(200, 220, 400, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(200, 360, 400, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));

        // EXIT
        wallGroup->addToGroup(scene->addRect(0, 280, 20, 20, QPen(Qt::NoPen), QBrush(Qt::green)));
        break;

    default:
        // Boundary walls
        wallGroup->addToGroup(scene->addRect(0, 0, 800, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(0, 0, 20, 600, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(0, 580, 800, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        wallGroup->addToGroup(scene->addRect(780, 0, 20, 600, QPen(Qt::NoPen), QBrush(Qt::darkGray)));
        // Letter T
        wallGroup->addToGroup(scene->addRect(260, 200, 100, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray))); // Top
        wallGroup->addToGroup(scene->addRect(300, 200, 20, 100, QPen(Qt::NoPen), QBrush(Qt::darkGray))); // Middle

        // Letter H
        wallGroup->addToGroup(scene->addRect(370, 200, 20, 100, QPen(Qt::NoPen), QBrush(Qt::darkGray))); // Left vertical
        wallGroup->addToGroup(scene->addRect(390, 240, 60, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));  // Middle horizontal
        wallGroup->addToGroup(scene->addRect(450, 200, 20, 100, QPen(Qt::NoPen), QBrush(Qt::darkGray))); // Right vertical

        // Letter E
        wallGroup->addToGroup(scene->addRect(480, 200, 100, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray))); // Top
        wallGroup->addToGroup(scene->addRect(480, 240, 80, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));  // Middle
        wallGroup->addToGroup(scene->addRect(480, 280, 100, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray))); // Bottom
        wallGroup->addToGroup(scene->addRect(480, 200, 20, 100, QPen(Qt::NoPen), QBrush(Qt::darkGray))); // Left vertical


        // Letter E for "END"
        wallGroup->addToGroup(scene->addRect(270, 350, 80, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray))); // Top
        wallGroup->addToGroup(scene->addRect(270, 390, 60, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));  // Middle
        wallGroup->addToGroup(scene->addRect(270, 430, 80, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray))); // Bottom
        wallGroup->addToGroup(scene->addRect(270, 350, 20, 100, QPen(Qt::NoPen), QBrush(Qt::darkGray))); // Left vertical

        // Letter N
        wallGroup->addToGroup(scene->addRect(360, 350, 20, 100, QPen(Qt::NoPen), QBrush(Qt::darkGray))); // Left vertical
        wallGroup->addToGroup(scene->addRect(380, 350, 60, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));  // Top slant
        wallGroup->addToGroup(scene->addRect(440, 350, 20, 100, QPen(Qt::NoPen), QBrush(Qt::darkGray))); // Right vertical

        // Letter D
        wallGroup->addToGroup(scene->addRect(470, 350, 20, 100, QPen(Qt::NoPen), QBrush(Qt::darkGray))); // Left vertical
        wallGroup->addToGroup(scene->addRect(470, 350, 60, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));  // Top horizontal
        wallGroup->addToGroup(scene->addRect(470, 430, 60, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray)));  // Bottom horizontal
        wallGroup->addToGroup(scene->addRect(530, 370, 20, 60, QPen(Qt::NoPen), QBrush(Qt::darkGray)));  // Right vertical
        break;
    }
    scene->addItem(wallGroup);
}

levels::~levels() {
    if (wallGroup != nullptr) {
        delete wallGroup;
        wallGroup = nullptr;
    }
}

