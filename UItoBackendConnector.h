#pragma once
#include <QObject>
#include <QString>
#include "Game.h"

class UItoBackendConnector : public QObject
{
	Q_OBJECT

public:
	explicit UItoBackendConnector(QObject* parent = nullptr);
	static QObject* UItoBackendConnector_singletonTypeProvider(QQmlEngine* engine, QJSEngine* scriptEngine);
	static UItoBackendConnector* getInstance();

	Q_INVOKABLE QString connectionTest();

protected:
	static UItoBackendConnector* mInstance;
	Game* mGame;
};

