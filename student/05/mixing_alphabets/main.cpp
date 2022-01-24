#include <iostream>
#include <string>
#include <algorithm>
#include <random>

int main()
{
    // This is a random number generator that should be given as parameter to the
    // function of the algorithm library to shuffle letters
    std::minstd_rand generator;

    std::cout << "Enter some text. Quit by entering the word \"END\"." << std::endl;
    std::string word;

    while (std::cin >> word)
    {
        if (word == "END")
        {
            return EXIT_SUCCESS;
        }

        // TODO: implement your solution here



        if (word.size() == 1){
            std::cout << word << std::endl;
        }
        else {
            std::string::iterator alota = word.begin();
            std::string::iterator lopeta = word.end();
            ++alota;
            --lopeta;

            shuffle(alota, lopeta, generator);
            std::cout << word << std::endl;
        }



    }
}
