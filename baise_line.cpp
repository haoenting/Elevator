#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class Elevator{
    private:
       int current_floor=1;
       bool running=false;

    public:
        void display_floor(){
            cout << "is at "<< current_floor<< " floor.\n";
        }
        bool state(){
            return running;
        }
        void move(int start, int end){
            running = true; 
            // 先到起始樓層
            while(current_floor != start){
                if(current_floor < start)
                    current_floor++;
                else
                    current_floor--;
            }

            while(current_floor != end){
                if(current_floor < end)
                    current_floor++;
                else
                    current_floor--;
            }
            running = false; 
        }
};

void select(Elevator &elevator1, Elevator &elevator2, int start, int end){
    if(!elevator1.state()){ // 沒在動
        elevator1.move(start, end);
    }
    else
        elevator2.move(start, end);
}


int main(){
    Elevator elevator1, elevator2;
    int start, end;
    while(true){
        cout << "Please enter your current floor : ";
        cin >> start;
        cout << "Please enter your target floor : ";
        cin >> end;
        
        select(elevator1, elevator2, start, end);
        
        cout <<"---------------------------------\n";
        cout <<"Elevator 1 ";
        elevator1.display_floor();
        cout << "Elevator 2 ";
        elevator2.display_floor();
        cout<<"\n";

    }
    return 0;
}