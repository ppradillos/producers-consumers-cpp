#pragma once

#include <string>

/** @class Product
 * @brief Data structure composed by name, version and manufacturer. Created by producers, consumed by consumers.
 * 
 */

class Product
{
protected:
    std::string name;
    std::string version;
    std::string manufacturer;

public:
    Product(std::string name, std::string version, std::string manufacturer);

    std::string getName() { return name;}
    std::string getversion() { return version;}
    std::string getmanufacturer() { return manufacturer;}
};

