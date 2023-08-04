#include "SwitchToPlayAction.h"

#include "..\ApplicationManager.h"


SwitchToPlayAction::SwitchToPlayAction(ApplicationManager * pApp):Action(pApp)
{}

void SwitchToPlayAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetRecording() == true)
	{
		pOut->PrintMessage("You have to stop the recording first.");
		return;
	}
	// Saving the orginal FigList
	pManager->ExchangeList(true);

	pOut->CreatePlayToolBar();

	pOut->ClearStatusBar();
}