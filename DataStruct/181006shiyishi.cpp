#include <Stdio.h>
#include <Stdlib.h>
#include <Stdbool.h>
#include <limits.h>
#define MAXSIZE 9
#define MAXweight 55555
typedef struct {
	int vnode[MAXSIZE];//��¼���� 
	int edge[MAXSIZE][MAXSIZE];//����Ǳ� 
	int nv;
	int ne;
}graph;

typedef struct qnode{
	int data[MAXSIZE*MAXSIZE];
	int front,rear;
}qnode;   //���нṹ��  

void DFSER(graph *g);
qnode *buildq()
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->front=q->rear=0;
	return q;
}

bool isempty(qnode *q) //�����Ƿ�Ϊ�� 
{
	return q->front==q->rear;
}
bool isfull(qnode *q) //�����Ƿ����� 
{
	return q->rear==MAXSIZE*MAXSIZE;
}

int push(qnode *q ,int v)//��� 
{
	if(isfull(q))
	{
		printf("the queue is full!\n");
		return NULL;
	}
	q->data[q->rear]=v;
	q->rear++;
}
int pop(qnode *q)//���� 
{
	if(isempty(q))
	{
		printf("the queue is empty!\n");
		return NULL;
	}
	return q->data[q->front++];
}
void insertq(qnode *q)
{
	//�����ǲ����������洢�ڵ��Ȩ�� ��������ӡ�������v1��v2��weight�洢 
	int a[]={1,3,1,3,6,2,3,4,3,3,5,4,5,8,5,4,7,6,-1};
	for(int i=0;a[i]!=-1;i++)
	{
		push(q,a[i]);
	}
	//DFS���ҵ�ʱ������һ���ߣ�362����362ɾ�����ֻ��������ıߺͶ��� 
}
graph *buildg(qnode *q)//ͼ�ĳ�ʼ�� 
{
	int v1,v2,w;
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=0;
	g->nv=0;
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
			g->edge[i][j]=0;//û�б߽���ͳһȨ��Ϊ0 
		}
		g->vnode[i]=0;//�ڵ��¼��ʼ�� 
	}
	while(!isempty(q))
	{
		v1=pop(q);
		v2=pop(q);
		w=pop(q);
		if(g->vnode[v1]==0)
		{
			g->vnode[v1]=1;
			++g->nv;
		}
		if(g->vnode[v2]==0)
		{
			g->vnode[v2]=1;
			++g->nv;
		}
		g->edge[v1][v2]=w;
		g->edge[v2][v1]=w;
		++g->ne;
	}
	return g;
}
void print(graph *g)
{
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
			printf("%d  ",g->edge[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<MAXSIZE;i++)
	{
		printf("%d->",g->vnode[i]);
	}
	printf("\n");
}
void DFS(graph *g,int v)  //dfs 
{
	printf("%d->",v);
	g->vnode[v]=-1;
	for(int i=0;i<MAXSIZE;i++)
	{
		//�᲻����������жϵ������أ� 
		if(g->edge[v][i]!=0&&g->vnode[i]==1)
		{
			DFS(g,i);
		}
	}
}

void DFSER(graph *g)  //defsearch 
{
	for(int i=0;i<MAXSIZE;i++)
	{
		if(g->vnode[i]==1)
		{
			DFS(g,i);
		}
	}
}

void BFS(graph *g,qnode *q,int v)
{
	printf("%d->",v);
	push(q,v);
	g->vnode[v]=2;
	while(!isempty(q))
	{
		v=pop(q);
		for(int i=0;i<MAXSIZE;i++)
		{
			if(g->edge[v][i]!=0&&g->vnode[i]==-1)
			{
				printf("%d->",i);
				g->vnode[i]=2;
				push(q,i);
			}
		}
	}
}
qnode *CS_Q(qnode *q)
{
	for(int i=0;i<MAXSIZE*MAXSIZE;i++)
	{
		q->data[i]=NULL;
	}
	q->front=q->rear=0;
	return q;
}

void CS_WAY(int path[],int dist[])
{
	for(int i=0;i<MAXSIZE;i++)
	{
		path[i]=-1;
		dist[i]=-1;
	}
}

void UNWAY(int path[],int dist[],graph *g,int v,qnode *q)
{
	dist[v]=0;
	push(q,v);
	g->vnode[v]=8;
	while(!isempty(q))
	{
		v=pop(q);
//		printf("shi zhelima ?%d\n",v);
		for(int i=0;i<MAXSIZE;i++)
		{
			if(g->vnode[i]!=0&&dist[i]==-1&&g->edge[v][i]!=0)
			{
				dist[i]=dist[v]+1;
				path[i]=v;
				g->vnode[i]=8;
				push(q,i);
			}
		}
	}
	
}
void printway(int path[],int dist[])
{
	printf("\n");
	for(int i=0;i<MAXSIZE;i++)
	{
		printf("PATH:%d\t",path[i]);
		printf("DIST:%d\n",dist[i]);
	}
	printf("\n");
}

void CS_DJ(int dist[],int path[],int collected[])
{
	for(int i=0;i<MAXSIZE;i++)
	{
		if(i==1)
		{
			dist[i]=0;
			path[i]=-1;
		}else if(i==3)
		{
			dist[i]=1;
			path[i]=1;
		}else 
		{
			dist[i]=INT_MAX;
			path[i]=-1;
		}
		collected[i]=-1;
	}
}
void Dijkstra(graph *g,int dist[],int path[],int collected[],int v)
{
	int min,k;
	for(int i=0;i<MAXSIZE;i++)
	{
		if(g->edge[v][i]!=0)
		{
			dist[i]=g->edge[v][i];
		}
		if(g->edge[i][v]!=0)
		{
			path[i]=v;
		}
	}
	g->vnode[v]=1;
	for(int i=0;i<MAXSIZE;i++)
	{
		min=INT_MAX;
		k=v;
		for(int j=1;j<MAXSIZE;j++)
		{
			if(g->vnode[j]==8&&dist[j]<min)
			{
				k=j;
				min=dist[j];
			}
		}
		g->vnode[k]=1;
		for(int j=1;j<MAXSIZE;j++)
		{
			if(g->vnode[j]==8)
			{
				if(g->edge[k][j]<min&&dist[k]+g->edge[k][j]<dist[j])
				{
					dist[j]=dist[k]+g->edge[k][j];
					path[j]=k;
				}
			}
		}
	}
}




int main()
{
	int path[MAXSIZE];
	int dist[MAXSIZE];
	int collected[MAXSIZE];
	qnode *q=buildq();
	insertq(q);
	graph *g=buildg(q);
	print(g);
	DFSER(g);
	qnode *Q=CS_Q(q);
	printf("\nBFS:\n");
	BFS(g,Q,1);
	CS_WAY(path,dist);
	UNWAY(path,dist,g,1,Q);
	printway(path,dist);
	CS_DJ(dist,path,collected);
	Dijkstra(g,dist,path,collected,1);
	printf("\nDijkstra:\n");
	printway(path,dist);
	
}

