#pragma once
#include "action.h"
class SwitchToDrawAction :
	public Action
{
private:
	GfxInfo ToolbarGfxInfo;
public:
	SwitchToDrawAction(ApplicationManager *pApp);
	
	//Switch to Draw Mode
	virtual void Execute() ;
};

