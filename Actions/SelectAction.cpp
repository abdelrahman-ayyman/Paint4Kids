#include "SelectAction.h"

#include "..\ApplicationManager.h"

#include<cmath>

SelectAction::SelectAction(ApplicationManager * pApp):Action(pApp)
{}

void SelectAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	// pOut->PrintMessage("Click on a Figure");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(p.x, p.y);
}

void SelectAction::Execute() 
{
	if(pManager->GetPlayRecording() == false)
		ReadActionParameters();

	CFigure* figu = pManager->GetFigure(p.x,p.y);

	if(figu != NULL)
	{
		if(figu->GetSelected() == false)
		{
			CFigure* PreSelectedFig = pManager->GetPrevSelectFigure();

			if(PreSelectedFig != NULL)
			{
				PreSelectedFig->SetSelected(false);
			}

			figu->SetSelected(true);
			pManager->SetSelectedFigure(figu);
			figu->PrintInfo(pManager->GetOutput());
		}
		else
		{
			figu->SetSelected(false);
			pManager->SetSelectedFigure(NULL);
		}
	}
	else
	{
		/*
		ActionType act = pManager->GetUserActionByPoint(p.x, p.y);
		Output* pOut = pManager->GetOutput();

		if (act == PICK_COLOR || act == PICK_TYPE_COLOR || act == PICK_TYPE)
		{
			return;
		}

		pManager->ExecuteAction(act);
		*/
	}
}

bool SelectAction::Execute(bool IsRecording)
{
	Execute();

	if (IsRecording == true)
	{
		pManager->AddAction(this);
		return false;
	}
	return true;
}
