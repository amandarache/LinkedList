template <class T>
struct Node {
	T element;
	Node<T>* next;
};

template <class T>
class LinkedList {
public:
	LinkedList();
	~LinkedList();
	void add(T element);
	void addIndex(T element, int index);
	void remove();
	void removeIndex(int index);
	int getSize();
	void print();
	bool empty();

private:
	Node<T>* first;
	int size;
};