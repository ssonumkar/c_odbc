#include <stdio.h>
#include <sql.h>
#include <sqlext.h>
#include <string.h>
#include "../../driver_files/sf_odbc.h"

void getData(SQLHSTMT hstmt)
{
    SQLSMALLINT columns;
    int row = 0;
    SQLRETURN ret;

    SQLExecute(hstmt);
    SQLNumResultCols(hstmt, &columns);
    while (SQL_SUCCEEDED(ret = SQLFetch(hstmt)))
    {
        SQLUSMALLINT i;
        printf("Row %d\n", row++);
        // Loop through the columns
        for (i = 1; i <= columns; i++)
        {
            SQLINTEGER indicator;
            char buf[512];
            // retrieve column data as a string
            ret = SQLGetData(hstmt, i, SQL_C_CHAR,
                             buf, sizeof(buf), &indicator);
            if (SQL_SUCCEEDED(ret))
            {
                // Handle null columns
                if (indicator == SQL_NULL_DATA)
                    strcpy(buf, "NULL");
                printf("  Column %u : %s\n", i, buf);
            }
            int iValue = 0;
            ret = SQLColAttribute(hstmt, i, SQL_SF_VARIANT, NULL,
                                  NULL, NULL, &iValue); // Figure out the type
            printf("Sub type = %d ", iValue);           // Print the type, the return is C_type of the column]
        }
    }
}
