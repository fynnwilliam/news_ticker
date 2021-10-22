#pragma once

#include <cstddef>

class counter
{
private:
    std::size_t count_{};
    
public:
    counter() = default;
    
    std::size_t data() const;
    counter& operator++();
    counter  operator++(int);
    counter  operator--(int);
    counter& operator--();
    void reset();
    void   set();
};