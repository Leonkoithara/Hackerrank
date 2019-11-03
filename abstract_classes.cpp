#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node 
{
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
    Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache 
{
protected: 
    map<int,Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};

class LRUCache : public Cache
{
protected:
    int* queue;
    int curr;
public:
    LRUCache(int capacity)
    {
	cp = capacity;
	head = 0;
	tail = 0;
	curr = 0;
	queue = new int(capacity); 
    }
    void set(int key, int value)
    {
	map<int, Node*>::iterator pos;

	if(!tail)
	{
	    mp.insert(pair <int, Node*>(key, new Node(key, value)));
	    head = mp[key];
	    tail = head;
	    queue[0] = key;
	}
	else
	{
	    pos = mp.find(key);
	    int i;
	    for(i=(curr+1)%cp;i!=curr;i=(i+1)%cp)
	    {
		if(queue[i] == key)
		    break;
	    }
	    	    
	    if(pos == mp.end())
	    {
		curr = (curr+1)%cp;
		int itemp = queue[curr];
		Node* temp = new Node(tail, 0, key, value);
		tail->next = temp;
		tail = temp;

		queue[curr] = key;
		mp.insert(pair <int, Node*>(key, temp));

		if(mp.size() >= cp)
		    mp.erase(itemp);
	    }
	    else
	    {
		for(;i!=curr;i=(i+1)%cp)
		{
		    queue[i] = queue[(i+1)%cp];
		}
		queue[i] = key;
	    }
	}
    }

    int get(int key)
    {
	auto pos = mp.find(key);
	if(pos == mp.end())
	    return -1;
	else
	    return mp[key]->value;
    }
};

int main()  
{
    int n, capacity,i;
    cin >> n >> capacity;
    LRUCache l(capacity);

    for(i=0;i<n;i++)  
    {
	string command;
	cin >> command;
	if(command == "get")  
	{
	    int key;
	    cin >> key;
	    cout << l.get(key) << endl;
	} 
	else if(command == "set")  
	{
	    int key, value;
	    cin >> key >> value;
	    l.set(key,value);
	}
    }
    return 0;
}
