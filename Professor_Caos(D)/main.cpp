#include <iostream>

using namespace std;

int main() {
    int a,b,c,d,k;
    int temp = INT32_MIN;

    cin >> a >> b >> c >> d >> k;
    for (int i = 0; i<k; i++ ){
        a = a*b-c;

        if (a<c) {
            a=0;
            break;
        }
        if (a>=d){
            a=d;
        }
        if (temp == a ) {
            break;
        }
        temp = a;

        cout << a <<" temp_i -> "<< temp << " i-> " << i <<  '\n';
    }
    cout << a << "\n";
    return 0;
}
