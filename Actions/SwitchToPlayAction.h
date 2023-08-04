#pragma once
#include "action.h"
class SwitchToPlayAction :
	public Action
{
private:
	GfxInfo ToolbarGfxInfo;
public:
	SwitchToPlayAction(ApplicationManager *pApp);
	
	//Switch to Play Mode
	virtual void Execute() ;
};

