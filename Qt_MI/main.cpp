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

    //create a player
    player* rect = new player();


    //add player to scene
    scene->addItem(rect);

    // add walls
    levels levels;
    levels.nextLvl();
    levels.addWalls(scene);  
    
   
    //qDebug() << X;

    //make player focusble
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    //add a view
    QGraphicsView* view = new QGraphicsView(scene);

    //view->setScene(scene);
    view->setFixedSize(800, 600);
    scene->setSceneRect(0, 0, 800, 600);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    
    //create a player
    view->show();

    rect->setPos(view->width() - 45, view->height() / 2 - rect->rect().height());

        QTimer* gameTick = new QTimer();
        QObject::connect(gameTick, &QTimer::timeout, [&]() {
            rect->movePlayer();
            if (rect->exitLvl()) {
                rect->setPos(view->width() - 45, view->height() / 2 - rect->rect().height());
                levels.nextLvl();
                levels.addWalls(scene);
            }
            qDebug() << rect->exitLvl();
            });
        gameTick->start(10);


    return a.exec();
}
