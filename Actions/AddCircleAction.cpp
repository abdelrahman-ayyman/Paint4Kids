#include "AddCircleAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

AddCircleAction::AddCircleAction(ApplicationManager * pApp):Action(pApp)
{}

void AddCircleAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at point to be the center");
	
	//Read the center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at another point for the radius");

	//Read a point for the radius and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	CircleGfxInfo.isFilled = pOut->isFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircleAction::Execute() 
{
	if(pManager->GetPlayRecording() == false)
		//This action needs to read some parameters first
		ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CCircle *C = new CCircle(P1, P2, CircleGfxInfo);

	//Add the circle to the list of figures
	pManager->AddFigure(C);
}

bool AddCircleAction::Execute(bool IsRecording)
{
	Execute();

	if (IsRecording == true)
	{
		pManager->AddAction(this);
		return false;
	}
	return true;
}

