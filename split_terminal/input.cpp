#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int start, end;

    while (true) {
        cout << "Please enter your current floor: ";
        cin >> start;
        cout << "Please enter your target floor: ";
        cin >> end;

        // 將請求寫入檔案
        ofstream fout("elevator_request.txt");
        fout << start << " " << end;
        fout.close();

        cout << "Request sent!\n\n";
    }

    return 0;
}
