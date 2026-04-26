#include <string>
#include <stack>
using namespace std;

bool pairedParentheses(string str) {
    int counter = 0;
    for (char ch : str) {
        if (ch == '(') {
            counter++;
        } else if (ch == ')') {
            if (counter == 0) {
                return false;
            }
            counter--;
        }
    }

    return counter == 0;
}