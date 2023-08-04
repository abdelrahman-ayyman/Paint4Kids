#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddSquareAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddHexAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\ClearAllAction.h"
#include "Actions\SwitchToDrawAction.h"
#include "Actions\SwitchToPlayAction.h"
#include "Actions\ChangeColorAction.h"
#include "Actions\SelectAction.h"
#include "Actions\DeleteFigAction.h"
#include "Actions\PickAndHide.h"
#include "Actions\StartRecording.h"
#include "Actions\StopRecording.h"
#include "Actions\PlayRecording.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"
#include "Actions/ExitAction.h"
#include "Actions/MoveFigureAction.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	needtodraw = true;
	CopiedFigList = NULL;
	CopiedFigCount = 0;
	SelectedFig = NULL;
	//Create an array of figure pointers and set them to NULL		
	for(int i = 0; i < MaxFigCount;i++)
		FigList[i] = NULL;

	LastAction = NULL;
	IsRecording = false;
	IsPlaying = false;
	RecordingCount = 0;
		
	for(int i = 0; i < 20;i++)
		RecordingList[i] = NULL;

}

//ahmed things
void ApplicationManager::AddAction(Action*last)
{
	if(RecordingCount < 20 )
		RecordingList[RecordingCount++] = last;
}

Action* ApplicationManager::GetAction()
{ return LastAction; }

void ApplicationManager::DeleteActionList()
{
	for(int i = 0; i < RecordingCount; i++)
	{
		delete RecordingList[i];
		RecordingList[i] = NULL;
	}
	RecordingCount = 0;
}

int ApplicationManager::GetRecordingCount()
{ return RecordingCount; }

bool ApplicationManager::GetRecording()
{ return IsRecording; }

void ApplicationManager::SetRecording(bool b)
{ IsRecording = b; }

bool ApplicationManager::GetPlayRecording()
{ return IsPlaying; }

void ApplicationManager::SetPlayRecording(bool b)
{ IsPlaying = b; }

void ApplicationManager::LoopRecording()
{
	for(int i=0; i < RecordingCount; i++)
	{
		RecordingList[i]->Execute(false);
		LastAction->playing();
	}
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
ActionType ApplicationManager::GetUserActionByPoint(int x, int y) const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction(true, x, y);		
}
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_SQR:
			pAct = new AddSquareAction(this);
			break;

		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;

		case DRAW_HEX:
			pAct = new AddHexAction(this);
			break;

		case DRAW_CRCL:
			pAct = new AddCircleAction(this);
			break;

		case TO_DRAW:
			pAct = new SwitchToDrawAction(this);
			break;

		case TO_PLAY:
			pAct = new SwitchToPlayAction(this);
			break;

		case CLEAR:
			pAct = new ClearAllAction(this);
			break;

		case SELECT:
			pAct = new SelectAction(this);
			break;

		//Pick & Hide
		case PICK_COLOR:
			pAct = new PickAndHide(this, PICK_COLOR);
			break;

		case PICK_TYPE:
			pAct = new PickAndHide(this, PICK_TYPE);
			break;

		case PICK_TYPE_COLOR:
			pAct = new PickAndHide(this, PICK_TYPE_COLOR);
			break;
		////////////////////

		case CHNG_COLOR:
			pAct = new ChangeColorAction(this);
			break;

		case FILL:
			pAct = new ChangeColorAction(this, true);
			break;

		case DLTE:
			pAct = new DeleteFigAction(this);
			break;

		case MOVE:
			pAct = new MoveFigureAction(this);
			break;

		case UNDO:
			break;

		case REDO:
			break;

		case STRT:
			pAct = new StartRecording(this);
			break;

		case STOP:
			pAct = new StopRecording(this);
			break;

		case PLY_RECORD:
			pAct = new PlayRecording(this);
			break;

		case SAVE:
			pAct = new SaveAction(this);
			break;

		case LOAD:
			pAct = new LoadAction(this);
			break;

		case EXIT:
			pAct = new ExitAction(this);
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		bool DltAct = pAct->Execute(IsRecording);//Execute
		if (DltAct)
			delete pAct;
		else if (RecordingCount < 20)
			LastAction = pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;
}

