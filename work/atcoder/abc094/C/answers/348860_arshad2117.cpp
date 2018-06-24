#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;
#define mp make_pair
typedef
tree<
  pair<int,int> ,
  null_type,
  less<pair<int,int> >,
  rb_tree_tag,
  tree_order_statistics_node_update>
order_set;

int df[200010];
int main(){
	order_set A;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>df[i];
	for(int i=0;i<n;i++)A.insert(mp(df[i],i));
	for(int i=0;i<n;i++){
		A.erase(mp(df[i],i));
		cout<<(*A.find_by_order((n/2) - 1)).first<<'\n';;
		A.insert(mp(df[i],i));
	}
}
