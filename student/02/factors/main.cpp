#include <iostream>
#include <cmath>


using namespace std;

int main()
{
    std::string user_input ="";

    std::cout << "Enter a positive number: ";
    std::cin >> user_input;

    int n = std::stoi(user_input);
    if (n <= 0){
        std::cout << "Only positive numbers accepted" << std::endl;
        return 0;

    }

    int factor_cand = std::max(static_cast<int>(sqrt(n)), 1);

    for (; n % factor_cand != 0; --factor_cand);


    int factor1 = factor_cand;
    int factor2 = n / factor_cand;


    std::cout << user_input << " = " << factor1 << " * " <<factor2 << endl;


    return 0;
}
