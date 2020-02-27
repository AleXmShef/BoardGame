#pragma once
#include "PlayableBoardUnit.h"
#include "BoardUnitFactory.h"
class Infantry : public PlayableBoardUnit
{
public:
	Infantry() {};
	ActionMeta turnAction() override;
};

class Swordsman : public Infantry 
{
public:
	Swordsman();
	ActionMeta userAction() override;
	ActionMeta defend(ActionMeta) override;
	BoardUnit* getCopy() override;
};

class Spearman : public Infantry
{
public:
	Spearman();
	ActionMeta userAction() override;
	ActionMeta defend(ActionMeta) override;
	BoardUnit* getCopy() override;
};

class InfantryFactory : public BoardUnitFactory
{
public:
	InfantryFactory() {};
	BoardUnit* getType(int type) override;
};

