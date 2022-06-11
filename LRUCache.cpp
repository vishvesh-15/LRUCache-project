#include <bits/stdc++.h>
using namespace std;

// Node to store the data (Linked List)
class Node
{
public:
  string key;
  int value;
  Node(string key, int value)
  {
    this->key = key;
    this->value = value;
  }
};

// LRU Cache Data Structure
class LRUCache
{
public:
  int maxSize;
  list<Node> l;
  unordered_map<string, list<Node>::iterator> m;

  // Constructor
  LRUCache(int maxSize)
  {
    this->maxSize = maxSize > 1 ? maxSize : 1;
  }

  void insertKeyValue(string key, int value)
  {

    if (m.count(key) != 0)
    {

      auto it = m[key];
      it->value = value;
    }

    else
    {

      if (l.size() == maxSize)
      {
        Node last = l.back();
        m.erase(last.key);
        l.pop_back();
      }

      Node n(key, value);

      l.push_front(n);

      m[key] = l.begin();
    }
  }

  int *getValue(string key)
  {
    if (m.count(key) != 0)
    {
      auto it = m[key];

      int value = it->value;
      l.push_front(*it);
      l.erase(it);
      m[key] = l.begin();
      int *address = &l.begin()->value;
      return address;
    }
    return NULL;
  }

  string mostRecentKey()
  {
    return l.front().key;
  }
};
// Input function
void inputOnScreen()
{
  cout << "1) Insert keyValue" << endl;
  cout << "2) Most RecentKey" << endl;
  cout << "3) getValue" << endl;
  cout << "4) quit" << endl;
}

// main
int main()
{
  string n;
  int sizeOfCache, value, op;
  string key;

  cout << "Please mention the size of cache: ";
  cin >> sizeOfCache;

  if (sizeOfCache != isdigit(sizeOfCache))
  {
    LRUCache lru(sizeOfCache);
    for (int i = 1; i <= sizeOfCache; i++)
    {
      cout << "please enter the key and the value : ";
      cin >> key >> value;
      lru.insertKeyValue(key, value);
    }
    while (1)
    {
      inputOnScreen();
      cin >> op;
      switch (op)
      {
      case 1:
        cout << "please enter the key and the value : ";
        cin >> key >> value;
        lru.insertKeyValue(key, value);
        cout << "Your Key and the value is inserted in cache" << endl;
        break;
      case 2:
        cout << lru.mostRecentKey() << endl;
        break;

      case 3:

        cout << "enter which value do u want:";
        cin >> n;
        if (lru.getValue(n) == NULL)
        {
          cout << n << " doesn't exist" << endl;
        }
        cout << lru.getValue(n) << endl;
        break;

      case 4:
        return 0;

      default:
        cout << "Please try again!" << endl;
      }
    }
  }
  else
  {
    cout << "please enter correct Value";
  }
}