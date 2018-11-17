#ifndef TRANSACTION_H
#define TRANSACTION_H
#include<string>

class Transaction
{
    int m_day;
    double m_amount;
    std::string m_description;

public:
    Transaction();
    Transaction(int day,double amount,std::string description);
    std::string to_string();
    void read();
    double get_day();
    double get_amount();
};

#endif
