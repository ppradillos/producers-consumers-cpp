#pragma once

#include "product.hpp"

class Producer
{
protected:
    std::string name;

public:
    Producer(std::string name);

    void createAndPushProduct();
};