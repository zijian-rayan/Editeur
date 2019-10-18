
// EditeurView.h : interface de la classe CEditeurView
//


#pragma once

class CEditeurCntrItem;

class CEditeurView : public CRichEditView
{
protected: // création à partir de la sérialisation uniquement
	CEditeurView();
	DECLARE_DYNCREATE(CEditeurView)

// Attributs
public:
	CEditeurDoc* GetDocument() const;

// Opérations
public:

// Substitutions
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // premier appel après la construction

// Implémentation
public:
	virtual ~CEditeurView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Fonctions générées de la table des messages
protected:
	afx_msg void OnDestroy();
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // version de débogage dans EditeurView.cpp
inline CEditeurDoc* CEditeurView::GetDocument() const
   { return reinterpret_cast<CEditeurDoc*>(m_pDocument); }
#endif

