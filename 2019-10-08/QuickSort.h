//
// Created by miao on 2019/10/8.
//
/*
 *  改进/修改：
 *
 *       1. 在递归到底部，元素少的时候，采用插入排序的方法
 */

#ifndef INC_2019_10_08_QUICKSORT_H
#define INC_2019_10_08_QUICKSORT_H
#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cassert>

#include "InsertionSort.h"
using namespace InsertionSort;

namespace QuickSort{
    // 对arr[l...r]部分进行partition操作
    // 返回p, 使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
    template <typename T>
    int __partition(T arr[], int l, int r){

        //2.2第二个改进的地方的第二步骤：选择一个尽可能处在数组中间的v
        swap(arr[l], arr[rand()%(r-l+1)+l]); //把左侧的v和处于l,r中间的一个随机位置的元素互换
        T v = arr[l];                        //再将该随机得到的元素赋值给v

        int j = l; // arr[l+1...j] < v ; arr[j+1...i) > v
        for( int i = l + 1 ; i <= r ; i ++ )
            if( arr[i] < v ){
                j ++;
                swap( arr[j] , arr[i] );
            }

        swap( arr[l] , arr[j]);

        return j;
    }

    // 对arr[l...r]部分进行快速排序
    template <typename T>
    void __quickSort(T arr[], int l, int r){
//*******************  1. 第一个改进优化的地方 ************************
        //if( l >= r )
          //  return;
        if(r-l <= 15)
        {
            insertionSort(arr, l, r);
            return;
        }
//*******************  end of  第一个改进优化 ************************
        int p = __partition(arr, l, r);
        __quickSort(arr, l, p-1 );
        __quickSort(arr, p+1, r);
    }

    template <typename T>
    void quickSort(T arr[], int n){
//*******************  2. 第二个改进优化的地方 ************************
       srand(time(NULL)); //2.1改进的第一步：首先设置随机种子
                                         //2.2第二步骤：去修改__partition()函数

        __quickSort(arr, 0, n-1);


//*******************  end of  第一个改进优化 ************************
    }
};
#endif //INC_2019_10_08_QUICKSORT_H
