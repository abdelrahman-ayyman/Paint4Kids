#include "DeleteFigAction.h"

#include "..\ApplicationManager.h"

DeleteFigAction::DeleteFigAction(ApplicationManager * pApp):Action(pApp)
{}

void DeleteFigAction::ReadActionParameters() 
{	
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();
	SelectedFig = pManager->GetPrevSelectFigure();

	if (SelectedFig == NULL)
	{
		pOut->PrintMessage("You have to select a figure first in order to delete it.");
		Sleep(2000);
	}

	pOut->ClearStatusBar();
}

//Execute the action
void DeleteFigAction::Execute() 
{
	if(pManager->GetPlayRecording() == false)
		//Check wheter a figure is selected or not
		ReadActionParameters();

	if (SelectedFig != NULL)
	{
		pManager->DeleteFig(SelectedFig->GetID());

		Output* pOut = pManager->GetOutput();
		pOut->ClearDrawArea();

	}
}

bool DeleteFigAction::Execute(bool IsRecording)
{
	Execute();

	if (IsRecording == true)
	{
		pManager->AddAction(this);
		return false;
	}
	return true;
}

