#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Game.h"

int main(int argc, char *argv[])
{
    Game* mGame = Game::getInstance();
    mGame->Init(argc, argv);
    return mGame->Start();
}
