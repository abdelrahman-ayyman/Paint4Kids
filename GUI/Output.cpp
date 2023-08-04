#include "Output.h"
#include <cmath>

Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 62;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.FillShapes = false;  //Fill the drawn shapes or not
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;
	Point toolbarP1 = {0, 0};
	Point toolbarP2 = {UI.width, UI.ToolBarHeight};
	GfxInfo gfxInfo;

	gfxInfo.BorderWdth = 0;
	gfxInfo.DrawClr = WHITE;	//any color for border
	gfxInfo.FillClr = WHITE;	//any color for filling
	gfxInfo.isFilled = true;

	DrawRect(toolbarP1, toolbarP2, gfxInfo, false);

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\Play_mode.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_SQR] = "images\\MenuItems\\Menu_Squ.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_Tria.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\Menu_Hexa.jpg";
	MenuItemImages[ITM_CRCL] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_SLCT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_COLOR] = "images\\MenuItems\\Menu_Color.jpg";
	MenuItemImages[ITM_FILL] = "images\\MenuItems\\Menu_Fill.jpg";
	MenuItemImages[ITM_DLT] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\Menu_Move.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\Menu_Undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\Menu_Redo.jpg";   
	MenuItemImages[ITM_CLR] = "images\\MenuItems\\Menu_Clear.jpg";
	MenuItemImages[ITM_STRT] = "images\\MenuItems\\Menu_Record.jpg";
	MenuItemImages[ITM_STP] = "images\\MenuItems\\Menu_Stop.jpg";
	MenuItemImages[ITM_PLY_REC] = "images\\MenuItems\\Menu_Play.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_Upload.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	Point toolbarP1 = {0, 0};
	Point toolbarP2 = {UI.width, UI.ToolBarHeight};
	GfxInfo gfxInfo;

	gfxInfo.BorderWdth = 0;
	gfxInfo.DrawClr = WHITE;	//any color for border
	gfxInfo.FillClr = WHITE;	//any color for filling
	gfxInfo.isFilled = true;

	DrawRect(toolbarP1, toolbarP2, gfxInfo, false);
	///TODO: write code to create Play mode menu

	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_PCK_COLOR] = "images\\MenuItems\\Pick_Color.jpg";
	MenuItemImages[ITM_PCK_TYPE] = "images\\MenuItems\\Pick_Type.jpg";
	MenuItemImages[ITM_PCK_TYPE_COLOR] = "images\\MenuItems\\Pick_Type_Color.jpg";
	MenuItemImages[ITM_DRW] = "images\\MenuItems\\Draw_mode.jpg";
	MenuItemImages[ITM_EXT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateColorPalette(bool noFill) const
{
	UI.InterfaceMode = COLOR_PALETTE;
	Point toolbarP1 = {0, 0};
	Point toolbarP2 = {UI.width, UI.ToolBarHeight};
	GfxInfo gfxInfo;

	gfxInfo.BorderWdth = 0;
	gfxInfo.DrawClr = WHITE;	//any color for border
	gfxInfo.FillClr = WHITE;	//any color for filling
	gfxInfo.isFilled = true;

	//Switch to the color pallete
	DrawRect(toolbarP1, toolbarP2, gfxInfo, false);

	///TODO: write code to create Play mode menu

	string MenuItemImages[COLOR_ITM_COUNT];
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\Black_Color.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\Yellow_Color.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\Orange_Color.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Red_Color.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Green_Color.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Blue_Color.jpg";
	MenuItemImages[ITM_NOFILL] = "images\\MenuItems\\No_Fill.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	int count = COLOR_ITM_COUNT;
	if (!noFill)
	{
		count--;
	}

	//Draw menu item one image at a time
	for(int i=0; i<count; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::setCrntDrawColor(const color Color)	//get current drawing color
{	UI.DrawColor = Color;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
void Output::setCrntFillColor(const color Color)	//get current drawing color
{	UI.FillColor = Color;	}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::setFilled(bool val)	//set the deafult to fill the shapes or not
{
	UI.FillShapes = val;
}
//////////////////////////////////////////////////////////////////////////////////////////

bool Output::isFilled() const		//get the deafult of fill
{
	return UI.FillShapes;
}

//////////////////////////////////////////////////////////////////////////////////////////
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}
//////////////////////////////////////////////////////////////////////////////////////////
/*
GUI_MODE Output::getCrntMode()
{ return UI.InterfaceMode;}
*/
//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}



void Output::DrawSquare(Point P1, GfxInfo RectGfxInfo, bool selected ) const
{

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	Point PSquare1;
	Point PSquare2;

	PSquare1.x = P1.x - 50;
	PSquare1.y = P1.y - 50;
	PSquare2.x = P1.x + 50;
	PSquare2.y = P1.y + 50;


	pWind->DrawRectangle(PSquare1.x, PSquare1.y, PSquare2.x, PSquare2.y, style);



}

void Output::DrawHexa(Point P1, GfxInfo HexaGfxInfo, bool selected) const
{
	color DrawingClr;
	int size = 60;

	int Xs[6] = {P1.x - size, P1.x - size*0.5, P1.x + size*0.5, P1.x + size, P1.x + size*0.5, P1.x - size*0.5},
		Ys[6] = {P1.y, P1.y - size*(sqrt(3)/2.0), P1.y - size*(sqrt(3)/2.0), P1.y, P1.y + size*(sqrt(3)/2.0), P1.y + size*(sqrt(3)/2.0)};
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = HexaGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (HexaGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(HexaGfxInfo.FillClr);
	}
	else	
		style = FRAME;
	
	pWind->DrawPolygon(Xs, Ys, 6, style);
	
}

void Output::DrawCirc(Point P1, Point P2, GfxInfo CircleGfxInfo, bool selected)const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = CircleGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (CircleGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(CircleGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	double radius;
	radius= sqrt(pow(P1.x-P2.x,2)+pow(P1.y-P2.y,2));

	radius=(int)radius;
	pWind->DrawCircle(P1.x, P1.y,  radius, style);

}


void Output::DrawTri(Point P1, Point P2,Point P3, GfxInfo CircleGfxInfo, bool selected)const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = CircleGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (CircleGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(CircleGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x,P2.y,P3.x,P3.y, style);
}


string Output::getColorText(color type)
{
	if (type == BLACK)
	{
		return "BLACK";
	}
	else if (type == YELLOW)
	{
		return "YELLOW";
	}
	else if (type == ORANGE)
	{
		return "ORANGE";
	}
	else if (type == RED)
	{
		return "RED";
	}
	else if (type == GREEN)
	{
		return "GREEN";
	}
	else if (type == BLUE)
	{
		return "BLUE";
	}
	else
	{
		return "Unknown Color";
	}
}

void Output::setCrntDrawColor(string colorname) const
{
	if (colorname == "BLACK")
	{
		UI.DrawColor = BLACK;
	}
	else if (colorname == "YELLOW")
	{
		UI.DrawColor = YELLOW;
	}
	else if (colorname == "ORANGE")
	{
		UI.DrawColor = ORANGE;
	}
	else if (colorname == "RED")
	{
		UI.DrawColor = RED;
	}
	else if (colorname == "GREEN")
	{
		UI.DrawColor = GREEN;
	}
	else if (colorname == "BLUE")
	{
		UI.DrawColor = BLUE;
	}

}

void Output::setCrntFillColor(string colorname) const
{
	if (colorname == "BLACK")
	{
		UI.FillColor = BLACK;
	}
	else if (colorname == "YELLOW")
	{
		UI.FillColor = YELLOW;
	}
	else if (colorname == "ORANGE")
	{
		UI.FillColor = ORANGE;
	}
	else if (colorname == "RED")
	{
		UI.FillColor = RED;
	}
	else if (colorname == "GREEN")
	{
		UI.FillColor = GREEN;
	}
	else if (colorname == "BLUE")
	{
		UI.FillColor = BLUE;
	}

}

color Output::getColortype(string colorname)
{
	if (colorname == "BLACK")
	{
		return BLACK;
	}
	else if (colorname == "YELLOW")
	{
		return YELLOW;
	}
	else if (colorname == "ORANGE")
	{
		return ORANGE;
	}
	else if (colorname == "RED")
	{
		return RED;
	}
	else if (colorname == "GREEN")
	{
		return GREEN;
	}
	else if (colorname == "BLUE")
	{
		return BLUE;
	}

}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

