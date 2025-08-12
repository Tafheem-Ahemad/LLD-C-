#include<bits/stdc++.h>
using namespace std;

#include "Node.hpp"
#include "DoublyLinkedList.hpp"

DoublyLinkedList::DoublyLinkedList(){
	head=nullptr;
	tail=nullptr;
	size=0;
}

DoublyLinkedList::~DoublyLinkedList(){
	clear();
}

Node<K,V>* DoublyLinkedList::getHead() const{
	return this->head;
}
Node<K,V>* DoublyLinkedList::getTail() const{
	return this->tail;
}
int DoublyLinkedList::getSize() const{
	return this->size;
}

void DoublyLinkedList::addFront(const K key,const V val){
	Node<K,V>* node=new Node(key,val);
	addFront(node);
}
void DoublyLinkedList::addFront(Node<K,V>* node){
	if(size==0){
		head=node;
		tail=node;
	}else{
		node->next=head;
		head->prev=node;
		head=node;
	}
	size++;
}
Node<K,V>* DoublyLinkedList::removeFront(){
	Node<K,V>* node=nullptr;
	if(size==1){
		node=head;
		head=tail=nullptr;
	}else{
		node=head;
		head=head->next;
		node->next=nullptr;
		head->prev=nullptr;
	}

	size--;
	return node;
}


void DoublyLinkedList::addEnd(const K key,const V val){
	Node<K,V>* node=new Node(key,val);
	addEnd(node);
}
void DoublyLinkedList::addEnd(Node<K,V>* node){
	if(size==0){
		head=node;
		tail=node;
	}else{
		node->prev=tail;
		tail->next=node;
		tail=node;
	}
	size++;
}
Node<K,V>* DoublyLinkedList::removeEnd(){
	Node<K,V>* node=nullptr;
	if(size==1){
		node=head;
		head=tail=nullptr;
	}else{
		node=tail;
		tail=tail->prev;
		node->prev=nullptr;
		tail->next=nullptr;
	}

	size--;
	return node;
}

void DoublyLinkedList::add(Node<K,V>* ptr , Node<K,V>* node){
	if(ptr==tail){
		addEnd(node);
		return;
	}

	Node*<K,V> next=cur->next;

	ptr->next=node;
	node->prev=ptr;

	node->next=next;
	next->prev=node;
}
void DoublyLinkedList::remove(Node<K,V>* node){
	if(node == head){
		removeFront();
		return ;
	}
	if(node == tail){
		removeEnd();
		return ;
	}

	Node<K,V>* prev=node->prev;
	Node<K,V>* next=node->next;
	
	prev->next=next;
	next->prev=prev;
}

void DoublyLinkedList::clear() {
    while (tail) {
        Node<K,V>* node = removeLast();
        delete node;
    }
}

void DoublyLinkedList::print() const{
	// Not implement still now
}