#pragma once
#include "action.h"

class PickAndHide :
	public Action
{
private:
	ActionType PickingType;

	int ValidPicks;
	int InvalidPicks;

	int NumFilled;

	TYPE FigType;
	color FigClr;
	int NumFigs;
	int NumFilledType;
public:
	PickAndHide(ApplicationManager * pApp, ActionType type);
	virtual void ReadActionParameters();
	virtual void Execute();
};

