#pragma once
#include "PongoBoardUnit.h"
#include "BoardUnitFactory.h"
#include "PongoBaseBoardUnit.h"

class Cavalry : public PongoBoardUnit
{
public:
	Cavalry(PongoBaseBoardUnit* base);
	std::vector<ActionMeta> turnAction() override;
};

class HeavyCavalry : public Cavalry
{
public:
	HeavyCavalry(PongoBaseBoardUnit* base);
	std::vector<ActionMeta> userAction() override;
	std::vector<ActionMeta> defend(ActionMeta) override;
	BoardUnit* getCopy() override;
};

class LightCavalry : public Cavalry
{
public:
	LightCavalry(PongoBaseBoardUnit* base);
	std::vector<ActionMeta> userAction() override;
	std::vector<ActionMeta> defend(ActionMeta) override;
	BoardUnit* getCopy() override;
};

class CavalryFactory : public BoardUnitFactory
{
public:
	CavalryFactory(PongoBaseBoardUnit* base) : BoardUnitFactory(base) {};
	PlayableBoardUnit* getType(int type) override;
};
