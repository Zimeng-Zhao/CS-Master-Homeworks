#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void random(int num){
    vector<int> temp;
    for(int i = 0; i < num; i++){
        temp.push_back(i + 1);
    }
    random_shuffle(temp.begin, temp.end);
    
    for(int i = 0; i < temp.size; i++){
        count << temp[i] << " ";
    }
}

void main(){
   srand((int)time(0));
	randperm(10);
	system("pause");
}

