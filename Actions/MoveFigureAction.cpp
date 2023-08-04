#include "MoveFigureAction.h"
#include "../ApplicationManager.h"

MoveFigureAction::MoveFigureAction(ApplicationManager* pApp):Action(pApp)
{}

void MoveFigureAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	SelectedFig = pManager->GetPrevSelectFigure();

	if (SelectedFig == NULL)
	{
		pOut->PrintMessage("You have to select a figure first in order to move it.");
		Sleep(2000);
	}
	else
	{
		pOut->PrintMessage("Click on point to move Figure to ");
		pIn->GetPointClicked(moveto.x, moveto.y);
		 
	}

	pOut->ClearStatusBar();
}

void MoveFigureAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	if (pManager->GetPlayRecording() == false)
		ReadActionParameters();

	if (SelectedFig != NULL)
	{
		pOut->ClearDrawArea();
		SelectedFig->Move(moveto);

		pOut->ClearDrawArea();
		pManager->UpdateInterface();

	}
	
}


bool MoveFigureAction::Execute(bool IsRecording)
{
	Execute();

	if (IsRecording == true)
	{
		pManager->AddAction(this);
		return false;
	}
	return true;
}

