#include <stdio.h>
#include <sql.h>
#include <sqlext.h>
#include <string.h>
#include "../../driver_files/sf_odbc.h"
#define PERSONID_LEN  2
#define LASTNAME_LEN  255
#define FIRSTNAME_LEN 255
#define ADDRESS_LEN 255
#define CITY_LEN  255
#define MAXCOLS 10
#define TRUE 1

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

void display_results(SQLHSTMT hstmt)
{
    SQLCHAR         colname[32];        // column name
    SQLSMALLINT     coltype;            // column type
    SQLSMALLINT     colnamelen;         // length of column name
    SQLSMALLINT     nullable;           // whether column can have NULL value
    SQLLEN          collen[MAXCOLS];    // array of column lengths
    SQLSMALLINT     decimaldigits;      // no of digits if column is numeric
    SQLLEN          outlen[MAXCOLS];    // lengths of column values returned
    SQLCHAR *       data[MAXCOLS];      // buffers for retrieving column values
    SQLRETURN       retcode;            // general return code
    SQLLEN          displaysize;        // drivers column display size
    SQLINTEGER      i,j;
    SQLSMALLINT columns;

    // Initialise data array
  

    // Get number of columns from prepared statement
    retcode=SQLNumResultCols(hstmt, &columns);
   
    printf ("Number of columns is %i\n", (int) columns);
    printf ("Use SQLDescribeCol to obtain column details\n");

    for (i = 0; i < columns; i++)
    {
        // for each column from the prepared statement in hstmt, get the
        // column name, type, column size, decimal digits, and nullability
        retcode = SQLDescribeCol (hstmt,
                                  (SQLUSMALLINT)i+1,
                                  colname,
                                  sizeof (colname),
                                  &colnamelen,
                                  &coltype,
                                  &collen[i],
                                  &decimaldigits,
                                  &nullable);

        

        displaysize=0;
        // get Maximum number of characters required to display data
        // from the column.
		char type_name[250];
		SQLLEN type ;
        SQLColAttribute (hstmt,
						(SQLUSMALLINT)i+1,
						SQL_COLUMN_TYPE_NAME,
						&type_name, 
						250, 
						NULL, 
						NULL);
		SQLColAttribute (hstmt,
						(SQLUSMALLINT)i+1,
						SQL_COLUMN_TYPE,
						NULL, 
						SQL_IS_SMALLINT, 
						NULL, 
						&type);
		printf("name: %s:\n\t type_describe_col: %d\n\t type_SQLColAttri: %ld\n\t type_name: %s\n", colname, coltype, type, type_name);
        /* set column length to max of display length, and column name
           length. Plus one byte for null terminator       */
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