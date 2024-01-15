#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
    Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
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
public:
    LRUCache(int capacity)
    {
        cp = capacity;
        head = NULL;
        tail = NULL;
    }

    void set(int key, int value)
    {
        std::cout << "Inserting " << key << " " << value << std::endl;
        Node *n;
        auto search = mp.find(key);
        if (search != mp.end())
        {
            Node *n = search->second;
            if (n != head)
            {
                n->prev->next = n->next;
                if (n != tail)
                    n->next->prev = n->prev;
                else
                    tail = n->prev;
                n->next = head;
            }
            n->prev = NULL;
            n->value = value;
            head->prev = n;
            head = n;
        }
        else
        {
            n = new Node(NULL, head, key, value);
            if (mp.size() < cp)
            {
                if (head == NULL)
                    tail = n;
                else
                    head->prev = n;
                head = n;
            }
            else
            {
                head->prev = n;
                tail->prev->next = NULL;
                Node *tmp = tail->prev;
                mp.erase(tail->key);
                delete tail;
                tail = tmp;
                head = n;
            }
            mp[key] = n;
        }

        printList();
    }

    int get(int key)
    {
        int result = -1;

        auto search = mp.find(key);
        if (search != mp.end())
		{
            Node *n = search->second;
            result = n->value;

            if (n != head)
			{
                n->prev->next = n->next;
                if (n != tail)
                    n->next->prev = n->prev;
                else
                    tail = n->prev;

                n->prev = NULL;
                n->next = head;
                head->prev = n;
                head = n;
            }
        }

        return result;
    }

    void printList()
    {
        Node *t1 = head, *t2 = tail;
        while (t1 != NULL)
		{
            std::cout << t1->key << "," << t1->value << " " << t2->key << "," << t2->value << std::endl;
            t1 = t1->next;
            t2 = t2->prev;
        }

        std::cout << "Map" << std::endl;
        for (auto[key,np] : mp)
		{
            std::cout << np->key << "," << np->value << std::endl;
        }
    }
};

int main() {
    int n, capacity,i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for(i=0;i<n;i++) {
        string command;
        cin >> command;
        if(command == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        } 
        else if(command == "set") {
            int key, value;
            cin >> key >> value;
            l.set(key,value);
        }
    }
    return 0;
}
