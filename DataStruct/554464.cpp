BtreeNode *creatBtree()
{
	int num;
	printf("请输入元素\n");
	scanf("%d",&num);
	if(num==0)//用0来区分是不是结束
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

