#ifndef DNA_DATABASE_H
#define DNA_DATABASE_H

#include <string>
#include <map>
using namespace std;

class DataBase
{
public:
    static map<int, string> m_id_database;
    static map<string, string> m_name_database;
    static map< pair<int, string>, string> m_database;
};

#endif