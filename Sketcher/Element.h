#pragma once

// CElement command target

class CElement : public CObject
{
protected:
	CPoint m_StartPoint;			//Element position
	int m_PenWidth;					//Pen width
	COLORREF m_Color;				//Color of an element
	CRect m_EnclosingRect;			//Rectangle enclosing an element

public:
	virtual ~CElement();
	virtual void Draw(CDC* pDC); ///virtual draw operation

	//Get the element enclosing rectangle
	const CRect& GetEnclosingRect() const;

protected:
	//Constructors protected so they cannot be called outside the class
	CElement();
	CElement(const CPoint& start, COLORREF color, int penWidth = 1);
	void CreatePen(CPen& aPen);
};


