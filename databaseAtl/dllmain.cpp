// dllmain.cpp : DllMain의 구현입니다.

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "databaseAtl_i.h"
#include "dllmain.h"

CdatabaseAtlModule _AtlModule;

class CdatabaseAtlApp : public CWinApp
{
public:

// 재정의입니다.
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CdatabaseAtlApp, CWinApp)
END_MESSAGE_MAP()

CdatabaseAtlApp theApp;

BOOL CdatabaseAtlApp::InitInstance()
{
	return CWinApp::InitInstance();
}

int CdatabaseAtlApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
