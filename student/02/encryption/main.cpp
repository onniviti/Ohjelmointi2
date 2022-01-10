#include <iostream>

using namespace std;

int main()
{
    std::string key;
    std::string message;

    std::cout << "Enter the encryption key: ";
    std::cin >> key;

    if ( key.length() != 26){

        std::cout << "Error! The encryption key must contain 26 characters." << endl;
        return EXIT_FAILURE;
    }
    for (std::string::size_type i = 0; i < key.length(); ++i)
    {
        if (key[i] < 'a' or key[i] > 'z')
            std::cout << "Error! The encryption key must contain only lower case characters." << endl;

    }

    for (char c = 'a'; c <= 'z'; ++c){
        if (key.find(c) == std::string::npos){
            std::cout << "Error! The encryption key must contain all alphabets a-z." << endl;
            return EXIT_FAILURE;
        }
    }
    std::cout << "Enter the text to be encrypted: ";
    std::cin >> message;

    std::cout << "Encrypted text: ";
    for (std::string::size_type i = 0; i < message.length(); ++i){
        char plain = message[i];
        char encrypted = key[plain - 'a'];
        std::cout << encrypted;


    }
    std::cout << std::endl;

    return 0;
}
