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

struct DbcStruct
{
    DocumentDBConfiguration *conf;
    DocumentClient *client;
    SQLINTEGER ansiApp;
};

struct EnvStruct
{

};