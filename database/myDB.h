﻿// myDB.h : CmyDB 선언

#pragma once
#include "resource.h"       // 주 기호입니다.



#include "database_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "단일 스레드 COM 개체는 전체 DCOM 지원을 포함하지 않는 Windows Mobile 플랫폼과 같은 Windows CE 플랫폼에서 제대로 지원되지 않습니다. ATL이 단일 스레드 COM 개체의 생성을 지원하고 단일 스레드 COM 개체 구현을 사용할 수 있도록 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA를 정의하십시오. rgs 파일의 스레딩 모델은 DCOM Windows CE가 아닌 플랫폼에서 지원되는 유일한 스레딩 모델이므로 'Free'로 설정되어 있습니다."
#endif

using namespace ATL;


// CmyDB

class ATL_NO_VTABLE CmyDB :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CmyDB, &CLSID_myDB>,
	public IDispatchImpl<ImyDB, &IID_ImyDB, &LIBID_databaseLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CmyDB()
	{
	}

	~CmyDB()
	{

	}

DECLARE_REGISTRY_RESOURCEID(106)


BEGIN_COM_MAP(CmyDB)
	COM_INTERFACE_ENTRY(ImyDB)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



	STDMETHOD(execQuery)(BSTR query, LONG option, VARIANT_BOOL* retval);
	STDMETHOD(nextObj)(VARIANT_BOOL* retval);
	STDMETHOD(getResultString)(BSTR* retval);
	STDMETHOD(getResult)(LONG nSubItem, BSTR* retval);
	STDMETHOD(clearResult)();
	STDMETHOD(connectDB)(BSTR server, BSTR db, BSTR id, BSTR pw, VARIANT_BOOL* retval);
	STDMETHOD(exitDB)();
};

OBJECT_ENTRY_AUTO(__uuidof(myDB), CmyDB)
