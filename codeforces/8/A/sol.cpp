#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s,a,b;
  bool w[2];
  cin >> s >> a >> b;
  int n = (int) s.size();
  int na = (int) a.size();
  int nb = (int) b.size();
  for (int r=0; r < 2; r++)
  {
    int i=0;
    bool ok=false;
    while (i <= n-na)
    {
      ok=true;
      for (int j=i; j < i+na; j++)
      {
        if (s[j] != a[j-i])
        {
          ok=false;
          break;
        }
      }
      if (ok) break;
      ++i;
    }
    if (!ok) w[r]=false; else
    {
      i += na;
      ok=false;
      while (i <= n-nb)
      {
        ok=true;
        for (int j=i; j < i+nb; j++)
        {
          if (s[j] != b[j-i])
          {
            ok=false;
            break;
          }
        }
        if (ok) break;
        ++i;
      }
      w[r]=ok;
    }
    for (i=0; i < n / 2; i++)
    {
      int t=s[i]; s[i]=s[n-i-1]; s[n-i-1]=t;
    }
  }
  if (w[0] && w[1]) cout << "both"; else
  if (w[0]) cout << "forward"; else
  if (w[1]) cout << "backward";
  else cout << "fantasy";
  cout << '\n';
  return 0;
}
