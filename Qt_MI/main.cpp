#include <QtWidgets/QApplication>
#include <QgraphicsScene>
#include "player.h"
#include <QgraphicsView>
#include "levels.h"
#include <QDebug>
#include <QTimer>
#include "enemy.h"
#include "gameState.h"
#include <QMessageBox>

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
    const int startX = view->width() - 45;
    const int startY = view->height() / 2 - sprite::SIZE;
    player* rect = new player(startX, startY);
    //make player focusble
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    //add player to scene
    scene->addItem(rect);

    //create a player
    view->show();

    //create and add game state indicators to scene
    gameState gameState(scene);
    gameState.render(scene);

    //create enemy
    std::vector<enemy*> enemies{ new enemy(100, 100), new enemy(150, 100), new enemy(100, 200) };
    std::vector<int> enemyStartX{ 50,70,50 };
    std::vector<int> enemyStartY{ 260,300,340 };
 
    //enemy kill range
    const int killDis = 22;

    for (auto& e : enemies) {
        scene->addItem(e);
    }

    int tmpX, tmpY, minDistance; // minDistance - minimal distance between player and cloasest enemy

    QMessageBox::information(nullptr, "Message Box", "use arrows to move\npress 'OK' to continue");

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

            gameState.render(scene);


            //next lvl condition:
            if (rect->exitLvl()) {
                gameState.changeScoreBy(100);
                rect->setSpritePos(startX, startY);
                for (size_t i = 0; i < enemies.size();i++) {
                    enemies[i]->setSpritePos(enemyStartX[i], enemyStartY[i]);
                }
                levels.nextLvl();
                levels.addWalls(scene);
            }

            //check if player is to close to enemy:
            rect->getPlayerPos(&tmpX, &tmpY);
            minDistance = view->width() + view->height(); // width + height always > diagonal [maximum distance]

            for (auto& e : enemies) {
                int dist = e->distanceTo(tmpX, tmpY);

                if (minDistance > dist) {
                    minDistance = dist;
                }
            }


            //reset lvl condition:
            if (minDistance <= killDis) {
                rect->setSpritePos(startX, startY);
                gameState.kill();

                for (size_t i = 0; i < enemies.size(); i++) {
                    enemies[i]->setSpritePos(enemyStartX[i], enemyStartY[i]);
                }
            }

            //chceck if player is alive
            if (!gameState.continueGame()) {
                QMessageBox::information(nullptr, "Message Box", "YOU DIED\n press 'OK' to close");
                QCoreApplication::quit();
            }
            
            //qDebug() << rect->getEndLvl();
            //qDebug() << tmpX << " " << tmpY;
            //qDebug() << minDistance;

            });
        gameTick->start(5);


    return a.exec();
}
