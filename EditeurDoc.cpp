
// EditeurDoc.cpp : implémentation de la classe CEditeurDoc
//

#include "stdafx.h"
#include "Editeur.h"

#include "EditeurDoc.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEditeurDoc

IMPLEMENT_DYNCREATE(CEditeurDoc, CRichEditDoc)

BEGIN_MESSAGE_MAP(CEditeurDoc, CRichEditDoc)
	// Active l'implémentation par défaut du conteneur OLE
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, &CRichEditDoc::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, &CRichEditDoc::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, &CRichEditDoc::OnUpdateObjectVerbMenu)
END_MESSAGE_MAP()


// construction ou destruction de CEditeurDoc

CEditeurDoc::CEditeurDoc()
{
	// Utilise les fichiers composés OLE
	EnableCompoundFile();

	// TODO : ajoutez ici le code d'une construction unique

}

CEditeurDoc::~CEditeurDoc()
{
}

BOOL CEditeurDoc::OnNewDocument()
{
	if (!CRichEditDoc::OnNewDocument())
		return FALSE;

	// TODO : ajoutez ici le code de réinitialisation
	// (les documents SDI réutiliseront ce document)

	return TRUE;
}

CRichEditCntrItem* CEditeurDoc::CreateClientItem(REOBJECT* preo) const
{
	return new CEditeurCntrItem(preo, const_cast<CEditeurDoc*>(this));
}




// sérialisation de CEditeurDoc

void CEditeurDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO : ajoutez ici le code de stockage
	}
	else
	{
		// TODO : ajoutez ici le code de chargement
	}

	// L'appel de la classe de base CRichEditDoc active la sérialisation
	//  des objets COleClientItem du document conteneur.
	// TODO : définissez CRichEditDoc::m_bRTF = FALSE si la sérialisation est effectuée en mode texte
	CRichEditDoc::Serialize(ar);
	// activer le premier
	if (!ar.IsStoring())
	{
		POSITION posItem = GetStartPosition();
		if (posItem != NULL)
		{
			CDocItem* pItem = GetNextItem(posItem);
			POSITION posView = GetFirstViewPosition();
			COleDocObjectItem *pDocObjectItem = DYNAMIC_DOWNCAST(COleDocObjectItem, pItem);
			if (posView != NULL && pDocObjectItem != NULL)
			{
				CView* pView = GetNextView(posView);
				pDocObjectItem->DoVerb(OLEIVERB_SHOW, pView);
			}
		}
	}
}


// diagnostics pour CEditeurDoc

#ifdef _DEBUG
void CEditeurDoc::AssertValid() const
{
	CRichEditDoc::AssertValid();
}

void CEditeurDoc::Dump(CDumpContext& dc) const
{
	CRichEditDoc::Dump(dc);
}
#endif //_DEBUG


// commandes pour CEditeurDoc
