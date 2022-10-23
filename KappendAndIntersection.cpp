#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head == NULL) {head = n; return;}
    node* tmp = head;
    while (tmp->next != NULL) tmp = tmp->next;
    tmp->next = n;
}

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

node* reverse(node* &head){
    node* prev = NULL;
    node* cur = head;
    node* nxt;

    while (cur != NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

node* reverseRecursive(node* head){
    if(head == NULL || head->next == NULL) return head;
    node* newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

void display(node* head){
    node* tmp = head;
    while (tmp != NULL)
    {
        cout<<tmp->data<<" -> ";
        tmp = tmp->next;
    }
    cout<<"NULL"<<endl;
}

bool search(node* head, int key){
    node* tmp = head;
    while (tmp != NULL)
    {
        if(tmp->data == key) return true;
        tmp = tmp->next;
    }
    return false;
}

void deleteAtHead(node* &head){
    node* todel = head;
    head = head->next;
    delete todel;
}

void deletion(node* &head, int val){

    if(head == NULL) return;
    if(head->next == NULL) {deleteAtHead(head); return;}

    node* tmp = head;
    while (tmp->next->data != val)
        tmp = tmp->next;
    node* todel = tmp->next;
    tmp->next = tmp->next->next;
    delete todel;
}

node* reversek(node* &head, int k){
    node* prev = NULL;
    node* curr = head;
    node* nxt;

    int count = 0;
    while (curr != NULL && count < k)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }

    if(nxt != NULL) head->next = reversek(nxt, k);
    return prev;
}

bool detectCycle(node* &head){
    node* slow = head;
    node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) return true;
    }

    return false;
}

void makeCycle(node* &head, int pos){
    node* tmp = head;
    node* startNode;

    int count = 1;
    while (tmp->next != NULL)
    {
        if(count == pos) startNode = tmp;
        tmp = tmp->next;
        count++;
    }
    tmp->next = startNode;
}

void removeCycle(node* &head){
    node* slow = head;
    node* fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    slow->next = NULL;
}

int leangth(node* head){
    int l  = 0; node* tmp = head;
    while(tmp != NULL){l++; tmp = tmp->next;}
    return l;
}

node* kappend(node* &head, int k){
    node* newHead;
    node* newTail;
    node* tail = head;

    int l = leangth(head);
    k= k%l;
    int count = 1;
    while(tail->next != NULL){
        if(count == l-k){
            newTail = tail;
        }
        if(count == l-k+1){
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }

    newTail->next = NULL;
    tail->next = head;

    return newHead;
}

int intersection(node* &head1, node* &head2){
    int l1 = leangth(head1);
    int l2 = leangth(head2);
    int d = 0;
    node* ptr1; node* ptr2;
    if(l1 > l2){
        d = l1-l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        d = l2-l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while(d--){ ptr1 = ptr1->next; if(ptr1 == NULL) return -1;}
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1 == ptr2) return ptr1->data;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

void intersect(node* &head1, node* &head2, int pos){
    node* tmp1 = head1; pos--;
    while(pos--) tmp1=tmp1->next;
    node* tmp2 = head2;
    while(tmp2->next != NULL) tmp2 = tmp2->next;
    tmp2->next = tmp1;
}

void solve(){
    node* head1 = NULL;
    node* head2 = NULL;

    v32 arr1 = {1,2,3,4,5,6};
    v32 arr2 = {9, 10};
    forn(i, arr1.size()) insertAtTail(head1, arr1[i]);
    forn(i, arr2.size()) insertAtTail(head2, arr2[i]);

    display(head1);
    display(head2);
    
    cout<<intersection(head1, head2)<<ln;
    intersect(head1, head2, 5);
    cout<<intersection(head1, head2)<<ln;

    // node* newHead = kappend(head, 2);
    // display(newHead);
}

int main()
{
 fast_cin();
 #ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif

 ll t;
 cin >> t;
 for(int it=1;it<=t;it++) {
    solve();
 }
 return 0;
}