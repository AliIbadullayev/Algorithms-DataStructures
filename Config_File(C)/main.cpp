#include <iostream>
#include <map>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

// to split the word by '='
vector<string> split (const string& s, const string& delimiter) {
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

// checker that the second part in line (after '=') is number
bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (c=='-') continue;
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

// the brain of my program
//void func (map<string, int> m){
//    vector<string> a;
//    string input;
//    while(cin>>input){
//        if (input=="{") func(m);
//        else if (input=="}") return ;
//        else {
//            a = split(input,"=");
//            string first = a.at(0);
//            auto second = a.at(1);
//            if (isNumber(second)) {
//                m[first]= stoi(second);
//            } else {
//                if (m.find(first) == m.end() && m.find(second) == m.end()){
//                    m[first]=0;
//                    m[second]=0;
//                } else m[first]=m[second];
//                cout << m[first]<<"\n";
//            }
//        }
//    }
//}

// the head of my program
int main()
{
    map<string, int> m {  };
    int count =0;
    vector<string> a;
    vector<map<string, int>> b;
    string input;
    while(cin>>input){
        if (input=="{") {
            b.push_back(m);
            count++;
        }
        else if (input=="}"){
            count--;
            if(count ==0){
                m = b.back();
            }
            else {
                b.pop_back();
                m = b.back();
            }
        }
        else {
            a = split(input,"=");
            string first = a.at(0);
            auto second = a.at(1);
            if (isNumber(second)) {
                m[first]= stoi(second);
            } else {
                if (m.find(first) == m.end() && m.find(second) == m.end()){
                    m[first]=0;
                    m[second]=0;
                } else m[first]=m[second];
                cout << m[first]<<"\n";
            }
        }
    }
//    vector <int> nums;
//    nums.push_back(6);
//    cout << nums.front() << "\n";
//    cout << nums.back() << "\n";
//    nums.push_back(7);
//    cout << nums.front() << "\n";
//    cout << nums.back() << "\n";
    return 0;
}