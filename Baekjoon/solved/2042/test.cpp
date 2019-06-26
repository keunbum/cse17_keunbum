#include <ios>

using namespace std;

int main() {
  for (int i = 0; i <= 33; i++) {
    printf("%d %08x %08x %d\n", i, i, -i, i & (-i));
  }
  return 0;
}