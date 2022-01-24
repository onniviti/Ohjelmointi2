/* Hitori
 *
 * Kuvaus:
 *   Ohjelma toteuttaa Hitori-pelin. Peliss� on peliruudukko kooltaan
 * 5 x 5. Kukin ruutu sis�lt�� jonkin numeroista 1-5. Vaaka- ja
 * pystyriveill� voi aluksi olla useita samoja numeroita, mutta
 * tarkoituksena on poistaa numeroita niin, ett� kullakin vaaka- ja
 * pystyrivill� on kutakin numeroa vain yksi tai ei yht��n. Kuitenkaan
 * vierekk�isten ruutujen numeroita ei saa poistaa, eik� mik��n j�ljelle
 * j��v� numero (ruutu) saa j��d� irralleen muista, eli sen ymp�rilt�
 * (yl�puolelta, alapuolelta, vasemmalta, oikealta) ei saa poistaa
 * kaikkia numeroita.
 *   Aluksi k�ytt�j�lt� kysyt��n, t�ytet��nk� peliruudukko satunnaisesti
 * arvottavilla luvuilla 1-5 vai k�ytt�j�n valitsemilla 25 luvulla.
 * Ensimm�isess� vaihtoehdossa k�ytt�j�lt� kysyt��n satunnaisluku-
 * generaattorin siemenlukua ja j�lkimm�isess� h�nt� pyydet��n sy�tt�m��n
 * 25 lukua.
 *   Joka kierroksella k�ytt�j�lt� kysyt��n poistettavan numeron
 * koordinaatteja eli kahta lukua. Peli p��ttyy pelaajan voittoon,
 * jos peliruudukon kaikilla vaaka- ja pystyriveill� esiintyy kukin
 * numero 1-5 korkeintaan kerran. Peli p��ttyy pelaajan h�vi��n,
 * jos h�n poistaa jo poistetun numeron viereisen numeron tai jos
 * jokin numero j�� irralleen muista.
 *   Ohjelma tarkistaa annetut koordinaatit. Koordinaattien pit�� olla
 * peliruudukon sis�ll�, ja niiden osoittaman ruudun pit�� sis�lt��
 * numero, eli jo poistettua numeroa ei voi poistaa toiseen kertaan.
 *   Pelin p��ttyess� kerrotaan, voittiko vai h�visik� pelaaja.
 *
 * Ohjelman kirjoittaja
 * Nimi: Onni Vitikainen
 * Opiskelijanumero: H292259
 * K�ytt�j�tunnus: ftonvi
 * E-Mail: onni.vitikainen@tuni.fi
 *
 * Huomioita ohjelmasta ja sen toteutuksesta:
 *
 * */





#include <iostream>
#include <vector>
#include <random>
#include <algorithm>


using namespace std;

const unsigned int BOARD_SIDE = 5;
const unsigned char EMPTY = ' ';

using Game_board_type = vector<vector<int>>;

// Muuttaa annetun numeerisen merkkijonon vastaavaksi kokonaisluvuksi
// (kutsumalla stoi-funktiota).
// Jos annettu merkkijono ei ole numeerinen, palauttaa nollan.
//
// Converts the given numeric string to the corresponding integer
// (by calling stoi).
// If the given string is not numeric, returns zero.
unsigned int stoi_with_check(const string& str)
{
    bool is_numeric = true;
    for(unsigned int i = 0; i < str.length(); ++i)
    {
        if(not isdigit(str.at(i)))
        {
            is_numeric = false;
            break;
        }
    }
    if(is_numeric)
    {
        return stoi(str);
    }
    else
    {
        return 0;
    }
}

// Splits the given string str into parts separated by the given delimiter
// and returns the parts in a vector.
// If the delimiter appears inside quatation, ignores delimiter,
// i.e. does not split quoted text.
std::vector<std::string> split_ignoring_quoted_delim(const std::string& str,
                                                     char delimiter)
{
    std::vector<std::string> result = {""};
    bool inside_quotation = false;
    for(char current_char : str)
    {
        if(current_char == '"')
        {
            inside_quotation = not inside_quotation;
        }
        else if(current_char == delimiter and not inside_quotation)
        {
            result.push_back("");
        }
        else
        {
            result.back().push_back(current_char);
        }
    }
    if(result.back() == "")
    {
        result.erase(--result.end());
    }
    return result;
}






// Tulostaa pelilaudan rivi- ja sarakenumeroineen.
//
// Prints the game board with row and column numbers.
void print(const Game_board_type& gameboard)
{
    cout << "=================" << endl;
    cout << "|   | 1 2 3 4 5 |" << endl;
    cout << "-----------------" << endl;
    for(unsigned int i = 0; i < BOARD_SIDE; ++i)
    {
        cout << "| " << i + 1 << " | ";
        for(unsigned int j = 0; j < BOARD_SIDE; ++j)
        {
            if(gameboard.at(i).at(j) == 0)
            {
                cout << EMPTY << " ";
            }
            else
            {
                cout << gameboard.at(i).at(j) << " ";
            }
        }
        cout << "|" << endl;
    }
    cout << "=================" << endl;
}

