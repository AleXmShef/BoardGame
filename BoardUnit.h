#pragma once
class BoardUnit
{
public:
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
	virtual ActionMeta turnAction() = 0;
	virtual bool isAttackable() = 0;
	static unsigned int getUnitCount();
private:
	static unsigned int unitCount;
};

