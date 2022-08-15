#include "queueManager.hpp"
#include "exceptions.hpp"
#include <iostream>

const int QueueManager::MAX_ELEMENTS = 10;

QueueManager::QueueManager()
{
    
}

void QueueManager::push(Product newProduct)
{
    std::lock_guard<std::mutex> lock(this->mutex);

    if(products.size() >= MAX_ELEMENTS)
        throw new FullQueueException();

    products.push_back(newProduct);
    std::cout << "Items in queue: " << products.size() << "\n";

    // mutex is automatically released when lock
    // goes out of scope

    return;
}

Product QueueManager::pop()
{
    std::lock_guard<std::mutex> lock(this->mutex);

    if(products.size() <= 0)
        throw new EmptyQueueException();

    Product p = products.front();
    products.pop_front();
    std::cout << "Items in queue: " << products.size() << "\n";

    // mutex is automatically released when lock
    // goes out of scope

    return p;
}
