#include <iostream>

using namespace std;

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;
    int square = number * number;
    int cube = square * number;

    if (number == 0)
        cout << "The cube of " << number << " is 0."<<endl;
    else if ( cube / square == number) {
        cout << "The cube of " << number << " is " << cube <<"."<<endl;
    }
    else {
        cout << "Error! The cube of " << number << " is not "
             << cube << "." << endl;
    }


    return 0;
}
