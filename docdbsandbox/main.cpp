#include <cpprest/json.h>
#include <documentdbcpp\DocumentClient.h>
#include <documentdbcpp\exceptions.h>
#include <documentdbcpp\TriggerOperation.h>
#include <documentdbcpp\TriggerType.h>
using namespace documentdb;
using namespace std;
using namespace web::json;

int main()
{
    // Connect to the emulator
    DocumentDBConfiguration conf(L"https://localhost:8081/", L"C2y6yDjf5/R+ob0N8A7Cgv30VRDJIWEHLM+4QDU5DE2nQ9nDuVTqobD4b8mGGyPMbIZnqyMsEcaGQy67XIw/Jw==");
    DocumentClient client(conf);

    // Create the db and collection
    shared_ptr<Database> db = client.CreateDatabase(L"test1");
    shared_ptr<Collection> coll = db->CreateCollection(L"collection1");

    // Create some test documents
    value document_family;
    document_family[L"id"] = value::string(L"AndersenFamily");
    document_family[L"FirstName"] = value::string(L"Thomas");
    document_family[L"LastName"] = value::string(L"Andersen");
    shared_ptr<Document> doc = coll->CreateDocument(document_family);

    document_family[L"id"] = value::string(L"WakefieldFamily");
    document_family[L"FirstName"] = value::string(L"Lucy");
    document_family[L"LastName"] = value::string(L"Wakefield");
    doc = coll->CreateDocument(document_family);
}