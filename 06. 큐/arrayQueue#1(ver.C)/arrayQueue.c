#define queueMAXSIZE 100;
typedef int element;

typedef struct _arrayQueue {
	element queue[queueMAXSIZE];
	int front, rear;
}arrayQueue;

arrayQueue* queueCreate(void);
void queueDestroy(arrayQueue* Q);
void enQueue(arrayQueue* Q, element item);
element deQueue(arrayQueue* Q);
element peek(arrayQueue* Q);
int isEmpty(arrayQueue* Q);
int isFull(arrayQueue* Q);
void queuePrint(arrayQueue* Q);