#pragma once
#include "Customer.h"
#include "Teller.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Bank
{
public:
    Bank()
    {
        tellers = new Teller[teller_num];
        for (int i = 0; i < teller_num; i++)
        {
            tellers[i].setIsAvailable(true);
            tellers[i].setTellerNum(i + 1);
        }
    }

    ~Bank()
    {
        delete[] tellers;
    }

    void add_customer(Customer& customer)
    {
        customer_Queue.push(customer);
    }

    void add_BankQueueCustomers(Customer& customer)
    {
        bank_Queue.push_back(customer);
    }

    void simulate()
    {
        while (!customer_Queue.empty())
        {
            Customer NextCustomer = customer_Queue.top();
            currentTime = NextCustomer.getArrivalOrLeaveTime();
            customer_Queue.pop();
            if (NextCustomer.getEvent_Type() == "Arrival")
            {
                bool isServiced = false;
                for (int i = 0; i < teller_num; i++)
                {
                    if (tellers[i].isAvailable())
                    {
                        NextCustomer.setWaiting_Time(currentTime - NextCustomer.getArrivalOrLeaveTime());
                        cout << "Customer: " << NextCustomer.getName() << " : WaitingTime: " << NextCustomer.getWaiting_Time() << " ServiceTime: " << NextCustomer.getServiceTime() << " Leaving Time: " << currentTime + NextCustomer.getServiceTime() << endl;
                        tellers[i].addToServiceTime(NextCustomer.getServiceTime());
                        NextCustomer.setArrivalOrLeaveTime(currentTime + NextCustomer.getServiceTime());
                        NextCustomer.setEvent_Type("Exit");
                        add_customer(NextCustomer);
                        tellers[i].setIsAvailable(false);
                        isServiced = true;
                        break;
                    }
                }
                if (!isServiced)
                {
                    add_BankQueueCustomers(NextCustomer);
                }
            }
            else if (NextCustomer.getEvent_Type() == "Exit")
            {
                if (!bank_Queue.empty())
                {
                    Customer NextCustomer = bank_Queue.front();
                    bank_Queue.erase(bank_Queue.begin());
                    NextCustomer.setWaiting_Time(currentTime - NextCustomer.getArrivalOrLeaveTime());
                    NextCustomer.setArrivalOrLeaveTime(currentTime + NextCustomer.getServiceTime());
                    NextCustomer.setEvent_Type("Exit");
                    cout << "Customer: " << NextCustomer.getName() << " WaitingTime: " << NextCustomer.getWaiting_Time() << " ServiceTime: " << NextCustomer.getServiceTime() << " Leaving Time: " << NextCustomer.getArrivalOrLeaveTime() << endl;
                    add_customer(NextCustomer);
                }
                else
                {
                    for (int i = 0; i < teller_num; i++)
                    {
                        if (!tellers[i].isAvailable())
                        {
                            tellers[i].setIsAvailable(true);
                            break;
                        }
                    }
                }
            }
        }

        printTellerUtilization();
    }

private:
    priority_queue<Customer, vector<Customer>, CompareCustomerTime> customer_Queue;
    vector<Customer> bank_Queue;
    int teller_num = 3;
    Teller* tellers;
    int currentTime = 0;

    //teller Utilization based on service time
    void printTellerUtilization()
    {
        int totalServiceTime = 0;
        for (int i = 0; i < teller_num; ++i)
        {
            totalServiceTime += tellers[i].getServiceTime();
        }

        int totalSimulationTime = currentTime;

        if (totalSimulationTime == 0)
        {
            cout << "Simulation not run yet or no customers served." << endl;
            return;
        }

        double totalUtilization = static_cast<double>(totalServiceTime) / totalSimulationTime;
        double averageUtilization = totalUtilization / teller_num;

        cout << "Teller Utilization " << endl;
        for (int i = 0; i < teller_num; ++i)
        {
            double utilization = static_cast<double>(tellers[i].getServiceTime()) / totalSimulationTime;
            cout << "Teller " << tellers[i].getTellerNum() << ": " << (utilization * 100) << "%" << endl;
        }

        cout << "Average Utilization: " << (averageUtilization * 100) << "%" << endl;
    }

};






