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

struct Player{
    std::string player_name;
    int points;
};


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
    return EXIT_SUCCESS;
}
