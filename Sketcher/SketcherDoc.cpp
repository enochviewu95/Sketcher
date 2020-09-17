
// SketcherDoc.cpp : implementation of the CSketcherDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Sketcher.h"
#endif

#include "SketcherDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSketcherDoc

IMPLEMENT_DYNCREATE(CSketcherDoc, CDocument)

BEGIN_MESSAGE_MAP(CSketcherDoc, CDocument)
	ON_COMMAND(ID_COLOR_BLACK, &CSketcherDoc::OnColorBlack)
	ON_COMMAND(ID_COLOR_RED, &CSketcherDoc::OnColorRed)
	ON_COMMAND(ID_COLOR_GREEN, &CSketcherDoc::OnColorGreen)
	ON_COMMAND(ID_COLOR_BLUE, &CSketcherDoc::OnColorBlue)
	ON_COMMAND(ID_ELEMENT_LINE, &CSketcherDoc::OnElementLine)
	ON_COMMAND(ID_ELEMENT_RECTANGLE, &CSketcherDoc::OnElementRectangle)
	ON_COMMAND(ID_ELEMENT_CIRCLE, &CSketcherDoc::OnElementCircle)
	ON_COMMAND(ID_ELEMENT_CURVE, &CSketcherDoc::OnElementCurve)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLACK, &CSketcherDoc::OnUpdateColorBlack)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CSketcherDoc::OnUpdateColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, &CSketcherDoc::OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, &CSketcherDoc::OnUpdateColorBlue)
	ON_UPDATE_COMMAND_UI(ID_ELEMENT_LINE, &CSketcherDoc::OnUpdateElementLine)
	ON_UPDATE_COMMAND_UI(ID_ELEMENT_RECTANGLE, &CSketcherDoc::OnUpdateElementRectangle)
	ON_UPDATE_COMMAND_UI(ID_ELEMENT_CIRCLE, &CSketcherDoc::OnUpdateElementCircle)
	ON_UPDATE_COMMAND_UI(ID_ELEMENT_CURVE, &CSketcherDoc::OnUpdateElementCurve)
	ON_COMMAND(ID_ELEMENT_ELLIPSE, &CSketcherDoc::OnElementEllipse)
	ON_UPDATE_COMMAND_UI(ID_ELEMENT_ELLIPSE, &CSketcherDoc::OnUpdateElementEllipse)
END_MESSAGE_MAP()


// CSketcherDoc construction/destruction

CSketcherDoc::CSketcherDoc() noexcept
{
	// TODO: add one-time construction code here

}

CSketcherDoc::~CSketcherDoc()
{
}

BOOL CSketcherDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CSketcherDoc serialization

void CSketcherDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CSketcherDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CSketcherDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CSketcherDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CSketcherDoc diagnostics

#ifdef _DEBUG
void CSketcherDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSketcherDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSketcherDoc commands


void CSketcherDoc::OnColorBlack()
{
	m_Color = ElementColor::BLACK;			//set the drawing color to black
}


void CSketcherDoc::OnColorRed()
{
	m_Color = ElementColor::RED;			//set the drawing color to red
}


void CSketcherDoc::OnColorGreen()
{
	m_Color = ElementColor::GREEN;			//set the drawing color to green
}


void CSketcherDoc::OnColorBlue()
{
	m_Color = ElementColor::BLUE;			//set the drawing color to blue
}


void CSketcherDoc::OnElementLine()
{
	m_Element = ElementType::LINE;			//Set the drawing type as line
}


void CSketcherDoc::OnElementRectangle()
{
	m_Element = ElementType::RECTANGLE;			//Set the drawing type as rectangle
}


void CSketcherDoc::OnElementCircle()
{
	m_Element = ElementType::CIRCLE;			//Set the drawing type as circle
}


void CSketcherDoc::OnElementCurve()
{
	m_Element = ElementType::CURVE;			//Set the drawing type as curve
}


void CSketcherDoc::OnElementEllipse()
{
	m_Element = ElementType::ELLIPSE;		//Set the drawing type as ellipse
}

ElementType CSketcherDoc::GetElementType() const
{
	// TODO: Add your implementation code here.
	return m_Element;
}


ElementColor CSketcherDoc::GetElementColor() const
{
	// TODO: Add your implementation code here.
	return m_Color;
}



void CSketcherDoc::OnUpdateColorBlack(CCmdUI* pCmdUI)
{
	//Set menu item checked if the current color is black
	pCmdUI->SetCheck(m_Color == ElementColor::BLACK);
}


void CSketcherDoc::OnUpdateColorRed(CCmdUI* pCmdUI)
{
	//Set menu item checked if the current color is red
	pCmdUI->SetCheck(m_Color == ElementColor::RED);
}


void CSketcherDoc::OnUpdateColorGreen(CCmdUI* pCmdUI)
{
	//Set menu item checked if the current color is green
	pCmdUI->SetCheck(m_Color == ElementColor::GREEN);
}


void CSketcherDoc::OnUpdateColorBlue(CCmdUI* pCmdUI)
{
	//Set menu item checked if the current color is blue
	pCmdUI->SetCheck(m_Color == ElementColor::BLUE);
}


void CSketcherDoc::OnUpdateElementLine(CCmdUI* pCmdUI)
{
	//Set checked if the current element is a line
	pCmdUI->SetCheck(m_Element == ElementType::LINE);
}


void CSketcherDoc::OnUpdateElementRectangle(CCmdUI* pCmdUI)
{
	//Set checked if the current element is a rectangle
	pCmdUI->SetCheck(m_Element == ElementType::RECTANGLE);
}


void CSketcherDoc::OnUpdateElementCircle(CCmdUI* pCmdUI)
{
	//Set checked if the current element is a circle
	pCmdUI->SetCheck(m_Element == ElementType::CIRCLE);
}


void CSketcherDoc::OnUpdateElementCurve(CCmdUI* pCmdUI)
{
	//Set checked if the current element is a curve
	pCmdUI->SetCheck(m_Element == ElementType::CURVE);
}





void CSketcherDoc::OnUpdateElementEllipse(CCmdUI* pCmdUI)
{
	//Set checked if the current element is an ellipse
	pCmdUI->SetCheck(m_Element == ElementType::ELLIPSE);
}


// Add a sketch element
void CSketcherDoc::AddElement(std::shared_ptr<CElement>& pElement)
{
	m_Sketch.push_back(pElement);
}


// Delete a sketch element
void CSketcherDoc::DeleteElement(std::shared_ptr<CElement>& pElement)
{
	m_Sketch.remove(pElement);
}


// Provide a begin iterator for the sketch
SketchIterator CSketcherDoc::begin() const
{
	return std::begin(m_Sketch);
}


SketchIterator CSketcherDoc::end() const
{
	return std::end(m_Sketch);
}
