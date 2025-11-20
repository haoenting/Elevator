#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <queue>
#include "Elevator.h"
using namespace std;

void elevatorController(Elevator &e1, Elevator &e2,
                        queue<pair<int,int>> &upQueue,
                        queue<pair<int,int>> &downQueue);

#endif
