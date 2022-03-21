#include "cards.hh"

using namespace std;

Cards::Cards(): top_(nullptr)
{
}

void Cards::add(int id)
{
    top_ = new Card_data{ id, !top_ ? nullptr : top_};
}

void Cards::print_from_top_to_bottom(std::ostream& s)
{
    if (!top_)
        return;

    auto ptr = top_;
    auto i = 0;

    while (ptr)
    {
        s << ++i << ": " << ptr->data << std::endl;
        ptr = ptr->next;
    }
}

bool Cards::remove(int& id)
{
    if (!top_)
        return false;

    id = top_->data;
    const auto to_be_removed = top_;
    top_ = top_->next;
    delete to_be_removed;

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

void Cards::print_from_bottom_to_top(std::ostream& s)
{
    recursive_print(top_, s);
}

int Cards::recursive_print(Card_data* top, std::ostream& s)
{
    if (!top->next)
    {
        s << "1: " << top->data << endl;
        return 1;
    }
    const auto i = recursive_print(top->next, s) + 1;
    s << i << ": " << top->data << endl;
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
