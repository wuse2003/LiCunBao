#include "LinkQueue.cpp"	//包含前面的链队基本运算函数
void main()
{	LinkQueue *lq;
	ElemType e;
	printf("初始化队列\n");
	InitQueue(lq);
	printf("队%s\n",(QueueEmpty(lq)==1?"空":"不空"));
	printf("a进队\n");EnQueue(lq,'a');
	printf("b进队\n");EnQueue(lq,'b');
	printf("c进队\n");EnQueue(lq,'c');
	printf("d进队\n");EnQueue(lq,'d');
	printf("队%s\n",(QueueEmpty(lq)==1?"空":"不空"));
	GetHead(lq,e);
	printf("队头元素:%c\n",e);
	printf("出队次序:");
	while (!QueueEmpty(lq))		//队不空循环
	{
		DeQueue(lq,e);			//出队元素e
		printf("%c ",e);		//输出元素e
	}
	printf("\n");
	DestroyQueue(lq);
}
