#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

 struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
 };


 UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	if(node == NULL)
		return node;

	map<UndirectedGraphNode*, UndirectedGraphNode*> umap;
	queue<UndirectedGraphNode*> que;
	que.push(node);

	UndirectedGraphNode* nnode = new UndirectedGraphNode(node->label);
	umap.insert(pair<UndirectedGraphNode*, UndirectedGraphNode*>(node, nnode));

	while(!que.empty()){
		UndirectedGraphNode* onode = que.front();
		que.pop();
		
		nnode = umap[onode];
		for(int i = 0; i < onode->neighbors.size(); i++){
			if(umap.find(onode->neighbors[i]) == umap.end()){
				UndirectedGraphNode* subnode = new UndirectedGraphNode(onode->neighbors[i]->label);
				nnode->neighbors.push_back(subnode);
				umap.insert(pair<UndirectedGraphNode*, UndirectedGraphNode*>(onode->neighbors[i], subnode));
				que.push(onode->neighbors[i]);
			}else{
				nnode->neighbors.push_back(umap[onode->neighbors[i]]);				
			}
		}
	}
	return umap[node];
    
}


 void maincloneGraph(){

	 
 }