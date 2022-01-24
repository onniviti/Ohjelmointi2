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

    std::ifstream file_in;
    file_in.open(filename);
    if (!file_in.is_open()){
        std::cout << "Error! The file " << filename << " cannot be opened." << std::endl;
        return EXIT_FAILURE;
    }
    std::vector <std::string> lines;
    std::string line;
    while (std::getline(file_in, line)){
        lines.push_back(line);
    }
    file_in.close();

    std::map<std::string, std::set<int>> lines_by_word;
    for (size_t row_index = 0; row_index < lines.size(); ++row_index)
    {
        line = lines.at(row_index);
        std::vector <std::string> words = split(line, ' ', true);
        for (const std::string& word:words)
        {
            if (lines_by_word.count(word) == 0)
            {
                lines_by_word[word] = {};
            }
            lines_by_word[word].insert(static_cast<int>(row_index)+1);
        }
    }

    for (const auto& key_value_pair : lines_by_word)
    {
        std::string word = key_value_pair.first;
        std::set<int> lines = key_value_pair.second;

        std::cout << word << " " << lines.size()<< ": ";

        for (auto current_line = lines.cbegin(); current_line != lines.cend(); ++current_line)
        {
            std::cout << *current_line;
            if (current_line != --lines.cend())
            {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;






}
