#include <iostream>
#include <stack>
using namespace std;


int main() {
    char letters[200000];
    cin >> letters;

    int n = 0;
    int push_count = 0;
    int pop_count = 0;
    int previous_push = 0;
    int result_count = 0;
    while (letters[n] != '\0'){
        n++;
    }
    int result[n/2];
    stack<char> stack;

    for(int i = 0 ; i<n; i++){
        if (stack.empty()) {
            stack.push(letters[i]);
            push_count++;
            pop_count = 0;
            previous_push =1;
            continue;
        }
        if (i > 0 && stack.top() == letters[i]){
            stack.push(letters[i]);
            push_count++;
            previous_push =1;
            continue;
        }
        if (tolower(stack.top()) != tolower(letters[i])){
            stack.push(letters[i]);
            push_count++;
            previous_push = 1;
        } else {
            stack.pop();
            if (previous_push == 1) result[result_count] = push_count;
            else result[result_count] = push_count - pop_count;
            pop_count ++;
            previous_push = 0;
            result_count++;
        }
        if (stack.empty()) pop_count = 0;
    }


    if(stack.empty()) {
        cout<<"Possible\n";
        for(int i = 0 ; i<n/2; i++){
            cout << result[i] << " ";
        }
    }
    else cout << "Impossible";
    return 0;
}
