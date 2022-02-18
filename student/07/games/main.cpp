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


void all_games(data_structure games){
    std::cout << "All games in alphabetical order:"<<std::endl;

}

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
            break;
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
                std::cout << "test" << std::endl;
                continue;
            }


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
