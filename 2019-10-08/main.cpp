//快速排序的几个改进

#include <iostream>
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SortTestHelper.h"
using namespace InsertionSort;
using namespace MergeSort;
using namespace QuickSort;
using namespace SortTestHelper;

int main() {

    int n = 1000000;

    // 测试1 一般性测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = generateRandomArray(n,0,n);
    int* arr2 = copyIntArray(arr1,n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    cout<<endl;

    //测试2 测试一个近乎于有序的数组
    int swapTimes = 100;
    arr1 = generateNearlyOrderedArray(n, swapTimes);
    arr2 = copyIntArray(arr1, n);

    testSort("Merge Sort", mergeSort, arr1, n);
    testSort("Quick Sort", quickSort, arr2, n);

    delete[] arr1;
    delete[] arr2;
    cout << endl;

    return 0;
}