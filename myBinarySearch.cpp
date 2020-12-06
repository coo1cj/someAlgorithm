#include "myBinarySearch.h"

int myBinarySearch1(int a[], int x, int lo, int hi){
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(a[mid] < x)
            lo = mid + 1;
        else if(a[mid] > x)
            hi = mid - 1;
        else
            return mid;
    }
    return -1;
}


int myBinarySearch2(double a[], double x, int lo, int hi)
{
    if(lo > hi) return -1;
    int mid = lo + (hi - lo) / 2;
    if(a[mid] < x){
        myBinarySearch2(a, x, mid + 1, hi);
    }
        
    else if(a[mid] > x){
        myBinarySearch2(a, x, lo, mid - 1);
    }
        
    else{
        return mid;
    }
    return -1;  
}


