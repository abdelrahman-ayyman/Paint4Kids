#include "AddHexAction.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

AddHexAction::AddHexAction(ApplicationManager * pApp):Action(pApp)
{}

void AddHexAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click a point");
	
	//Read center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	HexGfxInfo.isFilled = pOut->isFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexAction::Execute() 
{
	if(pManager->GetPlayRecording() == false)
		//This action needs to read some parameters first
		ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CHexagon *H=new CHexagon(P1, HexGfxInfo);
	//Add the rectangle to the list of figures
	pManager->AddFigure(H);
}

bool AddHexAction::Execute(bool IsRecording)
{
	Execute();

	if (IsRecording == true)
	{
		pManager->AddAction(this);
		return false;
	}
	return true;
}
