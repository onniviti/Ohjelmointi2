#include <cstdlib>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>



void read_integers(std::vector< int >& ints, int count)
{
    int new_integer = 0;
    for(int i = 0; i < count; ++i)
    {
        std::cin >> new_integer;
        ints.push_back(new_integer);
        // TODO: Implement your solution here
    }
}

// TODO: Implement your solution here
bool same_values(std::vector<int> integers) {
    int firstItem = *integers.begin();
    for (int alkio : integers ){
        if (alkio != firstItem)
          return false;
    }
    return true;
    }

bool is_ordered_non_strict_ascending(std::vector<int> integers){
    int maara = integers.size()-1;
    for (int n = 0; n < maara; ++n){
        if (integers.at(n) > integers.at(n+1)){
            return false;
            }
    }
    return true;
}

bool is_arithmetic_series(std::vector<int> integers){
    int b = integers.at(1) - integers.at(0);
    int maara = integers.size()-1;
    for (int n = 0; n < maara; ++n)
        if (integers.at(n+1) - integers.at(n) != b)
            return false;
    return true;
}

bool is_geometric_series(std::vector <int> integers){
    if (integers.at(0) == 0 and integers.at(1) == 0)
        return false;
    int b = integers.at(1) / integers.at(0);
    int maara = integers.size()-1;
    for (int n = 1; n < maara; ++n)
        if (integers.at(n) / integers.at(n-1) != b)

            return false;

    return true;
}


int main()
{
    std::cout << "How many integers are there? ";
    int how_many = 0;
    std::cin >> how_many;

    std::cout << "Enter the integers: ";
    std::vector<int> integers;
    read_integers(integers, how_many);

    if(same_values(integers))
        std::cout << "All the integers are the same" << std::endl;
    else
        std::cout << "All the integers are not the same" << std::endl;

    if(is_ordered_non_strict_ascending(integers))
        std::cout << "The integers are in a non-strict ascending order" << std::endl;
    else
        std::cout << "The integers are not in a non-strict ascending order" << std::endl;

    if(is_arithmetic_series(integers))
        std::cout << "The integers form an arithmetic series" << std::endl;
    else
        std::cout << "The integers do not form an arithmetic series" << std::endl;

    if(is_geometric_series(integers))
        std::cout << "The integers form a geometric series" << std::endl;
    else
        std::cout << "The integers do not form a geometric series" << std::endl;

    return EXIT_SUCCESS;
}
