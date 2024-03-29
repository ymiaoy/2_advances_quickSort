//
// Created by miao on 2019/10/8.
//

#ifndef INC_2019_10_08_INSERTIONSORT_H
#define INC_2019_10_08_INSERTIONSORT_H
#include <iostream>
#include <algorithm>

using namespace std;

namespace InsertionSort {
    template<typename T>
    void insertionSort(T arr[], int n) {

        for (int i = 1; i < n; i++) {

            T e = arr[i];
            int j;
            for (j = i; j > 0 && arr[j - 1] > e; j--)
                arr[j] = arr[j - 1];
            arr[j] = e;
        }

        return;
    }

// 对arr[l...r]范围的数组进行插入排序
    template<typename T>
    void insertionSort(T arr[], int l, int r) {

        for (int i = l + 1; i <= r; i++) {

            T e = arr[i];
            int j;
            for (j = i; j > l && arr[j - 1] > e; j--)
                arr[j] = arr[j - 1];
            arr[j] = e;
        }

        return;
    }
};
#endif //INC_2019_10_08_INSERTIONSORT_H
