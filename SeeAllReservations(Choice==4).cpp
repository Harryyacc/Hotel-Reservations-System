#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fileReading("Reservations.csv");
    string line = "";
    cout << "\nAll Reservations:\n";
    while(getline(fileReading, line)){
        cout << line << endl;
    }
    fileReading.close();
    return 0;
}