#include <iostream>
#include <queue>
#include <thread>
#include <mutex>

#include "Elevator.h"
#include "Controller.h"

using namespace std;

bool check_floor(int floor, int specified) {
    return floor >= 1 && floor <= 10 && specified >= 1 && specified <= 10;
}

int main() {
    // Elevator elevator1(1,true, false), elevator2(1,true, false);
    Elevator elevator1, elevator2;
    queue<pair<int,int>> upQueue, downQueue;
    mutex queue_mutex;


    thread controller(elevatorController,
                      ref(elevator1),
                      ref(elevator2),
                      ref(upQueue),
                      ref(downQueue));
    controller.detach();

    int current, specified;
    while(true) {
        cout << "Please enter your current & specified floor : ";
        cin >> current >> specified;

        if(!check_floor(current,specified)) {
            cout << "Invalid current floor pair.\n";
            continue;
        }

        if(current == specified) {
            cout << "You are already on that floor.\n";
            continue;
        }

        if(current < specified){
            queue_mutex.lock();
            upQueue.push({current,specified});
            queue_mutex.unlock();
        }
        else{
            queue_mutex.lock();
            downQueue.push({current,specified});
            queue_mutex.unlock();
        }
    }
}
