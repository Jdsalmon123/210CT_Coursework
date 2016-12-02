#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <stack>

using namespace std;

int main()
{

    //initilise a bool variable for error detection
    bool str = false;
    //Initilise a stack for use when reversing the string
    stack<string> uwords;

    string ustr;
    //I am using getline over cin in this program as it
    //allows for spaces within the imput
    cout<<"Please enter a sentence of string"<<endl;
    getline(cin, ustr);

    //error detection running the length of the string
    //checking if all the characters are alpha (A-Z or a space) characters
    while (!str) {
        while (!str) {
            for (int i = 0; i < ustr.length(); i++) {

                    if (i == (ustr.length() -1)) {str = true;}

                    if (isalpha(ustr[i])) {continue;}

                    str = false;
            }

            //if there is a non alpha character within the strin
            if (!str) {
            cout<<"Please enter a valid string"<<endl;
            cin.ignore();
            getline(cin, ustr);
            }
        }
    }

    //initilize variables for splitting the sentence
    stringstream split(ustr);
    string result;

    //while there is still characters to go though iterate over the string
    //when the loop reaches a space in the string split it as it must
    //be the end of the word. Make result equal to the resulting word then
    //push the word into the stack
    while (getline(split,result, ' ')) {
        uwords.push(result);
    }

    //while the stack is not empty print out the top element in the stack
    //and then remove the top element from the stack (.pop) the resulting
    //output should be the string in reverse
    while (!uwords.empty()) {
        cout<<uwords.top()<<" ";
        uwords.pop();
    }

    return 0;
}

//The runtime of this algorithm (ignoring error detection at the start of the program)
//is O(n) as it has to run as many time as there are elements in the string (elements
//being words in this case)
