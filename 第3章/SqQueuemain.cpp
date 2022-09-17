#include "SqQueue.cpp"	//包含前面的顺序队基本运算函数
void main()
{	SqQueue sq;
	ElemType e;
	printf("初始化队列");
	InitQueue(sq);
	printf("队%s\n",(QueueEmpty(sq)==1?"空":"不空"));
	printf("a进队\n");EnQueue(sq,'a');
	printf("b进队\n");EnQueue(sq,'b');
	printf("c进队\n");EnQueue(sq,'c');
	printf("d进队\n");EnQueue(sq,'d');
	printf("队%s\n",(QueueEmpty(sq)==1?"空":"不空"));
	GetHead(sq,e);
	printf("队头元素:%c\n",e);
	printf("出队次序:");
	while (!QueueEmpty(sq))		//队不空循环
	{	DeQueue(sq,e);			//出队元素e
		printf("%c ",e);		//输出元素e
	}
	printf("\n");
	DestroyQueue(sq);
}
