#pragma once

#include <string>

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

