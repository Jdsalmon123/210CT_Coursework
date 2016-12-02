#include <iostream>
#include <cctype>
#include <string>

using namespace std;

//recursive function to remove all vowels in a passed string
//I am using I as a counter here and a array of characters of
//length 10 to cover both upper and lower case vowels
string RemVowels(int i, string uinput, char vowels[10])
{
    //if the function has looped through the length of the
    //array then return the remainder of the string
    if (i > 10) {return uinput;}

    //for the length of the input iterate over each element
    //in the string removing the element if it matches the
    //current vowel remove the element from the string
    for (int x = 0; x < uinput.size(); x++) {
        if (uinput.at(x) == vowels[i]) {
            uinput.erase(x,1);
        }
    }

    //iterate variable i as to move along the array of vowels
    //and eventually end up at the base case i = 10
    return RemVowels(i+1,uinput,vowels);

}


int main()
{
    bool str = false;
    char vowels[10] = {'a','e','i','o','u','A','E','I','O','U'};

    string uinput;
    getline(cin, uinput);

    while (!str) {
        for (int i = 0; i < uinput.length(); i++) {

                if (i == (uinput.length() -1)) {str = true;}

                if (isalpha(uinput[i])) {continue;}

                str = false;

        }
        if (!str) {
        cout<<"Please enter a valid string"<<endl;
        cin.ignore();
        getline(cin, uinput);
        }

    }

    cout<<RemVowels(0, uinput, vowels)<<endl;


    return 0;
}

//The big 0 notation for this program is O(n*m) where n is the number of elements
//in the inputted string to search and m being the number of elements in the
//array used to make comparisons against. In this case it is O(10n)






