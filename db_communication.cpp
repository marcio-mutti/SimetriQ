#include "simetriq.hpp"

#include <iostream> //Debug

using namespace std;

simetriq::db_connection::db_connection(const char * connection_string) throw(const domain_error&) : dbconn(nullptr)
{
	dbconn = PQconnectdb(connection_string);
	if (PQstatus(dbconn) != CONNECTION_OK)
	{
		string error_message("Database connection unsuccessful.\n");
		error_message += PQerrorMessage(dbconn);
		PQfinish(dbconn);
		dbconn = nullptr;
		throw (domain_error(error_message));
	}
}

simetriq::simetriq::simetriq(const char* connection_string) : main_connection(nullptr)
{
	try
	{
		main_connection = shared_ptr<db_connection>(new db_connection(connection_string));
	}
	catch (const domain_error& erro)
	{
		//Enviar um sinal informando o erro na conexão. Por hora, será enviado para o stdout
		cout << erro.what();
	}
}