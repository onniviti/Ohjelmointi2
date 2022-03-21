#include "queue.hh"

Queue::Queue(unsigned cycle)
{
    cycle_ = cycle;
}

void Queue::enqueue(string reg)
{
    if(is_green_)
    {
        cout << "GREEN: The vehicle " << reg << " need not stop to wait" << endl;
        return;
    }

    if(!first_)
    {
        first_ = new Vehicle{ reg, nullptr };
        last_ = first_;
    }
    else
    {
        const auto new_last = new Vehicle{ reg, nullptr };
        last_->next = new_last;
        last_ = new_last;
    }
}

void Queue::switch_light()
{
    string print_out = !is_green_ ? "GREEN: " : "RED: ";
    if(is_green_)
    {
        is_green_ = false;
        if (!first_)
            cout << print_out << "No vehicles waiting in traffic lights" << endl;
        return;
    }
    is_green_ = true;

    if (!first_)
    {
        cout << print_out << "No vehicles waiting in traffic lights" << endl;
        return;
    }

    print_out += "Vehicle(s) ";

    for (auto i = 0u; i < cycle_; i++)
    {
        if (!first_)
            break;
        print_out += first_->reg_num + " ";
        const auto to_be_deleted = first_;
        first_ = first_->next;
        delete to_be_deleted;
    }
    is_green_ = false;

    cout << print_out << "can go on" << endl;
}

void Queue::reset_cycle(unsigned int cycle)
{
    cycle_ = cycle;
}

void Queue::print()
{
    string print_out = is_green_ ? "GREEN: " : "RED: ";

    if(!first_)
    {
        cout << print_out << "No vehicles waiting in traffic lights" << endl;
        return;
    }

    print_out += "Vehicle(s) ";
    auto ptr = first_;
    while(ptr)
    {
        print_out += ptr->reg_num + " ";
        ptr = ptr->next;
    }

    cout << print_out << (is_green_ ? "can go on" : "waiting in traffic lights") << endl;
}

Queue::~Queue()
{
    if (!first_)
        return;

    auto ptr = first_;
    while (ptr)
    {
        const auto to_be_deleted = ptr;
        ptr = ptr->next;
        delete to_be_deleted;
    }
    first_ = nullptr;
    last_ = nullptr;
}
