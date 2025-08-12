#include<bits/stdc++.h>
#include "Node.hpp"
using namespace std;


Node::Node(const K &key,const V &value):key(key),value(value){
	prev=nullptr;
	next=nullptr;
}

Node::Node(const K &key,const V &value,const Node<K,V>* prev,const Node<K,V>* next):key(key),value(value),prev(prev),next(next){}