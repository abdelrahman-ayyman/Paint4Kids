#pragma once
#include "Action.h"

class LoadAction : public Action
{

	string nameoutput;

public:

	LoadAction(ApplicationManager* pApp);

	void ReadActionParameters();

	void Execute();
	~LoadAction();


};
