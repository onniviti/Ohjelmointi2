#include <iostream>
#include <string>
#ifndef RECURSIVE_FUNC
#define RECURSIVE_FUNC
#endif

bool palindrome_recursive(std::string s)
{
  RECURSIVE_FUNC
  // Do not remove RECURSIVE_FUNC declaration, it's necessary for automatic testing to work
  // ------------


  // Add your implementation here
  int first = 0;
  int last = s.length()-1;

  if (last == 1){
      if(s[0] == s[1]){
          return true;
      }
      else{
          return false;
      }
  }

  if ( first == last){
      return true;
  }
  if (s[first] != s[last]){
      return false;
  }
  if(first < last +1){
      s = s.substr(1, s.size()-2);
      return palindrome_recursive(s);
  }
  return true;




}

// Do not modify rest of the code, or the automated testing won't work.
#ifndef UNIT_TESTING
int main()
{
    std::cout << "Enter a word: ";
    std::string word;
    std::cin >> word;

    if(palindrome_recursive(word)){
        std::cout << word << " is a palindrome" << std::endl;
    } else {
        std::cout << word << " is not a palindrome" << std::endl;
    }
}
#endif
