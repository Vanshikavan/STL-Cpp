#include<bits/stdc++.h>
using namespace std;

//pairs
// it is a part of utility library
void explainpair(){
    
    pair<int,int> p = {1,3};
    cout<< p.first << " " <<p.second; // 1 3
    
    // we can store more than two variables by using the nested property of pair
    pair<int, pair<int,int>> p = {1,{3,4}};
    cout<< p.first<< " "<< p.second.second << " " <<p.second.first; // 1 4 3
    
    pair<int,int> arr[]= {{1,2},{2,5},{5,1}};
    cout << arr[1].second;    //outputs 5
}

void explainVector(){  // it is a container that store elements and you can change the size whenever you want

    vector<int> v; //creates an empty container {}

    // push back and emplace back are used to insert elements in vector. 
    v.push_back(1); // empty container takes 1 into it {1}
    v.emplace_back(2); // dynamically increases its size and takes 1 into it. {1,2}
                       // emplace_back is faster than push_ back

    vector<pair<int, int>>vec; //you can also define a vector of pair datatype.

    v.push_back({1,2}); // it takes {1,2} pair as input
    v.emplace_back(1,2); // emplace_back automatically assumes (1,2) as a pair so no curly braces required

    vector<int> v(5,100); // a container with 5 instances of 100 is defined. {100,100,100,100,100}

    vector<int> v(5); // {0,0,0,0,0} it may be zero or any other garbage value.

    vector<int> v1(5,20); // {20,20,20,20,20}
    vector<int> v2(v1); //copy of v1 container in another container. {20,20,20,20,20}
    
    // accessing elements in vector using iterator.
    // iterator points to the memory address or memory where the element is lyiing.
    vector<int>::iterator it =v.begin();  // suppose {20,10,15,6,7}
                                          // it will begin with 20
    it++; // increment by 1
    //20to10 then 10->15 then 15to6 and 6to7
    cout << *(it) << " "; // 10

    it=it+2; //increment by 2
    //20to15 then 15to7 then 15to6 and 6to7
    cout<< *(it) <<  " "; //6

    //suppose {10,20,30,40}
    vector<int>::iterator it= v.end(); // will point to memory address after 40. to access 40 do it--
    /*not used much*/vector<int>::iterator it= v.rend(); //10
    /*not used much*/vector<int>::iterator it= v.rbegin(); //40
    
    //to access the elements directly without memory address.
    cout << v[0] << " "  v.at(0)/*not used much*/;

    cout << v.back() << " "; // supppse{10,20,30} then it's the element which is at 30

    // ways to print the vector (simplest way is by directly looping from indices or using iterators)
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout<< *(it) << " ";
    }
    // short way of using iterator(auto assigns datatype automatically according to data)
    for(auto it= v.begin(); it!= v.end(); it++){
        cout<< *it << " ";
    }
    //automatically iterates
    for(auto it : v){
        cout<< it<< " ";
    }

    //deletion in a vector
    v.erase(v.begin()+1); // suppose{10,20,12,23} => {10,12,23}

    //to delete a couple of elements give  starting and ending address
    v.erase(v.begin()+2, v.begin() +4); //{10,20,12,23,35} => {10,20,35}

    //Insert Function
    
    vector<int>(2,100); //{100,100}
    v.insert(v.begin(),300); // {300,100,100};
    v.insert(v.begin() +1,2,10); // {300,10,10,100,100}

    // copying a vector in another, here copy is a vector which you are copying in v
    // not used much
    vector<int> copy(2,50); // {50,50}
    v.insert(v.begin(), copy.begin(), copy.end()); // {50,50,300,10,10,100,100}

    //{10,20}
    cout << v.size(); //2

    //{10,20}
    v.pop_back(); // {10}

    // v1 -> {10,20}
    // v2 -> {30,40}
    v1.swap(v2); // v1 -> {30,40} , v2 -> {10,20}

    v.clear(); //erases the entire vector

    cout<< v.empty();
}


