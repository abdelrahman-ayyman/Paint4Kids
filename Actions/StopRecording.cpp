
#include<windows.h>
#include "../ApplicationManager.h"

#include<cmath>
#include <chrono>
#include <thread>

#include"StopRecording.h"

StopRecording::StopRecording(ApplicationManager * pApp):Action(pApp)
{}

void StopRecording::ReadActionParameters()
{}

void StopRecording::Execute() 
{
	if (pManager->GetRecording() == true)
	{
		pManager->SetRecording(false);
		pManager->SetPlayRecording(false);

		Output* pOut = pManager->GetOutput();
		pOut->ClearStatusBar();
		pOut->PrintMessage("Recording has stopped");
	}
}