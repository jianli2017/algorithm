//
//  LinkList.cpp
//  LJMainEntry
//
//  Created by lijian on 2019/5/16.
//

#include "SingleLinkList.hpp"

//template <typename T>
//LinkList<T>::LinkList(){
//    first = nullptr;
//    size = 0;
//}

/*
template <typename T>
void LinkList<T>::add(T element){
    add(size, element);
}

template <typename T>
void LinkList<T>::add(int index, T element) {
    if (index ==0) {
        first->next = new LinkListNode(element, first);
    } else {
        //找到pre节点
        LinkListNode *pre= node(index-1);
        pre->next = new LinkListNode(element,pre->next);
    }
}

template <typename T>
int LinkList<T>::indexOf(T element) {
    LinkListNode *node = first;
    for (int i=0; i<size; i++) {
        if (element == node->element) {
            return i;
        }
    }
    return Element_Not_Find;
}
*/

