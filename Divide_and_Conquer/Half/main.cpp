#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define Max 10001
using namespace std;


// recursive solution

//int a[Max], key;
//
//int search(int bot, int top) {
//    int mid;
//    if (top >= bot) {
//        mid = (top + bot) / 2;
//        if (key == a[mid]) {
//            cout << mid << endl;
//            return 0;
//        } else if (key < a[mid]) {
//            search(bot, mid - 1);
//        } else {
//            search(mid + 1, top);
//        }
//
//    } else {
//        printf("-1\n");
//        return 0;
//    }
//    return 0;
//}
//
//int main() {
//    int size;
//    cin >> size;
//    for (int i = 1; i <= size; i++) {
//        cin >> a[i];
//    }
//    cin >> key;
//    search(1, size);
//
//    return 0;
//}
//

// non-recursive solution
int key, top, bot, mid, n, a[Max];

void half() {
    top = 1;
    bot = n;
    while (top <= bot) {
        mid = (top + bot) / 2;
        if (key == a[mid]) {
            cout << mid << endl;
            exit(0);
        } else if (key < a[mid]) {
            top = mid - 1;
        } else {
            bot = mid + 1;
        }
    }
    cout << -1 << endl;
};

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> key;
    if (key < a[1] || key > a[n])
        cout << -1 << endl;
    else
        half();
}
