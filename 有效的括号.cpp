#include <iostream>
#include <unordered_map>
#include <stack>

int main()
{
    char s[] = "{}";

    int n = sizeof(s) / sizeof(s[0]);
    if (n % 2 != 1)
    {
        std::cout << "false" << std::endl;
        return 0;
    }
    std::unordered_map<char, char> pairs = 
    {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    std::stack<char> stk;
    for (char& ch : s)
    {
        if (ch == '\0') continue;
        if (pairs.count(ch)) 
        {
            if (stk.empty() || stk.top() != pairs[ch]) 
            {
                std::cout << "false" << std::endl;
                return 0;
            }
            stk.pop();
        }
        else {
            stk.push(ch);
        }
    }
    if (stk.empty()) std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;
    return 0;
}