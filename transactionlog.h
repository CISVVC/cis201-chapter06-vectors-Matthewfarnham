#ifndef TRANSACTIONLOG_H
#define TRANSACTIONLOG_H
#include<vector>
#include "transaction.h"

using namespace std;

class Transactionlog
{
    std::vector<Transaction> m_transaction;
    double get_total(int daynum);

public:
    void add(const Transaction &t);
    void read();
    void print();
    vector<double> get_daily_balances();
    void print_interest();
};

#endif
