#include "player.hh"

Player::Player(const std::string& name): name_(name), points_(0)
{

}

std::string Player::get_name()
{
    return name_;
}

int Player::get_points()
{
    return points_;

}

bool Player::has_won()
{
    return points_ == 50;
}

void Player::add_points(int amount)
{
    points_ += amount;
        if (points_ > 50){
            std::cout << name_ << " gets penalty points!" << std::endl;
            points_ = 25;
        }

}





