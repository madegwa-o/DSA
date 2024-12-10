#ifndef USERS_H
#define USERS_H

#include <iostream>
#include <string>
#include <vector.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>


class Users {

    private:

        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;

        void displayUser(const std::string &username,const std::string &password,const std::string &email);
    

    public:
        Users();
        ~Users();

        void fetchAllUsers();
}

#endif