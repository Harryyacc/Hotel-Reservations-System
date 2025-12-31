#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct roomBooking {
    string roomNo;
    string clientName;
    string roomKey;
    string noOfNights;
    string totalDues;
};

void availableRooms();

int main(){
    ifstream isExisting("Reservations.csv");
    if (!isExisting) {
    ofstream createFile("Reservations.csv");
    createFile << "RoomNo,ClientName,RoomKey,NoOfNights,TotalDues\n";
    createFile.close();
    }
    isExisting.close();

    int choice;
    while(true){
        cout<<"\n.....Welcome to Hotel Reservation System.....\n";
        cout<<"1.Add Booking.."<<endl;
        cout<<"2.Cancel Booking.."<<endl;
        cout<<"3.Rooms system.."<<endl;
        cout<<"4.See reservations.."<<endl;
        cout<<"5.Exit.."<<endl;

        cout<<"Enter choice: ";
        cin>>choice;

        //Add booking
        if(choice==1){
            roomBooking add;
            availableRooms();
            cout << "Enter room number from above list: ";
            cin >> add.roomNo;

            cout << "Enter client name(Only first name): ";
            cin >> add.clientName;

            cout << "Enter room safety key: ";
            cin >> add.roomKey;

            cout << "Enter number of nights: ";
            cin >> add.noOfNights;

            int totalDuess=stoi(add.noOfNights)*5000;

            add.totalDues = to_string(totalDuess);

            cout << "\nTotal dues to pay: " << add.totalDues << endl;

            ofstream fileBooking("Reservations.csv", ios::app);

            fileBooking << add.roomNo << ","
                        << add.clientName << ","
                        << add.roomKey << ","
                        << add.noOfNights << ","
                        << add.totalDues << "\n";

            fileBooking.close();
            cout<<"\nBooked successfully...\n";
        }
            
        //canceling room booking
        else if(choice==2){
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
            }

            //Room management system
            else if(choice==3){
                availableRooms();
            }
            
            //See overall bookings
            else if(choice==4){
                ifstream fileReading("Reservations.csv");
                string line="";
                cout << "\nAll Reservations:\n";
                while(getline(fileReading, line)){
                    cout << line << endl;
                }
                fileReading.close();
            }

            //exit
            else if(choice==5){
                cout<<"Thanks for your visit...."<<endl;
                break;
            }

            //invalid choice
            else{
                cout<<"\nInvalid choice:\n";
            }
        }      
    return 0;
}

//function for rooms
void availableRooms(){
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
