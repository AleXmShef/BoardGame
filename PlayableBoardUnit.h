#pragma once
#include "BoardUnit.h"
#include <vector>

class PlayableBoardUnit : public BoardUnit
{
public:
	struct Stats {
		int health = 0;
		int attack = 0;
		int armor = 0;
	};
	PlayableBoardUnit();
	virtual std::vector<ActionMeta> userAction() = 0;
	virtual std::vector<ActionMeta> defend(ActionMeta) = 0;
	Stats getStats();
	PlayableBoardUnit(PlayableBoardUnit& Base);
protected:
	Stats _stats;
};

