#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
using namespace std;

void sleep(){
    this_thread::sleep_for(chrono::seconds(1));
}
class Elevator {
private:
    int current_floor = 1;
    bool moving = false;
    int target_floor = 1;

public:
    void display_floor() {
        cout << current_floor;
    }

    bool state() {
        return moving;
    }

    void move(int start, int end) {
        moving = true;

        // 先到起始樓層
        while (current_floor != start) {
            if (current_floor < start) current_floor++;
            else current_floor--;
            sleep();
        }

        // 再到目標樓層
        while (current_floor != end) {
            if (current_floor < end) current_floor++;
            else current_floor--;
            sleep();
        }

        moving = false;
    }
};

int main() {
    Elevator elevator1, elevator2;

    while (true) {
        // 讀取最新請求
        ifstream fin("elevator_request.txt");
        int start, end;
        if (fin >> start >> end) {
            fin.close();

            
            if (!elevator1.state()) {
                thread t(&Elevator::move, &elevator1, start, end);
                t.detach(); // detach 讓它非阻塞
            } else if (!elevator2.state()) {
                thread t(&Elevator::move, &elevator2, start, end);
                t.detach();
            }

           
            ofstream fout("elevator_request.txt");
            fout.close();
        }

        
        cout << "Elevator 1: ";
        elevator1.display_floor();
        cout << " | Elevator 2: ";
        elevator2.display_floor();
        cout << "\n----------------\n";

        sleep();
    }

    return 0;
}
