#include "StartRecording.h"

#include "../ApplicationManager.h"

#include<cmath>

StartRecording::StartRecording(ApplicationManager * pApp):Action(pApp)
{}

void StartRecording::ReadActionParameters()
{}

 void StartRecording::Execute()
{
	if( pManager->GetFigCount() == 0)
	{
		Output* pOut = pManager->GetOutput();

		pOut->ClearDrawArea();

		pManager->deleteAllFigures();
		pManager->DeleteActionList();

		pManager->SetRecording(true);

		pOut->PrintMessage("Currently Recording.");
	}
}

