#include <QtWidgets/QApplication>
#include <QgraphicsScene>
#include "player.h"
#include <QgraphicsView>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    //creating a scene
    QGraphicsScene* scene = new QGraphicsScene();

    //create a player
    player* rect = new player();
    rect->setRect(0, 0, 20, 20);

    //add payer to scene
    scene->addItem(rect);



    //make player focusble
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    //add a view
    QGraphicsView* view = new QGraphicsView(scene);

    //view->setScene(scene);
    view->setFixedSize(820, 620);
    scene->setSceneRect(0, 0, 800, 600);

    view->show();

    rect->setPos(view->width() / 2, view->height() / 2 - rect->rect().height());


    return a.exec();
}
