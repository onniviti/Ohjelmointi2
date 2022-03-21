#include "gradecounter.hh"
#include <iostream>

using namespace std;

bool is_valid_input(unsigned int n,
                    unsigned int g,
                    unsigned int p,
                    unsigned int e)
{
    bool is_valid = true;
    if(n > MAX_N_POINTS)
    {
        cout << "Impossible N points" << endl;
        is_valid = false;
    }
    if(g > MAX_G_POINTS)
    {
        cout << "Impossible G points" << endl;
        is_valid = false;
    }
    if(p > MAX_P_POINTS)
    {
        cout << "Impossible P points" << endl;
        is_valid = false;
    }
    if(e > 5)
    {
        cout << "Impossible exam grade" << endl;
        is_valid = false;
    }
    return is_valid;
}

int main()
{
    unsigned int n = 0;
    unsigned int g = 0;
    unsigned int p = 0;
    unsigned int e = 0;
    cout << "Enter N points, G points, P points: ";
    cin >> n;
    cin >> g;
    cin >> p;
    cout << "Enter exam grade (if no exam, enter zero): ";
    cin >> e;

    if(is_valid_input(n, g, p, e))
    {
        cout << "The final grade is " << count_final_grade(n, g, p, e) << endl;
    }

    return 0;
}
