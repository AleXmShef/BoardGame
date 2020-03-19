#pragma once
#include "PongoBoardUnit.h"
#include "BoardUnitFactory.h"
#include "PongoBaseBoardUnit.h"

class Artillery : public PongoBoardUnit
{
public:
	Artillery(PongoBaseBoardUnit* base);	//!!!
	std::vector<ActionMeta> turnAction() override;
};

class Catapult : public Artillery
{
public:
	Catapult(PongoBaseBoardUnit* base);
	std::vector<ActionMeta> userAction() override;
	std::vector<ActionMeta> defend(ActionMeta) override;
	BoardUnit* getCopy() override;
};

class Cannon : public Artillery
{
public:
	Cannon(PongoBaseBoardUnit* base);
	std::vector<ActionMeta> userAction() override;
	std::vector<ActionMeta> defend(ActionMeta) override;
	BoardUnit* getCopy() override;
};

class ArtilleryFactory : public BoardUnitFactory
{
public:
	ArtilleryFactory(PongoBaseBoardUnit* base) : BoardUnitFactory(base) {};
	PlayableBoardUnit* getType(int type) override;
};

