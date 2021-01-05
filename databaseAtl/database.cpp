#include "pch.h"
#include "database.h"

dataBase::dataBase()
{
	// 초기화
	sqlConnHandle = NULL;
	sqlStmtHandle = NULL;

	// ODBC 핸들 설정 및 초기화
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle))
		exitDB();
	if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
		exitDB();
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle))
		exitDB();
}

dataBase::~dataBase()
{
	exitDB();
}

BOOL dataBase::execQuery(LPSTR query, INT option)
{
	// 결과 메모리 초기화
	memset(values, 0, sizeof(values));
	memset(ids, -1, sizeof(ids));

	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))
		return false;

	// Query 실행 프로시저 사용
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLCHAR*)query, SQL_NTS)) {
		// 오류 발생시 종료	
		return false;
	}
	// option이 1일 경우
	if (option == 1) {
		// 정상 실행 시
		for (int i = 0; i < MAX_COLUMN; i++) {
			SQLBindCol(sqlStmtHandle, i + 1, SQL_CHAR, &values[i], sizeof(values[i]), &ids[i]);
		}

		return true;
	}
	// option이 0일 경우
	return true;
}

BOOL dataBase::nextObj()
{
	// 다음 결과 불러오기
	if (SQLFetch(sqlStmtHandle) != SQL_NO_DATA) {
		clearResult();
		for (int i = 0; i < MAX_COLUMN; i++) {
			if (ids[i] < 0) {
				break;
			}
			sprintf_s(result, SQL_COLUMN_LEN, TEXT("%s|%s"), result, values[i]);
		}
		return true;
	}
	else {
		return false;
	}
}

LPCSTR dataBase::getResultString()
{
	return (LPCSTR)result;
}

LPCSTR dataBase::getResult(INT nSubItem)
{
	// 잘못된 인수 입력은 공백을 반환
	if (ids[nSubItem] < 0 || nSubItem > MAX_COLUMN) {
		return (LPCSTR)"";
	}
	else {
		// 정상적인 경우 결과 반환
		return (LPCSTR)values[nSubItem];
	}
}

void dataBase::clearResult()
{
	memset(result, 0, sizeof(result));
}

BOOL dataBase::connectDB(LPSTR server, LPSTR db, LPSTR id, LPSTR pw)
{
	TCHAR connectSQL[150];

	sprintf_s(connectSQL, 150, TEXT("DRIVER={SQL Server};SERVER=%s, 1433;DATABASE=%s;UID=%s;PWD=%s;"), server, db, id, pw);
	// 연결 시도
	switch (SQLDriverConnect(sqlConnHandle,
		NULL,
		(SQLCHAR*)connectSQL,
		SQL_NTS,
		retconstring,
		1024,
		NULL,
		SQL_DRIVER_NOPROMPT)) {
	case SQL_SUCCESS: // 성공
	case SQL_SUCCESS_WITH_INFO:
		checkError = TRUE;
		break;
	case SQL_INVALID_HANDLE: // 실패
	case SQL_ERROR:
		checkError = FALSE;
		break;
	default: // 실패
		checkError = FALSE;
		break;
	}
	// 만약 연결에 문제가 있다면
	// 종료 한다.

	if (checkError) {
		MessageBox(NULL, "DB연결 성공!", "Regular Warning", 0);
	}
	else {
		MessageBox(NULL, connectSQL, "Regular Warning", 0);
		exitDB();
	}
	return checkError;
}

void dataBase::exitDB()
{
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLDisconnect(sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
	sqlConnHandle = NULL;
	sqlStmtHandle = NULL;

	return;
}
