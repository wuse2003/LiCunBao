#include "LinkQueue.cpp"	//����ǰ������ӻ������㺯��
void main()
{	LinkQueue *lq;
	ElemType e;
	printf("��ʼ������\n");
	InitQueue(lq);
	printf("��%s\n",(QueueEmpty(lq)==1?"��":"����"));
	printf("a����\n");EnQueue(lq,'a');
	printf("b����\n");EnQueue(lq,'b');
	printf("c����\n");EnQueue(lq,'c');
	printf("d����\n");EnQueue(lq,'d');
	printf("��%s\n",(QueueEmpty(lq)==1?"��":"����"));
	GetHead(lq,e);
	printf("��ͷԪ��:%c\n",e);
	printf("���Ӵ���:");
	while (!QueueEmpty(lq))		//�Ӳ���ѭ��
	{
		DeQueue(lq,e);			//����Ԫ��e
		printf("%c ",e);		//���Ԫ��e
	}
	printf("\n");
	DestroyQueue(lq);
}
