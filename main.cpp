/*
File Name: main.cpp

Description: This program is designed to take in various sequences of transactions and print out a bank statement that includes all deposits, withdrawls, and the daily balance. In addition, it will also calculate the interest that has been earned by the account with both the minimum and average daily balances.

Author: Matthew Farnham
Date Created: Mon Nov 12 17:04:20 PST 2018
*/

#include<iostream>
#include<vector>
#include "transaction.h"
#include "transactionlog.h"


int main()
{
    Transactionlog tl;
    tl.read();
    tl.print();

    return 0;
}
