//
//  main.cpp
//  linkListCPP
//
//  Created by lijian on 2019/5/16.
//  Copyright © 2019 lijian. All rights reserved.
//

#include <iostream>
#include "SingleLinkList.hpp"
#include "DoubleLinkList.hpp"
#include "CicleSingleLinkList.hpp"

#include "Stack.hpp"
#include "CircleSingleQueue.hpp"

void testSingleLinkList();
void testDoubleLinkList();
void testCircleSingleLinkList3();
void testStack();
void testQueue();
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "********************";
    std::cout << "1. 单链表测试，添加和删除";
    std::cout << "********************" << endl;
    testSingleLinkList();
    
    
    std::cout << "********************";
    std::cout << "2. 双链表测试，添加和删除";
    std::cout << "********************" << endl;
    testDoubleLinkList();
    
    std::cout << "********************";
    std::cout << "3. 循环单链表 测试，添加和删除";
    std::cout << "********************" << endl;
    testCircleSingleLinkList3();
    
    
    std::cout << endl << endl ;
    std::cout << "********************";
    std::cout << "6. stack测试";
    std::cout << "********************" << endl;
    testStack();
    
    
    std::cout << endl << endl ;
    std::cout << "********************";
    std::cout << "7. 循环队列测试";
    std::cout << "********************" << endl;
    testQueue();
    
    return 0;
}
void testSingleLinkList()
{
    SingleLinkList<int> *link = new SingleLinkList<int>();
    link->add(1);
    link->print();
    link->add(2);
    link->print();
    link->add(3);
    link->print();
    link->add(4);
    link->print();
    link->add(5);
    link->print();
    
    link->add(0,0);
    link->print();
    
    link->add(6,6);
    link->print();
    
    cout << "开始删除：" << endl;
    link->remove(1);
    link->print();
    
    link->remove(5);
    link->print();
    
    link->remove(2);
    link->print();
    
    link->remove(3);
    link->print();
    
    link->remove(4);
    link->print();
}


void testDoubleLinkList() {
    DoubleLinkList<int> *dlink = new DoubleLinkList<int>();
    dlink->add(1);
    dlink->print();
    dlink->add(2);
    dlink->print();
    dlink->add(3);
    dlink->print();
    dlink->add(4);
    dlink->print();
    dlink->add(5);
    dlink->print();
    dlink->add(0,0);
    dlink->print();
    
    dlink->add(6,6);
    dlink->print();
    
    cout << "开始删除：" << endl;
    dlink->remove(1);
    dlink->print();
    
    dlink->remove(5);
    dlink->print();
    
    dlink->remove(2);
    dlink->print();
    
    dlink->remove(3);
    dlink->print();
    
    dlink->remove(4);
    dlink->print();
}


void testCircleSingleLinkList3()
{
    CicleSingleLinkList<int> *link = new CicleSingleLinkList<int>();
    link->add(1);
    link->print();
    link->add(2);
    link->print();
    link->add(3);
    link->print();
    link->add(4);
    link->print();
    link->add(5);
    link->print();
    
    link->add(0,0);
    link->print();
    
    link->add(6,6);
    link->print();
    
    cout << "开始删除：" << endl;
    link->remove(1);
    link->print();
    
    link->remove(5);
    link->print();
    
    link->remove(2);
    link->print();
    
    link->remove(3);
    link->print();
    
    link->remove(4);
    link->print();
    
    link->remove(0);
    link->print();
}



void testStack()
{
    Stack stack =  Stack();
    for (int i =1; i<= Stack::defaultSize; ++i) {
        stack.push(i);
    }
    stack.print();//【1，2，3，4，5，6，7，8，9，10】
    
    
    for (int i =0; i<5; ++i) {
        stack.pop();
    }
    
    stack.print(); //【1，2，3，4，5，0，0，0，0，0】
    
    
    for (int i =1; i<=10; ++i) {
        stack.push(i+10);
    }
    stack.print();//【【1，2，3，4，5，11，12，13，14，15】
    
    
    stack.push(15);
    stack.print();//【【1，2，3，4，5，11，12，13，14，15，16】
    
    cout << "top 元素" << stack.top() << endl;
  
}

void testQueue() {
    CircleSingleQueue queue =  CircleSingleQueue();
    for (int i =1; i<=CircleSingleQueue::defaultSize; ++i) {
        queue.enqueue(i);
    }
    queue.print();
    //[1,2,3,4,5,6,7,8,9,10]
    
    for (int i =0; i<5; ++i) {
        queue.dequeue();
    }
    queue.print();
    //[0,0,0,0,0,6,7,8,9,10]
    
    ///添加5个满了
    for (int i =1; i<=5; ++i) {
        queue.enqueue(i+10);
    }
    queue.print();
    //[11,12,13,14,15,6,7,8,9,10]
    
    //
    for (int i =1; i<=5; ++i) {
        queue.enqueue(i+15);
    }
    queue.print();
    //[6~20]
    
    queue.enqueue(21);
//    queue.enqueue(22);
//    queue.dequeue();
    
    queue.print();
    
}
