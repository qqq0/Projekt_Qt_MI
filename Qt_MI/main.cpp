#include <QtWidgets/QApplication>
#include <QgraphicsScene>
#include <QDebug>
#include <QTimer>
#include <QMessageBox>
#include <qpushbutton.h>
#include <vector>
#include "player.h"
#include <QgraphicsView>
#include "levels.h"
#include "enemy.h"
#include "gameState.h"


int main(int argc, char* argv[])
{
    srand(time(nullptr)); // time(nullptr)

    int NumberOfEnemies = 2;
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

//create enemy
    std::vector<enemy*> enemies{ };
    std::vector<int> enemyStartX{ };
    std::vector<int> enemyStartY{  };

//button signals
    QObject::connect(StartBt, &QPushButton::clicked, [&]() {
        QMessageBox::information(nullptr, "Message Box", "use arrow keys to move\npress 'OK' to continue");
        menuView->close();
        view->show();
        for (auto& e : enemies) {
            scene->removeItem(e);
        }
        enemies.clear();
        enemyStartX.clear();
        enemyStartY.clear();
        for (int i = 0; i < NumberOfEnemies; i++) {
            enemyStartX.push_back(50);
            enemyStartY.push_back(230 + i * 30);
            enemies.push_back(new enemy(enemyStartX[i], enemyStartY[i]));
        }
            
        for (auto& e : enemies) {
            e->setSpeed(DifficultyLVL + 1); // higher number - less enemy steps skipped
            scene->addItem(e);
        }
        
        
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


        //create a player
        const int startX = view->width() - 45;
        const int startY = view->height() / 2 - sprite::SIZE;

        player* rect = new player(startX, startY);
        //make player focusble
        rect->setFlag(QGraphicsItem::ItemIsFocusable);
        rect->setFocus();

        //add player to scene
        scene->addItem(rect);

        //create and add game state indicators to scene
        gameState gameState(scene);
        gameState.render(scene);

        // add walls
        levels levels;
        gameState.nextLvl();
        levels.addWalls(scene,gameState.getLvl());

        //enemy kill range
        const int killDis = 22;
        const  int chaseDis = 150;
        bool chasing = false;

       

        int tmpX, tmpY, minDistance; // minDistance - minimal distance between player and cloasest enemy


        QTimer* gameTick = new QTimer();
        QObject::connect(gameTick, &QTimer::timeout, [&]() {
            //move player:
            // check keyboard
            rect->movePlayer();

            //next lvl condition:
            if (rect->exitLvl()) {
                gameState.changeScoreBy(100);
                rect->setSpritePos(startX, startY);
                for (size_t i = 0; i < enemies.size(); i++) {
                    enemies[i]->setSpritePos(enemyStartX[i], enemyStartY[i]);
                    enemies[i]->clearPath();
                }
                gameState.nextLvl();
                levels.addWalls(scene, gameState.getLvl());
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
                e->moveEnemy(chasing, tmpX, tmpY); // chaising player
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

                QMessageBox::information(nullptr, "Message Box", "YOU DIED\n press 'OK' to open menu");
                gameState.resetGame();
                levels.addWalls(scene, gameState.getLvl());
                view->close();
                menuView->show();

            }

            if (gameState.gameWin()) {
                
                QMessageBox::information(nullptr, "Message Box", QString("YOU WON\npress 'OK' to open menu\nScore: %1").arg(gameState.getScore()));
                gameState.resetGame();
                levels.addWalls(scene, gameState.getLvl());
                view->close();
                menuView->show();

            }

            //render:
            rect->render();
            for (auto& e : enemies) {
                e->render();
            }

            gameState.render(scene);

            qDebug() << chasing;

            });
        gameTick->start(10);

 
    return a.exec();
}
