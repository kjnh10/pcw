#include<bits/stdc++.h>

using namespace std;

struct TrieNode
{
  int nxt[3];

  int exist;
  vector< int > accept;

  TrieNode() : exist(0)
  {
    memset(nxt, -1, sizeof(nxt));
  }
};

struct Trie
{
  vector< TrieNode > nodes;
  int root;

  Trie() : root(0)
  {
    nodes.push_back(TrieNode());
  }

  virtual void direct_action(int node, int id) {}

  virtual void child_action(int node, int child, int id) {}

  void update_direct(int node, int id)
  {
    nodes[node].accept.push_back(id);
    direct_action(node, id);
  }

  void update_child(int node, int child, int id)
  {
    ++nodes[node].exist;
    child_action(node, child, id);
  }

  void add(const string &str, int str_index, int node_index, int id)
  {
    if(str_index == str.size()) {
      update_direct(node_index, id);
    } else {
      const int c = str[str_index] - '0';
      if(nodes[node_index].nxt[c] == -1) {
        nodes[node_index].nxt[c] = (int) nodes.size();
        nodes.push_back(TrieNode());
      }
      add(str, str_index + 1, nodes[node_index].nxt[c], id);
      update_child(node_index, nodes[node_index].nxt[c], id);
    }
  }

  void add(const string &str, int id)
  {
    add(str, 0, 0, id);
  }

  void add(const string &str)
  {
    add(str, nodes[0].exist);
  }

  int size()
  {
    return (nodes[0].exist);
  }

  int nodesize()
  {
    return ((int) nodes.size());
  }
};

struct Aho_Corasick : Trie
{
  static const int FAIL = 2;
  vector< bitset< 510 > > correct;

  Aho_Corasick() : Trie() {}

  void build()
  {
    correct.resize(nodes.size());
    for(int i = 0; i < nodes.size(); i++) {
      for(int j : nodes[i].accept) correct[i][j] = true;
    }

    queue< int > que;
    for(int i = 0; i < 3; i++) {
      if(~nodes[0].nxt[i]) {
        nodes[nodes[0].nxt[i]].nxt[FAIL] = 0;
        que.emplace(nodes[0].nxt[i]);
      } else {
        nodes[0].nxt[i] = 0;
      }
    }
    while(!que.empty()) {
      TrieNode &now = nodes[que.front()];
      correct[que.front()] |= correct[now.nxt[FAIL]];
      que.pop();
      for(int i = 0; i < 2; i++) {
        if(now.nxt[i] == -1) continue;
        int fail = now.nxt[FAIL];
        while(nodes[fail].nxt[i] == -1) {
          fail = nodes[fail].nxt[FAIL];
        }
        nodes[now.nxt[i]].nxt[FAIL] = nodes[fail].nxt[i];
        que.emplace(now.nxt[i]);
      }

    }
  }

  int move(const string &str, int now = 0)
  {
    for(auto &c : str) {
      while(nodes[now].nxt[c - '0'] == -1) now = nodes[now].nxt[FAIL];
      now = nodes[now].nxt[c - '0'];
    }
    return (now);
  }
};

const int mod = 1e9 + 7;

int main()
{
  int N, L;
  string w[510];

  cin >> N >> L;
  for(int i = 0; i < N; i++) cin >> w[i];

  Aho_Corasick aho;
  for(int i = 0; i < N; i++) aho.add(w[i]);
  aho.build();

  vector< int > ismatch(aho.nodesize(), 0);
  for(int i = 0; i < aho.nodesize(); i++) {
    bitset< 510 > &p = aho.correct[i];
    for(int j = 0; j < N; j++) {
      if(p[j]) ismatch[i] |= 1 << (int) (w[j].size() - 1);
    }
  }

  const int mask = (1 << 8) - 1;
  map< int, int > dp[101][1 << 8];
  dp[0][1][0] = 1;
  for(int i = 0; i < L; i++) {
    for(int j = 0; j < (1 << 8); j++) {
      for(auto &v : dp[i][j]) {
        for(char c = '0'; c <= '1'; c++) {
          auto get = aho.move(string(1, c), v.first);
          bool mm = ismatch[get] & j;
          (dp[i + 1][((j << 1) | mm) & mask][get] += v.second) %= mod;
        }
      }
      dp[i][j].clear();
    }
  }

  int ret = 0;
  for(int i = 1; i < (1 << 8); i += 2) {
    for(auto &v : dp[L][i]) (ret += v.second) %= mod;
  }
  cout << ret << endl;

}