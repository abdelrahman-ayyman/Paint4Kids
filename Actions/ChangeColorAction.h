#pragma once
#include "action.h"
class ChangeColorAction :
	public Action
{
private:
	color DrawingColor;
	bool IsFilled;
	bool NoFill;
public:
	ChangeColorAction(ApplicationManager *pApp, bool fill = false);
	
	//Getting a drawing color
	virtual void ReadActionParameters(bool skip  = false);
	
	//Applying changes to the UI
	virtual void Execute();

	virtual bool Execute(bool IsRecording);

};

