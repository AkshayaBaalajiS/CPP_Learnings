#ifndef DEQUEQUEUE_H
#define DEQUEQUEUE_H

#include <iostream>
#include <deque>
#include <stdexcept>

#ifdef ENABLE_DEBUG
    #define LOG_DEBUG(msg) std::cout << "[DEBUG] " << msg << std::endl;
#else
    #define LOG_DEBUG(msg)
#endif

// A simple custom allocator (not really optimized, just to show concept)
template <typename T>
class MyAllocator {
public:
    using value_type = T;

    MyAllocator() noexcept {}

    template <typename U>
    MyAllocator(const MyAllocator<U>&) noexcept {}

    T* allocate(std::size_t n) {
        std::cout << "Allocating " << n << " elements" << std::endl;
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    void deallocate(T* ptr, std::size_t n) {
        std::cout << "Deallocating " << n << " elements" << std::endl;
        ::operator delete(ptr);
    }

    // Allow for rebinding of allocator (required by some containers like std::deque)
    template <typename U>
    struct rebind {
        using other = MyAllocator<U>;
    };
};

template <typename T, typename U>
bool operator==(const MyAllocator<T>&, const MyAllocator<U>&) { return true; }

template <typename T, typename U>
bool operator!=(const MyAllocator<T>&, const MyAllocator<U>&) { return false; }

class DequeQueue {
private:
    // Use custom allocator.
    std::deque<int, MyAllocator<int>> dq;

public:
    DequeQueue() {
        LOG_DEBUG("DequeQueue constructed.");
    }

    ~DequeQueue() {
        LOG_DEBUG("DequeQueue destructed.");
    }

    // Push an element to the back (pushback).
    void pushBack(int value) {
        dq.push_back(value);
        LOG_DEBUG("Pushed back: " + std::to_string(value));
    }

    // Push an element to the front (pushfront).
    void pushFront(int value) {
        dq.push_front(value);
        LOG_DEBUG("Pushed front: " + std::to_string(value));
    }

    // Pop an element from the front.
    void popFront() {
        if (dq.empty()) {
            throw std::underflow_error("Queue is empty! Cannot pop.");
        }
        int value = dq.front();
        dq.pop_front();
        LOG_DEBUG("Popped front: " + std::to_string(value));
    }

    // Pop an element from the back.
    void popBack() {
        if (dq.empty()) {
            throw std::underflow_error("Queue is empty! Cannot pop.");
        }
        int value = dq.back();
        dq.pop_back();
        LOG_DEBUG("Popped back: " + std::to_string(value));
    }

    // Display the current state of the deque.
    void display() const {
        if (dq.empty()) {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }

        std::cout << "Queue contents: ";
        for (int val : dq) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

#endif // DEQUEQUEUE_H
