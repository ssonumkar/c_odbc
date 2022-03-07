#include <stdio.h>
#include <sql.h>
#include <sqlext.h>
#include <string.h>
#include "../../driver_files/sf_odbc.h"


void getMetadata(SQLHSTMT stmt)
{
	SQLSMALLINT nCols;
	SQLNumResultCols(stmt, &nCols);
	printf("Table metadata: ");
	for (int i = 0; i < nCols; i++)
	{
		char buf[512];
		SQLSMALLINT sqltype, l, decimal, nullable;
		SQLULEN size;
		SQLDescribeCol(stmt, i + 1, buf, sizeof(buf), &l, &sqltype, &size, &decimal, &nullable);
		printf("Column %u : name: %s, datatype: %d\n", i, buf, sqltype);
	}
}
// void getMetadata1(SQLHSTMT hstmt)
// {
// 	SQLRETURN retcode;
// 	while ((retcode = SQLFetch(hstmt)) == SQL_SUCCESS)
// 	{
// 		if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO)
// 		{

// 			printf("Error \n");
// 			return;
// 		}
// 		SQLINTEGER indicator;
// 		char pBuff[512];
// 		retcode = SQLGetData(hstmt, 1, SQL_C_BINARY,
// 							 pBuff, 0, &indicator); // Figure out the length
// 		if (retcode != SQL_SUCCESS_WITH_INFO && retcode != SQL_SUCCESS)
// 		{
// 			printf("Error \n");
// 			return;
// 		}
// 		printf("Byte length : %d ", indicator); // Print out the byte length

// 		int iValue = 0;
// 		retcode = SQLColAttribute(hstmt, 1, SQL_SF_VARIANT, NULL,
// 								  0, NULL, 0); // Figure out the type
// 		printf("Sub type = %d ", iValue);				// Print the type, the return is C_type of the column]

// 		// Set up a new binding or do the SQLGetData on that column with
// 		// the appropriate type
// 	}
// }