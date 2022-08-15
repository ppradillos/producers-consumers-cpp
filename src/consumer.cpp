#include "consumer.hpp"
#include "queueManager.hpp"
#include "exceptions.hpp"

#include <iostream>
#include <thread>
#include <chrono>

// Public funtions
Consumer::Consumer(std::string name) : name(name)
{
    std::cout << "Consumer [" << this->name << "] created\n";
}

Consumer::~Consumer()
{
    std::cout << "Consumer [" << this->name << "] exited\n";
}

std::vector<Product> Consumer::getProducts(int numberOfProducts)
{
    std::vector<Product> products;

    for(int i = 0; i < numberOfProducts; ++i)
    {
        products.push_back(this->getProduct());
        std::this_thread::sleep_for (std::chrono::milliseconds(500));
    }

    return products;
}

// Protected functions
Product Consumer::getProduct()
{
    Product p("","","");    //empty product

    try 
    {
        p = QueueManager::getInstance().pop();
        std::cout << "Consumer " << this->name << ": got product\n";

    } catch (EmptyQueueException* e) 
    {
        std::cout << e->what() << "\n";
    }

    return p;
}
