#pragma once

#include <Windows.h>
#include <tchar.h>
#include "sql.h"
#include "sqlext.h"
#include <sqlucode.h>
#include <cpprest/json.h>
#include <documentdbcpp\DocumentClient.h>
#include <documentdbcpp\exceptions.h>
#include <documentdbcpp\TriggerOperation.h>
#include <documentdbcpp\TriggerType.h>

using namespace documentdb;
using namespace std;
using namespace web::json;

void TestTrace(LPCTSTR s);

struct DescStruct
{
    // SQLGetDescField functions
    SQLRETURN GetArraySize(SQLULEN *size)           { return SQL_ERROR; }
    SQLRETURN GetArrayStatusPtr(SQLUSMALLINT **ptr) { return SQL_ERROR; }
    SQLRETURN GetBindOffsetPtr(SQLLEN **ptr)        { return SQL_ERROR; }
    SQLRETURN GetBindType(SQLINTEGER *type)         { return SQL_ERROR; }
    SQLRETURN GetCount(SQLSMALLINT *count)          { return SQL_ERROR; }
    SQLRETURN GetAllocType(SQLSMALLINT *type)       { return SQL_ERROR; }
};

enum ColumnType { str };

struct IPDStruct : DescStruct
{
    
};

struct IRDStruct : DescStruct
{
    // Type, Name, Value
    shared_ptr<vector<tuple<ColumnType, string, string>>> columns;
    bool moreNewColumns;
    int firstNewColumn;
    SQLINTEGER dynamicColumns = SQL_TRUE;
};

struct APDStruct : DescStruct
{

};

struct ARDStruct : DescStruct
{

};

struct EnvStruct
{

};

struct DbcStruct
{
    DocumentDBConfiguration *conf;
    DocumentClient *client;
    shared_ptr<Database> database;
    shared_ptr<Collection> collection;
    SQLINTEGER ansiApp;

    ~DbcStruct()
    {
        delete conf, client;
    }
};

struct StmtStruct
{
    DbcStruct *dbc;
    ARDStruct *ard;
    APDStruct *apd;
    IRDStruct *ird;
    IPDStruct *ipd;
    shared_ptr<wstring> statement;
    shared_ptr<DocumentIterator> iter;
    shared_ptr<Document> doc;

    ~StmtStruct()
    {
        delete ard, apd, ird, ipd;
    }
};

inline shared_ptr<wstring> MakeWide(string s)
{
    int length = MultiByteToWideChar(CP_ACP, 0, s.c_str(), -1, NULL, 0);
    wchar_t *wide = new wchar_t[length];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), -1, wide, length);
    wstring ret(wide);
    delete wide;

    return make_shared<wstring>(ret);
}

inline shared_ptr<string> MakeMB(wstring s)
{
    int length = WideCharToMultiByte(CP_ACP, 0, s.c_str(), -1, NULL, 0, NULL, NULL);
    char *mb = new char[length];
    WideCharToMultiByte(CP_ACP, 0, s.c_str(), -1, mb, length, NULL, NULL);
    string ret(mb);
    delete mb;

    return make_shared<string>(ret);
}