// Starts the game, asks for user input and fills the game_board vector with random numbers or input
// returns filled vectors
Game_board_type start_game(){


    Game_board_type gameboard;


    while (true){

        cout << "Select start (R for random, I for input): ";
        string command;
        cin >> command;
        if(command == "i" or command == "I"){
                cin.ignore();
                string line;
                cout << "Input: ";

                getline(cin, line);
                vector<string> parts = split_ignoring_quoted_delim(line, ' ');

                int i = 0;
                vector<int> v;
                while (true){
                    if (i == 25){
                        break;
                    }

                    v.push_back(stoi_with_check(parts.at(i)));
                    v.push_back(stoi_with_check(parts.at(i+1)));
                    v.push_back(stoi_with_check(parts.at(i+2)));
                    v.push_back(stoi_with_check(parts.at(i+3)));
                    v.push_back(stoi_with_check(parts.at(i+4)));
                    i += 5;
                    gameboard.push_back(v);
                    v.clear();
                }

                return gameboard;
                }

        else if (command == "r" or command == "R"){
            cout << "Enter seed value: ";
            int seed;
            cin >> seed;
            default_random_engine gen(seed);

            uniform_int_distribution<int> distr(1, 5);
            for (int i = 0; i < 5; i++){
                vector<int> v;
                int count = 0;
                while (true){
                    if (count == 5)
                    {
                        break;
                    }
                    else{
                        v.push_back(distr(gen));
                        count += 1;
                    }
                }
                gameboard.push_back(v);
                v.clear();
            }
            return gameboard;
        }
        else{
            continue;
        }

    }


}

// Checks if input is out of board or for other errors in input
bool input_check(Game_board_type gameboard,string x, string y){

    if (stoi_with_check(x) == 0 or stoi_with_check(y) == 0){
        cout << "Out of board" << endl;
        return 0;
    }

    else if(stoi_with_check(x) > 5 or stoi_with_check(x) < 1){
        cout << "Out of board" << endl;
        return 0;
    }
    else if(stoi_with_check(y) > 5 or stoi_with_check(y) < 1){
        cout << "Out of board" << endl;
        return 0;
    }
    else if(gameboard.at(stoi_with_check(y)-1).at(stoi_with_check(x)-1) == 0){
        cout << "Already removed" << endl;
        return 0;
    }
    else{
        return 1;
    }

}

bool check_for_lose(Game_board_type gameboard){

    Game_board_type check_horizontal;
    check_horizontal.clear();
    vector<int> v;
    for (int j = 0; j < 5; j++){
        for (int i = 0; i < 5; i++){
            v.push_back(gameboard.at(i).at(j));
        }
        check_horizontal.push_back(v);
        v.clear();
    }

    //Checks if there are 2 empty spaces vertically next to each other
    for (int i = 0; i < int(gameboard.at(i).size()-1); i++){
        if (gameboard.at(i).at(i) == 0 and gameboard.at(i).at(i+1) == 0){
            return 0;
        }
    }

    //Checks if there are 2 empty spaces horizontally next to each other
    for (int i = 0; i < int(check_horizontal.at(i).size()-1); i++){
        if (check_horizontal.at(i).at(i) == 0 and check_horizontal.at(i).at(i+1) == 0){
            return 0;
        }
    }
    return 1;



}



bool check_for_win(Game_board_type gameboard){
    Game_board_type check_horizontal;
    vector<int> v;
    for (int j = 0; j < 5; j++){
        for (int i = 0; i < 5; i++){
            v.push_back(gameboard.at(i).at(j));
        }
        check_horizontal.push_back(v);
        v.clear();
    }

    // Checks if horizontal lines only contain one element max 1 time
    for (int i = 0; i < int(gameboard.at(i).size()); i++){
        if (count(check_horizontal.at(i).begin(), check_horizontal.at(i).end(),i+1) > 1){
            return 0;
        }
    }

    // Checks if vertical lines only contain one element max 1 time
    for (int i = 0; i < int(gameboard.at(i).size()); i++){
        if (count(gameboard.at(i).begin(), gameboard.at(i).end(),i+1) > 1){
            return 0;
        }
    }


    return 1;



}

// Taking commands and executing actions according
void running_game(Game_board_type gameboard){

    cin.ignore(1000, '\n');
    while (true){

        string line;
        cout << "Enter removable element (x, y): " ;

        getline(cin, line);
        vector<string> parts = split_ignoring_quoted_delim(line, ' ');
        //Quits program with command q or Q
        if (parts.at(0) == "q" or parts.at(0) == "Q"){
            cout << "Quitting" << endl;
            break;
        }

        // Error check for input
        else if (input_check(gameboard, parts.at(0),parts.at(1)) == 0){
            continue;
        }

        // Removes tile according to coordinate and prints changed board
        else{
            int x = stoi_with_check(parts.at(0));
            int y = stoi_with_check(parts.at(1));
            gameboard.at(y-1).at(x-1) = 0;
            print(gameboard);

            if (check_for_lose(gameboard) == 0){
                cout << "You lost" << endl;
                break;
            }
            else{
                continue;
            }


        }

    }

}






int main()
{
    Game_board_type gameboard = start_game();
    print(gameboard);
    running_game(gameboard);





    return 0;
}
