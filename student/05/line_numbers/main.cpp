#include <iostream>
#include <fstream>
#include <string>



int main()
{

    std::string input_file = "";
    std::string output_file = "";
    std::cout << "Input file: ";
    getline(std::cin, input_file);
    std::cout << "Output file: ";
    getline(std::cin, output_file);

    std::ifstream input_olio(input_file);
    if ( not input_olio ){
        std::cout << "Error! The file "<< input_file << " cannot be opened." << std::endl;
        return EXIT_FAILURE;
    }
    else {
        std::ofstream output_olio(output_file);
        std::string rivi;
        int number = 1;
        while (getline(input_olio, rivi)){
            output_olio << number << " " << rivi << std::endl;
            number += 1;

        }
        output_olio.close();
}
    input_olio.close();



    return 0;


}
