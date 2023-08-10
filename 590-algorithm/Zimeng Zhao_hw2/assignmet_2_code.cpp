/******************************************************************************

Template for Assignment-2

*******************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;

void Recursive_Bubble_Sort(int array[], int array_length){
    // sort array using recursive bubble sort algorithm.
    //The 1st element can be considered sorted
    if(array_length == 1){
        return;
    }
    //base case
    for(int i = 0; i < array_length -1; i++){
        if(array[i] > array[i + 1]){
            swap(array[i],array[i + 1]);
        }
    }
    Recursive_Bubble_Sort(array, array_length--);
}

void Recursive_Insertion_Sort(int array[], int array_length){
    // sort array using recursive insertion sort algorithm.
    int j,key;
    //The 1st element can be considered sorted
    if(array_length == 1){
        return;
    }
    //Recursively sort first n-1 elements.
    Recursive_Insertion_Sort(array, array_length -1);
    key = array[array_length - 1];
    j = array_length - 2;
    //Traverse through the sorted sequence of elements from back to front
    while(j >= 0 && array[j] > key){
        array[j + 1] = array[j];
        j = j - 1;
    }
    //Insert last element at its correct position
    array[j + 1] = key;
}

bool Check(int array[], int array_length){
    // complete the function to check if the array is sorted.
    for(int i = 0; i <= array_length; i++){
        if(array[i - 1] > array [i]){
            return false;
        }
        return true;
    }
}

int main()
{
    int array[100];                               // sample for generating rand array.
    for(int i = 0 ; i < 100 ; i++){
        array[i] = rand()%1000;
    }
    return 0;
}
