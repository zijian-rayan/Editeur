
// CntrItem.h : interface de la classe CEditeurCntrItem
//

#pragma once

class CEditeurDoc;
class CEditeurView;

class CEditeurCntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CEditeurCntrItem)

// Constructeurs
public:
	CEditeurCntrItem(REOBJECT* preo = NULL, CEditeurDoc* pContainer = NULL);
		// Remarque : pContainer peut avoir la valeur NULL pour activer IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE requiert que la classe possède un constructeur
		//  dépourvu d'arguments. En principe, les éléments OLE sont construits avec un
		//  pointeur de document non NULL

// Attributs
public:
	CEditeurDoc* GetDocument()
		{ return reinterpret_cast<CEditeurDoc*>(CRichEditCntrItem::GetDocument()); }
	CEditeurView* GetActiveView()
		{ return reinterpret_cast<CEditeurView*>(CRichEditCntrItem::GetActiveView()); }

// Implémentation
public:
	~CEditeurCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

