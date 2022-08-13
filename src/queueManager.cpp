#include "queueManager.hpp"
#include "exceptions.hpp"

const int QueueManager::maxElements = 10;

QueueManager::QueueManager()
{
    
}

void QueueManager::push(Product newProduct)
{
    std::lock_guard<std::mutex> lock(this->mutex);

    if(products.size() >= maxElements)
        throw new FullQueueException();

    products.push_back(newProduct);

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

    // mutex is automatically released when lock
    // goes out of scope

    return p;
}