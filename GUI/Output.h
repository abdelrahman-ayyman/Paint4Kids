#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateColorPalette(bool noFill  = false) const; //creates Color Palette toolbar
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	void DrawSquare(Point P1, GfxInfo RectGfxInfo, bool selected = false) const; //Draw a Square
	void DrawHexa(Point P1, GfxInfo HexaGfxInfo, bool selected=false) const;  //Draw a Hexagon
	void DrawCirc(Point P1, Point P2, GfxInfo CircleGfxInfo, bool selected=false)const;
	void DrawTri(Point P1, Point P2,Point P3, GfxInfo CircleGfxInfo, bool selected=false)const;
	
	///Make similar functions for drawing all other figure types.
	
	void PrintMessage(string msg) const;	//Print a message on Status bar
	
	color getCrntDrawColor() const;	//get current drwawing color
	void setCrntDrawColor(const color);	//set current drwawing color
	color getCrntFillColor() const;	//get current filling color
	/*GUI_MODE getCrntMode*/
	void setFilled(bool val);	//set the deafult to fill the shapes or not
	bool isFilled() const;		//get the deafult of fill

	void setCrntFillColor(const color);	//set current drwawing color
	int getCrntPenWidth() const;		//get current pen width
	string getColorText(color type);
	color getColortype(string colorname);
	void setCrntDrawColor(string colorname) const;
	void setCrntFillColor(string colorname) const;
	
	~Output();
};

#endif