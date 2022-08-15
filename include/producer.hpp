#pragma once

#include "product.hpp"

/** @class Producer
 * @brief this class will create products and then push them into the shared queue
 */

class Producer
{
protected:
    std::string name;

public:
    Producer(std::string name);
    ~Producer();

    /**
     * @brief Create and push Products into the queue
     * 
     * @param number of products to create and push into the queue
     */
    void createAndPushProducts(int numberOfProducts);

protected:
    /**
 * @brief Push a product into the shared queue, if not full.
 * 
 * @return void
 */
    void pushProduct(Product &newProduct);
};
