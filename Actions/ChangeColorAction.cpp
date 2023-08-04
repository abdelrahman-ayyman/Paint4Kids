#include "ChangeColorAction.h"

#include "..\ApplicationManager.h"

ChangeColorAction::ChangeColorAction(ApplicationManager * pApp, bool fill):Action(pApp)
{
	IsFilled = fill;
	NoFill = false;
}


void ChangeColorAction::ReadActionParameters(bool noFillIcon) 
{
	Output* pOut = pManager->GetOutput();

	pOut->CreateColorPalette(noFillIcon);

	pOut->PrintMessage("Choose a drawing color.");

	bool exit = false;

	while (!exit)
	{
		ActionType Color = pManager->GetUserAction();
		switch (Color)
		{
			case BLACK_COLOR:
				DrawingColor = BLACK;
				exit = true;
				break;

			case YELLOW_COLOR:
				DrawingColor = YELLOW;
				exit = true;
				break;

			case ORANGE_COLOR:
				DrawingColor = ORANGE;
				exit = true;
				break;

			case RED_COLOR:
				DrawingColor = RED;
				exit = true;
				break;

			case GREEN_COLOR:
				DrawingColor = GREEN;
				exit = true;
				break;

			case BLUE_COLOR:
				DrawingColor = BLUE;
				exit = true;
				break;
			case NOFILL:
				NoFill = true;
				exit = true;
				break;
		}
	}

	pOut->CreateDrawToolBar();

	pOut->ClearStatusBar();
}

void ChangeColorAction::Execute() 
{

	Output* pOut = pManager->GetOutput();
	CFigure* SelectedFig = pManager->GetPrevSelectFigure();

	if (IsFilled) 
	{
		if(pManager->GetPlayRecording() == false)
			// Asking the user to pick a color
			ReadActionParameters(IsFilled);

		if (NoFill)
		{
			pOut->setFilled(false);

			if (SelectedFig != NULL)
				SelectedFig->UnFill();

			pOut->ClearDrawArea();
			return;
		}

		// Setting the color
		pOut->setCrntFillColor(DrawingColor);
		pOut->setFilled(true);

		// Filling the selected figure
		if (SelectedFig != NULL)
			SelectedFig->ChngFillClr(DrawingColor);
	}
	else 
	{
		if(pManager->GetPlayRecording() == false)
			// Asking the user to pick a color
			ReadActionParameters();

		// Setting the color
		pOut->setCrntDrawColor(DrawingColor);

		// Filling the selected figure
		if (SelectedFig != NULL)
			SelectedFig->ChngDrawClr(DrawingColor);
	}
}

bool ChangeColorAction::Execute(bool IsRecording)
{
	Execute();

	if (IsRecording == true)
	{
		pManager->AddAction(this);
		return false;
	}
	return true;
}