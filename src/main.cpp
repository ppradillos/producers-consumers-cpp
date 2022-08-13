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
    Producer p4("Producer P4");
    Producer p5("Producer P5");

    Consumer c1;
    Consumer c2;
    Consumer c3;

    try
    {
        
        std::thread t1(&Producer::createAndPushProduct, &p1);
        std::thread t2(&Producer::createAndPushProduct, &p2);
        std::thread t3(&Consumer::getProduct, &c2);
        std::thread t4(&Consumer::getProduct, &c1);
        std::thread t5(&Consumer::getProduct, &c3);
        std::thread t6(&Producer::createAndPushProduct, &p3);
        std::thread t7(&Producer::createAndPushProduct, &p4);
        std::thread t8(&Producer::createAndPushProduct, &p5);

        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();
        t6.join();
        t7.join();
        t8.join();
    }
    catch(...)
    {
        std::cout << "exception catched" << '\n';
    }

    return 0;
}