#include <iostream>

using namespace std;

int main() {
    int a,b,c,d,k;
    cin >> a >> b >> c >> d >> k;
    for (int i = 0; i<k; i++ ){
        if (a == b && c < a ) {
            a = a*b -c;
            break;
        }
        a = a*b-c;
        if (a < c) {
            a=0;
            break;
        }
        if (a > d) {
            a=d;
            break;
        }
        cout << a << " ";
    }
    cout << a << "\n";
    return 0;
}
