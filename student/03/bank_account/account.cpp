#include "account.hh"
#include <iostream>

Account::Account(const std::string& owner, bool has_credit):  has_credit_(has_credit), owner_(owner)
{
    generate_iban();

}



void Account::set_credit_limit(int amount)
{
    if (has_credit_)
            credit_limit_ = amount;
        else
            std::cout << "Cannot set credit limit: the account has no credit card" << std::endl;

}

void Account::save_money(int amount)
{
    balance_ += amount;
}

void Account::take_money(int amount)
{
    if (balance_ > amount){
            balance_ -= amount;
            std::cout << amount << " euros taken: new balance of " << iban_ << " is "<< balance_
                 << " euros" << std::endl;
        }
        else if (has_credit_){
            if ((credit_limit_ + balance_) >= amount){
                balance_ -= amount;
                std::cout << amount << " euros taken: new balance of " << iban_ << " is "
                     << balance_ << " euros" << std::endl;}
            else {
                std::cout << "Cannot take money: credit limit overflow" << std::endl;
            }

        }
        else
            std::cout << "Cannot take money: balance underflow" << std::endl;

}


// Setting initial value for the static attribute running_number_
int Account::running_number_ = 0;


void Account::generate_iban()
{
    ++running_number_;
    std::string suffix = "";
    if(running_number_ < 10)
    {
        suffix.append("0");
    }
    else if(running_number_ > 99)
    {
        std::cout << "Too many accounts" << std::endl;
    }
    suffix.append(std::to_string(running_number_));

    iban_ = "FI00 1234 ";
    iban_.append(suffix);
}





void Account::transfer_to(Account &vastaanottaja, int amount)
{
    if (balance_ > amount){
            balance_ -= amount;
            vastaanottaja.balance_ += amount;
            std::cout << amount << " euros taken: new balance of " << iban_ << " is "
                 << balance_ << " euros" << std::endl;
        }
        else if (has_credit_){
            if ((credit_limit_ + balance_) > amount){
                balance_ -= amount;
                vastaanottaja.balance_ += amount;
                std::cout << amount << " euros taken: new balance of " << iban_ << " is "
                     << balance_ << " euros" << std::endl;}
            else {
                std::cout << "Cannot take money: credit limit overflow" << std::endl;
                std::cout << "Transfer from " << iban_ << " failed" << std::endl;
        }}
        else {
            std::cout << "Cannot take money: balance underflow" << std::endl;
            std::cout << "Transfer from " << iban_ << " failed" << std::endl;
        }

}

void Account::print() const
{
    std::cout << owner_ << " : " << iban_ << " : " << balance_ << " euros" << std::endl;
}
