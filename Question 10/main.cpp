#include <iostream>

using namespace std;

int main()
{
    //initilize an array of integers as to traverse and find the longest
    //ascending sequence
    int arr[10] = {1,2,3,3,5,6,8,3,1,8};

    //initilize current and longest variables to point to elements in the array
    int clen = 1, lstart = 0, llen = 1, cstart = 0;

    //for the length of the array
    for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); i++) {
        //if the next value in the array is larger
        if (arr[i] > arr[i-1]) {
            //increase the current length by 1
            clen++;
            //if current length is longer than longest
            if (clen > llen) {
                //make longest equal to current length
                llen = clen;
                //make the start the same as current as to
                //use in the for loop below
                lstart = cstart;
            }
        }
        else {
            //reset the current length and start from the i'th element
            clen = 1;
            cstart = i;
        }
    }

    cout<<"The largest substring of ascending integers within the array is: ";


    //while i is not equal to the end of the array and is either the first iteration or the
    //next array element is larger than the previous print the array element
    for (int i = lstart ; i != sizeof(arr) / sizeof(arr[0]) && (i == lstart || arr[i] > arr[i-1]) ; i++) {
    cout << arr[i] << " ";
    }

    //this gives us the output of all the elements that are in ascending order being printed in the console

    return 0;
}

//The big O notation in the program is O(n) as the program has to iterate over the
//sequence of numbers once to find the start of the longest ascending order sequence
//it saves variables for outputting the found sequence at a later date

//for i < size of array big O = O(n)
