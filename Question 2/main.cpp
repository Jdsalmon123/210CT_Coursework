#include <iostream>
#include <cstdint>
#include <math.h>

using namespace std;

/*function to return the factorial of a number, inputs are:
the number to be factorialised and a variable to hold
and return the result into the main function*/
uintmax_t factorial(uintmax_t x, uintmax_t result = 1){
    //If inputted number is equal to 1, return result to main.
    //This is the base case in this resursive function
    if (x == 1) return result;
    //if not run the function again storing the result for the next
    //iteration to use and take 1 from the original number.
    else return factorial(x - 1, x * result);
}

int main()
{
    //initilize variables for use later
    int counter = 0;
    int uinput;
    //I found that in order to store large enough numbers
    //to use when geting the result from my factorial
    //function I had to use a uintmax_t variable to
    //allow storage for such large numbers
    uintmax_t facresult;

    cout<< "Please enter an integer"<<endl;

    cin>>uinput;

    //error detection making sure the value inputted
    //by the user is valid for the factorial function
    //to be able to use
    while(cin.fail()){
        cout<< "Error please enter an integer"<<endl;
        cin.clear();
        cin.ignore(64, '\n');
        cin>>uinput;
    }

    //run the factorial function above untill it hits its base case
    //and store the result in facresult
    facresult = factorial(uinput, 1);

    //print the original number and the resulting factorial to the console
    cout<<"The factorial of "<<uinput<<" is "<<facresult<<endl;

    //while there is a 0 at the end of facresult divide it by 10
    //add 1 to variable counter (this is used to store the number
    //of trailing 0's in the number)
    while (facresult % 10 == 0) {
        counter++;
        facresult = facresult/10;
    }

    cout<<"The number of trailing 0's is: "<<counter<<endl;

    return 0;
}

//The big O notation for this program is O(n) as the factorial function recursivly runs n-1 times


