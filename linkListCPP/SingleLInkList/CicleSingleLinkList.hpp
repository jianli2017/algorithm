//
//  CicleSingleLinkList.hpp
//  linkListCPP
//
//  Created by lijian on 2019/5/17.
//  Copyright © 2019 lijian. All rights reserved.
//

#ifndef CicleSingleLinkList_hpp
#define CicleSingleLinkList_hpp

#include <stdio.h>


#include <iostream>
using namespace std;


template <typename T>
class CicleSingleLinkList {
private:
    class Node {
        friend CicleSingleLinkList;
        T element;
        Node *next;
        Node(T e, Node* n):element(e),next(n) {}; //构造函数
    };
    
private:
    Node *first = nullptr;
    int size = 0;

public:
    CicleSingleLinkList(Node *f,int s):first(f),size(s){}; //构造函数
    CicleSingleLinkList():CicleSingleLinkList(nullptr,0){}; //构造函数
    //添加元素
    void add(T element);
    void add(int index, T element) ;
    
    //查找元素的索引
    int indexOf(T element);
    
    //删除元素
    T remove(T element) ;
    
    //打印链表
    void print() ;
    
public:
    const int Element_Not_Find = -1;
    
private:
    //根据索引，查找node
    Node *node(int index);
    

};


//添加元素
template <typename T>
void CicleSingleLinkList<T>::add(T element){
    add(size, element);
}


template <typename T>
//单链表的插入，必须找到前一个节点
void CicleSingleLinkList<T>::add(int index, T element) {
    if (0 == index) {
        Node *c = new Node(element, first);
        
        //需要找到最后一个元素，将最后一个元素的nex设置为c
        Node *last ;
        if (0 == size) {
            last = c;
        } else {
            last = node(size-1);
        }
        last->next = c;
        first = c;
    } else {
        //找到pre节点
        Node *pre= node(index-1);
        pre->next = new Node(element,pre->next);
    }
    ++size;
}

//查找元素的索引
template <typename T>
int CicleSingleLinkList<T>::indexOf(T element) {
    Node *node = first;
    for (int i=0; i< size; ++i) {
        if (element == node->element) {
            return i;
        }
        node = node->next;
    }
    return Element_Not_Find;
}

//删除元素
template <typename T>
T CicleSingleLinkList<T>::remove(T element) {
    int index = indexOf(element);
    Node *c ;
    if (index ==0) {
        c = first;  //要删除的节点
        if (1 == size) {
            first = nullptr;
        } else {
            Node *last = node(size - 1);
            first = first->next;
            last->next = first;
        }
    } else {
        //找到前一个节点
        Node *pre = node(index -1);
        c = pre->next;
        pre->next = c->next;
    }
    T ret = c->element;
    delete c;
    --size;
    return ret;
}


//根据索引，查找node
template <typename T>
typename CicleSingleLinkList<T>::Node* CicleSingleLinkList<T>::node(int index) {
    Node *node = first;
    for (int i=0; i<index; ++i) {
        node= node->next;
    }
    return node;
}


//打印链表
template <typename T>
void CicleSingleLinkList<T>::print() {
    Node *node = first;
    for (int i=0; i<size; ++i) {
        cout << "【" << node->element << "】"; //打印当前节点
        if (node->next) {
            cout  << "_" << node->next->element ;
        }
        cout << "    ";
        node=node->next;
    }
    cout << endl;
}



#endif /* CicleSingleLinkList_hpp */
