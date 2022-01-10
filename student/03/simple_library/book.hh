#ifndef BOOK_HH
#define BOOK_HH


#include "date.hh"

#include <string>


class Book
{
public:
    Book(const std::string& author_name, const std::string& title);

    void print();

    void loan(const Date& loan_date);

    void renew();

    void give_back();


private:

    const std::string AUTHOR_NAME_;
    const std::string TITLE_;

    Date loan_date_;
    Date expiry_date_;
    bool is_loaned_;

};

#endif // BOOK_HH
