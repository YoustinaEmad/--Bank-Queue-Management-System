#pragma once
#include <iostream>
#include <string>
using namespace std;

class Teller
{
public:
    Teller()
    {
        IsAvailable = true;
        serviceTime = 0;
    }

    bool isAvailable() const {
        return IsAvailable;
    }

    void setIsAvailable(bool available) {
        IsAvailable = available;
    }

    int getTellerNum() const {
        return teller_NUM;
    }

    void setTellerNum(int num) {
        teller_NUM = num;
    }

    int getServiceTime() const {
        return serviceTime;
    }

    void addToServiceTime(int time) {
        serviceTime += time;
    }

private:
    bool IsAvailable;
    int teller_NUM;
    int serviceTime;
};
