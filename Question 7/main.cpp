#include <iostream>

using namespace std;

//recursive function to check if a number is prime or not
string  primeno(int prime, int primediv){
    //the base case for the function is if the divisor
    //reaches 1, then we know that it is not divisible
    //by anything else
    if (primediv == 1) {return " is ";}
    //else check if it is divisible by the current divisor
    //if it is without leaving a remainder then the number
    //is not a prime number.
    else {
        if (prime % primediv == 0) {return " is not ";}
        //else run the function again taking one from the
        //divisor to eventually reach the base car (divisor == 1)
        else {return primeno(prime, primediv -1);}
    }
}

int main()
{
    //initilize variables for user input and collection of results
    cout<<"Please enter a positive integer"<<endl;
    string result;
    int uinput;
    cin>>uinput;

    //error detection for user input checking if the input is a valid integer
    while(cin.fail()){
        cout<< "Error please enter an integer"<<endl;
        cin.clear();
        cin.ignore(64, '\n');
        cin>>uinput;
    }

    //statement to check if the input is 1, this is instead of creating error
    //detection as an input of 1 would result in a error thrown by the program
    //In this case the error is a floating point exeption caused by divinding 1 by 0
    if (uinput == 1) {cout<<"1 is not a prime number"<<endl; return 0;}

    //send the user input to the recursive function to recieve the result
    result = primeno(uinput, uinput -1);

    //print the result of the function wether or not it is a prime number
    cout<<uinput<<result<<"a prime number"<<endl;

    return 0;
}

//The big O notation for this algorithm is O(n) as the primeno function
//is required to run n-1 times to reach its base case
