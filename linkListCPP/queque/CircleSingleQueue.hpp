//
//  Queue.hpp
//  linkListCPP
//
//  Created by lijian on 2019/5/21.
//  Copyright © 2019 lijian. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>

#endif /* Queue_hpp */

class CircleSingleQueue {
public:
    static const int defaultSize = 10;
private:
    int *element;
    int size = 0;
    int capacity  = defaultSize;
    int first;
public:
    CircleSingleQueue();
    void enqueue(int);
    
    int dequeue();
    
    int front();
    
    int back();
    
    void print();
private:
    void expand(int size);
    
    int indexOf(int index);
};
