// dllmain.h : 모듈 클래스의 선언입니다.

class CdatabaseModule : public ATL::CAtlDllModuleT< CdatabaseModule >
{
public :
	DECLARE_LIBID(LIBID_databaseLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DATABASE, "{962ce875-0c26-41cb-8f6b-424a0dabbc0c}")
};

extern class CdatabaseModule _AtlModule;
