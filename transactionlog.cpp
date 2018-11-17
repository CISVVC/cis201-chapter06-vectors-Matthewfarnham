#include<iostream>
#include "transactionlog.h"

using namespace std;

const int MAX_DAY = 30;

void Transactionlog::add(const Transaction &t)
{
    m_transaction.push_back(t);
}

//Print function for Transactionlog that prints the each transaction as a bank
//statement and the daily balance for each day
void Transactionlog::print()
{
    vector<double> balances = get_daily_balances();
    for(int day=0;day < MAX_DAY;day++)
    {
        std::cout << "\n++++++++++++++++++++\n";
        for(int k=0; k < m_transaction.size(); ++k)
        {
            Transaction trans = m_transaction[k];
            if(trans.get_day() == day+1)
                std::cout << trans.to_string() << std::endl;
        }
        std::cout << "Balance for day " << day+1 << ": " << balances[day] << " "<< "\n++++++++++++++++++++\n";
    }
    print_interest();
}

//Read fucntion for transactionlog
void Transactionlog::read()
{
    Transaction t;
    while(! std::cin.eof())
    {
        t.read();
        add(t);
    }
}

//Function that gets total of transactions and returns the total
double Transactionlog::get_total(int daynum)
{
    double total = 0.0;
    for (int i = 0; i < m_transaction.size(); ++i)
    {
        Transaction trans = m_transaction[i];
        if(trans.get_day() == daynum)
            total += trans.get_amount();
    }
    return total;
}

//Fuction that gets the daily balance for each day
vector<double> Transactionlog::get_daily_balances()
{
    vector<double> daily_balances;
    double balance = 0.0;
    for(int day=0;day<MAX_DAY;day++)
    {
        balance += get_total(day+1);
        daily_balances.push_back(balance);
    }
    return daily_balances;
}

//Print function that both calculates and prints the average daily balance, minimum daily 
//balance, and the interest of both
void Transactionlog::print_interest()
{
    vector<double> balances = get_daily_balances();
    double smallest = balances[0];
    for(int i = 0;i <MAX_DAY; ++i)
    {
        if(balances[i] < smallest)
            smallest = balances[i];
    }
    double min_interest = smallest * .005;
    cout << "Minimum daily balance: " << smallest << endl;
    cout << "Interest: " << min_interest << endl;

    double sum = 0.0;
    for(int i = 0; i < MAX_DAY; ++i)
    {
        sum += balances[i];
    }
    double average = sum / MAX_DAY;
    double avg_interest = average *.005;
    cout << "Average daily balance: " << average << endl;
    cout << "Interest: " << avg_interest << endl;
}
