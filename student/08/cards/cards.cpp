#include "cards.hh"
#include <iostream>



// TODO: Implement the methods here

Cards::Cards():top_(nullptr){

}

Card_data *Cards::get_topmost()
{
    return top_;
}


bool Cards::is_empty() const
{
    return top_ == nullptr;
}



Card_data *Cards::find_bottom()
{
    Card_data* current = nullptr;

    for (current = top_; current != nullptr && current -> next !=nullptr;
         current = current -> next){

    }
    return current;
}

void Cards::add(int id)
{
    auto* new_card = new Card_data{id, nullptr};
    if(!is_empty()){

        new_card->next = top_;
    }

    top_ = new_card;
}

void Cards::print_from_top_to_bottom(std::ostream &s)
{

    for ( auto* current = top_; current != nullptr; current = current -> next){
        s << (*current).data << "\n";
    }

}



bool Cards::remove(int &id)
{


    if ( is_empty()){
        return false;
    }
    auto* old_top = top_;
    top_ = old_top -> next;
    id = old_top->data;
    delete old_top;


    return true;



}

bool Cards::bottom_to_top()
{
    if (is_empty()){
        return false;
    }

    auto* old_top = top_;
    Card_data* new_bottom = nullptr;
    auto* new_top = top_;

    for (;new_top -> next != nullptr; new_bottom = new_top, new_top=new_top-> next){

    }
    top_ = new_top;

    if(new_top != old_top){
        new_top ->next = old_top;
    }

    if ( new_bottom != nullptr){
        new_bottom -> next = nullptr;}

    return true;

   }


bool Cards::top_to_bottom()
{
    if (!top_)
            return false;

        if (!top_->next)
            return true;

        auto bottom_most = top_;

        for (;;)
        {
            if (bottom_most->next)
                bottom_most = bottom_most->next;
            else
                break;
        }

        const auto new_top = top_->next;
        top_->next = nullptr;
        bottom_most->next = top_;
        top_ = new_top;

        return true;
}

void Cards::print_from_bottom_to_top(std::ostream &s)
{
    recursive_print(top_, s);
}

int Cards::recursive_print(Card_data* top, std::ostream& s)
{
    if (!top->next)
    {
        s << "1: " << top->data << std::endl;
        return 1;
    }
    const auto i = recursive_print(top->next, s) + 1;
    s << i << ": " << top->data << std::endl;
    return i;
}

Cards::~Cards()
{
    if (!top_)
        return;

    auto ptr = top_;
    while(ptr)
    {
        const auto to_be_deleted = ptr;
        ptr = ptr->next;
        delete to_be_deleted;
    }
    top_ = nullptr;
}





