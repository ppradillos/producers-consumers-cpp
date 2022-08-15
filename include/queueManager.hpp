#pragma once

#include <deque>
#include <mutex>
#include "product.hpp"

/** @class QueueManager
 * @brief This class manages a shared queue where producers and consumers push and pop products, respectively.
 *        Because of the concurrent scenario, the class makes the access to the shared resource thread-safe.
 */

class QueueManager
{
public:
    /**
     * @brief Get the Instance object.
     * 
     * The nature of a thread-safe scenario makes the QueueManager class suitable for the Singleton design pattern
     */
    static QueueManager& getInstance()
        {
            static QueueManager    instance;    // Guaranteed to be destroyed.
                                                // Instantiated on first use.
            return instance;
        }

protected:
    static const int MAX_ELEMENTS;  // maximum elements for the shared queue
    std::deque<Product> products;   // the queue of products
    std::mutex mutex;

    QueueManager(); //singleton

public:
    QueueManager(QueueManager const&)       = delete;
    void operator=(QueueManager const&)     = delete;

    /**
     * @brief Push products into the queue if not full already. Throws FullQueueException otherwise.
     * 
     * @param newProduct 
     */
    void push(Product newProduct);

    /**
     * @brief Pop products from the queue if not empty already. Throws EmptyQueueException otherwise.
     * 
     * @return Product 
     */
    Product pop();
};
