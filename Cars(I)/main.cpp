#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
#include <utility>


using namespace std;

int main() {
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> pos[n]; // it is array in which we save indexes of each car in
    int arr[p]; // input data
    priority_queue<pair<int, int>> priority; // here is priority that helps to delete/change element that is on top
    unordered_set<int> cars; // here is container to cars that on floor at this iteration
    int result = 0;

    unsigned i = 0;
    while (i != p){
        cin >> arr[i] ;
        pos[--arr[i]].push_back(i);
        i++;

    }

//    for (auto &a: pos){
//        for (auto b: a){
//            cout << b << endl;
//        }
//        cout << endl;
//    }

    i = 0;
    for (; i < p ; i++) {
        pos[arr[i]].erase(pos[arr[i]].begin());

        if (cars.find(arr[i]) == cars.end()) {
            if (cars.size() >= k) {
                cars.erase(priority.top().second);
                priority.pop();

            }
            result++;
            cars.insert(arr[i]);

        }

        if (pos[arr[i]].empty()) priority.push({INT32_MAX, arr[i]});
        else priority.push({pos[arr[i]].front(), arr[i]});
    }
    cout << result << endl;


    return 0;
}
