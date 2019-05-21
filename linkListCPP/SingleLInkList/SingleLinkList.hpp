//
//  LinkList.hpp
//  LJMainEntry
//
//  Created by lijian on 2019/5/16.
//

#ifndef LinkList_hpp
#define LinkList_hpp

#include <stdio.h>
#include <iostream>
using namespace std;


template <typename T>
class SingleLinkList {
private:
    class LinkListNode {
        friend SingleLinkList;
        T element;
        LinkListNode *next;
        
        LinkListNode(T e, LinkListNode* n){
            element = e;
            next = n;
        }
    };
    
    LinkListNode *first = nullptr;
    int size = 0;
    static const int Element_Not_Find = -1;
public:
    SingleLinkList();
    //添加元素
    void add(T element);
    void add(int index, T element) ;
    
    //查找元素的索引
    int indexOf(T element);
    
    //删除元素
    T remove(T element) ;
    //打印链表
    void print() ;
private:
    //根据索引，查找node
    LinkListNode *node(int index) {
        LinkListNode *node = first;
        for (int i=0; i<index; ++i) {
            node= node->next;
        }
        return node;
    }
};


//添加元素
template <typename T>
void SingleLinkList<T>::add(T element){
    add(size, element);
}


template <typename T>
//单链表的插入，必须找到前一个节点
void SingleLinkList<T>::add(int index, T element) {
    if (index ==0) {
        first = new LinkListNode(element, first);
    } else {
        //找到pre节点
        LinkListNode *pre= node(index-1);
        pre->next = new LinkListNode(element,pre->next);
    }
    ++size;
}

//查找元素的索引
template <typename T>
int SingleLinkList<T>::indexOf(T element) {
    LinkListNode *node = first;
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
T SingleLinkList<T>::remove(T element) {
    int index = indexOf(element);
    LinkListNode *removeNode = first;
    if (index ==0) {
        first = first->next;
    } else if (index>0 && index <size){
        //找到前一个节点
        LinkListNode *pre = node(index -1);
        removeNode = pre->next;
        pre->next = removeNode->next;
    } else {
        return 0;
    }
    T ret = removeNode->element;
    delete removeNode;
    --size;
    return ret;
}

//打印链表
template <typename T>
void SingleLinkList<T>::print() {
    LinkListNode *node = first;
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

//构造函数
template <typename T>
SingleLinkList<T>::SingleLinkList(){
    first = nullptr;
    size = 0;
}



#endif /* LinkList_hpp */
