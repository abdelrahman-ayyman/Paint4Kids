#pragma once
#include "action.h"

class ClearAllAction :
	public Action
{
private:
	bool deleteAction;
public:
	ClearAllAction(ApplicationManager *pApp);

	//Warns the user before clearing all the data
	virtual void ReadActionParameters();
	
	//Clear All the figures & recordings in the ApplicationManager
	virtual void Execute();

	virtual bool Execute(bool IsRecording);
};

