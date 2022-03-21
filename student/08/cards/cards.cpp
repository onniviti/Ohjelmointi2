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

Cards::~Cards(){
    while (!is_empty()){
        int dummy;
        remove(dummy);
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
    if (!top_)
        return false;

    if (!top_->next)
        return true;

    auto bottom_most = top_;
    Card_data* second_to_bottom = nullptr;

    for(;;)
    {
        const auto temp = bottom_most;
        if (temp->next)
            bottom_most = temp->next;
        else
            break;
        second_to_bottom = temp;
    }

    bottom_most->next = top_;
    top_ = bottom_most;
    second_to_bottom->next = nullptr;

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
