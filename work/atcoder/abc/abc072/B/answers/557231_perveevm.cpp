#include <bits/stdc++.h>

int main(void) {
    std::string str;
    std::cin >> str;
    for (int i = 0; i < str.size(); i += 2) {
        std::cout << str[i];
    }
    std::cout << '\n';
    return 0;
}