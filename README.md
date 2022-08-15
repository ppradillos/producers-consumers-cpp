# producers-consumers-cpp
Small implementation of a classic concurrent programming design pattern: producers/consumers

The goal of this small program is to serve as a simple reference of how to implement a non-trivial scenario where several producers and consumers make use of a shared buffer or queue. For the system not to be a total mess, the access of such shared resource must be thread-safe. 

The class 'QueueManager' implements the thread-safe mechanism, providing an abstraction layer to consumers and producers, who are unaware of such security tools. In addition, that class also provides abstraction to STL containers.

Some JSON files are provided to build the program in VS Code.
