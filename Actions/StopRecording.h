#pragma once
#include "Action.h"
class StopRecording:public Action
{
public:
	StopRecording(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};