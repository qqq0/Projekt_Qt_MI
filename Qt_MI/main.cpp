#include <QtWidgets/QApplication>
#include <QgraphicsScene>
#include <QGraphicsRectItem>
#include <QgraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //creating a scene
    QGraphicsScene* scene = new QGraphicsScene();

    //create a player
    QGraphicsRectItem* rect = new QGraphicsRectItem();
    rect->setRect(0, 0,100,100);

    //add payer to scene
    scene->addItem(rect);

    //add a view
    QGraphicsView* view = new QGraphicsView(scene);
    //view->setScene(scene);
    view->show();



    return a.exec();
}
