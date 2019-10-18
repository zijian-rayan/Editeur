
// Editeur.h�: fichier d'en-t�te principal pour l'application Editeur
//
#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'stdafx.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"       // symboles principaux


// CEditeurApp:
// Consultez Editeur.cpp pour l'impl�mentation de cette classe
//

class CEditeurApp : public CWinAppEx
{
public:
	CEditeurApp();


// Substitutions
public:
	virtual BOOL InitInstance();

// Impl�mentation
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CEditeurApp theApp;
