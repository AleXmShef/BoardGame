#include "PongoBoardUnit.h"

int PongoBoardUnit::unit_count = 0;

PongoBoardUnit::PongoBoardUnit(PongoBaseBoardUnit* base) : _base(base) {
	unit_count++;
}

PongoBoardUnit::~PongoBoardUnit() {
	unit_count--;
}

int PongoBoardUnit::getUnitCount() {
	return unit_count;
}
