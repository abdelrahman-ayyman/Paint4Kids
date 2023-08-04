#include "ClearAllAction.h"

#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"

ClearAllAction::ClearAllAction(ApplicationManager * pApp):Action(pApp)
{
	this->deleteAction = false;
}


void ClearAllAction::ReadActionParameters() 
{	
	//Get a Pointer to the Output Interfaces
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Are you sure that you want to clear all the figures and recordings? type(Y or y) for yes");
	
	//Get an answer from the user
	string response = pIn->GetSrting(pOut);
	if (response == "Y" || response == "y")
	{
		deleteAction = true;
	}
	else
	{
		pOut->PrintMessage("The action is cancelled.");
		Sleep(800);
	};

	pOut->ClearStatusBar();

}

//Execute the action
void ClearAllAction::Execute() 
{
	if(pManager->GetPlayRecording() == false)
		//This action needs to read some parameters first
		ReadActionParameters();

	if (deleteAction) 
	{
		//Clear the drawing area
		Output* pOut = pManager->GetOutput();
		pOut->ClearDrawArea();
		
		//Delete all the figures stored
		pManager->deleteAllFigures();

		//Reset the counter of fogures to zero
		CFigure::ResetCounter();

		if(pManager->GetRecording() == false && pManager->GetPlayRecording() == false)
		{
			pManager->DeleteActionList();
			Action::PlayingCount = 1;
		}
		//TODO
		// Delete All Recordings & reset all variables
	}

}

bool ClearAllAction::Execute(bool IsRecording)
{
	Execute();

	if (IsRecording == true)
	{
		pManager->AddAction(this);
		return false;
	}
	return true;
}