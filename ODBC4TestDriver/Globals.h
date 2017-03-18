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
#include <set>

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

struct IPDStruct : DescStruct
{
    
};

struct CellStruct
{
    SQLSMALLINT type;
    string name;
    string value;
    bool bound;
    char *binding;
    SQLLEN bindingLength;
    SQLLEN *StrLen_or_Ind;
    bool notInThisRow;
    SQLUSMALLINT columnNumber;

    CellStruct(string _name, SQLUSMALLINT _columnNumber, SQLSMALLINT _type = SQL_C_CHAR,
               bool _bound = false, string _value = "", bool _notInThisRow = false)
    {
        name = _name;
        columnNumber = _columnNumber;
        type = _type;
        bound = _bound;
        value = _value;
        notInThisRow = _notInThisRow;
    }
};

struct cell_compare
{
    bool operator() (const CellStruct &a, const CellStruct &b)
    {
        return a.columnNumber < b.columnNumber;
    }
};

struct IRDStruct : DescStruct
{
    shared_ptr<DocumentIterator> rowIter;
    vector<CellStruct> columns;
    shared_ptr<Document> doc;
    set<CellStruct, cell_compare> unprocessedColumns;

    void resetRow()
    {
        if (doc)
        {
            doc.reset();
        }
        unprocessedColumns.clear();
        for (auto c : columns)
        {
            c.notInThisRow = true;
        }
    }
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
    DocumentDBConfiguration *conf = NULL;
    DocumentClient *client = NULL;
    shared_ptr<Database> database;
    shared_ptr<Collection> collection;
    SQLINTEGER ansiApp;

    ~DbcStruct()
    {
        if (conf)
            delete conf;
        if (client)
            delete client;
    }
};

struct StmtStruct
{
    DbcStruct *dbc = NULL;
    ARDStruct *ard = NULL;
    APDStruct *apd = NULL;
    IRDStruct *ird = NULL;
    IPDStruct *ipd = NULL;
    shared_ptr<wstring> statement;
    SQLINTEGER supportsDynamicColumns = 0L;

    ~StmtStruct()
    {
        if (ard)
            delete ard;
        if (apd)
            delete apd;
        if (ird)
            delete ird;
        if (ipd)
            delete ipd;
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