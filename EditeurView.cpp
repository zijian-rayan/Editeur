
// EditeurView.cpp : implémentation de la classe CEditeurView
//

#include "stdafx.h"
#include "Editeur.h"

#include "EditeurDoc.h"
#include "CntrItem.h"
#include "EditeurView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEditeurView

IMPLEMENT_DYNCREATE(CEditeurView, CRichEditView)

BEGIN_MESSAGE_MAP(CEditeurView, CRichEditView)
	ON_WM_DESTROY()
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// construction ou destruction de CEditeurView

CEditeurView::CEditeurView()
{
	// TODO : ajoutez ici du code de construction

}

CEditeurView::~CEditeurView()
{
}

BOOL CEditeurView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO : changez ici la classe ou les styles Window en modifiant
	//  CREATESTRUCT cs

	return CRichEditView::PreCreateWindow(cs);
}

void CEditeurView::OnInitialUpdate()
{
	CRichEditView::OnInitialUpdate();


	// Définir les marges d'impression (720 twips = 1/2 pouce)
	SetMargins(CRect(720, 720, 720, 720));
}

void CEditeurView::OnDestroy()
{
	// Désactiver l'élément en destruction ; cela est important
	// lorsqu'une vue fractionnée est utilisée
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
   CRichEditView::OnDestroy();
}


void CEditeurView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CEditeurView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// diagnostics pour CEditeurView

#ifdef _DEBUG
void CEditeurView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CEditeurView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CEditeurDoc* CEditeurView::GetDocument() const // la version non Debug est inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEditeurDoc)));
	return (CEditeurDoc*)m_pDocument;
}
#endif //_DEBUG


// gestionnaires de messages pour CEditeurView
