/******************************************************************************

Template for Assignment-1

*******************************************************************************/

#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace chrono;

//problem 1

void bubble_sort(int array[], int array_length){
    // sort array using bubble sort algorithm.
    int cur = 0;
    for(int i = 0; i < array_length; i++){
        for(int j = array_length -1; j >= i + 1; j--){
            if(array[j] < array[j - 1]){
                cur = array[j];
                array[j] = array[j - 1];
                array[j - 1] = cur;
            }
        }
    }
}

void insertion_sort(int array[], int array_length){
    // sort array using insertion sort algorithm.
    int key = 0;
    for(int j = 1; j < array_length; j++){
        key = array[j];
        int i = j - 1;
        while(array[i] > key && i >= 0){
            array[i + 1] = array[i];
            i = i - 1;
        }
        array[i + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

//problem 2
void bubble_sort(int array[], int array_length, int cur){
    // sort array using bubble sort algorithm.
    //int cur = 0;
    for(int i = 0; i < array_length; i++){
        for(int j = array_length -1; j >= i + 1; j--){
            if(array[j] < array[j - 1]){
                cur = array[j];
                array[j] = array[j - 1];
                array[j - 1] = cur;
            }
        }
    }
}

void insertion_sort(int array[], int array_length, int key){
    // sort array using insertion sort algorithm.
    //int key = 0;
    for(int j = 2; j < array_length; j++){
        key = array[j];
        int i = j - 1;
        while(array[i] > key && i >= 0){
            array[i + 1] = array[i];
            i = i - 1;
        }
        array[i + 1] = key;
    }
}

void merge2(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r, int t) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, t);
        mergeSort(arr, m + 1, r, t);

        merge2(arr, l, m, r);
    }
}

int main()
{//problem 1
    int a[10];
    int b[100];
    int c[1000];
    for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++){
        a[i]=rand()%100;
    }

    for(int i = 0; i < sizeof(b)/sizeof(b[0]); i++){
        b[i]=rand()%1000;
    }

    for(int i = 0; i < sizeof(c)/sizeof(c[0]); i++){
        c[i]=rand()%10000;
    }

    for(int i=0; i<sizeof(a)/sizeof(a[0]); i++){
        cout << a[i] << " ";
    }
    cout << endl;
//random
    typedef std::chrono::high_resolution_clock Clock;
    auto T1 = Clock::now();
    //mergeSort(a,0,sizeof(a) / sizeof(a[0])-1);
    //insertion_sort(b,sizeof(b) / sizeof(b[0])-1);
    //bubble_sort(b,sizeof(b) / sizeof(b[0])-1);
    //insertion_sort(a, sizeof(a) / sizeof(a[0])-1);
    bubble_sort(a, sizeof(a) / sizeof(a[0]));
    auto T2 = Clock::now();//计时结束
    std::cout <<std::chrono::duration_cast<std::chrono::nanoseconds>(T2 - T1).count()<< '\n';

    int sorted[sizeof(a) / sizeof(a[0])];
    int re_sorted[sizeof(a) / sizeof(a[0])];
    for(int i=0; i<sizeof(a)/sizeof(a[0]); i++){
        sorted[i] = a[i];
        re_sorted[i] = a[sizeof(a)/sizeof(a[0]) - i - 1];
        cout << a[i] << " ";
    }
    cout << endl;

    //sorted arrays
    for(int i=0; i<sizeof(a)/sizeof(a[0]); i++) {
        cout << sorted[i] << " ";
    }
    cout << "\n";

    typedef std::chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();
    //insertion_sort(b,sizeof(sorted) / sizeof(sorted[0])-1);
    //bubble_sort(b,sizeof(sorted) / sizeof(sorted[0])-1);
    //mergeSort(a,0,sizeof(sorted) / sizeof(sorted[0])-1);
    //insertion_sort(a, sizeof(a) / sizeof(a[0])-1);
    bubble_sort(a, sizeof(a) / sizeof(a[0]));

    auto t2 = Clock::now();//计时结束
    std::cout <<std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()<< '\n';
    //float t2 = clock();

    for(int i=0; i<sizeof(sorted)/sizeof(sorted[0]); i++){
        sorted[i] = a[i];
        cout << sorted[i] << " ";
    }
    cout << endl;

//re_sorted

    for(int i=0; i<sizeof(a)/sizeof(a[0]); i++) {
        cout << re_sorted[i] << " ";

    }
    cout << "\n";
    typedef std::chrono::high_resolution_clock Clock;
    auto m1 = Clock::now();
    //mergeSort(a,0,sizeof(re_sorted) / sizeof(re_sorted[0])-1);
    //insertion_sort(a,sizeof(re_sorted) / sizeof(re_sorted[0])-1);
    bubble_sort(a,sizeof(re_sorted) / sizeof(re_sorted[0])-1);
    //float m2 = clock();
    auto m2 = Clock::now();//计时结束
    std::cout <<std::chrono::duration_cast<std::chrono::nanoseconds>(m2 - m1).count()<< '\n';
    for(int i=0; i<sizeof(re_sorted)/sizeof(re_sorted[0]); i++){
        re_sorted[i] = a[i];
        cout << re_sorted[i] << " ";
    }
    cout << endl;

    return 0;

//    problem2
//    int* pArray;//set up pointers
//    int i;
//    pArray = new int[10];
//
//    for (i = 0; i < 10; i++)//random array
//        pArray[i] = rand()%100;
//
//    insertion_sort(pArray, 10, 0);//调用排序算法
//    for (i = 0; i < 10; i++)//system out
//        cout << pArray[i] << "  ";
//    return 0;
}