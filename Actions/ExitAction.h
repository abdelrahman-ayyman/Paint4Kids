#pragma once
#include "../Actions/Action.h"

class ExitAction : public Action
{
	bool exitaction;
public:
	ExitAction(ApplicationManager* pApp);

	 void ReadActionParameters() ;

	void Execute();
	~ExitAction();

};

