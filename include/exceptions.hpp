#pragma once

#include <exception>
#include <string>

class EmptyQueueException : public std::exception
{
public:
    virtual char const * what() const noexcept { return "Error. Empty queue\n"; }
};


class FullQueueException : public std::exception
{
public:
    virtual char const * what() const noexcept { return "Error. Full queue\n"; }
};