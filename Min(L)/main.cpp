#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    vector<int> v;
    for (auto &a: arr){
        cin >> a;
    }
    v.assign(arr, arr+k);
    sort(v.begin(), v.end());
    unsigned i = 0;
    cout << v.front() << " ";
    for ( ;i < n - k  ; ++i){
        v.erase(lower_bound(v.begin(), v.end(), arr[i]));
        v.insert(lower_bound(v.begin(), v.end(), arr[k+i]),arr[k+i]);
        cout << v.front() << " ";
    }
    return 0;
}

