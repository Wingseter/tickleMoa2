#pragma once

#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <Windows.h>
#include <stdio.h>

#pragma comment(lib, "odbc32.lib")

#define SQL_RESULT_LEN 240 // 결과 반환 길이
#define SQL_COLUMN_LEN 50 // 각각의 Column 길이
#define MAX_COLUMN 10 // 최대 Column 개수
#define SQL_RETURN_CODE_LEN 1024 // Query 결과 길이


class dataBase {
public:
	dataBase();
	~dataBase();
	// Query 실행 
	// option 0 = 실행, option 1 = 조회
	BOOL execQuery(LPSTR query, INT option);
	// 다음 결과
	BOOL nextObj();
	// 결과 문자열로 가져오기
	LPCSTR getResultString();
	// 특정 결과 가져오기
	LPCSTR getResult(INT nSubItem);

	// 결과 비우기
	void clearResult();

	// DB 연결
	BOOL connectDB(LPSTR server, LPSTR db, LPSTR id, LPSTR pw);

	// db 종료
	void exitDB();
private:
	// SQL Query를 위한 변수 정의
	SQLHANDLE sqlConnHandle;
	SQLHANDLE sqlStmtHandle;
	SQLHANDLE sqlEnvHandle;
	SQLCHAR retconstring[SQL_RETURN_CODE_LEN];
	SQLRETURN retval;

	TCHAR result[SQL_RESULT_LEN]; // 결과 저장 버퍼
	BOOL checkError; // 에러 체크

	// 결과 반환용 변수
	SQLINTEGER ids[MAX_COLUMN];
	SQLCHAR values[MAX_COLUMN][SQL_COLUMN_LEN];

};