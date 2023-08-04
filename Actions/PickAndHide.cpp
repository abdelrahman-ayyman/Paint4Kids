#include "PickAndHide.h"

#include "..\ApplicationManager.h"

#include "SelectAction.h"

#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

PickAndHide::PickAndHide(ApplicationManager * pApp, ActionType type):Action(pApp)
{ 
	PickingType = type;
	NumFilledType = InvalidPicks = ValidPicks = 0;
	NumFilled = pManager->GetFigFillColorCount(true);
}

void PickAndHide::ReadActionParameters()
{

	// Reset the selected figure
	CFigure* PreSelectedFig = pManager->GetPrevSelectFigure();

	if(PreSelectedFig != NULL)
		PreSelectedFig->SetSelected(false);

	pManager->SetSelectedFigure(NULL);

	// Pick a random type
	CFigure* RandFig;

	srand(time(0));
 
	int RandIndex = rand() % pManager->GetFigCount();

	RandFig = pManager->GetFigByIndex(RandIndex);
	FigType = RandFig->GetType();
	NumFigs = pManager->GetFigTypeCount(FigType);

	if (PickingType == PICK_COLOR || PickingType == PICK_TYPE_COLOR)
	{
		while (true)
		{
			bool IsFilled = RandFig->IsFilled();

			if (IsFilled)
			{
				FigClr = RandFig->GetFillColor();
				NumFilled = pManager->GetFigFillColorCount(false, FigClr);
				if (PickingType == PICK_TYPE_COLOR)
					NumFilledType = pManager->GetFigTypeFillCount(FigType, FigClr);
				break;
			}
 
			int RandIndex = rand() % pManager->GetFigCount();

			RandFig = pManager->GetFigByIndex(RandIndex);
			FigType = RandFig->GetType();
			NumFigs = pManager->GetFigTypeCount(FigType);

		}
	}

	string arr[6] = {
		"Circles",
		"Squares",
		"Triangles",
		"Rectangles",
		"Hexagons"
	};

	/*cout<<"No. Filled "<<NumFilled<<endl;
	cout<<"Type "<<arr[FigType]<<endl;
	cout<<"No. TypeFigs "<<NumFigs<<endl;
	cout<<"No. TypeFill "<<NumFilledType<<endl;*/
}

