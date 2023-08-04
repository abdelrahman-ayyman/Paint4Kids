#include "Action.h"

//Add Hexagon Action class
class AddHexAction: public Action
{
private:
	Point P1; //Hexagon Center
	GfxInfo HexGfxInfo;
public:
	AddHexAction(ApplicationManager *pApp);

	//Reads hexagon parameters
	virtual void ReadActionParameters();
	
	//Add hexagon to the ApplicationManager
	virtual void Execute();
	
	virtual bool Execute(bool IsRecording);
	
};