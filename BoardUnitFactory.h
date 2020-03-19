#pragma once
#include "PongoBoardUnit.h"
#include "PongoBaseBoardUnit.h"
class BoardUnitFactory
{
public:
	BoardUnitFactory(PongoBaseBoardUnit* base) : _base(base) {};
	virtual PlayableBoardUnit* getType(int type = 0) = 0;
protected:
	PongoBaseBoardUnit* _base;
};

