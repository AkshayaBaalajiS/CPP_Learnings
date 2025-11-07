#include "DequeQueue.h"

int main() {
    try {
        DequeQueue queue;

        queue.pushBack(10);
        queue.pushBack(20);
        queue.pushFront(5);
        queue.pushFront(2);

        queue.display();

        queue.popFront();
        queue.popBack();

        queue.display();
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
