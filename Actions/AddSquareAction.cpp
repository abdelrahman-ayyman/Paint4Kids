#include "AddSquareAction.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

AddSquareAction::AddSquareAction(ApplicationManager * pApp):Action(pApp)
{}

void AddSquareAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click a point");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	SquareGfxInfo.isFilled = pOut->isFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquareGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddSquareAction::Execute() 
{
	if(pManager->GetPlayRecording() == false)
		//This action needs to read some parameters first
		ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CSquare *S=new CSquare(P1, SquareGfxInfo);
	//Add the rectangle to the list of figures
	pManager->AddFigure(S);
}

bool AddSquareAction::Execute(bool IsRecording)
{
	Execute();

	if (IsRecording == true)
	{
		pManager->AddAction(this);
		return false;
	}
	return true;
}