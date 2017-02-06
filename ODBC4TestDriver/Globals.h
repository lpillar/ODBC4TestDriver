#pragma once

#include <Windows.h>
#include <tchar.h>
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
    shared_ptr<wstring> statement;
    shared_ptr<DocumentIterator> iter;
    shared_ptr<Document> doc;
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