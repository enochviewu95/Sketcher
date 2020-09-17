#include "pch.h"
#include "Line.h"

CLine::~CLine()
{
}
//Draw a CLine object
void CLine::Draw(CDC* pDC)
{
	//Create a pen for this object and initialize it
	CPen aPen;
	CreatePen(aPen);

	CPen* pOldPen{ pDC->SelectObject(&aPen) };	//Select the pen

	//Now draw the line
	pDC->MoveTo(m_StartPoint);	
	pDC->LineTo(m_EndPoint);

	pDC->SelectObject(&pOldPen);			//Restore the old pen
}

CLine::CLine(const CPoint& start, const CPoint& end, COLORREF aColor):
	CElement{ start,aColor }, m_EndPoint{ end }
{
	//Define the enclosing rectangle
	m_EnclosingRect = CRect{ start,end };
	m_EnclosingRect.NormalizeRect();
	m_EnclosingRect.InflateRect(m_PenWidth, m_PenWidth);
}

CLine::CLine()
{
}
