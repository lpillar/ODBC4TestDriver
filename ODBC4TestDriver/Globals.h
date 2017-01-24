#pragma once
#include <Windows.h>
#include <tchar.h>
#include "sqlext.h"

#include <cpprest/json.h>
#include <documentdbcpp\DocumentClient.h>
#include <documentdbcpp\exceptions.h>
#include <documentdbcpp\TriggerOperation.h>
#include <documentdbcpp\TriggerType.h>

using namespace documentdb;
using namespace std;
using namespace web::json;

void TestTrace(LPCTSTR s);

struct HandleDbc
{
    DocumentDBConfiguration *conf;
    DocumentClient *client;
};

struct HandleEnv
{

};