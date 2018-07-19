#include <cstdio>
#include <string>
#include <algorithm>

int main() {
  char buf[16];
  std:: string S, T;
  scanf("%s", buf);
  S = buf;
  scanf("%s", buf);
  T = buf;

  for (std::size_t i=0; i<S.length(); ++i) {
    if (S[i] == T[i]) continue;
    if (T[i] == '@') std::swap(S[i], T[i]);
    if (S[i] == '@') {
      switch (T[i]) {
      case 'a':
      case 't':
      case 'c':
      case 'o':
      case 'd':
      case 'e':
      case 'r':
        continue;
      default:
        return !printf("You will lose\n");
      }
    }
    return !printf("You will lose\n");
  }
  printf("You can win\n");
  return 0;
}