// Next Container
//list is similar to vectors but gives you front operations as well
// it is also a container dynamic in  nature so same operations
void explainList(){
    list<int> ls;

    ls.push_back(2); // {2}
    ls.emplace_back(4); // {2,4}

    ls.push_front(5); // {5,2,4}; it is very very cheap in terms of time complexity when compared to vectors

    ls.emplace_front(); {2, 4};

    //rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}


// next container is deque   
void explainDeque(){

    deque<int>dq;
    dq.push_back(1); // {1}
    dq.emplace_back(2); // {1,2}
    dq.push_front(4); // {4,1,2}
    dq.emplace_front(3); // {3,4,1,2}

    dq.pop_back(); // {3,4,1}
    dq.pop_front(); // {4,1}

    dq.back();

    dq.front();

    //rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}


// next container is stack [time complexity- O(n)]
// for stack remember LIFO - last in , first out
// (the one went in last will come out the first)
void explainStack(){
   stack<int> st; 
   st.push(1); // {1}
   st.push(2); // {2,1}
   st.push(3); // {3,2,1}
   st.push(3); // {3,3,2,1}
   st.emplace(5); // {5,3,3,2,1}

   cout << st.top(); // prints 5 " **st[2] is invalid** "(you can't call by index value)

   st.pop(); // st looks like {3,3,2,1}

   cout << st.top(); //3

   cout << st.size(); //4

   cout << st.empty(); //false

   stack<int>st1, st2;
   st1.swap(st2);
}


// next container is a queue data structure
// FIFO- first in first out
// again all the operations are happening in constant time O(1)
void explainQueue(){
    queue<int> q;
    q.push(1); // {1}
    q.push(2); // {1,2}
    q.emplace(4); // {1,2,4}

    q.back() += 5;

    cout << q.back(); // prints 9
    
    // Q is {1,2,9}
    cout << q.front(); // prints 1

    q.pop(); // {2,9}

    cout << q.front(); // prints 2

    // size swap empty same as stack   
}



// Priority Queue (the one having the largest/maximum  value stays at top)
void explainPQ(){          
    priority_queue<int>pq;    //mah heap

    pq.push(5); // {5}
    pq.push(2); // {5,2}
    pq.push(8); // {8,5,2}
    pq.emplace(10); // {10,8,5,2}

    cout << pq.top(); // prints 10

    pq.pop(); // {8,5,2}

    cout << pq.top(); // prints 8

    // size swap empty function same as others

    // priority queue that stores the minimum element at the top.
    // Minimum Heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5); //{5}
    pq.push(2); //{2,5}
    pq.push(8); //{2,5,8}
    pq.emplace(10); // {2,5,8,10}

    cout << pq.top(); // prints 2

    //time complexity
    // push -> log(n)
    // top -> O(1)
    // pop -> log(n)
}



// Next container is set
// stores everything in sorted order and unique
void explainSet(){
    set<int>st;
    st.insert(1); // {1}
    st.emplace(2); // {1,2}
    st.insert(2); // {1,2}
    st.insert(4); // {1,2,4}
    st.insert(3); // {1,2,3,4}

    //Functionality of insert in vector can be used also, that only increases efficiency

    // begin(), end(), rbegin(), rend(), size(), empty() and swap() are same as those of above

    // {1,2,3,4,5}
    auto it = st.find(3); // returns an iterator which points to 3

    // {1,2,3,4,5}
    auto it = st.find(6); // returns st.end()

    // {1,4,5}
    st.erase(5); // erase 5 // takes logarithmic time

    int cnt = st.count(1); // 1 if element is existing in the set or 0 (1 as all elements are unique)

    auto it = st.find(3);
    st.erase(it); // it takes constant time

    //{1,2,3,4,5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1,it2); // after erase {1,4,5} not {1,3,5} as [first, last)

    //lower_bound() and upper_bound() function works in the same way as in vector it does

    // this is the syntax
    auto it = st.lower_bound(2);

    auto it = st.upper_bound(3);
}


// Next container is Multiset
// sorted order
void explainMultiSet(){
    // Everything is same as set only stores duplicate elements also

    multiset<int>ms;
    ms.insert(1); //{1}
    ms.insert(1); //{1,1}
    ms.insert(1); // {1,1,1}

    ms.erase(1); // all 1's erased

    int cnt = ms.count(1);

    //only a single one erased
    ms.erase(ms.find(1));

    ms.erase(ms.find(1), ms.find(1)+2);

    // rest all function same as set
}


// Next container is unordered set
// stores unique elements but not in sorted order
// in any random order
void explainUSet(){
    unordered_set<int> st;
    // lower_bound and upper bound function does not works, rest all functions are same
    // as above, it does not stores in any particular order it has a better complexity
    // than set in most cases, exceptsome when collision happens
}


// Next container is Map
// it stores everything in respect of {key ,values} both can be of any datatype and key should be unique
void explainMap(){
    //  key ,value
    map<int, int> mpp; // one integer is key and the other is value
    //  key,   value
    map<int, pair<int, int>> mpp; // here key is one integer and value is two integers
    //     key,        value
    map< pair<int,int>, int> mpp; // 2 int = key and 1 int = value

    mpp[1] = 2; // on the key 1 it stores 2
    mpp.emplace({3,1}); //stores 3 as key and value to key is 1

    mpp.insert({2,4});

    mpp[{2,3}] = 10; // key is {2,3} and corresponding value is 10

    // map stores unique keys in sorted order
    // {
    //     {1,2}
    //     {2,4}
    //     {3,1}
    // }

    for(auto it : mpp){
        cout<< it.first << " " << it.second << endl; // [{1,2},{2,4}, {3,1}]
    }

    cout << mpp[1]; // 2
    cout << mpp[5]; // 0 or null

    auto it= mpp.find(3);
    cout << *(it).second;

    auto it = mp.find(5); // returns mpp.end() if 5 is not there

    //This is the syntax
    auto it = mpp.lower_bound(2);

    auto it = mpp.upper_bound(3);

    // erase, swap, size, empty, are same as above
}


// Next container is Multi map
// you can store duplicate keys over here
void explainMultimap(){
    // everything same as map, only it can store multiple keys
    // only mpp[key] cannot be used here
}


// Next container is Unordered map
// here keys are unique but not in sorted order
void explainUnorderedMap(){
    // same as set and unordered_set difference
}
// map works in log n and unordered map works in O(n) [very rare in worst case it goes O(n)]

// Till here containers and iterators done now some Algorithms ->




bool comp()(pair<int,int> p1, pair<int,int> p2){
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    // they are same

    if(p1.first> p2.first) return true;
    return false;
} // if not in a correct order then comperator swap the value

void explainExtra(){


    sort(a, a+n);
    sort(v.begin(), v.end());
     
    sort(a+2, a+4);

    sort(a, a+n, greater<int>);

    pair<int,int> a[] = {{1,2}, {2,1}, {4,1}};
    
    // sort in this way:
    // sort it according to increasing second element
    // if second element is same , then sort
    // it according to first element but in descending order

    sort(a, a+n, comp) // use comperators , it is a boolean function wchich returns true and false

    // {{4,1}, {2,1}, {1,2}};

    int num =7;
    int cnt = __builtin_popcount(); // how many set bits are there binary of 7 is 111 so it will return 3

    long long num = 165784387354;
    int cnt = __builtin_popcountll();

    string s ="123"; // to find all the permutations of strings.

    do{
        cout << s << endl;
    } while(next_permutation(s.begin(), s.end()));

    int maxi = *max_element(a,a+n); // a is start iterator and a+n is end iterator and *maxelement gives address of max no.
}




int main(){

    return 0;
}