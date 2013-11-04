class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return cloneGraphBFS(node);
    }
	UndirectedGraphNode * cloneGraphBFS(UndirectedGraphNode * node)
	{
		if (!node)
			return NULL;
		map <int, UndirectedGraphNode *> nodes;
		queue <UndirectedGraphNode *> my_queue;
		my_queue.push(node);
		while(!my_queue.empty())
		{
			UndirectedGraphNode * my_node = my_queue.front();
			my_queue.pop();
			int i_label = my_node->label;
			if (nodes.find(my_node->label)==nodes.end())
				nodes.insert(make_pair(i_label, new UndirectedGraphNode(i_label)));

			vector <UndirectedGraphNode *> & neighbors = nodes[my_node->label]->neighbors;
			for (int i = 0; i<my_node->neighbors.size(); ++i)
			{
				i_label = my_node->neighbors[i]->label;
				if (nodes.find(i_label)==nodes.end())
				{
					nodes.insert(make_pair(i_label, new UndirectedGraphNode(i_label)));
					my_queue.push(my_node->neighbors[i]);
				}
				neighbors.push_back(nodes[i_label]);
			}
		}
		return (*nodes.begin()).second;
	}
};