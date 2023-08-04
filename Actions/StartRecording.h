#pragma once
#include "Action.h"
class StartRecording:public Action
{
public:
	StartRecording(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};