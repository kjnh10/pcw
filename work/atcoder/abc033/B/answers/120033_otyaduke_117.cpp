#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>

struct town {
    int num;
    std::string name;
    town () {}
    town (int num, std::string name) : num(num), name(name) {}
};

bool comp (const town &t1, const town &t2) {
    return t1.num > t2.num;
}

std::string a;
int n, b;
long long sum;
std::vector<town> t;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a >> b;
        t.push_back(town(b, a));
        sum += b;
    }
    std::sort(t.begin(), t.end(), comp);
    if (t[0].num > sum/2) std::cout << t[0].name << std::endl;
    else std::cout << "atcoder\n";

}
