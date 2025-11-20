#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <queue>
#include <iostream>
using namespace std;

class Elevator {
private:
    int current_floor, start_floor, target_floor;
    bool direction; // true=上, false=下
    bool moving; // 

public:
    Elevator(int floor = 1, bool dir = true, bool moving =false);

    void display_floor();
    bool dir();
    bool running();
    void setTarget(int start, int end);
    void move();
};

#endif
