#include <iostream>
#include <array>

using namespace std;

int binarysearch(array <int, 10> values, int low, int high, int uintlow, int uinthigh, int *middle)
{
    //while the binarysearch is still running (if low is higher than high the last search only had a
    //single element in it so has completed
    while (low<=high) {
        //find the middle of the array
        *middle = (low + high)/2;

        // if the middle is found within the user inputted boundrys then return the middle element of the list
        if (values[*middle] >= uintlow && values[*middle] <= uinthigh) {return *middle;}
        // else if it is lower or higher make the low or high in the array equal to the middle -+1
        else if (values[*middle] < uintlow) { low = *middle + 1;}
        else if (values[*middle] > uinthigh) { high = *middle - 1;}
    }
    return -1;
}

int main()
{
    //initilize variables for use in the tree, taking the user input in the form of an array to
    //iterate over
    int ubounds[1];
    int middle = 0;
    array <int, 10> values = {2,5,7,12,20,23,25,40,41,46};

    // user input loop for both the lower and higher bounds that we will search for
    for (int i = 0; i < 2; i++) {

        string check[] = {"Lower", "Higher"};
        cout<<"Please enter the "<<check[i]<<" bounds of the interval"<<endl;

        cin>>ubounds[i];

        //error detection to check if the user inputted a valid integer
        while(cin.fail()){
        cout<< "Error please enter an integer"<<endl;
        cin.clear();
        cin.ignore(64, '\n');
        cin>>ubounds[i];
        }
    }

    //run binary search sending the array to search, and setting the low and high to 0 and
    //the length respectivly, along with the user inputted boundarys and a reference to the middle
    if (binarysearch(values,0,values.size()-1, ubounds[0],ubounds[1], &middle) != -1) {
        //print out the middle value found along with the bounds inputted from the user
        cout<<"The value "<<values[middle]<<" was found within the bounds of "<<ubounds[0]<<" and "<<ubounds[1]<<endl;
    }
    else {
        //If no value is found the function will return -1 and print this statement
        cout<<"Error: no values found between "<<ubounds[0]<<" and "<<ubounds[1]<<endl;
    }

    return 0;
}

//The big O notation for the program is O(log(n)) as each iteration over the binary search
//function halves the number of elements that is required to be searched
