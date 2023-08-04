#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include <fstream>
#include "../Figures/CCircle.h"
#include "../Figures/CSquare.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CHexagon.h"
#include "../Figures/CTriangle.h"
#include "../Figures/CFigure.h"


LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{ }

void LoadAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Please Enter File Name to load from: ");
	nameoutput = pIn->GetSrting(pOut);
	nameoutput = nameoutput + ".txt";
}

void LoadAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	//clear undo and redo

	ifstream LoadedGraph(nameoutput);

	if (LoadedGraph.is_open())
	{
		string NewDrawColor;
		string NewFillColor;
		LoadedGraph >> NewDrawColor >> NewFillColor;

		int NewFigsCount;
		LoadedGraph >> NewFigsCount;
		pManager->deleteAllFigures();     //Delete all the figures stored
		CFigure::ResetCounter();	//Reset the counter of figures to zero
		pOut->ClearDrawArea();

		pOut->setCrntDrawColor(NewDrawColor);
		pOut->setCrntFillColor(NewFillColor);

		CFigure* NewFigs;


		for (int i = 0; i < NewFigsCount; i++)
		{
			string shape;

			LoadedGraph >> shape;

			if (shape == "RECT")
			{
				NewFigs = new CRectangle();
			}
			else if (shape == "SQUR")
			{
				NewFigs = new CSquare();
			}
			else if (shape == "HEXA")
			{
				NewFigs = new CHexagon();
			}
			if (shape == "CIRC")
			{
				NewFigs = new CCircle();
			}
			if (shape == "TRIA")
			{
				NewFigs = new CTriangle();
			}

			NewFigs->SetSelected(false);

			pManager->LoadAll(NewFigs, LoadedGraph);

			if (i == NewFigsCount - 1)
				CFigure::SetCounter(NewFigs->GetID());
		}

		LoadedGraph.close();
		pOut->PrintMessage("Successfully Loaded From " + nameoutput);
	}
	else
	{
		pOut->PrintMessage("Can't find file with this name ");
		Sleep(2000);


		pOut->ClearStatusBar();
	}
}

LoadAction::~LoadAction()
{}