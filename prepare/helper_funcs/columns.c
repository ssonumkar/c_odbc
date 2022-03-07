#include <stdio.h>
#include <sql.h>
#include <sqlext.h>
#include <string.h>
#include "../../driver_files/sf_odbc.h"

void getColumns(SQLHSTMT hstmt, char table_name[256])
{
	SQLRETURN ret;
	ret = SQLColumns(hstmt, NULL, 0, NULL, 0, &table_name, SQL_NTS, NULL, 0);
}