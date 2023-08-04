#include "Action.h"

//Add Circle Action class
class AddCircleAction: public Action
{
private:
	Point P1, P2; //Circle Coordinates
	GfxInfo CircleGfxInfo;
public:
	AddCircleAction(ApplicationManager *pApp);

	//Reads Circle parameters
	virtual void ReadActionParameters();
	
	//Add Circle to the ApplicationManager
	virtual void Execute();
	
	virtual bool Execute(bool IsRecording);
};


