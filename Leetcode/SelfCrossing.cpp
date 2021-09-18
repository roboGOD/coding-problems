#include <bits/stdc++.h>
#define lli long long int
#define pb push_back

using namespace std;

/**
 * Test Case: [1,1,2,2,3,3,4,4,10,4,4,3,3,2,2,1,1]
 * Output: false
 * */
bool isSelfCrossing(vector<int> &distance)
{
  int len = distance.size();
  bool isShort = false;

  if (len < 4)
  {
    return false;
  }

  int p = 0;

  int n = distance[0];
  int w = (-1) * distance[1];
  int s = 0;
  int e = 0;

  int x = w;
  int y = n;
  int i = 2;

  while (i < len)
  {

    int dir = i % 4;
    int v = distance[i];

    if (dir == 0)
    {
      if (isShort)
      {
        y += v;

        if(y < n) {
          n = y;
        } else {
          return true;
        }
      }
      else
      {
        y += v;
        if (y > n)
        {
          n = y;
        }
        else if(i+1 < len)
        {
          isShort = true;
          n = y;
          i++;

          v = distance[i];
          x -= v;

          p = x + v - distance[i-2];
          if(i > 5 || y >= 0) {
            p += distance[i-4];
          }

          if (x > p)
          {
            w = x;
          }
          else
          {
            return true;
          }
        }
      }
    }
    else if (dir == 1)
    {
      if (isShort)
      {
        x -= v;

        if(x > w) {
          w = x;
        } else {
          return true;
        }
      }
      else
      {
        x -= v;

        if (x < w)
        {
          w = x;
        }
        else if(i+1 < len)
        {
          isShort = true;
          i++;

          v = distance[i];
          y -= v;

          p = y + v - distance[i-2];
          if(i > 6 || (i >= 4 && x <= 0)) {
            p += distance[i-4];
          }
          w = x;

          if (y > p)
          {
            s = y;
          }
          else
          {
            return true;
          }
        }
      }
    }
    else if (dir == 2)
    {
      if (isShort)
      {
        y -= v;

        if(y > s) {
          s = y;
        } else {
          return true;
        }
      }
      else
      {
        y -= v;
        if (y < s)
        {
          s = y;
        }
        else if(i+1 < len)
        {
          isShort = true;
          i++;

          v = distance[i];
          x += v;

          p = x - v + distance[i-2];
          if(i >= 8 || (i >= 4 && s == y)) {
            p = p - distance[i-4];
          }

          s = y;

          if (x < p)
          {
            e = x;
          }
          else
          {
            return true;
          }
        }
      }
    }
    else if (dir == 3)
    {
      if (isShort)
      {
        x += v;

        if(x < e) {
          e = x;
        } else {
          return true;
        }
      }
      else
      {
        x += v;
        if (x > e)
        {
          e = x;
        }
        else if(i+1 < len)
        {
          isShort = true;
          i++;

          v = distance[i];
          y += v;

          p = y - v + distance[i-2];
          if(i >= 8 || (i >= 4 && x == e)) {
            p -= distance[i-4];
          }

          e = x;

          if (y < p)
          {
            n = y;
          }
          else
          {
            return true;
          }
        }
      }
    }

    i++;
  }

  return false;
}
