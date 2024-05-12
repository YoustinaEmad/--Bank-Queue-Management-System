#pragma once
#include <iostream>
#include <string>
using namespace std;
class Customer
{
public:
    Customer(string name, int Event_time, int serviceTime)
    {
        this->name = name;
        this->Event_time = Event_time;
        this->serviceTime = serviceTime;
    }
    void setName(const string& customerName) {
        name = customerName;
    }

    string getName() const {
        return name;
    }

    int getArrivalOrLeaveTime() const {
        return Event_time;
    }

    void setArrivalOrLeaveTime(int time) {
        Event_time = time;
    }

    int getServiceTime() const {
        return serviceTime;
    }

    void setServiceTime(int time) {
        serviceTime = time;
    }

    string getEvent_Type() const {
        return Event_type;
    }

    void setEvent_Type(const string& type) {
        Event_type = type;
    }

    int getWaiting_Time() const {
        return waitingTime;
    }

    void setWaiting_Time(int time) {
        waitingTime = time;
    }
    bool operator<(const Customer& other) const
    {
        return Event_time > other.Event_time;
    }
    bool operator==(const Customer& othercustomer)const
    {
        return(name == othercustomer.name) && (Event_time == othercustomer.Event_time) && (serviceTime == othercustomer.serviceTime);
    }
private :
    string name;
    int serviceTime;
    int waitingTime;
    int Event_time;//ArrivalTime OR LeaveTime
    string Event_type;
};
struct CompareCustomerTime
{
    bool operator()(const Customer& lhs, const Customer& rhs)const
    {
        return lhs.getArrivalOrLeaveTime() > rhs.getArrivalOrLeaveTime();
    }
};
