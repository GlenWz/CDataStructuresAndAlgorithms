BtreeNode *creatBtree()
{
	int num;
	printf("������Ԫ��\n");
	scanf("%d",&num);
	if(num==0)//��0�������ǲ��ǽ���
	{
		return NULL;
	}
	else 
	{
		BtreeNode *s = (BtreeNode *)malloc(sizeof(BtreeNode));
		s->data=num;
		s->lchild=creatBtree();
		s->rchild=creatBtree();
		return s;
	}
}

