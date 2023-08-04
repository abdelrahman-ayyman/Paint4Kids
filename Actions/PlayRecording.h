#pragma once
#include "Action.h"
class PlayRecording:public Action
{
public:
	PlayRecording(ApplicationManager * pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};