#pragma once

#include <deque>
#include <mutex>
#include "product.hpp"

class QueueManager
{
public:
    static QueueManager& getInstance()
        {
            static QueueManager    instance;    // Guaranteed to be destroyed.
                                                // Instantiated on first use.
            return instance;
        }

protected:
    std::deque<Product> products;
    std::mutex mutex;
    static const int maxElements;

    QueueManager(); //singleton

public:
    QueueManager(QueueManager const&)       = delete;
    void operator=(QueueManager const&)     = delete;

    void push(Product newProduct);
    Product pop();
};
