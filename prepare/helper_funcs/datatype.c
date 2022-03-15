#include <stdio.h>
#include <sql.h>
#include <sqlext.h>
#include <string.h>
#include "../../driver_files/sf_odbc.h"

// void getDatatypeInfo(SQLHSTMT hstmt, SQLSMALLINT dataType)
// {
// 	SQLRETURN ret;
// 	ret = SQLGetTypeInfo(hstmt, SQL_SF_VARIANT);
// 	if (ret != SQL_SUCCESS)
// 	{
// 		printf("Failed..");
// 		return;
// 	}
// 	char name[256];
// 	SQLINTEGER name_ind;
// 	SQLBindCol(hstmt, 1, SQL_CHAR, (SQLPOINTER)name, 256, (SQLLEN)&name_ind);
// 	SQLSMALLINT datatype;
// 	SQLINTEGER datatype_ind;
// 	SQLBindCol(hstmt, 2, SQL_C_DEFAULT, (SQLPOINTER)&datatype, sizeof(datatype), (SQLLEN)&datatype_ind);
// 	while ((ret = SQLFetch(hstmt)) == SQL_SUCCESS)
// 	{
// 		printf("Name : %s, Type : %u \n", name, datatype);
// 	}
// }
