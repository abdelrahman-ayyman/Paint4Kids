#pragma once
#include "Action.h"

#include "..\Figures\CFigure.h"

class DeleteFigAction :
	public Action
{
private:
	CFigure* SelectedFig;
public:
	DeleteFigAction(ApplicationManager *pApp);

	//Check if a figure is selected or not
	virtual void ReadActionParameters();
	
	//Clear All the figures & recordings in the ApplicationManager
	virtual void Execute();

	virtual bool Execute(bool IsRecording);
};

