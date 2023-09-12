#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue {  //Circular Queue
public:
    Queue();
    Queue(unsigned int size);
    ~Queue();
    void resize(unsigned int size);
    void enqueue(const T& value);
    T dequeue();
    T peek() const;
    bool isEmpty() const;
    void print_content() const;
private:
    T* queue;
    unsigned int front;
    unsigned int back;
    unsigned int size;
};

template <typename T>
Queue<T>::Queue() {
    size = 100;
    queue = new T[size+1];  //Always leave one space empty at end of queue
    front = 0;
    back = 0;
}

template <typename T>
Queue<T>::Queue(unsigned int size) {
    if (size <= 0) {
        throw std::invalid_argument("Please use size bigger than 0.");
    }
    this->size = size;
    queue = new T[size+1];
    front = 0;
    back = 0;
}

template <typename T>
Queue<T>::~Queue() {
    delete[] queue;
}

template <typename T>
void Queue<T>::resize(unsigned int size) {
    if (size <= 0) {
        throw std::invalid_argument("Invalid size for resizing.");
    }

    T* newQueue = new T[size+1];

    for (unsigned int i = 0; i < size+1; i++) {
        newQueue[i] = queue[(front + i)];
    }
    delete[] queue;
    queue = newQueue;
    front = 0;
    back = size;
    this->size = size+1;
}

template <typename T>
void Queue<T>::enqueue(const T& value) {
    if ((back + 1) % size == front) {
        throw std::overflow_error("Queue is full!");
    }
    queue[back] = value;
    back = (back + 1) % size;
}

template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty!");
    }
    T value = queue[front];
    front = (front + 1) % size;
    return value;
}

template <typename T>
T Queue<T>::peek() const {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty!");
    }
    return queue[front];
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return front == back;
}

template <typename T>
void Queue<T>::print_content() const {
    if (isEmpty()) {
        std::cout << "Queue is empty!" << std::endl;
        return;
    }
    std::cout << "Queue: ";
    for (unsigned int i = front; i != back; i = (i + 1) % size) {
        std::cout << queue[i] << " ";
    }
    std::cout << std::endl;
}


#endif // QUEUE_H