#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <fstream>

//Base class for all figures
class CFigure
{
protected:
	static int FigCreatedCount;
	int ID;			//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo, bool SkipID = false);
	CFigure();

	void SetSelected(bool s);	//select/unselect the figure
	bool GetSelected();
	virtual bool IsSelected(int x,int y);	//check whether fig is selected
	bool CFigure::IsFilled();
	int GetID();

	color GetFillColor();
	virtual TYPE GetType() = 0;

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	void UnFill();					//Unfill the figure

	static void ResetCounter();
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	
	virtual void Save(ofstream &OutFile, Output * pOut) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile, Output* pOut) = 0;	//Load the figure parameters to the file
	static void SetCounter(int current);

	
	virtual void Move(Point moveto) = 0;


	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif