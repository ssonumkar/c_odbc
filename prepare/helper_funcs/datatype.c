#include <stdio.h>
#include <sql.h>
#include <sqlext.h>
#include <string.h>
#include "../../driver_files/sf_odbc.h"

void getDatatypeInfo(SQLHSTMT hstmt, SQLSMALLINT DataType )
{
	SQLGetTypeInfo(hstmt, SQL_ALL_TYPES);
}
