#include "..\ApplicationManager.h"
#include"Action.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

bool Action::Execute(bool) {

	Execute(); return true; };

void Action::playing()
{
	Output* pOut = pManager->GetOutput();
	pManager->UpdateInterface();
	 
	if(PlayingCount % 2 == 0 && PlayingCount != 0)
	{
		Sleep(1000);
		pOut->PrintMessage("Playing The Recording.");
	}
	pOut->PrintMessage("Playing The Recording.");
	PlayingCount++;
}

int Action::PlayingCount = 1;