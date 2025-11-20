#include "Elevator.h"

Elevator::Elevator(int floor, bool dir, bool m)
    : current_floor(floor), direction(dir),start_floor(floor), target_floor(floor){}

void Elevator::display_floor() {
    cout << "at " << current_floor << " floor.\n";
}

bool Elevator::dir(){
    return direction;
}
bool Elevator::running(){
    return moving;
}
void Elevator::setTarget(int start, int end) {
        start_floor = start;
        target_floor = end;
        moving = true;
}

void Elevator::move() {
    if(!moving) return;

    // 移動到起始樓層
    if(current_floor != start_floor){
        if(current_floor < start_floor) current_floor++;
        else if(current_floor > start_floor) current_floor--;
    }
    else{
        if(current_floor < target_floor) current_floor++;
        else if(current_floor > target_floor) current_floor--;
    }
    cout <<"start:"<<start_floor<<endl;
    cout<<"end:"<<target_floor<<endl;
    
    if(current_floor == target_floor) moving = false;
}

