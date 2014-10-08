/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution{
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        return cloneGraphBFS(node);
    }
    UndirectedGraphNode *cloneGraphBFS(UndirectedGraphNode * node)
    {
        if (node == NULL)
            return NULL;
        
        map<int, UndirectedGraphNode *> myMap;
        queue<UndirectedGraphNode *> myQueue;
        myQueue.push(node);
        while(!myQueue.empty())
        {
            UndirectedGraphNode * tempNode = myQueue.front();
            myQueue.pop();
            int label = tempNode->label;
            if (myMap.find(label) == myMap.end())
                myMap.insert(make_pair(label, new UndirectedGraphNode(label)));
            
            vector <UndirectedGraphNode *> & neighbors = myMap[label]->neighbors;
            int N = tempNode->neighbors.size();
            for (int i = 0; i<N; ++i)
            {
                label = tempNode->neighbors[i]->label;
                if (myMap.find(label) == myMap.end())
                {
                    myQueue.push(tempNode->neighbors[i]);
                    myMap.insert(make_pair(label, new UndirectedGraphNode(label)));
                }
                neighbors.push_back(myMap[label]);
            }
        }
        return myMap.begin()->second;
    }
};