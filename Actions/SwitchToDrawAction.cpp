#include "SwitchToDrawAction.h"

#include "..\ApplicationManager.h"

SwitchToDrawAction::SwitchToDrawAction(ApplicationManager * pApp):Action(pApp)
{}

void SwitchToDrawAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	
	pManager->ExchangeList(false);
	pOut->ClearDrawArea();
	pManager->UpdateInterface();

	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();
}