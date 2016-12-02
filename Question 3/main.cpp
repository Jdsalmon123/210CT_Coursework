#include <iostream>
#include <math.h>

using namespace std;

int main()
{

    int uinput;
    cout<<"Please enter an integer to find the highest perfect square"<<endl;
    cin>>uinput;

    //error detection to check if the user inputted a valid integer
    while(cin.fail()){
        cout<< "Error please enter an integer"<<endl;
        cin.clear();
        cin.ignore(64, '\n');
        cin>>uinput;
    }

    //square the number (sqrt) and round down to the nearest integer (floor) then
    //raise that number to the power of 2 (pow) hence leaving us with the highest perfect square
    cout<<"The highest perfect square of "<<uinput<<" is "<<pow(floor(sqrt(uinput)),2)<<endl;

    return 0;
}

//The big O for this program is O(1) as the program has to run simple multiplication
//and divisiion on the number to get the perfect square, no loops are required
