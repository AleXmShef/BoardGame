#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <iostream>
#include "Game.h"

int main(int argc, char *argv[])
{
    Game* mGame = Game::getInstance();
    mGame->Init(argc, argv);
    mGame->_debug_demo();
    //mGame->Start();
}
