#pragma once

#include<bits/stdc++.h>
using namespace std;

template<typename K, typename V>
class Node {
public:
    const K key;
    V value;
    Node<K,V>* prev;
    Node<K,V>* next;
    
    Node(const K &key,const V &value);
    Node(const K &key,const V &value,const Node<K,V>* prev,const Node<K,V>* next);

};
