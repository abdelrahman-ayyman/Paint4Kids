#include "CFigure.h"

int CFigure::FigCreatedCount = 0;

CFigure::CFigure(GfxInfo FigureGfxInfo, bool SkipID)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;

	if (!SkipID)
	{
		FigCreatedCount++;
		ID = FigCreatedCount;
	}
}

CFigure::CFigure()
{}

int CFigure::GetID()
{return ID;}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::GetSelected()
{return Selected;}

bool CFigure::IsSelected(int x,int y) 
{	return Selected; }

bool CFigure::IsFilled()
{	return FigGfxInfo.isFilled; }


void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

void CFigure::UnFill()
{
	FigGfxInfo.isFilled = false;
}

void CFigure::ResetCounter()
{
	CFigure::FigCreatedCount = 0;
}

void CFigure::SetCounter(int current)
{
	CFigure::FigCreatedCount = current;
}

color CFigure::GetFillColor()
{ return FigGfxInfo.FillClr; }