#ifndef ACCOUNT_HH
#define ACCOUNT_HH

#include <string>

class Account
{
public:
    // Constructor
    Account(const std::string& owner, bool has_credit = false);

    // More methods
    void set_credit_limit(int amount);

    void save_money(int amount);

    void take_money(int amount);

    void transfer_to(Account& vastaanottaja, int amount);

    void print() const;






private:
    // Generates IBAN (based on running_number_ below).
    // Allows no more than 99 accounts.
    void generate_iban();

    // Used for generating IBAN.
    // Static keyword means that the value of running_number_ is the same for
    // all Account objects.
    // In other words, running_number_ is a class-wide attribute, there is
    // no own copies of it for each object of the class.
    static int running_number_;
    int credit_limit_ = 0;
    int balance_ = 0;
    bool has_credit_ = false;
    std::string owner_;
    std::string iban_;


    // More attributes/methods
};



#endif // ACCOUNT_HH
