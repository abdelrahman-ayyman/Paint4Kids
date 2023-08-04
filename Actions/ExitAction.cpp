#include "ExitAction.h"
#include "../ApplicationManager.h"

ExitAction::ExitAction(ApplicationManager* pApp) : Action(pApp)
{
	exitaction = false;
}

void ExitAction::ReadActionParameters()
{}


void ExitAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("The game will be closed.");
	Sleep(800);
}


ExitAction::~ExitAction()
{};
