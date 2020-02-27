#pragma once
#include "BoardUnit.h"
class PlayableBoardUnit : public BoardUnit
{
public:
	struct Stats {
		int health = 0;
		int attack = 0;
		int armor = 0;
	};
	PlayableBoardUnit() {};
	virtual ActionMeta userAction() = 0;
	virtual ActionMeta defend(ActionMeta) = 0;
	Stats getStats();
	bool isAttackable() override;
	PlayableBoardUnit(PlayableBoardUnit& Base);
protected:
	Stats _stats;
};

