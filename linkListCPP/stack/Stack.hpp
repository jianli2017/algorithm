//
//  Stack.hpp
//  linkListCPP
//
//  Created by lijian on 2019/5/21.
//  Copyright © 2019 lijian. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>



class Stack {
public:
    static const int defaultSize = 10;
private:
    
    int *element;
    int size = 0;
    int capacity  = defaultSize;
public:
    Stack();
    void push(int);
    
    int pop ();
    
    int top();
    
    void print();
private:
    void expand(int size);
};


#endif /* Stack_hpp */


