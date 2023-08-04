#include "CSquare.h"

CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P1;
}
	
CSquare::CSquare()
{}

void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSquare to draw a square on the screen	
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}

bool  CSquare::IsSelected(int x,int y) 
 {
	 double L1=fabs(float(x-Center.x));
	 double L3=fabs(float(y-Center.y));
 
	 if(L1<=50  && L3<=50)
	 {
		return true;
	 }
	 else
	 {
		return false;
	 }
 }

TYPE CSquare::GetType()
{ return SQUARE;}

 void CSquare::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("ID. " + to_string(ID) + " | Center (" + to_string(Center.x) + ", " + to_string(Center.y) + ")" + " | Length: 50");
}
 void CSquare::Save(ofstream& SavedGraph, Output* pOut)
 {
	 SavedGraph << "SQUR" << "\t";
	 SavedGraph << ID << "\t";
	 SavedGraph << Center.x << "\t";
	 SavedGraph << Center.y << "\t";
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
 void CSquare::Load(ifstream& LoadedGraph, Output* pOut)
 {
	 string DrawColor;
	 string FillColor;
	 LoadedGraph >> ID >> Center.x >> Center.y >> DrawColor >> FillColor;
	 FigGfxInfo.DrawClr = pOut->getColortype(DrawColor);
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

 void CSquare::Move(Point moveto)
 {
	 Center.x = moveto.x;
	 Center.y = moveto.y;

 }