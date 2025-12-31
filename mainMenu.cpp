#include <iostream>
using namespace std;

int main() {
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

        if(choice==1){
            cout<<"\nWorking....\n";
        }
            
        //canceling room booking
        else if(choice==2){
            cout<<"\nWorking....\n";
        }

        //Room management system
        else if(choice==3){
            cout<<"\nWorking....\n";
        }
            
        //See overall bookings
        else if(choice==4){
            cout<<"\nWorking....\n";
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