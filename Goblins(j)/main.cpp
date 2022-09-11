#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// for string delimiter
vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

int main() {
    deque<int> q_1 {}; // here is the beginning of queue
    deque<int> q_2 {}; // the second part of queue where first is privileged goblins than not privileged
    int n;
    string str;
    getline (cin,str);
    stringstream(str) >> n;

    int k ;
    for (int i = 0; i<n; i++){
        vector<string> str_arr;
        string res;
        getline(cin,res);
            str_arr = split(res, " " );
            if (str_arr.at(0) == "+") { // if not privileged
                q_2.push_back(stoi( str_arr.at(1)));
            }else if (str_arr.at(0) == "*"){ // if privileged
                q_2.push_front(stoi( str_arr.at(1)));
            } else {

                cout << q_1.front() << "\n";
                q_1.pop_front();

            }
            if (q_1.size() < q_2.size()) {
                q_1.push_back(q_2.front());
                q_2.pop_front();
            }

        }


    return 0;
}
