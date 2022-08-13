#include "consumer.hpp"
#include "queueManager.hpp"
#include "exceptions.hpp"
#include <iostream>

Consumer::Consumer()
{

}

Product Consumer::getProduct()
{
    Product p("","","");    //empty product

    try 
    {
        std::cout << "Consumer: getting product\n";
        p = QueueManager::getInstance().pop();

    } catch (EmptyQueueException* e) 
    {
        std::cout << e->what() << "\n";
    }

    return p;
}