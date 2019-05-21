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


void testSingleLinkList();
void testDoubleLinkList();
void testCircleSingleLinkList3();
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
