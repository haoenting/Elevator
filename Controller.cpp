#include "Controller.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <mutex>
using namespace std;


mutex cout_mutex;
atomic<bool> running(true);

void elevatorController(Elevator &e1, Elevator &e2,
                        queue<pair<int,int>> &upQueue,
                        queue<pair<int,int>> &downQueue) {
    while(true) {
        lock_guard<mutex> lock(cout_mutex);
        //system("clear"); //mac
        //system("cls"); //windows
        cout << "\n------------------------------\n";
        cout << "Elevator 1 " ;
        e1.display_floor() ;
        // cout << "Elevator 2 ";
        // e2.display_floor() ;
        cout << "------------------------------\n";
        cout.flush();
        // e2.display_floor();
           
        this_thread::sleep_for(chrono::seconds(2));

        if(!e1.running()) {  // 只有在電梯空閒時才取新的目標
            if(!upQueue.empty() && e1.dir()) {
                e1.setTarget(upQueue.front().first, upQueue.front().second);
                upQueue.pop();
            } 
            else if(!downQueue.empty()) {
                e1.setTarget(upQueue.front().first, downQueue.front().second);
                downQueue.pop();
            }
        }

        // 每次迴圈只走一步
        e1.move();


     
    }
}
