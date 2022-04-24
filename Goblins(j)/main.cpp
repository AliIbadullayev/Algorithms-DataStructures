#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, p;
    set<int> cars;
    vector<int> pos;
    vector<set<int>> cars_arr;
    int res = 0;

    cin >> n >> k >> p;
    int arr[n];
    for (int i = 0 ; i < p; i++){
        cin >> arr[i];
    }

    for (int i = 0 ; i < p; i++){
        cars.insert(arr[i]);
//        cout << "arr [i] -> " << arr[i] << endl;
        if (cars.size() == k) {
//            cout << "i -> " << i + 1 << endl;
            if (cars.find(arr[i+1]) != cars.end()) continue;
            if ( i == p - 1 ) continue;
            pos.push_back(i+1);
        } else if (cars.size() > k) {
            res = res + cars.size();
            cars.erase(cars.begin(), cars.end());
            cars.insert(arr[i]);
//            cout << "More than " << k << " cars on ground" << endl;
        }
    }

    int temp = 0 ;
    cars.erase(cars.begin(), cars.end());
    res = 0 ;
    pos.push_back(p);
//    for (auto pp : pos){
//        cout << pp << endl;
//    }

    for (int i = 0; i < pos.size(); i ++){
        for (int j = temp; j < pos[i]; j++){
            cars.insert(arr[j]);
//            if (cars.size() == 1) cout << j << " not full set" << endl;
//            cout << arr[j] << " arr[j]" << endl;
        }
        cars_arr.push_back(cars);
        cars.erase(cars.begin(), cars.end());
        temp = pos[i] ;
//        cout << temp << " temp" << endl;

    }
    std::vector<int> v_intersection;
    if (cars_arr.size() == 1 ) res = cars_arr[0].size();
    for (int a = 0; a < cars_arr.size() - 1; a++){
        if (a == 0) {
            res += cars_arr[a].size();
//            cout << cars_arr[a].size() << " <- size of first arr" <<endl;
        }
//        cout << "________"<<endl;
//        for (auto v:cars_arr[a+1]){
//            cout << v << " Cars"<<  endl;
//        }
//        cout << "________"<<endl;
        set_difference(cars_arr[a+1].begin(), cars_arr[a+1].end(),
                         cars_arr[a].begin(), cars_arr[a].end(),
                         std::inserter(v_intersection, v_intersection.begin()));
        res += v_intersection.size();
//        for (auto v:v_intersection){
//            cout << v << " insertication"<< endl;
//        }
        v_intersection.erase(v_intersection.begin(), v_intersection.end());
    }
    cout << res << endl;

}
