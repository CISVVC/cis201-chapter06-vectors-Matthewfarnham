#include<iostream>
#include "transaction.h"
#include<string>
#include<cstdlib>
#include<vector>

using namespace std;

Transaction::Transaction()
{
    m_day = 0;
    m_amount = 0;
    m_description = "Undefined";
        
}

Transaction::Transaction(int day,double amount,std::string description)
{
    m_day = day;
    m_amount = amount;
    m_description = description;
}

string Transaction::to_string()
{
    string day = std::to_string(m_day);
    string amount = std::to_string(m_amount);
    return (day + " " + amount + " " +  m_description);
}

//Read function for Transaction
void Transaction::read()
{
    string substr = "";
    string str;
    getline(cin,str);
    int i = 0;

    while (str[i] != ' ')
    {
        substr += str[i] ;
        ++i;
    }
    ++i;
    m_day = atoi(substr.c_str());
    substr = "";
    while (str[i] != ' ')
    {
        substr += str[i] ;
        ++i;
    } 
    i++;
    m_amount = atof(substr.c_str());
    substr = "";
    while (i < str.size())
    {
        substr +=str[i] ;
        ++i;
    }
    m_description = substr;
}

//Declaraction for get_day
double Transaction::get_day()
{
    return m_day;
}

//Declaration for get_amount
double Transaction::get_amount()
{
    return m_amount;
}

