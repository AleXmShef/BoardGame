#pragma once
#include "BoardUnit.h"
class Board
{
public:
	struct BoardProperties {
		unsigned int maxAllowedUnits = 0;
		unsigned int sizeX = 0;
		unsigned int sizeY = 0;
	};
	struct BoardCell {
		bool isEmpty = true;
		BoardUnit* unit = nullptr;
	};
public:
	Board(BoardProperties* properties);
	Board(Board& board);
	void addUnit(BoardUnit* newUnit, unsigned int x, unsigned int y);
	void removeUnit(unsigned int x, unsigned int y);
	void removeUnit(BoardUnit* unit);
	void moveUnit(BoardUnit* unit, unsigned int x, unsigned int y);
	void moveUnit(unsigned int current_x, unsigned int current_y, unsigned int intended_x, unsigned int intended_y);

	BoardUnit* operator()(unsigned int x, unsigned int y);
protected:
	BoardProperties* mBoardProperties = nullptr;
	BoardCell** boardArray = nullptr;
	unsigned int unitCount = 0;
	unsigned int freeCells = 0;
};

