#ifndef SIMETRIQ_MAIN
#define SIMETRIQ_MAIN

#include <memory>
#include <stdexcept>
#include <string>

#include <libpq-fe.h>

namespace simetriq
{
	class db_connection
	{
	public:
		db_connection() : dbconn(nullptr) {}
		db_connection(const char *) throw (const std::domain_error&);
	protected:
		PGconn * dbconn;
	};
	class simetriq
	{
	public:
		simetriq() : main_connection(nullptr) {}
		simetriq (const char *);
	protected:
		std::shared_ptr<db_connection> main_connection;
	};
}

#endif