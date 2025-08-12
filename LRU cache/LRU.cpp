
#include "LRU.hpp"

LRU::LRU(int capacity):capacity(capacity){
	cache.clear();
	curSize=0;
}

LRU::~LRU(){
	clear();
}

V LRU::_get(const K &key) const{
	if(contains(key)==0){
		static_assert(0);
	}
	
	Node<K,V>* node=cache[K];
	makeRecent(node);

	return node->val;
}

void LRU::_put(const K &key,const V &val){
	if(contains(key)){
		Node<K,V>* node=cache[key];
		makeRecent(node);
		node->value=val;
	}else{
		if(this->curSize == this->capacity){
			this->curSize--;
			Node<K,V>* node=DLL.getTail();
			K k=node->key;
			if(contains(key)==0){
				assert(0);
			}
			cache.erase(key);
		}

		Node<K,V>* node=new Node(key,val);
		cache[key]=node;
		addFront(node);

		this->curSize++;
	}
}

void LRU::_remove(const K &key){
	if(contains(key)==0){
		assert(0);
	}
	Node<K,V>* node=cache[key];
	DLL.remove(node);
	cache.erase(key);

	this->curState--;
}

V LRU::get(const K &key) const{
	return _get(key);
}

bool LRU::contains(K key) const {
    return (cache.find(key) != cache.end());
}

int LRU::getSize(){
	return curSize;
}

void LRU::clear() {
    DLL.clear();
	cache.clear();
}

void LRU::put(const K &key,const V &val){
	_put(key,val);
}

void LRU::remove(const K &key){
	_remove(key);
}

void LRU::makeRecent(const Node<K,V>* Node){
	DLL.remove(node);
	DLL.addFront(node);
}