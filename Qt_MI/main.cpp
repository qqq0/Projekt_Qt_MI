#include <QtWidgets/QApplication>
#include <QgraphicsScene>
#include "player.h"
#include <QgraphicsView>
#include "levels.h"
#include <QDebug>
#include <QTimer>
#include "enemy.h"

#include <vector>

int main(int argc, char* argv[])
{
    srand(11); // time(nullptr)

    QApplication a(argc, argv);

    //creating a scene
    QGraphicsScene* scene = new QGraphicsScene();



    // add walls
    levels levels;
    levels.nextLvl();
    levels.addWalls(scene);  
    
   
    //qDebug() << X;

    //add a view
    QGraphicsView* view = new QGraphicsView(scene);

    //view->setScene(scene);
    view->setFixedSize(800, 600);
    scene->setSceneRect(0, 0, 800, 600);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    
    //create a player
    int startX = view->width() - 45;
    int startY = view->height() / 2 - sprite::SIZE;
    player* rect = new player(startX, startY);
    //make player focusble
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    //add player to scene
    scene->addItem(rect);

    //create a player
    view->show();

    //create enemi
    std::vector<enemy*> enemies{ new enemy(100, 100), new enemy(150, 100), new enemy(100, 200) };

    for (auto& e : enemies) {
        scene->addItem(e);
    }

        QTimer* gameTick = new QTimer();
        QObject::connect(gameTick, &QTimer::timeout, [&]() {
            //move:
            // check keyboard
            rect->movePlayer();
            for (auto& e : enemies) {
                e->moveEnemy();
            }

            //render:
            rect->render();
            for (auto& e : enemies) {
                e->render();
            }

            //end lvl condition:
            if (rect->exitLvl()) {
                rect->setSpritePos(startX, startY);
                levels.nextLvl();
                levels.addWalls(scene);
            }
            //qDebug() << rect->exitLvl();
            });
        gameTick->start(10);


    return a.exec();
}
