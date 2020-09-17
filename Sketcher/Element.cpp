// Element.cpp : implementation file
//

#include "pch.h"
#include "Sketcher.h"
#include "Element.h"


// CElement

CElement::CElement()
{
}

CElement::CElement(const CPoint& start, COLORREF color, int penWidth):
	m_StartPoint{ start }, m_PenWidth{ penWidth },m_Color{color}{}

void CElement::CreatePen(CPen& aPen)
{
		if (!aPen.CreatePen(PS_SOLID, m_PenWidth, m_Color))
		{
			//Pen creation failed
			AfxMessageBox(_T("Pen creation failed."), MB_OK);
			AfxAbort();
		}
}

CElement::~CElement()
{
}

void CElement::Draw(CDC* pDC)
{
}

const CRect& CElement::GetEnclosingRect() const
{
	return m_EnclosingRect;
}


// CElement member functions

