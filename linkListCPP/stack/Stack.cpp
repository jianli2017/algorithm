//
//  Stack.cpp
//  linkListCPP
//
//  Created by lijian on 2019/5/21.
//  Copyright © 2019 lijian. All rights reserved.
//

#include "Stack.hpp"
#include <memory>
#include <iostream>
using namespace std;

Stack::Stack() {
    element =new int[defaultSize];
    memset(element, 0, defaultSize);
}
/**
 插入元素

 @param  element 元素
 */
void Stack::push(int element) {
    expand(size);
    this->element[size++] = element;
}


int Stack::pop() {
    int e = this->element[size-1];
    size --;
    return e;
}

int Stack::top() {
    return this->element[size-1];
}

void Stack::expand(int size) {
    ///判断是否需要扩容
    if (size < capacity) {
        return;
    }
    cout << "扩容 " << "oldCapacity=" << capacity;
    int newSize = size + (size>>1);
    int* newElement = new int[newSize];
    memset(newElement, 0, newSize);
    capacity = newSize;
    
    //拷贝原有数据
    memcpy(newElement, element, size);
    delete [] element;
    element = newElement;
    cout << "capacity=" << capacity << endl;
    
}


void Stack::print() {
    for (int i = 0; i< size; ++i) {
        cout << "【" << i  << "】" << "  " ;
    }
    cout << "size= " << size << "    capacity=" << capacity << endl ;
}
