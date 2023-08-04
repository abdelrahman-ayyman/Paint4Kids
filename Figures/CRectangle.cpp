#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;

	width = abs(Corner1.x-Corner2.x);
	length = abs((Corner1.y-Corner2.y));

	if (width > length)
	{
		int tmp = width;
		width = length;
		length = tmp;
	}

}
	
CRectangle::CRectangle()
{}


void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

 bool  CRectangle::IsSelected(int x,int y) 
 {
	 //Sides
	 double L1=fabs(float(x-Corner1.x));
	 double L2=fabs(float(x-Corner2.x));
	 double L3=fabs(float(y-Corner1.y));
	 double L4=fabs(float(y-Corner2.y));

	 double width=fabs(float(Corner1.x-Corner2.x));
	 double lenght=fabs(float(Corner1.y-Corner2.y));

	 if(L1<=width && L2<=width && L3<=lenght && L4<=lenght)
	 {
		return true;
	 }
	 else
	 {
		return false;
	 }
 }

 TYPE CRectangle::GetType()
 { return RECTANGLE;}

  void CRectangle::PrintInfo(Output* pOut)
{
	pOut->PrintMessage(
		"ID. " + to_string(ID) + " | Start Point (" + to_string(Corner1.x) + ", " + to_string(Corner1.y) + ")" 
		+ " | End Point (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + ")" 
		+ " | Length: " + to_string(length) + " | Width: " + to_string(width)
		);
}
  
  void CRectangle::Save(ofstream& SavedGraph, Output* pOut)
  {
	  SavedGraph << "RECT" << "\t";
	  SavedGraph << ID << "\t";
	  SavedGraph << Corner1.x << "\t";
	  SavedGraph << Corner1.y << "\t";
	  SavedGraph << Corner2.x << "\t";
	  SavedGraph << Corner2.y << "\t";
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

  void CRectangle::Load(ifstream& LoadedGraph, Output* pOut)
  {
	  string DrawColor;
	  string FillColor;
	  LoadedGraph >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> DrawColor >> FillColor;
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
  void CRectangle::Move(Point moveto)
  {
	  int diffx = abs(Corner2.x - Corner1.x);
	  int diffy = abs(Corner2.y - Corner1.y);

	  Corner1.x = moveto.x - (diffx / 2);
	  Corner1.y = moveto.y - (diffy / 2);
	  Corner2.x = Corner1.x + diffx;
	  Corner2.y = Corner1.y + diffy;

  }
