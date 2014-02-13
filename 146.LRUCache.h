struct LinkNode {
public:
	int val;	//store key
	LinkNode * next;
	LinkNode(){};
	LinkNode(int x) : val(x), next(NULL) {}
	LinkNode(int x, LinkNode * p_node) : val(x), next(p_node) {}
};
class LRUCache{
public:
	LRUCache(int capacity) {
		_capacity = capacity;
		_p_link_fake_head = _p_link_tail = new LinkNode(-1);
		_size = 0;
	}
	~LRUCache(){
		LinkNode * p_node;
		while (_p_link_fake_head != NULL)
		{
			p_node = _p_link_fake_head->next;
			delete _p_link_fake_head;
			_p_link_fake_head = p_node;
		}
	}
	int get(int key) {
		if (_stl_map.find(key) == _stl_map.end())
			return -1;

		reorder(key);
		return _stl_map[key].val;
	}
	void reorder(int key){
		LinkNode * p_my_node_1 = _stl_map[key].next;
		LinkNode * p_my_node_2 = p_my_node_1->next;
		if (p_my_node_2 == _p_link_tail)
			return;
		LinkNode * p_my_node_3 = p_my_node_2->next;
		p_my_node_1->next = p_my_node_3;
		_stl_map[p_my_node_3->val].next = p_my_node_1;
		_p_link_tail->next = p_my_node_2;
		p_my_node_2->next = NULL;
		_stl_map[key].next = _p_link_tail;
		_p_link_tail = p_my_node_2;
	}
	void set(int key, int value) {
		if (_capacity == 0)
			return;
		if (_stl_map.find(key) == _stl_map.end())
		{
			if (_size == _capacity)
			{
				LinkNode * p_node = _p_link_fake_head->next;
				_p_link_fake_head->next = p_node->next;
				_stl_map.erase(p_node->val);	//Don't forget.
				delete p_node;
				p_node = _p_link_fake_head->next;
				if (p_node != NULL)
					_stl_map[p_node->val].next = _p_link_fake_head;
				else
					_p_link_tail = _p_link_fake_head;
				--_size;
			}
			_p_link_tail->next = new LinkNode(key);
			LinkNode my_node(value, _p_link_tail);
			my_node.next = _p_link_tail;
			_stl_map.insert(make_pair(key, my_node));
			_p_link_tail = _p_link_tail->next;
			++_size;
		}
		else
		{
			_stl_map[key].val = value;
			reorder(key);
		}
	}
	void printList()
	{
		LinkNode * p_traverse = _p_link_fake_head;
		while (p_traverse != NULL)
		{
			printf("%d ", p_traverse->val);
			p_traverse = p_traverse->next;
		}
		printf("\n");
	}
private:
	int _capacity;
	int _size;
	LinkNode * _p_link_fake_head;
	LinkNode * _p_link_tail;
	unordered_map <int, LinkNode> _stl_map;	//pair stores key and the pointer point to the previous node of the node with key.
};