#pragma once

#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <Windows.h>
#include <stdio.h>

#pragma comment(lib, "odbc32.lib")

#define SQL_RESULT_LEN 240 // ��� ��ȯ ����
#define SQL_COLUMN_LEN 50 // ������ Column ����
#define MAX_COLUMN 10 // �ִ� Column ����
#define SQL_RETURN_CODE_LEN 1024 // Query ��� ����


class dataBase {
public:
	dataBase();
	~dataBase();
	// Query ���� 
	// option 0 = ����, option 1 = ��ȸ
	BOOL execQuery(LPSTR query, INT option);
	// ���� ���
	BOOL nextObj();
	// ��� ���ڿ��� ��������
	LPCSTR getResultString();
	// Ư�� ��� ��������
	LPCSTR getResult(INT nSubItem);

	// ��� ����
	void clearResult();

	// DB ����
	BOOL connectDB(LPSTR server, LPSTR db, LPSTR id, LPSTR pw);

	// db ����
	void exitDB();
private:
	// SQL Query�� ���� ���� ����
	SQLHANDLE sqlConnHandle;
	SQLHANDLE sqlStmtHandle;
	SQLHANDLE sqlEnvHandle;
	SQLCHAR retconstring[SQL_RETURN_CODE_LEN];
	SQLRETURN retval;

	TCHAR result[SQL_RESULT_LEN]; // ��� ���� ����
	BOOL checkError; // ���� üũ

	// ��� ��ȯ�� ����
	SQLINTEGER ids[MAX_COLUMN];
	SQLCHAR values[MAX_COLUMN][SQL_COLUMN_LEN];

};