#pragma once
#include "Board.h"
#include <queue>
class ActionDispatcher
{
public:
	ActionDispatcher(Board* board);
	void push_back(BoardUnit::ActionMeta meta);
	std::vector<BoardUnit::ActionMeta>* flush();
	void ImmediateExec(BoardUnit::ActionMeta meta);
protected:
	std::queue<BoardUnit::ActionMeta> actionQueue;
	Board* mBoard = nullptr;
};

