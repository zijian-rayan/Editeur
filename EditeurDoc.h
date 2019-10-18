
// EditeurDoc.h : interface de la classe CEditeurDoc
//


#pragma once


class CEditeurDoc : public CRichEditDoc
{
protected: // cr�ation � partir de la s�rialisation uniquement
	CEditeurDoc();
	DECLARE_DYNCREATE(CEditeurDoc)

// Attributs
public:

// Op�rations
public:

// Substitutions
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual CRichEditCntrItem* CreateClientItem(REOBJECT* preo) const;

// Impl�mentation
public:
	virtual ~CEditeurDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Fonctions g�n�r�es de la table des messages
protected:
	DECLARE_MESSAGE_MAP()
};


