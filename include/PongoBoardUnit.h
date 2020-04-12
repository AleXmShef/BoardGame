#pragma once
#include "PlayableBoardUnit.h"
class PongoBaseBoardUnit;
class PongoBoardUnit : public PlayableBoardUnit
{
public:
	PongoBoardUnit(PongoBaseBoardUnit* base);
	virtual ~PongoBoardUnit();
	static int getUnitCount();
protected:
	PongoBaseBoardUnit* _base;
private:
	static int unit_count;
};

