#pragma once

#include <vector>
#include "product.hpp"

/** @class Consumer
 * @brief this class will pull products from the shared queue
 */

class Consumer
{
protected:
    std::string name;

public:
    Consumer(std::string name);
    ~Consumer();

    /**
     * @brief Get either N products from the shared queue or as many as possible if there are less than N products in it. 
     * 
     * @param numberOfProducts 
     * @return std::vector<Product> products retrieved from the queue.
     */
    std::vector<Product> getProducts(int numberOfProducts);

protected:
    /**
     * @brief Get a product from the shared queue, if not empty.
     * 
     * @return Product 
     */
    Product getProduct();
};
