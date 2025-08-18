#include <bits/stdc++.h>
using namespace std;

int main(){
    // int arr[10];
    
    // 静态数组定义，赋值
    // memset(arr, 0, sizeof(arr));
    // arr[0] = 1;
    // arr[1] = 2;
    // int a = arr[0];
    // cout << a << endl;

    // 增-尾加
    // for(int i = 0; i < 10; i++){
    //     arr[i] = i;
    // }
    // arr[4] = 4;
    // arr[5] = 5;

    // 增-插入
    // for(int i = 4; i > 2; i--){
    //     arr[i] = arr[i-1];
    // }
    // arr[2] = 666;

    // 增-内存空间满
    // int newArr[20];
    // memset(newArr, 0, sizeof(newArr));
    // for(int i = 0; i < 10; i++){
    //     newArr[i] = arr[i];
    // }
    // newArr[10] = 666;

    // newArr[10] = -1;    // -1 means delete

    // 删
    // for(int i = 0; i < 5; i++){
    //     arr[i] = i;
    // }

    // for(int i = 1; i < 5; i++){
    //     arr[i] = arr[i+1];
    // }
    // arr[4] = -1;
    
    // 动态数组：动态数组底层还是静态数组，只是自动帮我们进行数组空间的扩缩容，并把增删查改操作进行了封装，让我们使用起来更方便而已。
    vector<int> arr;
    for(int i = 0; i < 10; i++){
        arr.push_back(i);
    }
    
    arr.insert(arr.begin() + 2, 666);
    arr.insert(arr.begin(), -1);

    arr.pop_back();
    arr.erase(arr.begin() + 2);
    int a = arr[0];
    arr[0] = 100;
    int index = find(arr.begin(), arr.end(), 666) - arr.begin();

    cout << index << endl;
    
    return 0;
    
}
