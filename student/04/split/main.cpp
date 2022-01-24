
#include <iostream>
#include <string>
#include <vector>




// TODO: Implement split function here
// Do not change main function
std::vector <std::string> split(std::string merkkijono, char erotinmerkki,
                                bool totuusarvo = false){


    std::string merkit = "";
    std::vector <std::string> tuote;
    std::vector <std::string> valmistuote;
    if (totuusarvo == false){
        for (char& c :  merkkijono){
            if (c != erotinmerkki){
                merkit += c;
            }

            else {
                tuote.push_back(merkit);
                merkit.clear();}

        }
        tuote.push_back(merkit);
    return tuote;
}
    else {
        for (char& c :  merkkijono){
            if (c != erotinmerkki){
                merkit += c;
            }

            else {
                tuote.push_back(merkit);
                merkit.clear();}

        }
        tuote.push_back(merkit);

        int maara = tuote.size();
        for (int i = 0; i < maara; ++i){
            if (tuote[i] == ""){
                valmistuote.push_back(tuote[i]);
                valmistuote.pop_back();
            }
            else (valmistuote.push_back(tuote[i]));

        }
        return valmistuote;
        }
    }


int main()
{
    std::string line = "";
    std::cout << "Enter a string: ";
    getline(std::cin, line);
    std::cout << "Enter the separator character: ";
    char separator = getchar();

    std::vector< std::string > parts  = split(line, separator);
    std::cout << "Splitted string including empty parts: " << std::endl;
    for( auto part : parts ) {
        std::cout << part << std::endl;
    }

    std::vector< std::string > parts_no_empty  = split(line, separator, true);
    std::cout << "Splitted string ignoring empty parts: " << std::endl;
    for( auto part : parts_no_empty ) {
        std::cout << part << std::endl;
    }
}
