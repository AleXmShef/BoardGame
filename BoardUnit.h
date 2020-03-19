#pragma once
#include <vector>
class BoardUnit
{
public:
	enum class UnitType{Pongo, Base, Terrain, Misc};
	struct ActionMeta {
		BoardUnit* fromUnit = nullptr;
		BoardUnit* toUnit = nullptr;

		bool isMove = false;
		unsigned int moveX = 0;
		unsigned int moveY = 0;

		bool isHeal = false;
		unsigned int hpHeal = 0;
		unsigned int armorBuff = 0;

		bool isAttack = false;
		unsigned int hpAttack = 0;
		unsigned int armorAttack = 0;
	};
	BoardUnit();
	~BoardUnit();
	virtual BoardUnit* getCopy() = 0;
	virtual std::vector<ActionMeta> turnAction() = 0;
	//virtual UnitType getType() = 0;
	unsigned int getID();
private:
	static unsigned int getUnitCount();
	static unsigned int unitCount;
	static unsigned int idCount;
	unsigned int _id;
};

