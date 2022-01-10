#include <iostream>

using namespace std;

unsigned long int factorial(unsigned long int number){
    if (number > 1){
        return number * factorial(number-1);}
    else
        return 1;
}

int probability(unsigned long int total, unsigned long int number){
    unsigned long int prob = factorial(total) / (factorial(total - number)*factorial(number));
    return prob;

}

void check(int total, int number){
    if (total <= 0 or number <= 0){
        cout << "The number of balls must be a positive number." << endl;
    }
    else if (total < number){
        cout << "The maximum number of drawn balls is the total amount of balls."<< endl;
    }
    else {
        cout << "The probability of guessing all " << number << " balls correctly is 1/" << probability(total, number) <<endl;
    }
}


int main()
{
    unsigned long int total;
    cout << "Enter the total number of lottery balls: ";
    cin >> total;

    unsigned long int number;
    cout << "Enter the number of drawn balls: ";
    cin >> number;

    check(total, number);




    return 0;
}

