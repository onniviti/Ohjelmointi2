
#include <iostream>
#include <random>
#include <string>

using namespace std;

void produce_random_numbers(unsigned int lower, unsigned int upper, int s)
{
    default_random_engine gen(s);
    uniform_int_distribution<int> distr(lower, upper);

    bool flag = true;
    while (flag){
        cout << "" << endl;
        std::cout << "Your drawn random number is "
                  <<distr(gen) << std::endl;
        string user_input;
        cout << "Press c to continue or q to quit: ";
        cin >> user_input;
        if (user_input == "q")
            flag = false;
        else if (user_input == "c")
            continue;

    }

}

int main()
{
    unsigned int lower_bound, upper_bound;
    int s;
    cout << "Enter a lower bound: ";
    cin >> lower_bound;
    cout << "Enter an upper bound: ";
    cin >> upper_bound;


    if(lower_bound >= upper_bound)
    {
        cout << "The upper bound must be strictly greater than the lower bound"
             << endl;
        return EXIT_FAILURE;
    }

    cout << "Enter a seed value: ";
    cin >> s;

    produce_random_numbers(lower_bound, upper_bound,s);

    return EXIT_SUCCESS;
}
