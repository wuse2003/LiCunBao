#include "SqQueue.cpp"	//����ǰ���˳��ӻ������㺯��
void main()
{	SqQueue sq;
	ElemType e;
	printf("��ʼ������");
	InitQueue(sq);
	printf("��%s\n",(QueueEmpty(sq)==1?"��":"����"));
	printf("a����\n");EnQueue(sq,'a');
	printf("b����\n");EnQueue(sq,'b');
	printf("c����\n");EnQueue(sq,'c');
	printf("d����\n");EnQueue(sq,'d');
	printf("��%s\n",(QueueEmpty(sq)==1?"��":"����"));
	GetHead(sq,e);
	printf("��ͷԪ��:%c\n",e);
	printf("���Ӵ���:");
	while (!QueueEmpty(sq))		//�Ӳ���ѭ��
	{	DeQueue(sq,e);			//����Ԫ��e
		printf("%c ",e);		//���Ԫ��e
	}
	printf("\n");
	DestroyQueue(sq);
}
