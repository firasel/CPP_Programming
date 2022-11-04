#include <bits/stdc++.h>
using namespace std;

class MyHashMap
{
public:
  vector<int> data;
  MyHashMap()
  {
    data.resize(1E6 + 1, -1);
  }

  void put(int key, int value)
  {
    data[key] = value;
  }

  int get(int key)
  {
    return data[key];
  }

  void remove(int key) { data[key] = -1; }
};

class Solution
{
public:
};

int main()
{
  Solution st;

  MyHashMap *obj = new MyHashMap();
  obj->remove(14);
  cout << obj->get(4) << endl;
  obj->put(7, 3);
  obj->put(11, 1);
  obj->put(12, 1);
  cout << obj->get(7) << endl;
  obj->put(7, 4);
  cout << obj->get(7) << endl;
  obj->put(1, 19);
  obj->put(0, 3);
  obj->put(1, 8);
  obj->put(2, 6);
  cout << obj->get(0) << endl;
  cout << obj->get(2) << endl;

  return 0;
}