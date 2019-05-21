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

//构造函数
Stack::Stack() {
    element =new int[defaultSize]();
    size = 0;
}
/**
 栈顶插入元素

 @param  element 元素
 */
void Stack::push(int element) {
    expand(size);
    this->element[size++] = element;
}


int Stack::pop() {
    int e = this->element[size-1];
    
    //pop后，清除元素
    this->element[size-1] = 0;
    
    //大小减少
    size --;
    return e;
}

int Stack::top() {
    return this->element[size-1];
}

void Stack::expand(int newSize) {
    ///如果不需要扩容，直接返回
    if (newSize < capacity) {
        return;
    }
    cout << "扩容 " << "oldCapacity=" << capacity;
    
    //扩容1.5倍
    newSize = newSize + (newSize>>1);
    int* newElement = new int[newSize]();
    
    //拷贝原有数据
    for (int i=0; i<size; ++i) {
        newElement[i] = element[i];
    }
    //清理和重置操作
    delete [] element;
    element = newElement;
    capacity = newSize;
    cout << "capacity=" << capacity << endl;
}

void Stack::print() {
    for (int i = 0; i< size; i++) {
        cout << "【" << element[i]  << "】" << "  " ;
    }
    cout << "size= " << size << "    capacity=" << capacity << endl ;
}
