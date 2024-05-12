#include <iostream>
#include <vector>
#include "Bank.h"
#include "Customer.h"
using namespace std;

int main()
{
    Bank b1;
    int numCustomers;
    cout << "Enter the number of customers: ";
    cin >> numCustomers;
    for (int i = 0; i < numCustomers; ++i) {
        string name;
        int arrivalTime, serviceTime;

        cout << "Enter customer name: ";
        cin >> name;

        cout << "Enter arrival time: ";
        cin >> arrivalTime;

        cout << "Enter service time: ";
        cin >> serviceTime;

        Customer customer(name, arrivalTime, serviceTime);
        customer.setEvent_Type("Arrival");

        b1.add_customer(customer);
    }

    b1.simulate();

    return 0;
}
