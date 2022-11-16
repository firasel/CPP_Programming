#include <bits/stdc++.h>
#include <iostream>
#include <numeric>

using namespace std;

class MinStack
{
public:
  multiset<int> sortNums;
  vector<int> nums;
  MinStack()
  {
    sortNums.clear();
    nums.clear();
  }

  void push(int val)
  {
    sortNums.insert(val);
    nums.push_back(val);
  }

  void pop()
  {
    sortNums.erase(sortNums.find(nums.back()));
    nums.pop_back();
  }

  int top()
  {
    return nums.back();
  }

  int getMin()
  {
    return *sortNums.begin();
  }
};

int main()
{
  MinStack *obj = new MinStack();
  obj->push(-2);
  obj->push(0);
  obj->push(-3);

  cout << obj->getMin() << endl;
  obj->pop();
  cout << obj->top() << endl;
  cout << obj->getMin() << endl;

  cout << "Set: ";
  for (auto num : obj->sortNums)
    cout << num << " ";
  cout << endl;

  cout << "Vector: ";
  for (auto num : obj->nums)
    cout << num << " ";
  cout << endl;

  return 0;
}