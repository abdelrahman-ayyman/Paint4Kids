#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include"Actions/Action.h"
#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:

	Action* LastAction;
	Action* RecordingList[20];
	bool IsRecording;
	bool IsPlaying;
	int RecordingCount;
	bool needtodraw;


	int FigCount;		//Actual number of figures
	int CopiedFigCount;		//Actual number of copied figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure** CopiedFigList;	//Copied List of all figures [Play Mode Operations]
	CFigure* SelectedFig; //Pointer to the selected figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	ActionType GetUserActionByPoint(int x, int y) const;
	void ExecuteAction(ActionType); //Creates an action and executes it
	void SetSelectedFigure(CFigure* pFig);
	CFigure *GetPrevSelectFigure() const;
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	CFigure *GetFigByIndex(int index) const; //Search for a figure given an index inside the figure list
	void DeleteFig(int id, GUI_MODE mode = MODE_DRAW); //Delete the selected Figure
	
	// -- Recording Actions
	void AddAction(Action*last);
	Action* GetAction();
	void DeleteActionList();

	bool GetRecording();
	void SetRecording(bool b);
	bool GetPlayRecording();
	void SetPlayRecording(bool b);
	void LoopRecording();
	int GetRecordingCount();

	void SaveAll(ofstream& SavedGraph);
	void LoadAll(CFigure* NewFigs, ifstream& LoadedGraph);
	void setneedtodraw();
	void setFigCount(int n);



	// -- Copying the original figList
	void ApplicationManager::ExchangeList(bool PlayModeOn);

	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output

	int GetFigCount() const; //Return the number of figures
	int GetFigTypeCount(TYPE t) const;	// Return the number of figures of a specific type t
	int GetFigFillColorCount(bool FilledOnly = false, color C = WHITE) const;	//Return the number of figures of a specific color C
	int GetFigTypeFillCount(TYPE t, color C) const;	//Return the number of figures of a specific type t and color C
	int GetCopiedFigCount() const; //Return the number of figures of a specific type t and color C

	void UpdateInterface() const;	//Redraws all the drawing window
	void deleteAllFigures(); //Empty the FigList Array
};

#endif