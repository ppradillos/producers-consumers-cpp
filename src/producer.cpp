#include "producer.hpp"
#include "queueManager.hpp"
#include "exceptions.hpp"

#include <iostream>
#include <thread>
#include <chrono>

// Public functions
Producer::Producer(std::string name) : name(name)
{
    std::cout << "Producer [" << this->name << "] created\n";
}

Producer::~Producer()
{
    std::cout << "Producer [" << this->name << "] exited\n";
}

void Producer::createAndPushProducts(int numberOfProducts)
{
    for(int i = 0; i < numberOfProducts; ++i)
    {
        Product newProduct("newProduct", "1.0", this->name);
        this->pushProduct(newProduct);
        std::this_thread::sleep_for (std::chrono::milliseconds(500));
    }
}


// Protected functions
void Producer::pushProduct(Product &newProduct)
{
    try
    {
        QueueManager::getInstance().push(newProduct);
        std::cout << "Product pushed into the queue by " << this->name << "\n";
    }
    catch(const FullQueueException* e)
    {
        std::cout << e->what() << "\n";
    }
    
    return;
}
