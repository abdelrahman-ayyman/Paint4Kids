#pragma once
#include "Action.h"


class SaveAction : public Action
{
	string nameinput;
public:
	SaveAction(ApplicationManager* pman);
	void Execute();
	void ReadActionParameters();
	~SaveAction();

};

