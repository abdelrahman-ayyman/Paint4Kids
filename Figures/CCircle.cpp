#include "CCircle.h"

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P1;
	EndPoint = P2;

	Radius = sqrt(float(pow(Center.x-EndPoint.x,2)+pow(Center.y-EndPoint.y,2)));
}

CCircle::CCircle() {}

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawCirc(Center, EndPoint, FigGfxInfo, Selected);
}

bool CCircle::IsSelected(int x,int y) 
 {
	 if(sqrt(float(pow(Center.x-x,2)+pow(Center.y-y,2))) <= Radius)
	 {
		return true;
	 }
	 else
	 {
		return false;
	 }
}

TYPE CCircle::GetType()
{ return CIRCLE;}

void CCircle::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("ID. " + to_string(ID) + " | center (" + to_string(Center.x) + ", " + to_string(Center.y) + ")" + " | radius: " + to_string(Radius));
}


void CCircle::Save(ofstream& SavedGraph, Output* pOut)
{
	SavedGraph << "CIRC" << "\t";
	SavedGraph << ID << "\t";
	SavedGraph << Center.x << "\t";
	SavedGraph << Center.y << "\t";
	SavedGraph << EndPoint.x << "\t";
	SavedGraph << EndPoint.y << "\t";
	SavedGraph << pOut->getColorText(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled)
	{
		SavedGraph << pOut->getColorText(FigGfxInfo.FillClr) << endl;
	}
	else
	{
		SavedGraph << "NO_FILL" << endl;
	}
}

void CCircle::Load(ifstream& LoadedGraph, Output* pOut)
{
	string DrawColor;
	string FillColor;
	LoadedGraph >> ID >> Center.x >> Center.y >> EndPoint.x >> EndPoint.y >> DrawColor >> FillColor;
	color newcolortype = pOut->getColortype(DrawColor);
	FigGfxInfo.DrawClr = newcolortype;
	Radius = sqrt(float(pow(Center.x - EndPoint.x, 2) + pow(Center.y - EndPoint.y, 2)));

	if (FillColor != "NO_FILL")
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = pOut->getColortype(FillColor);
	}
	else
	{
		FigGfxInfo.isFilled = false;
	}
}

void CCircle::Move(Point moveto)
{
	int xdiff = abs(EndPoint.x - Center.x);
	int ydiff = abs(EndPoint.y - Center.y);
	Center.x = moveto.x;
	Center.y = moveto.y;
	EndPoint.x = moveto.x + xdiff;
	EndPoint.y = moveto.y + ydiff;

}