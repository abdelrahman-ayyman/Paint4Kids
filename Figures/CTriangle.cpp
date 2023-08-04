#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo, bool SkipID):CFigure(FigureGfxInfo, SkipID)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}
CTriangle::CTriangle()
{}
	

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a triangle on the screen	
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}


bool CTriangle::IsSelected(int x,int y)
{

	float test1 = fabs(float(Corner2.x-Corner3.x));
	float test2 = fabs(float(Corner1.x-Corner3.x));
	float test3 = fabs(float(Corner2.x-Corner1.x));

	bool check1 = fabs(float(Corner1.x-Corner2.x))<=test1 && fabs(float(Corner1.x-Corner3.x))<=test1;
	bool check2 = fabs(float(Corner1.x-Corner2.x))<=test2 && fabs(float(Corner2.x-Corner3.x))<=test2;
	bool check3 = fabs(float(Corner3.x-Corner2.x))<=test3 && fabs(float(Corner1.x-Corner3.x))<=test3;

	Point middle;
	Point p1;
	Point p3;


	if(check1)
	{
		middle=Corner1;
		p1=Corner2;
		p3=Corner3;
	}
	else if(check2)
	{
		middle=Corner2;
		p1=Corner1;
		p3=Corner3;
	}
	else if(check3)
	{
		middle=Corner3;
		p1=Corner2;
		p3=Corner1;

	}

	float m1 = (float)(p1.y-middle.y)/(p1.x-middle.x);
	float m2 = (float)(p3.y-middle.y)/(p3.x-middle.x);
	float m3 = (float)(p3.y-p1.y)/(p3.x-p1.x);

	if((x<=p1.x && x>=p3.x)||(x<=p3.x && x>=p1.x))
	{

		if((x<=p1.x &&x>=middle.x)||(x<=middle.x &&x>=p1.x))
		{

			float diff1=fabs(float((m1*(x-p1.x)+p1.y)-(m3*(x-p1.x)+p1.y)));

			if(fabs(float(y-(m1*(x-p1.x)+p1.y)))<=diff1 &&fabs(float(y-(m3*(x-p1.x)+p1.y)))<=diff1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if((x<=middle.x &&x>=p3.x)||(x<=p3.x &&x>=middle.x))
		{

			float diff2=fabs(float((m2*(x-p3.x)+p3.y)-(m3*(x-p1.x)+p1.y))) ;

			if(fabs(float(y-(m2*(x-p3.x)+p3.y)))<=diff2 && fabs(float(y-(m3*(x-p1.x)+p1.y)))<=diff2)
			{
				return true;
			}
			else
			{
				return false;
			}
		} 
		else
		{
			return false;
		}

	}
	else
	{
		return false;
	}
}

TYPE CTriangle::GetType()
{ return TRIANGLE;}

 void CTriangle::PrintInfo(Output* pOut)
{
	pOut->PrintMessage(
		"ID. " + to_string(ID) + " | First Corner (" + to_string(Corner1.x) + ", " + to_string(Corner1.y) + ")" 
		+ " | Second Corner (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + ")" 
		+ " | Third Corner: " + to_string(Corner3.x) + ", " + to_string(Corner3.y) + ")"
		);
}

 
 void CTriangle::Save(ofstream& SavedGraph, Output* pOut)
 {
	 SavedGraph << "TRIA" << "\t";
	 SavedGraph << ID << "\t";
	 SavedGraph << Corner1.x << "\t";
	 SavedGraph << Corner1.y << "\t";
	 SavedGraph << Corner2.x << "\t";
	 SavedGraph << Corner2.y << "\t";
	 SavedGraph << Corner3.x << "\t";
	 SavedGraph << Corner3.y << "\t";
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

 void CTriangle::Load(ifstream& LoadedGraph, Output* pOut)
 {
	 string DrawColor;
	 string FillColor;
	 LoadedGraph >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y >> DrawColor >> FillColor;
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

 void CTriangle::Move(Point moveto)
 {
	 float centerx = (Corner1.x + Corner2.x + Corner3.x) / 3.0;
	 float centery = (Corner1.y + Corner2.y + Corner3.y) / 3.0;
	 float diffx1 = (Corner1.x - centerx);
	 float diffy1 = (Corner1.y - centery);
	 float diffx2 = (Corner2.x - centerx);
	 float diffy2 = (Corner2.y - centery);
	 float diffx3 = (Corner3.x - centerx);
	 float diffy3 = (Corner3.y - centery);



	 Corner1.x = moveto.x + diffx1;
	 Corner1.y = moveto.y + diffy1;
	 Corner2.x = moveto.x + diffx2;
	 Corner2.y = moveto.y + diffy2;
	 Corner3.x = moveto.x + diffx3;
	 Corner3.y = moveto.y + diffy3;

 }