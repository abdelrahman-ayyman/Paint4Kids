#include "Action.h"

//Add Square Action class
class AddSquareAction: public Action
{
private:
	Point P1; //Square Center
	GfxInfo SquareGfxInfo;
public:
	AddSquareAction(ApplicationManager *pApp);

	//Reads Square parameters
	virtual void ReadActionParameters();
	
	//Add Square to the ApplicationManager
	virtual void Execute() ;

	virtual bool Execute(bool IsRecording);
	
};