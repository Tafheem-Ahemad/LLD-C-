#pragma once

#include<bits/stdc++.h>
#include "Node.hpp"
using namespace std;


template<typename K, typename V>
class DoublyLinkedList{
private:
	Node<K,V>* head;
	Node<K,V>* tail;
	int size;
public:

	DoublyLinkedList();
	~DoublyLinkedList();

	Node<K,V>* getHead() const;
	Node<K,V>* getTail() const;
	int getSize() const;

	void addFront(const K key,const V val);
	void addFront(Node<K,V>* node);
	Node<K,V>* removeFront();


	void addEnd(const K key,const V val);
	void addEnd(Node<K,V>* node);
	Node<K,V>* removeEnd();
	
	void add(Node<K,V>* ptr , Node<K,V>* node);
	void remove(Node<K,V>* node);

	void clear();

	void print() const;
};