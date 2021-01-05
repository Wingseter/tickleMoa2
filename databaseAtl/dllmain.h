// dllmain.h : 모듈 클래스의 선언입니다.

class CdatabaseAtlModule : public ATL::CAtlDllModuleT< CdatabaseAtlModule >
{
public :
	DECLARE_LIBID(LIBID_databaseAtlLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DATABASEATL, "{47981f8f-7a46-4b6c-a396-baccf44802ac}")
};

extern class CdatabaseAtlModule _AtlModule;
