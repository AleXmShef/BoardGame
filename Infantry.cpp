#include "Infantry.h"

Infantry::ActionMeta Infantry::turnAction() {

}

Swordsman::Swordsman() {
	_stats.health = 10;
	_stats.armor = 15;
	_stats.attack = 20;
}

Swordsman::ActionMeta Swordsman::userAction() {

}

Swordsman::ActionMeta Swordsman::defend(Swordsman::ActionMeta) {

}

BoardUnit* Swordsman::getCopy() {

}

Spearman::Spearman() {
	_stats.health = 10;
	_stats.armor = 15;
	_stats.attack = 20;
}

Spearman::ActionMeta Spearman::userAction() {

}

Spearman::ActionMeta Spearman::defend(Spearman::ActionMeta) {

}

BoardUnit* Spearman::getCopy() {

}

BoardUnit* InfantryFactory::getType(int type) {
	switch (type)
	{
	case 0:
		return (BoardUnit*)(new Swordsman());
		break;
	case 1:
		return (BoardUnit*)(new Spearman());
		break;
	default:
		//throw
		return nullptr;
		break;
	}
}

