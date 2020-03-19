#pragma once
#include "PongoBoardUnit.h"
#include "BoardUnitFactory.h"
#include "PongoBaseBoardUnit.h"

class Infantry : public PongoBoardUnit
{
public:
	Infantry(PongoBaseBoardUnit* base);
	std::vector<ActionMeta> turnAction() override;
};

class Swordsman : public Infantry
{
public:
	Swordsman(PongoBaseBoardUnit* base);
	std::vector<ActionMeta> userAction() override;
	std::vector<ActionMeta> defend(ActionMeta) override;
	BoardUnit* getCopy() override;
};

class Spearman : public Infantry
{
public:
	Spearman(PongoBaseBoardUnit* base);
	std::vector<ActionMeta> userAction() override;
	std::vector<ActionMeta> defend(ActionMeta) override;
	BoardUnit* getCopy() override;
};

class InfantryFactory : public BoardUnitFactory
{
public:
	InfantryFactory(PongoBaseBoardUnit* base) : BoardUnitFactory(base) {};
	PlayableBoardUnit* getType(int type) override;
};

