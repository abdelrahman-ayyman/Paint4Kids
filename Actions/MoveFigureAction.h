#pragma once
#include "../Actions/Action.h"
#include "../Figures/CFigure.h"

class MoveFigureAction :public Action
{
private:
	CFigure* SelectedFig;
	Point moveto;
public:
	MoveFigureAction(ApplicationManager* pApp);  //Check if a figure is selected or not

	virtual void ReadActionParameters();
	virtual void Execute();
	bool Execute(bool IsRecording);

};


