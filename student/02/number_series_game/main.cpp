#include <iostream>


int main()
{
    int numbers = 0;
    int i = 0;
    std::cout << "How many numbers would you like to have? ";
    std::cin >> numbers;

    while ( i < numbers ){
        i += 1;
        if ( i % 3 == 0 and i % 7 == 0 ){
            std::cout << "zip boing" << std::endl; }
        else if ( i % 3 == 0){
            std::cout << "zip" << std::endl;}
        else if ( i % 7 == 0){
            std::cout << "boing" << std::endl;}
        else
            std::cout << i << std::endl;
        }
        }
