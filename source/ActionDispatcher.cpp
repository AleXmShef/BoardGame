#include "ActionDispatcher.h"
#include "PlayableBoardUnit.h"

ActionDispatcher::ActionDispatcher(Board* board) : mBoard(board) {
	
}

void ActionDispatcher::push_back(BoardUnit::ActionMeta meta) {
	actionQueue.push(meta);
}

std::vector<BoardUnit::ActionMeta>* ActionDispatcher::flush() {
	auto allActionsStack = new std::vector<BoardUnit::ActionMeta>;
	//user move
	for (int i = 0; i < actionQueue.size(); i++) {
		auto meta = actionQueue.front();
		if (!meta.isEmpty) {
			allActionsStack->push_back(meta);
			if (meta.isAttack || meta.isHeal) {
				auto fromUnit = dynamic_cast<PlayableBoardUnit*>(meta.fromUnit);
				auto toUnit = dynamic_cast<PlayableBoardUnit*>(meta.toUnit);
				auto defendMetas = toUnit->defend(meta);
				for (int i = 0; i < defendMetas.size(); i++) {
					if (defendMetas[i].isAttack || defendMetas[i].isHeal) {
						auto toUnit = dynamic_cast<PlayableBoardUnit*>(defendMetas[i].toUnit);
						toUnit->defend(defendMetas[i]);
						allActionsStack->push_back(defendMetas[i]);
					}
				}
			}
			else if (meta.isCreate) {
				mBoard->addUnit(meta.createdUnit, meta.unitX, meta.unitY);
			}
			else if (meta.isMove) {
				auto unit = meta.fromUnit;
				mBoard->moveUnit(unit, meta.moveX, meta.moveY);
			}
		}
		actionQueue.pop();
	}

	//turn moves
	for (int i = 0; i < mBoard->getBoardProperties().sizeY; i++) {
		for (int j = 0; j < mBoard->getBoardProperties().sizeX; j++) {
			auto cell = mBoard->getCellAt(j, i);
			auto metas = cell.terrainUnit->turnAction();
			if (!metas[0].isEmpty) {
				for (int k = 0; k < metas.size(); k++) {
					if (metas[k].isAttack || metas[k].isHeal) {
						auto toUnit = dynamic_cast<PlayableBoardUnit*>(metas[i].toUnit);
						toUnit->defend(metas[i]);
						allActionsStack->push_back(metas[i]);
					}
				}
			}
			else if(!cell.isEmpty){
				auto _metas = cell.unit->turnAction();
				for (int k = 0; k < _metas.size(); k++) {
					if (_metas[k].isAttack || _metas[k].isHeal) {
						auto toUnit = dynamic_cast<PlayableBoardUnit*>(_metas[i].toUnit);
						toUnit->defend(_metas[i]);
						allActionsStack->push_back(_metas[i]);
					}
				}
			}
		}
	}
	return allActionsStack;
}