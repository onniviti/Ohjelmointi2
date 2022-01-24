#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>



std::vector <std::string > split(const std::string& text, char separator, bool ignore_empty = false)
{
    std::vector <std::string > parts;

    std::string::size_type left = 0;
    std::string::size_type right = text.find(separator, left);

    while ( right != std::string::npos)
    {
        std::string part = text.substr(left, right - left);

        if (part != "" || !ignore_empty)
        {
            parts.push_back(part);
        }
        left = right +1;
        right = text.find(separator, left);
    }

    std::string final_part = text.substr(left, std::string::npos);
    parts.push_back(final_part);



    return parts;
}


int main(){

    std::string filename;
    std::cout << "Input file: ";
    std::cin >> filename;



    std::map<std::string, int> name_points;
    std::ifstream file_in;
    file_in.open(filename);
    if (!file_in.is_open()){
        std::cout << "Error! The file " << filename << " cannot be opened." << std::endl;
        return EXIT_FAILURE;
    }

    std::string line;
    while (std::getline(file_in, line)){
        std::vector <std::string> words = split(line, ':', true);
        if ( name_points.find(words.at(0)) != name_points.end()){
            name_points.at(words.at(0)) += stoi(words.at(1));
        }
        else {
            name_points.insert({words.at(0), stoi(words.at(1))});
        }
    }
    std::cout << "Final scores:"<< std::endl;
    std::map<std::string, int>::iterator iter;
    iter = name_points.begin();
    while ( iter != name_points.end() ){
        std::cout << iter -> first << ": " << iter -> second << std::endl;
        ++iter;
    }

    file_in.close();














}


