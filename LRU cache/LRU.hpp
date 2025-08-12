#pragma once

#include<bits/stdc++.h>
using namespace std;
#include "DoublyLinkedList.hpp"
#include "Node.hpp"

typename<typename K,typename V>
class LRU{
private:

	const int capacity;
	int curSize;
	unordered_map <K,Node<K,V>*>cache;
	DoublyLinkedList<K,V> DLL;

	// cannot copy 
	LRU(const LRU&) = delete;
    LRU& operator=(const LRU&) = delete;

	~LRU();

public:

	LRU(int capacity);

	V get(const K &key) const;
	void put(const K &key,const V &val);
	void remove(const K &key);

	bool contains(K key) const;
	int getSize();
	void clear();

private:
	V _get(const K &key) const;
	void _put(const K &key,const V &val);
	void _remove(const K &key);
	void makeRecent(const K &key);
};