#include "Game.h"
#include "Infantry.h"
#include <QDebug>
#include "UItoBackendConnector.h"

Game* Game::mInstance = nullptr;

Game* Game::getInstance() {
	if (mInstance == nullptr) {
		mInstance = new Game();
	}
	return mInstance;
}

void Game::Init(int argc, char* argv[]) {
	qInfo() << "--------------------Game Start----------------------";
	qInfo() << " ";
	//Initialize GUI
	qmlRegisterSingletonType<UItoBackendConnector>("game", 1, 0, "UIConnector", UItoBackendConnector::UItoBackendConnector_singletonTypeProvider);
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	_qApp = new QGuiApplication(argc, argv);
	_qEngine = new QQmlApplicationEngine();
	const QUrl url(QStringLiteral("qrc:/main.qml"));	//Path to main GUI file
	QObject::connect(_qEngine, &QQmlApplicationEngine::objectCreated,
		_qApp, [url](QObject* obj, const QUrl& objUrl) {
			if (!obj && url == objUrl)
				QCoreApplication::exit(-1);				//If there is no such file
		}, Qt::QueuedConnection);
	QObject::connect(_qEngine, &QQmlApplicationEngine::quit, _qApp, &QGuiApplication::quit);
	_qEngine->load(url);

	//Initializze game board and rules
	auto boardProp = new Board::BoardProperties;
	boardProp->sizeX = 10;
	boardProp->sizeY = 10;
	boardProp->maxAllowedUnits = 10;
	mGameBoard = new Board(boardProp);
	//mGameBoard->_debug_print();
}

int Game::Start() {
	return _qApp->exec();
}

void Game::_debug_demo() {
	
}
