#include <stdio.h>
#include <sql.h>
#include <sqlext.h>
#include <string.h>
#include "../settings/setting_configs.h"
#include "helper_funcs/metadata.c"

void prepare(SQLHDBC dbc)
{
	SQLHSTMT stmt;
	SQLRETURN ret;		 /* ODBC API return status */
	SQLSMALLINT columns; /* number of columns in result-set */
	int row = 0;
	SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);
	char buff[512];
	SQLLEN datalen = sizeof(SQL_CHAR);

	SQLPrepare(stmt, QUERY_STRING, SQL_NTS);
	printf("fetching metadata: \n");
	getMetadata(stmt);
}
