#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	PICK_COLOR,
	PICK_TYPE,
	PICK_TYPE_COLOR,		//Draw Rectangle
	EXIT,			//Exit
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar

	///TODO: Add the other action types of the two modes
	DRAW_SQR,
	DRAW_TRI,
	DRAW_HEX,
	DRAW_CRCL,
	SELECT,
	CHNG_COLOR,
	FILL,
	DLTE,
	MOVE,
	UNDO,
	REDO,
	CLEAR,
	STRT,
	STOP,
	PLY_RECORD,
	SAVE,
	LOAD,

	//Color Palette
	BLACK_COLOR,
	YELLOW_COLOR,
	ORANGE_COLOR,
	RED_COLOR,
	GREEN_COLOR,
	BLUE_COLOR,
	NOFILL
};

enum TYPE {
	CIRCLE,
	SQUARE,
	TRIANGLE,
	RECTANGLE,
	HEXAGON
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif