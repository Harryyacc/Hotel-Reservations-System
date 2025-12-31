#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string cancelRoomNo;
    cout<<"Enter room no. to cancel booking: ";
    cin>>cancelRoomNo;

    ifstream file("Reservations.csv");
    ofstream temp("temp.csv");

    string line = "";
    getline(file,line);
    temp<<line<<"\n";

    string username , user ,password , key ,ID , nights , dues;
    bool found=false;

    if(file.is_open()){
        while(getline(file,line)){
            stringstream check(line);
            getline(check , ID , ',');
            getline(check , user , ',');
            getline(check , key , ',');
            getline(check , nights , ',');
            getline(check , dues);

            if(cancelRoomNo == ID){
                cout<<"\n....Verify room by entering name and key....\n";
                cout<<"Enter Username: ";
                cin>>username;
                cout<<"Enter Password: ";
                cin>>password;

                if(username == user && password == key){
                    found=true;
                    continue;
                }
            }
            temp<<line<<"\n";
        }
    }

    file.close();
    temp.close();

    remove("Reservations.csv");
    rename("temp.csv","Reservations.csv");

    if(found){
        cout<<"\nVerification succeeded... Booking cancelled.\n";
    }
    else{
        cout<<"\nRoom not found or verification failed.\n";
    }

    return 0;
}