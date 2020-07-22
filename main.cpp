#include <iostream>
#include <stack>
#include <string>

struct Node
{
    char c;
    int pos;
    Node(char _c, int _pos) {
        c = _c;
        pos = _pos;
    }
};

int isBalanced(std::string const str)
{
    std::stack<Node> seq;
    int i = 0;
    for (; i < str.length(); ++i)
    {
        char c = str.at(i);
        if (c == '{' || c == '(' || c == '[')
        {
            Node e(c, i);
            seq.push(e);
        }
        else if (c == ']' || c == '}' || c == ')') {
            if (seq.empty()) return i+1;
            else {
                Node top = seq.top();
                if ((top.c == '[' && c == ']') || (top.c == '(' && c == ')') || (top.c == '{' && c == '}'))
                    seq.pop();
                else return i+1;
            }
        }
        else continue;
    }
    if (seq.empty()) return -1;
    else {
        Node top = seq.top();
        return top.pos+1;
    }
}

int main() {
    std::string s1;
    std::count << "Enter the string to check it" std::endl;
    std::cin >> s1;

    int k = isBalanced(s1);
    if (k == -1 ) std::cout << "Success" ;
    else std::cout << k;

    return 0;
}