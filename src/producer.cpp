#include "producer.hpp"
#include "queueManager.hpp"
#include "exceptions.hpp"
#include <iostream>

Producer::Producer(std::string name) : name(name)
{

}

void Producer::createAndPushProduct()
{
    try
    {
        QueueManager::getInstance().push(Product("newProduct", "1.0", this->name));
        std::cout << "Product pushed to the queue\n";
    }
    catch(const FullQueueException* e)
    {
        std::cout << e->what() << "\n";
    }
    
    return;
}