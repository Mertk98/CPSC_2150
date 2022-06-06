#ifndef _STACK_H_
#define _STACK_H_

template <typename T>
class Stack
{
    public:
    Stack();
    int size() const;
    bool empty();
    // Define your own exception
    const T& top() const throw (StackEmpty);

}

#endif