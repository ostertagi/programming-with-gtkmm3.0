#include <stdlib.h>
#include <iostream>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace sql;
using namespace std;

int main(void)
{
    try
    {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        driver = get_driver_instance();

        con = driver->connect("localhost", "root", "root");
        con->setSchema("safe_student");

        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT name FROM users");

        cout << "Connected to MySQL" << endl;
        cout << "------------------" << endl;

        while (res->next())
        {
            cout << res->getString("name") << endl;
        }

        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException &e)
    {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}