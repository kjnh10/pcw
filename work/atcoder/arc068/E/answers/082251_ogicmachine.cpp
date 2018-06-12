#include <tuple>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <iostream>
namespace loquat {
template <typename T, typename F = std::plus<T>>
class fenwick_tree {
public:
	using value_type = T;
private:
	std::vector<T> m_data;
	F m_func;
public:
	explicit fenwick_tree(
		size_t n,
		const value_type& x = value_type(),
		const F& f = F())
		: m_data(n + 1)
		, m_func(f)
	{
		m_data[0] = value_type();
		for(size_t i = 1; i <= n; ++i){
			m_data[i] = x;
			for(size_t j = i; (j & 1) == 0u; j >>= 1){
				m_data[i] = m_func(m_data[j], m_data[i]);
			}
		}
	}
	value_type query(size_t i) const {
		value_type s = m_data[i];
		for(i -= i & -i; i > 0; i -= i & -i){
			s = m_func(m_data[i], s);
		}
		return s;
	}
	void modify(size_t i, const value_type& x){
		const auto n = m_data.size();
		for(++i; i < n; i += i & -i){
			m_data[i] = m_func(m_data[i], x);
		}
	}
};
}
using namespace std;
using pii = pair<int, int>;
int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<pii> segs;
	for(int i = 0; i < n; ++i){
		int l, r;
		cin >> l >> r;
		++r;
		segs.emplace_back(r - l, l);
	}
	sort(segs.begin(), segs.end());
	loquat::fenwick_tree<int> ft(m + 2);
	for(int i = 1, j = 0; i <= m; ++i){
		while(j < n && segs[j].first < i){
			const auto p = segs[j];
			ft.modify(p.second, 1);
			ft.modify(p.second + p.first, -1);
			++j;
		}
		int answer = n - j;
		for(int k = i; k <= m; k += i){
			answer += ft.query(k + 1);
		}
		cout << answer << "\n";
	}
	return 0;
}
