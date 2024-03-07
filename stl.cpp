#include <bits/stdc++.h>
// STL - 1.algo 2.containers 3.function 4.iterators
using namespace std;

void pairs()
{
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> p2 = {1, {2, 3}};
    cout << p2.first << " " << p2.second.first << " " << p2.second.second << endl;

    // array of pair
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    cout << arr[1].second; // output 4
}
void vectors()
{
    // Vectors dynamic arrays
    vector<int> v;
    v.push_back(1);    // It adds a new element at the end.
    v.emplace_back(2); // It inserts a new element at the end.
    vector<pair<int, int>> vec;
    vec.push_back({1, 2});
    vec.emplace_back(3, 4); // no need to specify curly brackets

    vector<int> vect1(5, 100); // size 5 of 100 ex -{100,100,100,100,100}
    vector<int> vect2(5);      // empty container of  5 element filled with 0 or garbage value
    vector<int> vect3(5, 20);  // container of 5 instances of 20
    vector<int> vect4(vect3);  // copy of vector3

    vector<int>::iterator it = vect3.begin(); // points to the begining/start of the vector's memory
    it++;                                     // moving to next element memory
    cout << *(it) << " ";                     // converting address to value
    it = it + 2;                              // shifting by 2

    vector<int>::iterator it1 = vect3.end(); // points to right after last element
    // vector<int>::iterator it = vect3.rend();   // reverse end (right after reverse end)
    // vector<int>::iterator it = vect3.rbegin(); // reverse begin

    v.back(); // last element of vector

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }
    for (auto i : v)
    {
        cout << i << "";
    }

    // deletion in vector
    v.erase(v.begin() + 1);
    v.erase(v.begin() + 2, v.begin() + 4); //(start,end) end is not included whereas start is included

    v.insert(v.begin(), 300);      // inserts at begining
    v.insert(v.begin() + 1, 2, 5); // will insert 2 times the or instance of 5 on the given location
    vector<int> copy(2, 50);
    v.insert(v.begin(), copy.begin(), copy.end()); // insert another vector to an existing vector

    v.pop_back();      // removes the last element
    vect1.swap(vect2); // swaps vect with vect1
    v.clear();         // erases entire vector;
}
void list()
{
    //////////////////////////
    // LIST
    list<int> ls;
    ls.push_back(2);
    ls.emplace_back(4);
    ls.push_front(5);
    ls.emplace_front();
    return 0;
}
void dynamicQueue()
{

    /////////////////////
    // Dynamic queue
    deque<int> dq;
    dq.push_back(1);
    dq.emplace_back(2);
    dq.push_front(4);
    dq.emplace_front(3);

    dq.pop_back();
    dq.pop_front();

    dq.back();
    dq.front();
}
void stack()
{
}
int main()
{

    //////////////////////
    // STACK
    stack<int> st;
    st.push(1);
    st.emplace(5);
    st.top(); // top element of stack
    st.pop();
    st.size();
    st.empty(); // empty or not gives boolean value
    stack<int> st1;
    st.swap(st1);

    ///////////////////////
    // Queue

    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(4);
    q.back() = +5;
    q.back();
    q.front();
    q.pop(); // pops first element in the queue
    q.front();

    ////////////////////
    // Priority Queue

    priority_queue<int> pq;
    pq.push(2);
    pq.push(3);
    pq.emplace(10);
    cout << pq.top();
    pq.pop();
    pq.top();

    // MIN HEAP

    priority_queue<int, vector<int>, greater<int>> mh;
    mh.push(5);     //{5}
    mh.push(2);     //{2,5}
    mh.push(8);     //{2,5,8}
    mh.emplace(10); // {2,,5,8,10}

    mh.top(); // 2

    ///////////////
    // SET
    // everything sorted and unique
    set<int> set;
    set.insert(1);
    set.emplace(2);
    auto it = set.find(3);
    auto it = set.find(6); // finds 6 in set //if not then will point to right after end
    set.erase(5);          // value 5 removes
    set.count(1);          // counts no. of 1 in a set
    auto it = set.find(3);
    // set.erase(it);

    auto it4 = set.lower_bound(2);
    auto it5 = set.upper_bound(3);

    ////////////////////
    // MULTISET
    // everything as set but can stores duplicates

    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);

    ms.erase(1); // all 1s are erased
    ms.count(1);
    ms.erase(ms.find(1));
    // ms.erase(ms.find(1), ms.find(1) + 2);

    /// unordered set
    // stores in unordered or unsorted order ;
    // all things same as set except lower bound and upper bound function

    ///////////////////////////
    // MAP
    // key value pair
    map<int, int> mpp;
    map<int, pair<int, int>> mpp2;
    map<pair<int, int>, int> mpp3;
    mpp[1] = 2;         // on key 1 stores 2//{1,2}
    mpp.emplace(3, 1);  // key 3 value 1
    mpp.insert({2, 4}); // key 2 value 4

    // {
    //     {1, 2}
    //     {2, 4}
    //     {3, 1}
    // }
    for (auto it : mpp)
    {
        cout << it.first << " " << it.second << endl;
    }

    mpp3[{2, 3}] = 10;
    mpp[1]; // value at key 1

    /// ALGOs

    // sort(a, a + n);
    sort(v.begin(), v.end());
    // sort(a, a + n, greater<int>); //descending order sort

    // custom comparitor for custom sort
    //  bool comp(pair<int, int> p1, pair<int, int> p2)
    //  {
    //      if (p1.second < p2.second)
    //          return true;
    //      if (p1.second > p2.second)
    //          return false;
    //      if (p1.second == p2.second)
    //      {
    //          if (p1.first > p2.first)
    //              return true;
    //          else
    //              return false;
    //      }
    //  }
    // sort(a,a+n,comp)

    int num = 7;                       // binary 111
    int cnt = __builtin_popcount(num); // how many set bits in a binary number

    // all permutation
    // start from the sorted string to get all permutation
    string s = "123";
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));

    // max elelment
    // int maxi = *max_element(a, a + n);
}