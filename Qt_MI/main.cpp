#include <QtWidgets/QApplication>
#include <QgraphicsScene>
#include "player.h"
#include <QgraphicsView>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    //creating a scene
    QGraphicsScene* scene = new QGraphicsScene();
   // scene->setBackgroundBrush(QBrush(QPixmap("lvl_bg.png")));
    //create a player
    player* rect = new player();


    //add payer to scene
    scene->addItem(rect);

    // add walls
    scene->addRect(0, 0, 800, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray));
    scene->addRect(0, 0, 20, 600, QPen(Qt::NoPen), QBrush(Qt::darkGray));
    scene->addRect(0, 580, 800, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray));
    scene->addRect(780, 0, 20, 600, QPen(Qt::NoPen), QBrush(Qt::darkGray));
    scene->addRect(200, 200, 400, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray));
    scene->addRect(200, 400, 400, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray));



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

    rect->setPos(view->width() / 2, view->height() / 2 - rect->rect().height());



    return a.exec();
}
