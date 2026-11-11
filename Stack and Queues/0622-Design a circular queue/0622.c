typedef struct {
    int *arr;
    int front;
    int capacity;
    int count;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* q = malloc(sizeof(MyCircularQueue));

    q->arr = malloc(k * sizeof(int));
    q->front = 0;
    q->capacity = k;
    q->count = 0;

    return q;
}


bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(obj->count == obj->capacity)
        return false;

    int rear = (obj->front + obj->count) % obj->capacity;

    obj->arr[rear] = value;
    obj->count++;

    return true;
}


bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(obj->count == 0)
        return false;

    obj->front = (obj->front + 1) % obj->capacity;
    obj->count--;

    return true;
}


int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj->count == 0)
        return -1;

    return obj->arr[obj->front];
}


int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj->count == 0)
        return -1;

    int rear = (obj->front + obj->count - 1) % obj->capacity;

    return obj->arr[rear];
}


bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->count == 0;
}


bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->count == obj->capacity;
}


void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/