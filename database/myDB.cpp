// myDB.cpp : CmyDB 구현

#include "pch.h"
#include "myDB.h"


// CmyDB



STDMETHODIMP CmyDB::execQuery(BSTR query, LONG option, VARIANT_BOOL* retval)
{
	// 결과 메모리 초기화
	memset(values, 0, sizeof(values));
	memset(ids, -1, sizeof(ids));

	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle)) {
		*retval = false;
		return S_OK;
	}

	// Query 실행 프로시저 사용
	USES_CONVERSION;
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLCHAR*)OLE2A(query), SQL_NTS)) {
		// 오류 발생시 종료	
		*retval = false;
		return S_OK;

	}
	// option이 1일 경우
	if (option == 1) {
		// 정상 실행 시
		for (int i = 0; i < MAX_COLUMN; i++) {
			SQLBindCol(sqlStmtHandle, i + 1, SQL_CHAR, &values[i], sizeof(values[i]), &ids[i]);
		}

		*retval = true;
		return S_OK;

	}
	// option이 0일 경우
	*retval = true;
    return S_OK;
}


STDMETHODIMP CmyDB::nextObj(VARIANT_BOOL* retval)
{
	clearResult();
	// 다음 결과 불러오기
	if (SQLFetch(sqlStmtHandle) != SQL_NO_DATA) {
		for (int i = 0; i < MAX_COLUMN; i++) {
			if (ids[i] < 0) {
				break;
			}
			sprintf_s(result, SQL_COLUMN_LEN, "%s|%s", result, values[i]);
		}
		*retval = true;
	}
	else {
		*retval = false;
	}

    return S_OK;
}


STDMETHODIMP CmyDB::getResultString(BSTR* retval)
{
	CComBSTR bstrText(result);
    return bstrText.CopyTo(retval);
}


STDMETHODIMP CmyDB::getResult(LONG nSubItem, BSTR* retval)
{
	// 잘못된 인수 입력은 공백을 반환
	if (ids[nSubItem] < 0 || nSubItem > MAX_COLUMN) {
		CComBSTR bstrText("");
		return bstrText.CopyTo(retval);;
	}
	else {
		// 정상적인 경우 결과 반환
		CComBSTR bstrText(reinterpret_cast<char*>(values[nSubItem]));
		return bstrText.CopyTo(retval);
	}
    return S_OK;
}


STDMETHODIMP CmyDB::clearResult()
{
	memset(result, 0, sizeof(result));
    return S_OK;
}


STDMETHODIMP CmyDB::connectDB(BSTR server, BSTR db, BSTR id, BSTR pw, VARIANT_BOOL* retval)
{
	TCHAR connectSQL[150];
	USES_CONVERSION;

	sprintf_s(connectSQL, 150, "DRIVER={SQL Server};SERVER=%s, 1433;DATABASE=%s;UID=%s;PWD=%s;", OLE2A(server), OLE2A(db), OLE2A(id), OLE2A(pw));
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
	*retval = checkError;
    return S_OK;
}


STDMETHODIMP CmyDB::exitDB()
{
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLDisconnect(sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
	sqlConnHandle = NULL;
	sqlStmtHandle = NULL;

    return S_OK;
}
