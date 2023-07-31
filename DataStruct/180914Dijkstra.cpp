#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define maxsize 100
typedef int vertex;       
typedef struct edge{
	vertex adjvex;
	struct edge *next;
	int weight;
}edgenode;

typedef struct vnode{
	edgenode *firstedge;
	vertex head;
}Adjlist[maxsize];

typedef struct{
	Adjlist adjlist;
	int nv,ne;
}graph;                          //ͼ ������ӱ�洢 

typedef struct qnode{
	vertex data[maxsize];
	int front,rear;	
}qnode;                         //�������ڴ��ͼ�ĳ�ʼ��v1,v2��weight 

qnode *buildq()                //���г�ʼ�� 
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->front=q->rear=0;
	return q;
}
bool isfull(qnode *q)        //�ж϶����Ƿ�Ϊ���� 
{
	return q->rear==maxsize;
}
bool isempty(qnode *q)       //�ж϶����Ƿ�Ϊ�� 
{
	return q->front==q->rear;
}
void CS_unway(int dist[],int path[]) //��Ȩ·��dist��ʼ����dist���ڴ�����V�� 
{                            //����X����Ȩ���� 
	for(int i=0;i<maxsize;i++)      //path���ڴ����Դ��� 
	{
		path[i]=-1;
		dist[i]=-1;
	}
}
void CS_DJ(int dist[],int path[],int collected[])
{							//Dijkstra�㷨�����dist��path��collected���飬
	//path�����Դ��㣬dist��Ŵ����V��N�ľ���Ȩ�أ�collected���� �����Ƿ񱻷��� 
	for(int i=0;i<maxsize;i++)
	{
		collected[i]=-1;
		if(i==0)
		{
			dist[i]=0;
		}else if(i==1)
		{
			dist[i]=3;
			path[i]=0;
		}else if(i==2)
		{
			dist[i]=2;
			path[i]=0;
		}else 
		{
			dist[i]=INT_MAX;
			path[i]=-1;
		}
		
	}
}

int push(qnode *q,int v)     //���Ӳ��� 
{
	if(isfull(q))
	{
		printf("the queue is full!");
		return false;
	}else 
	{
		q->data[q->rear]=v;
		q->rear++;
	}
}
int pop(qnode *q)        //���Ӳ��� 
{
	if(isempty(q))
	{
		printf("the queue is empty!");
		return false;
	}else
	{
		return q->data[(q->front)++];
	}
}

void insertq(qnode *q)
{	//a�����ŵ���5�����㣬6���� ��0��1��3|��ʾ��0->1��Ȩ��Ϊ3 
	int a[]={0,1,3,0,2,2,1,4,1,1,3,3,2,3,3,3,4,2,-1};
	for(int i=0;a[i]!=-1;i++)
	{
		push(q,a[i]);   //���� 
	}
}
graph *buildg(qnode *q)
{	//ͼ�ĳ�ʼ�� 
	vertex v,w;
	int v1,v2,v3;
	graph *g=(graph *)malloc(sizeof(graph));
	g->nv=5;
	g->ne=6;
	for(v=0;v<g->nv;v++)
	{
		g->adjlist[v].firstedge=NULL;
		g->adjlist[v].head=v;
	}
	for(w=0;w<g->ne;w++)
	{
		edgenode *e=(edgenode *)malloc(sizeof(edgenode));
		v1=pop(q);      
		v2=pop(q);
		v3=pop(q);   //Ȩ�س��� 
		e->adjvex=v2;
		e->weight=v3;
		e->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e;
	}
	return g;
}
void printg(graph *g)   //��ӡ�ڽӱ� 
{
	edgenode *e;
	for(int i=0;i<g->nv;i++)
	{
		printf("H:%d->",g->adjlist[i].head);
		e=g->adjlist[i].firstedge;
		for(;e!=NULL;e=e->next)
		{
			printf("E:%d(W:%d)",e->adjvex,e->weight);
		}
		printf("\n");
	}
}
void DFS(graph *g,int visited[],vertex v)  //DFS�㷨 
{
	visited[v]=-1;
	edgenode *e;
	printf("%d->",g->adjlist[v].head);
	for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visited[e->adjvex]!=-1)
		{
			DFS(g,visited,e->adjvex);
		}
	}
}
void BFS(graph *g,int visited[],vertex v,qnode *q) //bfs�㷨 
{
	visited[v]=1;
	printf("%d->",g->adjlist[v].head);
	edgenode *e;
	push(q,v);
	while(!isempty(q))
	{
		v=pop(q);
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(visited[e->adjvex]!=1)
			{
				visited[e->adjvex]=1;
				printf("%d->",e->adjvex);
				push(q,e->adjvex);
			}
		}
	}
}
void Unway(graph *g,int dist[],int path[],vertex v,qnode *q)
{		//��Ȩ· 
	dist[v]=0;
	edgenode *e;
	push(q,v);
	while(!isempty(q))
	{
		v=pop(q);
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(dist[e->adjvex]==-1)
			{
				dist[e->adjvex]=dist[v]+1;
				path[e->adjvex]=v;
				push(q,e->adjvex);
			}
		}
	}
}
void printway(graph *g,int dist[],int path[])
{	//���·����ӡ 
	for(int i=0;i<g->nv;i++)
	{
		printf("DIST:%d\t",dist[i]);
		printf("PATH:%d\n",path[i]);
	}
}
void Dijkstra(graph *g,int dist[],int path[],int collected[],vertex v,qnode *q)
{	//dijkstra �㷨��ʵ�֣����������������˺ܾö���֪��������� 
	int min;      //��Сֵ 
	while(1)
	{
		edgenode *e;  
		e=g->adjlist[v].firstedge;
		min=e->weight;
		v=e->adjvex;
		for(;e!=NULL;e=e->next)  //δ��¼�����о�����С�� 
		{
			if(e->weight<min)
			{
				min=e->weight;
				v=e->adjvex;
			}
		}
		if(v==NULL)
		{
			break;
		}
		collected[v]=1;     //��¼��ȥ 
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(collected[e->adjvex]==-1)
			{
				if(dist[v]+e->weight<dist[e->adjvex])
				{
					dist[e->adjvex]=dist[v]+e->weight;
					path[e->adjvex]=v;
					
				}
			}
		}
	}
}

int main()
{
	int visited[maxsize];
	int dist[maxsize];
	int path[maxsize];
	int collected[maxsize];
	
	vertex v=0;
	qnode *q=buildq();
	insertq(q);
	graph *g=buildg(q);	
	printg(g);
	
	printf("\nDFS:\n");
	DFS(g,visited,v);
	printf("\nBFS:\n");
	BFS(g,visited,v,q);
	
	CS_unway(dist,path);    //��ʼ��dist��path 
	Unway(g,dist,path,v,q);
	printf("\nUNWAY:\n");
	printway(g,dist,path);
	
	CS_DJ(dist,path,collected);
	printf("\nDijkstra:\n");
	Dijkstra(g,dist,path,collected,v,q);
	printway(g,dist,path);
	
}
