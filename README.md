# ODBC4TestDriver

This is a sample driver to illustrate and test the ODBC 4.0 spec using Azure DocumentDB. It is not full-featured.

### Current Functionality
* Supports getting and binding dynamic columns. Some of the ODBC Test aggregate results functions (such as "Bind Col All") do not currently work, but manually performing the operations does.
* Does not truly support a notion of Tables. ODBC4TestDriver is hard-coded to treat the DocumentDB database "test1" and collection "collection1" as the only table.
* Hard-coded to attach to a local Azure DocumentDB emulator.
* Uses the DocumentDbCpp NuGet library to interface with Azure DocumentDB, which is not compatible with the newest version of the DocumentDB API. Sample data must be created using an API compatible with the DocumentDbCpp library. There is an example "ODBC4TestSetup" project in this repository that can be used to populate the database.
* Build assumes that the ODBC-Specification and ODBCTest repositories are also cloned at the same root level, e.g. \git\ODBC4TestDriver, \git\ODBCTest, \git\ODBC-Specification. The build takes dependencies from the ODBC-Specification repo and copies output to the ODBCTest repo. Building in debug or release mode will copy the output to the appropriate ODBCTest ODBC Drivers directory.

### Usage
1. Clone the ODBC4TestDriver, ODBC-Specification, and ODBCTest repositories to the same directory.
2. Build ODBCTest. This currently requires some extra ODBC 4 Driver Manager libraries. See the ODBCTest repository for details.
3. Build ODBC4TestDriver for the same configuration as ODBCTest (Debug/Release).
4. Optionally: Create a DSN for the ODBC4TestDriver. This isn't supported via the DSN Setup interface yet, so you'll need to do it manually through the Registry Editor. Navigate to HKEY_LOCAL_MACHINE\SOFTWARE\[ODBC | WOW6432Node\ODBC]\ODBC.INI\ODBC Data Sources, and create a new String with the name and value "ODBC4TestDriver". This DSN is not required to use this driver in the ODBC Test tool, but it is required to use the "Full Connect" option.
5. Start ODBC Test and connect to the driver. If you created a DSN, you can use "Full Connect" with no Username or Password. Otherwise, use SQLDriverConnect with the InConnectionString "Driver={ODBC4TestDriver}" Note that the application will currently crash if the emulator is not running.
6. Use SQLExecDirect to run SQL queries. "select * from c" is the most basic query that will return all documents in test1\collection1 as records. Note that there is currently a bug that requires a null-terminated query string (use the NTS option).
7. SQLFetch the first row, then repeatedly call "SQLNextColumn" to process all dynamic columns. Optionally bind, get, or describe any of these columns, then continue fetching.
