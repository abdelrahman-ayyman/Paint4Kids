#include "PlayRecording.h"

#include<windows.h>
#include "../ApplicationManager.h"

#include<cmath>
#include <chrono>
#include <thread>


PlayRecording::PlayRecording(ApplicationManager * pApp):Action(pApp)
{}
void PlayRecording::ReadActionParameters()
{}

void PlayRecording::Execute()
{
	if(pManager->GetRecording() == false && pManager->GetPlayRecording() == false && pManager->GetRecordingCount() > 0)
	{
		Output* pOut = pManager->GetOutput();

		pOut->ClearDrawArea();
		pManager->deleteAllFigures();
		CFigure::ResetCounter();

		pOut->PrintMessage("Playing The Recording.");

		pManager->SetPlayRecording(true);
		pManager->LoopRecording();
		pManager->SetPlayRecording(false);
		Action::PlayingCount = 1;
	}
}
 