////////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::GetFigCount() const
{ return FigCount; }
////////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::GetCopiedFigCount() const
{ return CopiedFigCount; }
////////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::GetFigTypeCount(TYPE t) const
{ 
	int i = 0;
	int num = 0;
	while (FigList[i] != NULL)
	{
		if (FigList[i]->GetType() == t)
		{
			num++;
		}
		i++;
	}
	return num;
}
////////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::GetFigFillColorCount(bool FilledOnly, color C) const
{
	int i = 0;
	int num = 0;
	while (FigList[i] != NULL)
	{
		if (FilledOnly == false)
		{
			if (FigList[i]->IsFilled())
				if (FigList[i]->GetFillColor() == C)
					num++;
		}
		else if (FilledOnly == true)
			if (FigList[i]->IsFilled())
				num++;
		i++;
	}
	return num;
}
////////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::GetFigTypeFillCount(TYPE t, color C) const
{
	int i = 0;
	int num = 0;
	while (FigList[i] != NULL)
	{
		if (FigList[i]->IsFilled())
			if (FigList[i]->GetType() == t && FigList[i]->GetFillColor() == C)
				num++;
		i++;
	}
	return num;
}
////////////////////////////////////////////////////////////////////////////////////
void  ApplicationManager::SetSelectedFigure(CFigure* pFig)
{
	SelectedFig = pFig;
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::DeleteFig(int id, GUI_MODE mode)
{
	int index;

	for(int i = 0; i < FigCount; i++)
	{
		if(FigList[i]->GetID() == id)
		{

			if (mode == MODE_PLAY)
				FigList[i] = NULL;
			else
				delete FigList[i];

			index = i;
			break;
		}
	}

	for(int i = index; i < FigCount - 1; i++)
		FigList[i] = FigList[i+1];

	FigList[FigCount - 1] = NULL;
	FigCount--;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	for(int i=FigCount-1; i >= 0; i--)
	{
		if(FigList[i]->IsSelected(x,y) == true)
		{
			return FigList[i];
		}
	}

	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigByIndex(int i) const
{ return FigList[i];}
////////////////////////////////////////////////////////////////////////////////////
CFigure * ApplicationManager::GetPrevSelectFigure() const
{
	for(int i=0; i < FigCount; i++)
	{
		if(FigList[i]->GetSelected() == true)
		{
			return FigList[i];
		}
	}

	return NULL;
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::deleteAllFigures()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	FigCount = 0;
}
//==================================================================================//
//								Play Mode Functions									//
//==================================================================================//
void ApplicationManager::ExchangeList(bool PlayModeOn)
{
	if (PlayModeOn)
	{
		CopiedFigList = new CFigure*[FigCount];

		for(int i=0; i<FigCount; i++)
			CopiedFigList[i] = FigList[i];

		CopiedFigCount = FigCount;
	}
	else // PlayModeOff
	{
		FigCount = CopiedFigCount;
		for(int i = 0; i < CopiedFigCount; i++)
			FigList[i] = CopiedFigList[i];

		CopiedFigCount = 0;
		if (CopiedFigList != NULL)
			delete[] CopiedFigList;
		CopiedFigList = NULL;
	}
}

void ApplicationManager::SaveAll(ofstream& SavedGraph)
{
	for (int i = 0; i < FigCount; i++)
		if (FigList[i] != NULL)
		{
			FigList[i]->Save(SavedGraph, pOut);
		}
}

void ApplicationManager::LoadAll(CFigure* NewFigs, ifstream& LoadedGraph)
{
	NewFigs->Load(LoadedGraph, pOut);
	AddFigure(NewFigs);
}

void ApplicationManager::setneedtodraw()
{
	needtodraw = false;
}

void ApplicationManager::setFigCount(int n)
{
	FigCount = n;
}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	if (CopiedFigList != NULL)
	{
		for(int i=0; i<FigCount; i++)
			delete CopiedFigList[i];

		delete[] CopiedFigList;
	} 
	else
	{
		for(int i=0; i<FigCount; i++)
			delete FigList[i];
	}
	CopiedFigList = NULL;

	if (RecordingCount != 0)
		for(int i=0; i<RecordingCount; i++)
			delete RecordingList[i];

	delete pIn;
	delete pOut;
	
}
