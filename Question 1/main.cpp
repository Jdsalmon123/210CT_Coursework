#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;


/*Task 1 required us to randomly shuffle an array
of integers. As arrays are not resizable in c++ the
easiest implmentation of this was to create a
vector which is a copy of the original array
and delete the nodes from the array as they
were chosen. Therefore denying any duplicates
in the new array.

Inputting them into the new array was easy once
the element was selected from the vector and deleted
the element is the placed at the tail of the new array*/


int main()
{
    //initilise the oniginal array with the values 1-10
    static const int originalarray[10] = {1,2,3,4,5,6,7,8,9,10};
    //copy the array into a vector for selection and deletion of elements
    vector<int> originalvector(originalarray, originalarray + sizeof(originalarray) / sizeof(originalarray[0]));
    //create an empty aray of the same size to place slected elementg in.
    int shuffledarray[10];


    //this uses the system time to seed a new random number generator
    //making each use of the program unique
    srand(time(0));

    //for the number of elements in the array
    for (int i = 0; i < sizeof(originalarray) / sizeof(originalarray[0]; i++) {
        //choose a random number between 1 and the size of the array
        int random = rand() % (10 - i);
        //make the n'th element equal to the randomly
        //selected element in the vector
        shuffledarray[i] = originalvector.at(random);
        //remove the randomly selected element from the vector
        originalvector.erase(originalvector.begin() + random);
    }


    //print the array using a for statment to cycle through all the elements
    //within the arrays.
    cout<<"The Original Array Was: ";
    for (int i = 0; i < sizeof(originalarray) / sizeof(originalarray[0]); i++) {std::cout << originalarray[i] << + ", ";}
    std::cout<<std::endl;
    cout<<"The Shuffled Array Is: ";
    for (int i = 0; i < sizeof(originalarray) / sizeof(originalarray[0]); i++) {std::cout << shuffledarray[i] << + ", ";}
    return 0;
}


//the runtime bounds for this algorithm is O(n) as it requires the algorithm to run
//as many time as there are elements in the original array

