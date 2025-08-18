#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    // standard output
    // cout << a << endl;
    // cout << "Hello" << "," << "World!" << endl;
    // string s = "abc";
    // cout << s << " " << a << endl;

    // control flow
    // if (a > 5) {
    //     cout << "a > 5" << endl;
    // } else if (a == 5) {
    //     cout << "a == 5" << endl;
    // } else {
    //     cout << "a < 5" << endl;
    // }

    // loop
    for (int i = 0; i <5; i++) {
        cout << i << " ";
    }
    cout << endl;
    int num = 100;
    while (num > 0) {
        cout << num << " ";
        num /= 2;
    }

    // data structures
    

    return 0;
}
