
// EditeurDoc.h : interface de la classe CEditeurDoc
//


#pragma once


class CEditeurDoc : public CRichEditDoc
{
protected: // création à partir de la sérialisation uniquement
	CEditeurDoc();
	DECLARE_DYNCREATE(CEditeurDoc)

// Attributs
public:

// Opérations
public:

// Substitutions
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual CRichEditCntrItem* CreateClientItem(REOBJECT* preo) const;

// Implémentation
public:
	virtual ~CEditeurDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Fonctions générées de la table des messages
protected:
	DECLARE_MESSAGE_MAP()
};


