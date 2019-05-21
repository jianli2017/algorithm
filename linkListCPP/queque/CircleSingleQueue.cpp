//
//  Queue.cpp
//  linkListCPP
//
//  Created by lijian on 2019/5/21.
//  Copyright © 2019 lijian. All rights reserved.
//

#include "CircleSingleQueue.hpp"
#include <memory>
using namespace std;
#include <iostream>

CircleSingleQueue::CircleSingleQueue() {
    element =new int[defaultSize];
    memset(element, 0, defaultSize);
    first = 0;
}

void CircleSingleQueue::enqueue(int element) {
    expand(size);
    int index = indexOf(size++);
    this->element[index] = element;
}


int CircleSingleQueue::dequeue() {
    int index = indexOf(0);
    int ret = this->element[index] ;
    this->element[index] = 0;
    first = indexOf(1);
    --size;
    return ret;
}

int CircleSingleQueue::front() {
   return element[first];
}

int CircleSingleQueue::back() {
    return element[indexOf(first+size-1)];
}
void CircleSingleQueue::expand(int newSize) {
    ///如果不需要扩容，直接返回
    if (newSize < capacity) {
        return;
    }
    cout << "扩容 " << "oldCapacity=" << capacity;
    
    //扩容1.5倍
    newSize = newSize + (newSize>>1);
    int* newElement = new int[newSize]();
    
    //拷贝原有数据
    for (int i=0; i<size; i++) {
        newElement[i] =element[indexOf(i)];
    }
    
    delete [] element;
    element = newElement;
    capacity = newSize;
    first = 0;
    cout << "capacity=" << capacity << endl;
}


void CircleSingleQueue::print() {
    for (int i = 0; i< capacity; ++i) {
        cout << "【" << element[i]  << "】" << "  " ;
    }
    cout << "size= " << size << "    capacity=" << capacity << "  first=" << first << endl ;
}

int CircleSingleQueue::indexOf(int index) {
    index = first + index;
    if (index < 0) {
        index = index + capacity;
    }
    index= index % capacity;
    return index;
}
