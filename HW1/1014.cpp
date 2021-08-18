#include <iostream>

using namespace std;

long a[10];

int main() {
    long long n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    if (n == 0) {
        cout << 10;
        return 0;
    }
    for (int i = 9; i > 1; i--) {
        while(n % i == 0) {
            a[i]++;
            n /= i;
        }
    }

//    for(int i = 0; i < 10; i++) {
//        cout << a[i] << " ";
//    }
//    cout << endl;
         if( n == 1) {

             for (int i = 2; i < 10; i++) {
                 if (a[i] != 0) {
                     for (int j = 0; j < a[i]; j++)
                         cout << i;
                 }
             }
         }
         else {
             cout << -1;
         }

    return 0;
}
