#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

//function declaration
void availableRooms();

//function call
int main(){
    availableRooms();
    return 0;
}

//function definition
void availableRooms() {
    string arr[60];
    int rooms = 60;

    for(int i=0; i<rooms; i++){
        arr[i] = to_string(i+1);
    }

    ifstream roomChecking("Reservations.csv");
    string line, ID;
    getline(roomChecking, line); 

    while(getline(roomChecking, line)){
        stringstream roomNum(line);
        getline(roomNum, ID, ',');

        for(int i=0; i<rooms; i++){
            if(arr[i] == ID){
                for(int j=i; j<rooms-1; j++){
                    arr[j] = arr[j+1];
                }
                rooms--;
                break;
            }
        }
    }
    roomChecking.close();

    cout << "\nAvailable Rooms:\n";
    for(int i=0; i<rooms; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}