void PickAndHide::Execute()
{
	Output* pOut = pManager->GetOutput();
	string arr[6] = {
		"Circles",
		"Squares",
		"Triangles",
		"Rectangles",
		"Hexagons"
	};

	if (pManager->GetCopiedFigCount() != 0)
	{
		//Restarting the game
		pManager->ExchangeList(false);
		pManager->ExchangeList(true);

		pManager->UpdateInterface();
	}

	if (pManager->GetFigCount() == 0)
		pOut->PrintMessage("You have to draw at least one figure to start the game.");
	else if ((PickingType == PICK_COLOR || PickingType == PICK_TYPE_COLOR) && NumFilled == 0)
		pOut->PrintMessage("You have to draw at least one filled figure to start the game.");
	else
	{
		//Picking a random shape and color
		ReadActionParameters();

		// Starting the game
		CFigure* PreSelectedFig;
		string FigClrStr;
		//GUI_MODE CrntMode = pOut->getCrntMode();

		switch(PickingType)
		{
			case PICK_TYPE:
				pOut->PrintMessage("Pick all the " + arr[FigType]);
				//while (NumFigs > 0 && CrntMode == MODE_PLAY)
				while (NumFigs > 0)
				{
					pManager->ExecuteAction(SELECT);
					//Checking if the user hadn't switched to the draw mode
					// CrntMode = pOut->getCrntMode();

					PreSelectedFig = pManager->GetPrevSelectFigure();

					if(PreSelectedFig != NULL)
					{
						if (PreSelectedFig->GetType() == FigType)
						{
							ValidPicks++;
							NumFigs--;
							pManager->DeleteFig(PreSelectedFig->GetID(), MODE_PLAY);

							PreSelectedFig->SetSelected(false);
							pManager->SetSelectedFigure(NULL);

							pOut->ClearDrawArea();
							pManager->UpdateInterface();
						}
						else
						{
							InvalidPicks++;
							PreSelectedFig->SetSelected(false);
							pManager->SetSelectedFigure(NULL);
						}
					}

					//if (CrntMode == MODE_PLAY)
					//{
						pOut->PrintMessage("Pick all the " + arr[FigType] + " Correct Picks: " + to_string(ValidPicks) + " Incorrect Picks: " + to_string(InvalidPicks));

						if (NumFigs == 0)
						{
							pOut->PrintMessage("Pick all the " + arr[FigType] + " Correct Picks: " + to_string(ValidPicks) + " Incorrect Picks: " + to_string(InvalidPicks) 
							+ " You got a grade of " + to_string(  100 - InvalidPicks * 2) + "%" );

							break;
						}
					//}
				}
				break;
			case PICK_COLOR:
				if (FigClr == RED)
					FigClrStr = "Red";
				else if (FigClr == BLUE)
					FigClrStr = "Blue";
				else if (FigClr == GREEN)
					FigClrStr = "Green";
				else if (FigClr == BLACK)
					FigClrStr = "Black";
				else if (FigClr == ORANGE)
					FigClrStr = "Orange";
				else if (FigClr == YELLOW)
					FigClrStr = "Yellow";

				pOut->PrintMessage("Pick all the " + FigClrStr + " Figures.");

				while (NumFilled > 0 /* && pOut->getCrntMode() == MODE_PLAY*/ )
				{
					pManager->ExecuteAction(SELECT);
					//Checking if the user hadn't switched to the draw mode
					//CrntMode = pOut->getCrntMode();

					PreSelectedFig = pManager->GetPrevSelectFigure();

					if(PreSelectedFig != NULL)
					{
						if (PreSelectedFig->IsFilled())
						{
							if (PreSelectedFig->GetFillColor() == FigClr)
							{
								ValidPicks++;
								NumFilled--;
								pManager->DeleteFig(PreSelectedFig->GetID(), MODE_PLAY);

								PreSelectedFig->SetSelected(false);
								pManager->SetSelectedFigure(NULL);

								pOut->ClearDrawArea();
								pManager->UpdateInterface();
							}
							else
							{
								InvalidPicks++;
								PreSelectedFig->SetSelected(false);
								pManager->SetSelectedFigure(NULL);
							}
						}
						else
						{
							InvalidPicks++;
							PreSelectedFig->SetSelected(false);
							pManager->SetSelectedFigure(NULL);
						}
					}

					//if (CrntMode == MODE_PLAY) 
					//{
						pOut->PrintMessage("Pick all the " + FigClrStr + " Figures. " + "Correct Picks: " + to_string(ValidPicks) + " Incorrect Picks: " + to_string(InvalidPicks));

						if (NumFilled == 0)
						{
							pOut->PrintMessage("Pick all the " + FigClrStr + " Figures. " + "Correct Picks: " + to_string(ValidPicks) + " Incorrect Picks: " + to_string(InvalidPicks) 
							+ " You got a grade of " + to_string(  100 - InvalidPicks * 2) + "%" );

							break;
						}
					//}
				}
				break;
			case PICK_TYPE_COLOR:
				if (FigClr == RED)
					FigClrStr = "Red";
				else if (FigClr == BLUE)
					FigClrStr = "Blue";
				else if (FigClr == GREEN)
					FigClrStr = "Green";
				else if (FigClr == BLACK)
					FigClrStr = "Black";
				else if (FigClr == ORANGE)
					FigClrStr = "Orange";
				else if (FigClr == YELLOW)
					FigClrStr = "Yellow";

				pOut->PrintMessage("Pick all the " + FigClrStr + " " + arr[FigType] + ".");

				while (NumFilledType > 0 /* && pOut->getCrntMode() == MODE_PLAY */ )
				{
					pManager->ExecuteAction(SELECT);
					//Checking if the user hadn't switched to the draw mode
					//CrntMode = pOut->getCrntMode();

					PreSelectedFig = pManager->GetPrevSelectFigure();

					if(PreSelectedFig != NULL)
					{
						if (PreSelectedFig->IsFilled())
						{
							if (PreSelectedFig->GetFillColor() == FigClr && PreSelectedFig->GetType() == FigType)
							{
								ValidPicks++;
								NumFilledType--;
								pManager->DeleteFig(PreSelectedFig->GetID(), MODE_PLAY);

								PreSelectedFig->SetSelected(false);
								pManager->SetSelectedFigure(NULL);

								pOut->ClearDrawArea();
								pManager->UpdateInterface();
							}
							else
							{
								InvalidPicks++;
								PreSelectedFig->SetSelected(false);
								pManager->SetSelectedFigure(NULL);
							}
						}
						else
						{
							InvalidPicks++;
							PreSelectedFig->SetSelected(false);
							pManager->SetSelectedFigure(NULL);
						}
					}

					//if (CrntMode == MODE_PLAY)
					//{
						pOut->PrintMessage("Pick all the " + FigClrStr + " " + arr[FigType] + ". " + "Correct Picks: " + to_string(ValidPicks) + " Incorrect Picks: " + to_string(InvalidPicks));

						if (NumFilledType == 0)
						{
							pOut->PrintMessage("Pick all the " + FigClrStr + + " " + arr[FigType] + ". " + "Correct Picks: " + to_string(ValidPicks) + " Incorrect Picks: " + to_string(InvalidPicks) 
							+ " You got a grade of " + to_string(  100 - InvalidPicks * 2) + "%" );

							break;
						}
					//}
				}

				break;
		}

	}
}