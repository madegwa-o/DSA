#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>



int main(){

    std::string username,password,email;

    //get user details
    std::cout << "Enter user name: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << "Enter email: ";
    std::cin >> email;

    try
    {
        sql::mysql::MySQL_Driver *driver = sql::mysql::get_mysql_driver_instance();
        sql::Connection *con = driver->connect("tcp://127.0.0.1:3306", "dev", "1234");
        con->setSchema("mydb");

        //prepare Sql statement  to insert data

        sql::PreparedStatement *pstmt;
        pstmt = con->prepareStatement("INSERT INTO users (username, password, email) VALUES (?, ?, ?)");

        pstmt->setString(1, username);
        pstmt->setString(2, password);
        pstmt->setString(3, email);


        pstmt->execute();

        std::cout << "User registered successfully!" << std::endl;

        // clean up
        delete pstmt;
        delete con;
    }
    catch(sql::SQLException &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
    return 0;
}