#include "Game.h"
#include <iostream>
#include <fstream>
#include <windows.h>

Game* Game::mInstance = nullptr;

Game* Game::getInstance() {
	if (mInstance == nullptr) {
		mInstance = new Game();
	}
	return mInstance;
}

void Game::Init(int argc, char* argv[]) {
	//Initialize GUI
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	_qApp = new QGuiApplication(argc, argv);
	_qEngine = new QQmlApplicationEngine();
	const QUrl url(QStringLiteral("qrc:/main.qml"));	//Path to main GUI file
	QObject::connect(_qEngine, &QQmlApplicationEngine::objectCreated,
		_qApp, [url](QObject* obj, const QUrl& objUrl) {
			if (!obj && url == objUrl)
				QCoreApplication::exit(-1);				//If there is no such file
		}, Qt::QueuedConnection);
	_qEngine->load(url);

	//Initializze game board and rules
	auto boardProp = new Board::BoardProperties;
	boardProp->sizeX = 50;
	boardProp->sizeY = 50;
	boardProp->maxAllowedUnits = 10;
	mGameBoard = new Board(boardProp);
}

int Game::Start() {
	return _qApp->exec();
}
