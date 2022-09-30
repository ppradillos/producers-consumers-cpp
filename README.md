# Small implementation of a classic concurrent programming design pattern: producers/consumers

## Description
The goal of this small program is to serve as a reference of how to implement a non-trivial scenario where several producers and consumers make use of a shared buffer or queue. For the system not to be a total mess, the access of such shared resource must be thread-safe.

This solution was implemented in C/C++ programming language.

## Classes
* [Product](https://github.com/ppradillos/producers-consumers-cpp/blob/master/include/product.hpp) : a simple data structure with 3 parameters: name, version and manufacturer.
* [Producer](https://github.com/ppradillos/producers-consumers-cpp/blob/master/include/producer.hpp): it implements a function to create and push products to the shared queue, if not full.
* [Consumer](https://github.com/ppradillos/producers-consumers-cpp/blob/master/include/consumer.hpp): it implements a function to pop products from the shared queue, if not empty.
* [QueueManager](https://github.com/ppradillos/producers-consumers-cpp/blob/master/include/queueManager.hpp):
    * It implements thread-safe mechanism to access the shared queue.
    * It provides an abstraction layer to consumers and producers of such thread-safe mechanisms.
    * It also provides abstraction to STL containers.
    * Singleton design-pattern.

In addition, there are also some custom exceptions implemented:
* [EmptyQueueException](https://github.com/ppradillos/producers-consumers-cpp/blob/master/include/exceptions.hpp)
* [FullQueueException](https://github.com/ppradillos/producers-consumers-cpp/blob/master/include/exceptions.hpp)

The purpose of such exceptions is not other than prevent any new product from being pushed into the queue, or prevent any pop from an empty queue.

## Run the program
### Main function

The `main` function serves as a testing tool for this producers/consumers program. The user can instantiate as many producers and consumers as they want to run threads upon them and check how the threads interact with the shared queue.

### VS Code ready project

Some JSON files are provided to build the program in VS Code. They are located in the [.vscode](https://github.com/ppradillos/producers-consumers-cpp/tree/master/.vscode) folder.

### To-Do
A thread wrapper implementation to make easier the testing process. So, the user will not call the STL API straight away by themselves, but only a "runThread"-style function.

## License
MIT 
