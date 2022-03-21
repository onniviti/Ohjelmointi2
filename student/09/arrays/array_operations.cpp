#include "array_operations.hh"
#include <iostream>
#include <algorithm>
#include <cstddef>

int greatest_v1(int *itemptr, int size)
{
    int max = *(itemptr + 0);
    for (int i=0; i<size; i++){
        if(*(itemptr+i) > max){
            max = *(itemptr+i);
        }
    }
    return max;

}

int greatest_v2(int *itemptr, int *endptr)
{
    int max = *itemptr;
    for (;itemptr != endptr; ++itemptr){
        int current = *(itemptr);
        max = std::max(max, current);
    }
    return max;
}

void copy(int *itemptr, int *endptr, int *targetptr)
{

    while(itemptr <= endptr){
        *targetptr  = *itemptr;
        targetptr++;
        itemptr++;
    }
}

void reverse(int *leftptr, int *rightptr)
{
    -- rightptr;
    for(; leftptr < rightptr; ++leftptr, --rightptr){

        int temp = * leftptr;
        *leftptr = *rightptr;
        *rightptr = temp;



    }




}

