
// CntrItem.cpp : implémentation de la classe CEditeurCntrItem
//

#include "stdafx.h"
#include "Editeur.h"

#include "EditeurDoc.h"
#include "EditeurView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// implémentation de CEditeurCntrItem

IMPLEMENT_SERIAL(CEditeurCntrItem, CRichEditCntrItem, 0)

CEditeurCntrItem::CEditeurCntrItem(REOBJECT* preo, CEditeurDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO : ajoutez ici le code d'une construction unique
}

CEditeurCntrItem::~CEditeurCntrItem()
{
	// TODO : ajoutez ici le code de nettoyage
}


// diagnostics pour CEditeurCntrItem

#ifdef _DEBUG
void CEditeurCntrItem::AssertValid() const
{
	CRichEditCntrItem::AssertValid();
}

void CEditeurCntrItem::Dump(CDumpContext& dc) const
{
	CRichEditCntrItem::Dump(dc);
}
#endif

