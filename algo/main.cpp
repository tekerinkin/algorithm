#include<iostream>
#include"LinkedList/ArrayBasedList.h"

using namespace std;

int main(){
    Alist<int> arr(5);
    for(size_t i = 1; i < 6; ++i){
        arr.append(i);
    }
    for(arr.moveToStart(); arr.curPos() < arr.length(); arr.next()){
        cout << arr.getVal() << " ";
    }
}