#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>


const std::string HELP_TEXT = "S = store id1 i2\nP = print id\n"
                              "C = count id\nD = depth id\n";


std::vector<std::string> split(const std::string& s, const char delimiter, bool ignore_empty = false){
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos)
    {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter)+1, tmp.size());
        if(not (ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}



using Network = std::map<std::string, std::vector<std::string>>;

void store(Network& network, const std::string& id1, const std::string& id2){
    if (network.count(id1) == 0){
        network[id1] = {};
    }

    if (network.count(id2) == 0){
        network[id2] = {};
    }

    network.at(id1).push_back(id2);
}

void print(const Network& network, const std::string& current_id, const int depth = 0){
    for (int i = 0; i < depth; ++i){
        std::cout << "..";
    }
    std::cout << current_id << std::endl;

    for (const std::string& child : network.at(current_id)){
        print(network, child, depth + 1);
    }
}

int count (const Network& network, const std::string& current_id, bool count_self = false){
    int child_count = 0;
    if (count_self){
        child_count = 1;
    }

    for (const std::string& child : network.at(current_id))
    {
        child_count += count(network, child, true);
    }


    return child_count;
}

int depth(const Network& network, const std::string& current_id, int depth_tmp = 1)
{
    int max_child_depth = depth_tmp;

    for (const std::string& child : network.at(current_id))
    {
        int current_child_depth = depth(network, child, depth_tmp + 1);
        max_child_depth = std::max(max_child_depth, current_child_depth);
    }
    return max_child_depth;
}

int main()
{
    // TODO: Implement the datastructure here

    Network network;

    while(true){
        std::string line;
        std::cout << "> ";
        getline(std::cin, line);
        std::vector<std::string> parts = split(line, ' ', true);

        std::string command = parts.at(0);

        if(command == "S" or command == "s"){
            if(parts.size() != 3){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id1 = parts.at(1);
            std::string id2 = parts.at(2);

            // TODO: Implement the command here!

            store(network, id1, id2);


        } else if(command == "P" or command == "p"){
            if(parts.size() != 2){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            // TODO: Implement the command here!
            print(network, id);


        } else if(command == "C" or command == "c"){
            if(parts.size() != 2){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            // TODO: Implement the command here!
            std::cout << count(network, id) << std::endl;
        } else if(command == "D" or command == "d"){
            if(parts.size() != 2){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            // TODO: Implement the command here!

            std::cout << depth(network, id) << std::endl;
        } else if(command == "Q" or command == "q"){
           return EXIT_SUCCESS;
        } else {
            std::cout << "Erroneous command!" << std::endl << HELP_TEXT;
        }
    }
}
