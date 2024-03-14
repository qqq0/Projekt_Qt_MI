#include <QtWidgets/QApplication>
#include <QgraphicsScene>
#include "player.h"
#include <QgraphicsView>
#include "levels.h"
#include <QDebug>
#include <QTimer>


int main(int argc, char* argv[])
{

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
    int startY = view->height() / 2 - entity::SIZE;
    player* rect = new player(startX, startY);
    //make player focusble
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    //add player to scene
    scene->addItem(rect);

    //create a player
    view->show();

        QTimer* gameTick = new QTimer();
        QObject::connect(gameTick, &QTimer::timeout, [&]() {
            // check keyboard
            rect->movePlayer();
            rect->render();
            if (rect->exitLvl()) {
                rect->setEntityPos(startX, startY);
                levels.nextLvl();
                levels.addWalls(scene);
            }
            qDebug() << rect->exitLvl();
            });
        gameTick->start(2);


    return a.exec();
}
