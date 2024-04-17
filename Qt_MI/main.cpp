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
#include <qpushbutton.h>

#include <vector>

int main(int argc, char* argv[])
{
    srand(time(nullptr)); // time(nullptr)

    int NumberOfEnemies = 1;
    int DifficultyLVL = 0;
    const QString DifficultyNames[] = { "EASY","NORMAL","HARD" };

    QApplication a(argc, argv);

    //creating a scene
    QGraphicsScene* menu = new QGraphicsScene();
    //add a view
    QGraphicsView* menuView = new QGraphicsView(menu);
    menuView->setFixedSize(800, 600);

    //Adding buttons to menu
    QPushButton* StartBt = new QPushButton;
    StartBt->setText("START");
    StartBt->setGeometry(QRect(100, 100, 150, 40));
    menu->addWidget(StartBt);

    QPushButton* DifficultyBt = new QPushButton;
    DifficultyBt->setText("DIFFICULTY: " + DifficultyNames[DifficultyLVL]);
    DifficultyBt->setGeometry(QRect(100, 150, 150, 40));
    menu->addWidget(DifficultyBt);

    QPushButton* EnemyBt = new QPushButton;
    EnemyBt->setText(QString("ENEMIES: %1").arg(NumberOfEnemies));
    EnemyBt->setGeometry(QRect(100, 200, 150, 40));
    menu->addWidget(EnemyBt);

    QPushButton* QuitBt = new QPushButton;
    QuitBt->setText("QUIT");
    QuitBt->setGeometry(QRect(100, 250, 150, 40));
    menu->addWidget(QuitBt);

    menuView->show();

    //creating a scene
    QGraphicsScene* scene = new QGraphicsScene();
    //add a view
    QGraphicsView* view = new QGraphicsView(scene);

    view->setFixedSize(800, 600);
    scene->setSceneRect(0, 0, 800, 600);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



    QObject::connect(StartBt, &QPushButton::clicked, [&]() {
        menuView->close();
        view->show();
        });
    QObject::connect(DifficultyBt, &QPushButton::clicked, [&]() {
        DifficultyLVL == 2 ? DifficultyLVL = 0 : DifficultyLVL++;
        DifficultyBt->setText("DIFFICULTY: " + DifficultyNames[DifficultyLVL]);
        });
    QObject::connect(EnemyBt, &QPushButton::clicked, [&]() {
        NumberOfEnemies == 3 ? NumberOfEnemies = 1 : NumberOfEnemies++;
        EnemyBt->setText(QString("ENEMIES: %1").arg(NumberOfEnemies));
        });
    QObject::connect(QuitBt, &QPushButton::clicked, [&]() {
        QCoreApplication::quit();
        });



    // add walls
    levels levels;
    levels.nextLvl();
    levels.addWalls(scene);  
    //creating game view
    

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
    

    //create and add game state indicators to scene
    gameState gameState(scene);
    gameState.render(scene);

    //create enemy
    std::vector<enemy*> enemies{ new enemy(100, 100) , new enemy(150, 100)};
    std::vector<int> enemyStartX{ 50 , 70};
    std::vector<int> enemyStartY{ 260 , 300};
 
    //enemy kill range
    const int killDis = 22;
    const  int chaseDis = 150;
    bool chasing = false;

    for (auto& e : enemies) {
        scene->addItem(e);
    }

    int tmpX, tmpY, minDistance; // minDistance - minimal distance between player and cloasest enemy

    //QMessageBox::information(nullptr, "Message Box", "use W S A D to move\npress 'OK' to continue");

        QTimer* gameTick = new QTimer();
        QObject::connect(gameTick, &QTimer::timeout, [&]() {
            //move player:
            // check keyboard
            rect->movePlayer();

            //next lvl condition:
            if (rect->exitLvl()) {
                gameState.changeScoreBy(100);
                rect->setSpritePos(startX, startY);
                for (size_t i = 0; i < enemies.size();i++) {
                    enemies[i]->setSpritePos(enemyStartX[i], enemyStartY[i]);
                    enemies[i]->clearPath();
                }
                levels.nextLvl();
                levels.addWalls(scene);
            }

            //calculate distance from player to cloasest enemy
            rect->getPlayerPos(&tmpX, &tmpY);
            minDistance = view->width() + view->height(); // width + height always > diagonal [maximum distance]

            for (auto& e : enemies) {
                int dist = e->distanceTo(tmpX, tmpY);

                if (minDistance > dist) {
                    minDistance = dist;
                }
            }

            //check if enemy should chase player
            if (minDistance <= chaseDis)
                chasing = true;
            else {
                chasing = false;
            }
                for (auto& e : enemies) {
                    e->moveEnemy(chasing,tmpX,tmpY); // chaising player
                }


            //reset lvl condition:
            if (minDistance <= killDis) {
                rect->setSpritePos(startX, startY);
                gameState.kill();

                for (size_t i = 0; i < enemies.size(); i++) {
                    enemies[i]->setSpritePos(enemyStartX[i], enemyStartY[i]);
                    enemies[i]->clearPath();
                }
            }

            //chceck if player is alive
            if (!gameState.continueGame()) {
                QMessageBox::information(nullptr, "Message Box", "YOU DIED\n press 'OK' to close");
                QCoreApplication::quit();
            }

            //render:
            rect->render();
            for (auto& e : enemies) {
                e->render();
            }

            gameState.render(scene);
            
            //qDebug() << rect->getEndLvl();
            //qDebug() << tmpX << " " << tmpY;
            qDebug() << chasing;
            

            });
        gameTick->start(10);


    return a.exec();
}
