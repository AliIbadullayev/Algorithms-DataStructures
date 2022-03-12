#include <iostream>

using namespace std;

int main() {
    int a,b,c,d,k;
    int temp = -2;

    cin >> a >> b >> c >> d >> k;
    for (int i = 0; i<k; i++ ){
        if (c == 0 && b == 1) break;
        a = a*b-c;

        if (a<c) {
            a=0;
            break;
        }
        if (a>=d){
            a=d;
            if (temp == i-1) break;
            temp = i;
        }

        cout << a <<" temp_i -> "<< temp << " i-> " << i <<  '\n';
    }
    cout << a << "\n";
    return 0;
}
