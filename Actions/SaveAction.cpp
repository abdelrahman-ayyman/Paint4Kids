#include "SaveAction.h"
#include "..\ApplicationManager.h"
#include <fstream>


SaveAction::SaveAction(ApplicationManager* pman) :Action(pman)
{}

void SaveAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Please Enter File Name: ");
	nameinput = pIn->GetSrting(pOut);	 
	nameinput = nameinput + ".txt";

}

//Save Excution
void SaveAction::Execute()
{
	ReadActionParameters();
	ofstream SavedGraph(nameinput);
	Output* pOut = pManager->GetOutput();
	SavedGraph << pOut->getColorText(UI.DrawColor) << "\t";
	SavedGraph << pOut->getColorText(UI.DrawColor) << endl;
	SavedGraph << pManager->GetFigCount() << endl;
	pManager->SaveAll(SavedGraph);
	SavedGraph.close();
	pOut->PrintMessage("Successfully Saved to " + nameinput);


}

SaveAction::~SaveAction()
{}