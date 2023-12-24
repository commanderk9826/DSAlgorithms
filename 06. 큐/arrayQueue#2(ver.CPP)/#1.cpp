#define queueMAXSIZE 100;

template<typename E>
class arrayQueue {
private: 
	E queue[queueMAXSIZE];
	int front, rear;
public:
	arrayQueue();
	~arrayQueue();
	void enQueue(const E& e);
	E deQuee(void);
	E peek(void) const;
	bool isEmpty(void) const;
	bool isFull(void) const;
	void printQueue(void) const;
};
