// dllmain.cpp : DLL 애플리케이션의 진입점을 정의합니다.
#include "pch.h"
#include "database.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

// 래퍼 함수 정의

// 생성자
extern "C" __declspec(dllexport) dataBase * __cdecl CreateDatabase() {
    return new dataBase();
}

extern "C" __declspec(dllexport)
void __cdecl DeleteDatabase(dataBase * obj) {
    delete obj;
    obj = nullptr;
}

extern "C" __declspec(dllexport) BOOL __cdecl execQuery(dataBase * obj, LPSTR query, INT option) {
    return obj->execQuery(query, option);
}

extern "C" __declspec(dllexport) BOOL __cdecl nextObj(dataBase * obj) {
    return obj->nextObj();
}

extern "C" __declspec(dllexport) LPSTR __cdecl getResultString(dataBase * obj) {
    return obj->getResultString();
}

extern "C" __declspec(dllexport) LPSTR __cdecl getResult(dataBase * obj, INT nSubItem) {
    return obj->getResult(nSubItem);
}

extern "C" __declspec(dllexport) void __cdecl clearResult(dataBase * obj) {
    obj->clearResult();
}

extern "C" __declspec(dllexport) BOOL __cdecl connectDB(dataBase * obj, LPSTR server, LPSTR db, LPSTR id, LPSTR pw) {
    return obj->connectDB(server, db, id, pw);
}

extern "C" __declspec(dllexport) void  __cdecl exitDB(dataBase * obj) {
    obj->exitDB();
}


