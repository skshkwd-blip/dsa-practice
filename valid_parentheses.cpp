// Problem: Valid Parentheses
// Approach: Stack

#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);  // Push opening bracket
            } else {
                if(st.empty()) { // No opening bracket to match
                    return false;
                }

                if((st.top() == '(' && s[i] == ')') ||
                   (st.top() == '{' && s[i] == '}') ||
                   (st.top() == '[' && s[i] == ']')) {
                    st.pop(); // Matching pair
                } else {
                    return false; // Mismatch
                }
            }
        }

        return st.empty(); // True if all brackets matched
    }
};

int main() {
    Solution obj;
    string s;

    cout << "Enter a string of brackets: ";
    cin >> s;

    if(obj.isValid(s)) {
        cout << "The string has valid brackets." << endl;
    } else {
        cout << "The string has invalid brackets." << endl;
    }

    return 0;
}
