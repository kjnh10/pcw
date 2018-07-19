#include <bits/stdc++.h>
using namespace std;
#define REP(i, s, n) for (int i = s; i < n; ++i)
#define rep(i, n) REP(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG true
// sort(a.begin(), a.end(), std::greater<int>());

/*
std::vector<std::string> split(const std::string &input, char delimiter)
{
    std::istringstream stream(input);

    std::string field;
    std::vector<std::string> result;
    while (std::getline(stream, field, delimiter))
    {
        result.push_back(field);
    }
    return result;
}
*/
/*
int dfs(int foo, int timer)
{
    //foo is node number
    if (finds[foo].first != -1)
        return timer;
    finds[foo].first = ++timer;
    int result = timer;
    if (data[foo].size() != 0)
    {
        rep(i, data[foo].size())
        {
            result = dfs(data[foo][i], result);
        }
    }
    finds[foo].second = ++result;
    return result;
}
*/

int main()
{
    int a;
    cin>>a;
    double b= sqrt(a);
    a=(int)b;
    cout<<a*a<<endl;
}
