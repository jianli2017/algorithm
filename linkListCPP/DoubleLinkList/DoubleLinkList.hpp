//
//  LJDoubleLinkList.hpp
//  linkListCPP
//
//  Created by lijian on 2019/5/17.
//  Copyright © 2019 lijian. All rights reserved.
//

#ifndef LJDoubleLinkList_hpp
#define LJDoubleLinkList_hpp
#include <iostream>
#include <stdio.h>

using namespace std;

template <typename T>
class DoubleLinkList {
    //定义节点类
private:
    class Node {
    private:
        friend DoubleLinkList;
        Node *pre;
        T element;
        Node *next;
        
    public:
        Node(Node* p, T e,Node* n):pre(p),element(e),next(n){};
    };
    Node *first = nullptr;
    Node *last = nullptr;
    int size = 0;
public:
    const int Element_Not_Find = -1;
    //构造函数
    DoubleLinkList(Node *f,Node *l,int s):first(f),last(l),size(s) {};
    DoubleLinkList():DoubleLinkList(nullptr,nullptr,0) {};
    
    //添加元素
    void add(T element);
    void add(int index, T element);
    
    //根据元素找到索引
    int indexOf(T element);
    
    //删除元素
    int remove(T element);
    
    void print();
private:
    //根据索引获取node节点
    Node * node(int index);
};

template <typename T>
void DoubleLinkList<T>::add(T element) {
    add(size, element);
}

template <typename T>
void DoubleLinkList<T>::add(int index, T element) {

    Node *c ;  //插入后，插入的元素
    Node *p ; //插入后，插入的前驱元素
    Node *n ; //插入后，插入的后继元素
    if (index == size) { //尾部插入，兼容空链表
        p = last;
        c = new Node(p,element,nullptr);
        if (0 == size) { //空链表
            first = c;
        } else { //尾部，非空链表
            p->next = c;
        }
        last = c; //最后需要重新设置尾节点
    } else { //位置 [0->size-1]
        n = node(index);
        p = n->pre;
        c = new Node(p,element,n);
        n->pre = c; //设置next的pre
        if (p) { //[1，size-1]
            p->next = c;
        }
        else { //位置位【0】的情况
            first = c;
        }
    }
    ++size;
}


//删除元素
template <typename T>
int DoubleLinkList<T>::remove(T element) {
    //首节点、一个节点的情况
    int index = indexOf(element);
    Node *c = node(index); //要删除的元素
    Node *p = c->pre; //要删除元素 的前驱
    Node *n = c->next; //要删除元素 的后继
    
    //处理前指针
    if (p == nullptr) {
        first = n;
    } else
    {
        p->next = n;
    }
    
    //处理后指针
    if (n == nullptr) {
        last = p;
    } else {
        n->pre= p;
    }
    --size;
    T ret = c->element;
    delete c;
    return ret;
}

//根据元素找到索引
template <typename T>
int DoubleLinkList<T>::indexOf(T element) {
    Node* node = first;
    for(int i = 0; i<size; ++i) {
        if (element == node->element) {
            return  i;
        }
        node = node->next;
    }
    return Element_Not_Find;
}

//根据索引获取node节点
template <typename T>
typename DoubleLinkList<T>::Node * DoubleLinkList<T>::node(int index) {
    //校验index,统一不做
    Node *node;
    if (index < size/2) {
        node = first;
        for (int i=0; i<index; ++i) {
            node = node->next;
        }
    } else {
        node = last;
        for (int i = size -1; i > index; --i) {
            node = node->pre;
        }
    }
     return node;
}


template <typename T>
void DoubleLinkList<T>::print() {
    Node *node = first;
    for (int i=0; i<size; ++i) {
        if (node->pre) {
            cout<< node->pre->element << "_";
        }
        cout << "【" << node->element << "】";
        if (node->next) {
            cout <<  "_" << node->next->element ;
        }
        
        cout << "    " ;
        node=node->next;
    }
    cout << endl;
}


#endif /* LJDoubleLinkList_hpp */
