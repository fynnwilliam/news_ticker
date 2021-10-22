#include "counter.h"

std::size_t counter::data() const
{
    return count_;
}
     
counter& counter::operator++()
{
    ++count_;

    return *this;
}

counter  counter::operator++(int)
{
    counter count = *this;
    ++*this;
    
    return count;
}

counter& counter::operator--()
{
    --count_;
    return *this;
}

counter  counter::operator--(int)
{
    counter count = *this;
    --*this;
    
    return count;
}

void counter::reset() { count_ = 0; }

void counter::set(int c)
{
    count_ = c >= 0 ? c : 0;
}