#include "CHexagon.h"
#include "CTriangle.h"

CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P1;
}
	
	CHexagon::CHexagon()
	{}

void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHex to draw a hexagon on the screen	
	pOut->DrawHexa(Center, FigGfxInfo, Selected);
}

bool  CHexagon::IsSelected(int x,int y) 
 {
	Point P1=Center;
	int size = 60;

	Point p1;
	p1.x=P1.x - size;
	p1.y=P1.y;

	Point p2;
	p2.x=P1.x - size*0.5;
	p2.y= P1.y - size*(sqrt(3)/2.0);

	Point p3;
	p3.x=P1.x + size*0.5;
	p3.y=P1.y - size*(sqrt(3)/2.0);

	Point p4;
	p4.x=P1.x + size;
	p4.y=P1.y;

	Point p5;
	p5.x=P1.x + size*0.5;
	p5.y=P1.y + size*(sqrt(3)/2.0);

	Point p6;
	p6.x=P1.x - size*0.5;
	p6.y=P1.y + size*(sqrt(3)/2.0);
 
 
	CFigure* part1 = new CTriangle(p1,p2,P1,FigGfxInfo, true);
	CFigure* part2 = new CTriangle(p2,p3,P1,FigGfxInfo, true);
	CFigure* part3 = new CTriangle(p3,p4,P1,FigGfxInfo, true);
	CFigure* part4 = new CTriangle(p4,p5,P1,FigGfxInfo, true);
	CFigure* part5 = new CTriangle(p5,p6,P1,FigGfxInfo, true);
	CFigure* part6 = new CTriangle(p6,p1,P1,FigGfxInfo, true);

	 if(
		 part1->IsSelected(x,y)
		 || part2->IsSelected(x,y)
		 || part3->IsSelected(x,y)
		 || part4->IsSelected(x,y)
		 || part5->IsSelected(x,y)
		 ||part6->IsSelected(x,y)
		 )
	 {
		return true;
	 }
	 else
	 {
		return false;
	 }
	 
	 delete part1;
	 delete part2;
	 delete part3;
	 delete part4;
	 delete part5;
	 delete part6;
 }

TYPE CHexagon::GetType()
{ return HEXAGON;}

 void CHexagon::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("ID. " + to_string(ID) + " | Center (" + to_string(Center.x) + ", " + to_string(Center.y) + ")" + " | Side Length: 60");
}

 void CHexagon::Save(ofstream& SavedGraph, Output* pOut)
 {
	 SavedGraph << "HEXA" << "\t";
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

 void CHexagon::Load(ifstream& LoadedGraph, Output* pOut)
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

 void CHexagon::Move(Point moveto)
 {
	 Center.x = moveto.x;
	 Center.y = moveto.y;

 }