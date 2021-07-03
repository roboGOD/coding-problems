#include <bits/stdc++.h>
#define lli long long int
#define pb push_back
#define node pair<lli, lli>

using namespace std;

struct pair_hash
{
  inline size_t operator()(const node &v) const
  {
    return v.first * 1000 + v.second;
  }
};

queue<node> q;
unordered_set<node, pair_hash> s;

void add(node const &x)
{
  if (s.find(x) == s.end())
  {
    q.push(x);
    s.insert(x);
  }
}

int main()
{
  lli t, r, c, total;
  cin >> t;
  for (int _ = 0; _ < t; _++)
  {
    total = 0;
    cin >> r >> c;
    lli m[r][c];

    for (lli i = 0; i < r; i++)
    {
      for (lli j = 0; j < c; j++)
      {
        cin >> m[i][j];
      }
    }

    for (lli i = 0; i < r; i++)
    {
      for (lli j = 0; j < c; j++)
      {
        if ((i > 0 && m[i - 1][j] - m[i][j] > 1) ||
            (j > 0 && m[i][j - 1] - m[i][j] > 1) ||
            (i < r - 1 && m[i + 1][j] - m[i][j] > 1) ||
            (j < c - 1 && m[i][j + 1] - m[i][j] > 1))
        {
          add(make_pair(i, j));
        }
      }
    }

    while (q.size() != 0)
    {
      node x = q.front();
      lli i = x.first;
      lli j = x.second;
      q.pop();
      s.erase(x);

      if ((i > 0 && m[i - 1][j] - m[i][j] > 1) ||
          (j > 0 && m[i][j - 1] - m[i][j] > 1) ||
          (i < r - 1 && m[i + 1][j] - m[i][j] > 1) ||
          (j < c - 1 && m[i][j + 1] - m[i][j] > 1))
      {
        lli mt = 0, mr = 0, mb = 0, ml = 0;
        if (i > 0)
        {
          mt = m[i - 1][j];
        }

        if (j > 0)
        {
          ml = m[i][j - 1];
        }

        if (i < r - 1)
        {
          mb = m[i + 1][j];
        }

        if (j < c - 1)
        {
          mr = m[i][j + 1];
        }

        lli diff = max({mt, mr, mb, ml}) - m[i][j] - 1;
        if (diff > 0)
        {
          m[i][j] += diff;
          total += diff;

          if (i > 0 && m[i - 1][j] - m[i][j] < -1)
          {
            add(make_pair(i - 1, j));
          }

          if (j > 0 && m[i][j - 1] - m[i][j] < -1)
          {
            add(make_pair(i, j - 1));
          }

          if (i < r - 1 && m[i + 1][j] - m[i][j] < -1)
          {
            add(make_pair(i + 1, j));
          }

          if (j < c - 1 && m[i][j + 1] - m[i][j] < -1)
          {
            add(make_pair(i, j + 1));
          }
        }
      }
    }

    cout << "Case #" << _ + 1 << ": " << total << endl;
  }
}
