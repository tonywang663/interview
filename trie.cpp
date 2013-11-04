#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Node{
public:
	Node(char c = ' '): words(0), prefix(0){
		mContent = c;
	}
	~Node(){}
	Node* findChild(char c);
	void addchild(Node* node){mChildren.push_back(node);}
	void incwords(){
		words++;
	}
	void incprefix(){
		prefix++;
	}

	int getwords(){
		return words;
	}

	int getprefix(){
		return prefix;
	}

private:
	vector<Node*> mChildren;
	char mContent;
	int words;
	int prefix;
};

class Trie{
public:
	Trie();
	~Trie(){};
	void addword(const string&);
	int countword(const string&);
	int countprefix(const string&);
//	void deleteword(const string&);

private:
	Node* root;
};

Node* Node::findChild(char c){
	for(int i = 0; i < mChildren.size(); i++){
		if(mChildren[i]->mContent == c)
			return mChildren[i];
	}
	return NULL;
}

Trie::Trie(){
	root = new Node();
}

void Trie::addword(const string& str){
	if(str.empty())
		return;
	
	Node* cur = root;
	int index = 0;

	while(index < str.size()){
		Node* next = cur->findChild(str[index]);
		if(next == NULL){
			next = new Node(str[index]);
			cur->addchild(next);
		}
		if(index == str.size() - 1)
			next->incwords();
		else
			next->incprefix();

		cur = next;
		index++;
	}
}

int Trie::countword(const string& str){
	if(str.empty())
		return 0;

	Node* cur = root;
	int index = 0;

	while(index < str.size()){
		Node* next = cur->findChild(str[index]);
		if(next == NULL)
			return 0;
		
		cur = next;
		index++;
	}
	return cur->getwords();

}

int Trie::countprefix(const string& str){
	if(str.empty())
		return 0;

	Node* cur = root;
	int index = 0;

	while(index < str.size()){
		Node* next = cur->findChild(str[index]);
		if(next == NULL)
			return 0;
		
		cur = next;
		index++;
	}
	return cur->getprefix();

}

void maintrie(){
	Trie tree;
	tree.addword("abc");
	tree.addword("apple");

	cout<<tree.countprefix("a")<<endl;
	cout<<tree.countword("abc")<<endl;

	system("pause");

}