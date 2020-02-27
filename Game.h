#pragma once
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Board.h"
class Game
{
public:
	static Game* getInstance();
	void Init(int argc, char* argv[]);
	int Start();
protected:
	static Game* mInstance;
	Board* mGameBoard = nullptr;

	QGuiApplication* _qApp;
	QQmlApplicationEngine* _qEngine;
};

