/*  COMP.CS.100 Project 2: GAME STATISTICS
 * ===============================
 * EXAMPLE SOLUTION
 * ===============================
 *
 *  Acts as a game statistics with n commands:
 * ALL_GAMES - Prints all known game names
 * GAME <game name> - Prints all players playing the given game
 * ALL_PLAYERS - Prints all known player names
 * PLAYER <player name> - Prints all games the given player plays
 * ADD_GAME <game name> - Adds a new game
 * ADD_PLAYER <game name> <player name> <score> - Adds a new player with the
 * given score for the given game, or updates the player's score if the player
 * already playes the game
 * REMOVE_PLAYER <player name> - Removes the player from all games
 *
 *  The data file's lines should be in format game_name;player_name;score
 * Otherwise the program execution terminates instantly (but still gracefully).
 *
 * */
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <cctype>
#include <algorithm>

// Creating struct for player
struct Player{
    std::string player_name;
    int points;
};

// Used data structure to shorten function parameters
using data_structure = std::map<std::string, std::vector<Player>>;

// Casual split func, if delim char is between "'s, ignores it.
std::vector<std::string> split( const std::string& str, char delim = ';' )
{
    std::vector<std::string> result = {""};
    bool inside_quatation = false;
    for ( auto current_char : str )
    {
        if ( current_char == '"' )
        {
            inside_quatation = not inside_quatation;
        }
        else if ( current_char == delim and not inside_quatation )
        {
            result.push_back("");
        }
        else
        {
            result.back().push_back(current_char);
        }
    }
    if ( result.back() == "" )
    {
        result.pop_back();
    }
    return result;
}

// Checks input in file
bool check_input(std::vector <std::string>& parts){
    if (parts.size() != 3){
        return false;
    }
    for (auto& part : parts){
        if (part == ""){
            return false;
        }
    }
    return true;
}

// Turns all character in string to uppercase and returns string
std::string touppercase(std::string string){
    std::for_each(string.begin(),string.end(), [] (char & c){ c = ::toupper(c);});
    return string;
}

// Prints all games in ASCII order
void all_games(data_structure games){
    std::cout << "All games in alphabetical order:"<<std::endl;
    std::map <std::string,std::vector < Player>>::iterator iter;
        iter = games.begin();
        while (iter != games.end()){
            std::cout << iter -> first << std::endl;
            ++ iter;
        }
}

template <typename T>
void print_vector(const std::vector<T> & vec, std::string sep=" ")
{
    for(unsigned int i = 0; i < vec.size();i++)
    {
        if (i == vec.size()-1){
            std::cout<<vec.at(i)<<std::endl;
        }
        else{
            std::cout<<vec.at(i)<< sep;
        }

    }
}

// Prints all players in a given game and their points in ascending order.
void game(data_structure games, std::string name){
    std::cout << "Game " << name << " has these scores and players, listed in ascending order:" << std::endl;
    std::map<int , std::vector<std::string>> for_print;

    for (unsigned int i = 0; i < games.at(name).size(); i++){
        if(for_print.find(games.at(name).at(i).points) == for_print.end()){
            for_print.insert({games.at(name).at(i).points, {games.at(name).at(i).player_name}});
        }
        else{
            for_print.at(games.at(name).at(i).points).push_back(games.at(name).at(i).player_name);
        }
    }
    std::map<int , std::vector<std::string>>::iterator iter;
    iter = for_print.begin();
    while(iter != for_print.end()){
        std::cout << iter -> first << " : ";
        print_vector(for_print.at(iter->first), ", ");
        iter ++;
    }
}

// Checks if game with given name exist in data structure
bool check_games(data_structure games, std::string game_name){
    if(games.find(game_name) == games.end()){
        return false;
    }
    else{
        return true;
    }
}

void running_program(data_structure games){
    while(true){
        std::string line;
        std::cout << "games> ";
        getline(std::cin, line);
        std::vector<std::string> parts = split(line,' ');
        // Checks if command is correct
        if(parts.size() < 0){
            std::cout << "Error: Invalid input." << std::endl;
        }
        else if (touppercase(parts.at(0)) == "QUIT"){
            break;
        }
        else if (touppercase(parts.at(0)) == "ALL_GAMES"){
            all_games(games);
            continue;
        }
        else if (touppercase(parts.at(0)) == "GAME"){
            if (parts.size() < 2){
                std::cout << "Error: Invalid input." << std::endl;
                continue;
            }
            if(games.find(parts.at(1)) == games.end()){
                std::cout << "Error: Game could not be found." << std::endl;
                continue;
            }
            else{
                game(games, parts.at(1));
                continue;
            }
        }
        else if (touppercase(parts.at(0)) == "ALL_PLAYERS"){
            continue;
        }
        else if (touppercase(parts.at(0)) == "PLAYER"){
            continue;
        }
        else if (touppercase(parts.at(0)) == "ADD_GAME"){
            continue;
        }
        else if(touppercase(parts.at(0)) == "ADD_PLAYER"){
            continue;
        }
        else if(touppercase(parts.at(0))== "REMOVE"){
            continue;
        }
        else{
            std::cout<<"Invalid input." << std::endl;
        }



    }
}


int main()
{
    std::string input_file = "";
    std::cout << "Give a name for input file: ";
    getline(std::cin, input_file);
    std::ifstream input_creature(input_file);
    if (not input_creature){
        std::cout << "Error: File could not be read." << std::endl;
        return EXIT_FAILURE;
    }
    std::string line;


    std::map<std::string, std::vector<Player>> games;
    while(getline(input_creature,line)){
        std::vector<std::string> parts = split(line);
        if (!check_input(parts)){
            std::cout<<"Error: Invalid format in file."<<std::endl;
            return EXIT_FAILURE;
        }

        std::string game_name = parts.at(0);
        std::string player_name = parts.at(1);
        int points = std::stoi(parts.at(2));
        struct Player player = {player_name, points};

        if(games.find(game_name) == games.end()){
            games.insert({game_name, {player}});
        }
        else{
            games.at(game_name).push_back(player);
        }
    }
    input_creature.close();

    running_program(games);
    return EXIT_SUCCESS;
}
