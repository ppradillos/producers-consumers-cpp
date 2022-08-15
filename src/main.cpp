#include "consumer.hpp"
#include "producer.hpp"
#include <iostream>
#include <thread>

int main (int argc, char** argv)
{
    (void)argc;
    (void)argv;

    Producer p1("Producer P1");
    Producer p2("Producer P2");
    Producer p3("Producer P3");

    Consumer c1("Consumer c1");
    Consumer c2("Consumer c2");

    try
    {
        
        std::thread t1(&Producer::createAndPushProducts, &p1, 3);
        std::thread t2(&Producer::createAndPushProducts, &p2, 2);
        std::thread t3(&Consumer::getProducts, &c2, 6);
        std::thread t4(&Consumer::getProducts, &c1, 4);
        std::thread t5(&Producer::createAndPushProducts, &p3, 3);

        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();
    }
    catch(...)
    {
        std::cout << "exception catched" << '\n';
    }

    return 0;
}