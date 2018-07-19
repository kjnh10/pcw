#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORD(i,b,a) for (int i = (int)(b) - 1; i >= a; --i)
#define REP(i,N) FOR(i,0,N)
#define st first
#define nd second
#define pb push_back

typedef pair<int, int> PII;
typedef long long LL;

/**
 * Intervals are left_bound-closed and right_bound-open: [L, R)
 */
 template <typename TData, typename TOperationInput=void*>
 class BinaryIndexedTree {
 private:
   typedef const function<bool(const TData&)>& Predicate;

   virtual TData _neutral() = 0;
   virtual TData _merge(const TData& left, const TData& right) = 0;

   /**
    * Need to be overriden if we have on-line operations
    */
   virtual void _apply(const TOperationInput& op, TData& value) {
   }
   virtual void _apply(const TOperationInput& op, TData& value, int A, int B) {
     _apply(op, value);
   }
   virtual TOperationInput _compose(const TOperationInput& outer, const TOperationInput& inner) {
     return inner;
   };

   int length;
   /** Interval represented by the node */
   vector<int> left_bound, right_bound;
   vector<TData> data;
   /** For on-line operations */
   vector<bool> hasPendingSubtreeOperation;
   vector<TOperationInput> pendingSubtreeOperation;

   template<typename Iterator>
   void __initialize(Iterator start, Iterator end) {
     left_bound.resize(2*length);
     right_bound.resize(2*length);
     data = vector<TData>(2*length, _neutral());
     hasPendingSubtreeOperation.resize(2*length);
     pendingSubtreeOperation.resize(2*length);
     int N = end - start;
     for (int i = 0; i < N; ++i) {
       data[length + i] = start[i];
     }
     for (int i = 0; i < length; ++i) {
       left_bound[length + i] = i;
       right_bound[length + i] = i + 1;
     }
     for (int idx = length - 1; idx >= 1; --idx) {
       left_bound[idx] = left_bound[2*idx];
       right_bound[idx] = right_bound[2*idx+1];
       data[idx] = _merge(data[2*idx], data[2*idx+1]);
     }
   }

   void __applyToNode(int idx, const TOperationInput& operation) {
     _apply(operation, data[idx], left_bound[idx], right_bound[idx]);

     if (hasPendingSubtreeOperation[idx]) {
       pendingSubtreeOperation[idx] = _compose(operation, pendingSubtreeOperation[idx]);
     } else {
       pendingSubtreeOperation[idx] = operation;
     }

     hasPendingSubtreeOperation[idx] = true;
   }

   void __pushPendingSubtreeOperation(int idx) {
     if (!hasPendingSubtreeOperation[idx]) {
       return;
     }

     if (idx < length) {
       __applyToNode(2*idx, pendingSubtreeOperation[idx]);
       __applyToNode(2*idx + 1, pendingSubtreeOperation[idx]);
     }
     hasPendingSubtreeOperation[idx] = false;
   }

   void __applyToRange(int L, int R, const TOperationInput& op, int idx) {
     if (right_bound[idx] <= L || R <= left_bound[idx]) return;
     if (L <= left_bound[idx] && right_bound[idx] <= R) {
       __applyToNode(idx, op);
       return;
     }

     __pushPendingSubtreeOperation(idx);
     __applyToRange(L, R, op, 2*idx);
     __applyToRange(L, R, op, 2*idx+1);

     data[idx] = _merge(data[2*idx], data[2*idx+1]);
   }

   TData __queryRange(int L, int R, int idx) {
     if (right_bound[idx] <= L || R <= left_bound[idx]) return _neutral();
     if (L <= left_bound[idx] && right_bound[idx] <= R) {
       return data[idx];
     }
     __pushPendingSubtreeOperation(idx);
     return _merge(__queryRange(L, R, 2*idx), __queryRange(L, R, 2*idx+1));
   }

   /**
    * If last=1, the last matching is returned. If last=0, the first one.
    */
   int __find(int L, int R, Predicate fn, int idx, int last) {
     if (right_bound[idx] <= L || R <= left_bound[idx]) return -1;
     if (!fn(data[idx])) return -1;
     if (idx >= length) return left_bound[idx];

     __pushPendingSubtreeOperation(idx);
     int preferred = __find(L, R, fn, 2*idx+last, last);
     if (preferred != -1) return preferred;
     return __find(L, R, fn, 2*idx+(last^1), last);
   }

 public:
   void init(int size) {
     length = 1;
     while (length < size) {
       length <<= 1;
     }
     vector<TData> empty;
     __initialize(empty.begin(), empty.end());
   }

   template<typename Iterator>
   void init(Iterator begin, Iterator end) {
     length = 1;
     while (length < end - begin) {
       length <<= 1;
     }
     __initialize(begin, end);
   }

   void applyToRange(int L, int R, const TOperationInput& op) {
     __applyToRange(L, R, op, 1);
   }

   void apply(int pos, const TOperationInput& op) {
     applyToRange(pos, pos+1, op);
   }

   TData queryRange(int L, int R) {
     return __queryRange(L, R, 1);
   }

   TData query(int pos) {
     return queryRange(pos, pos+1);
   }

   void set(int pos, TData value) {
     // Push pending operations
     query(pos);

     pos += length;
     data[pos] = value;
     pos >>= 1;
     while (pos > 0) {
       data[pos] = _merge(data[2*pos], data[2*pos+1]);
       pos >>= 1;
     }
   }

   /** @returns -1 if no element found */
   int firstWhich(int L, int R, Predicate contain_check) {
     return __find(L, R, contain_check, 1, 0);
   }

   int firstWhich(Predicate contain_check) {
     return firstWhich(0, length, contain_check);
   }

   /** @returns -1 if no element found */
   int lastWhich(int L, int R, Predicate contain_check) {
     return __find(L, R, contain_check, 1, 1);
   }

   int lastWhich(Predicate contain_check) {
     return lastWhich(0, length, contain_check);
   }
 };

 class BIT: public BinaryIndexedTree<int, int> {
 private:
   virtual int _neutral() {
     return 0;
   }
   virtual int _merge(const int& left, const int& right) {
     return left + right;
   }
   virtual void _apply(const int& op, int& value) {
     value += op;
   }
   virtual int _compose(const int& outer, const int& inner) {
     return outer + inner;
   };
};

vector<int> starts[111111];
vector<int> endss[111111];

int result[111111];
vector<int> trains[111111];

int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  REP(i,N) {
    int L, R;
    scanf("%d%d", &L, &R);
    starts[L].pb(R);
    endss[R].pb(L);
  }

  FOR(t,1,M+1) for (int i = 0; i <= M; i += t) trains[i].pb(t);

  BIT tree;
  tree.init(M+1);

  FOR(i,1,M+1) {
    for (int& r: starts[i]) tree.applyToRange(i, r+1, 1);
    for (int& t: trains[i]) {
      int res = tree.query(i);
      if (i >= t) res -= tree.query(i - t);
      result[t] += res;
    }
    for (int& l: endss[i]) tree.applyToRange(l, i+1, -1);
  }
  FOR(i,1,M+1) printf("%d\n", result[i]);
}
