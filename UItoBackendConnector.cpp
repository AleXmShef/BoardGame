#include "UItoBackendConnector.h"

UItoBackendConnector::UItoBackendConnector(QObject* parent = nullptr) {
	mGame = Game::getInstance();
}

QObject* UItoBackendConnector::UItoBackendConnector_singletonTypeProvider(QQmlEngine* engine, QJSEngine* scriptEngine) {
	Q_UNUSED(engine)
	Q_UNUSED(scriptEngine)

	auto connector = new UItoBackendConnector();
	mInstance = connector;
	return connector;
}

UItoBackendConnector* UItoBackendConnector::getInstance() {
	return mInstance;
}

QString UItoBackendConnector::connectionTest() {
	QString str = "test successful";
	return str;
}
