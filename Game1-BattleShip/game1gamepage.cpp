#include "game1gamepage.h"

Game1GamePage::Game1GamePage()
{
    player1Grid = new QGraphicsPixmapItem();
    player2Grid = new QGraphicsPixmapItem();
    playerCommandPanel = new commandPanel();
    GCPLabel = new QLabel("Good Coding Practices");
    BCPLabel = new QLabel("Bad Coding Practices");

    player1Boat1 = new QGraphicsPixmapItem();
    player1Boat2 = new QGraphicsPixmapItem();
    player1Boat3 = new QGraphicsPixmapItem();

    player2Boat1 = new QGraphicsPixmapItem();
    player2Boat2 = new QGraphicsPixmapItem();
    player2Boat3 = new QGraphicsPixmapItem();

    button00 = new QPushButton();
    button01 = new QPushButton();
    button02 = new QPushButton();
    button03 = new QPushButton();
    button10 = new QPushButton();
    button11 = new QPushButton();
    button12 = new QPushButton();
    button13 = new QPushButton();
    button20 = new QPushButton();
    button21 = new QPushButton();
    button22 = new QPushButton();
    button23 = new QPushButton();
    button30 = new QPushButton();
    button31 = new QPushButton();
    button32 = new QPushButton();
    button33 = new QPushButton();

    setupScene();
    setupWidgets();
    setupBoats();
    setupGrids();
    setupButtons();
    fillScene();
}

void Game1GamePage::setupScene(){
    this->setSceneRect(0,0,1000,1000);
    this->setBackgroundBrush(QBrush(QImage(":/images/pannel-bg.jpg")));

}

void Game1GamePage::setupWidgets(){
    GCPLabel->setGeometry(60,200,500,80);
    GCPLabel->setAttribute(Qt::WA_NoSystemBackground);
    GCPLabel->setStyleSheet("QLabel { font-size: 32px; font-weight: bold; color: white}");

    BCPLabel->setGeometry(550,200,500,80);
    BCPLabel->setAttribute(Qt::WA_NoSystemBackground);
    BCPLabel->setStyleSheet("QLabel { font-size: 32px; font-weight: bold; color: white}");
}

void Game1GamePage::setupBoats()
{
    player1Boat1->setPixmap((QPixmap(":/images/big-boat.png")).scaled(200,50));
    player1Boat1->setPos(QPointF(115,270));
}

void Game1GamePage::setupGrids()
{
    player1Grid->setPixmap((QPixmap(":/images/grid.png")).scaled(300,300));
    player1Grid->setPos(QPointF(100,250));

    player2Grid->setPixmap((QPixmap(":/images/grid.png")).scaled(300,300));
    player2Grid->setPos(QPointF(600,250));

}

void Game1GamePage::setupButtons(){
    button00->setGeometry(618,268,62,62);
    button01->setGeometry(686,268,62,62);
    button02->setGeometry(753,268,62,62);
    button03->setGeometry(821,268,62,62);
    button10->setGeometry(618,336,62,62);
    button11->setGeometry(686,336,62,62);
    button12->setGeometry(753,336,62,62);
    button13->setGeometry(821,336,62,62);
    button20->setGeometry(618,403,62,62);
    button21->setGeometry(686,403,62,62);
    button22->setGeometry(753,403,62,62);
    button23->setGeometry(821,403,62,62);
    button30->setGeometry(618,471,62,62);
    button31->setGeometry(686,471,62,62);
    button32->setGeometry(753,471,62,62);
    button33->setGeometry(821,471,62,62);
}

void Game1GamePage::fillScene()
{
    this->addWidget(GCPLabel);
    this->addWidget(BCPLabel);

    this->addItem(player1Boat1);
    this->addItem(player1Boat2);
    this->addItem(player1Boat3);
    this->addItem(player2Boat1);
    this->addItem(player2Boat2);
    this->addItem(player2Boat3);

    this->addItem(player1Grid);
    this->addItem(player2Grid);

    this->addWidget(button00);
    this->addWidget(button01);
    this->addWidget(button02);
    this->addWidget(button03);
    this->addWidget(button10);
    this->addWidget(button11);
    this->addWidget(button12);
    this->addWidget(button13);
    this->addWidget(button20);
    this->addWidget(button21);
    this->addWidget(button22);
    this->addWidget(button23);
    this->addWidget(button30);
    this->addWidget(button31);
    this->addWidget(button32);
    this->addWidget(button33);
}
