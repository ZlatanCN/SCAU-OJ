#include"string.h"
#include"malloc.h" /* malloc()�� */
#include"stdio.h" /* EOF(=^Z��F6),NULL */
#include"stdlib.h" /* exit() */
using namespace std;

typedef int InfoType; /* ����Ȩֵ���� */
#define MAX_NAME 3 /* �����ַ�������󳤶�+1 */
typedef char VertexType[MAX_NAME]; /* �ַ������� */

/*ͼ���ڽӱ�洢��ʾ */
#define MAX_VERTEX_NUM 20
typedef enum {DG,DN,AG,AN} GraphKind; /* {����ͼ,������,����ͼ,������} */

// �߱���
typedef struct ArcNode
{
    int adjvex; /* �û���ָ��Ķ����λ�� */
    struct ArcNode *nextarc; /* ָ����һ������ָ�� */
    InfoType *info; /* ����Ȩֵָ�룩 */
} ArcNode;

// �������
typedef struct
{
    VertexType data; /* ������Ϣ */
    ArcNode *firstarc; /* ��һ������ĵ�ַ,ָ���һ�������ö���Ļ���ָ�� */
} VNode, AdjList[MAX_VERTEX_NUM];

// ͼ
typedef struct
{
    AdjList vertices;
    int vexnum,arcnum; /* ͼ�ĵ�ǰ�������ͻ��� */
    int kind; /* ͼ�������־ */
} ALGraph;

// ��λ���� u ��λ��
int LocateVex(ALGraph G,VertexType u)
{
    /* ��ʼ����: ͼG����,u��G�ж�������ͬ���� */
    /* �������: ��G�д��ڶ���u,�򷵻ظö�����ͼ��λ��;���򷵻�-1 */
    int i;
    for(i=0; i<G.vexnum; ++i)
        if(strcmp(u,G.vertices[i].data)==0)
            return i;
    return -1;
}

// ����ͼ
void CreateGraph(ALGraph *G)
{
    /* �����ڽӱ�洢�ṹ,����û�������Ϣ��ͼG(��һ����������4��ͼ) */
    int i,j,k;
    int w; /* Ȩֵ */
    VertexType va,vb;
    ArcNode *p;

    scanf("%d",&(*G).kind); // ����ͼ������
    scanf("%d%d",&(*G).vexnum,&(*G).arcnum); // ���붥�����ͱ���

    for(i=0; i<(*G).vexnum; ++i) /* ���춥������ */
    {
        scanf("%s",(*G).vertices[i].data);
        (*G).vertices[i].firstarc=NULL;
    }

    for(k=0; k<(*G).arcnum; ++k) /* ����������� */
    {
        if((*G).kind==1||(*G).kind==3) /* �� */
            scanf("%d%s%s",&w,va,vb);
        else /* ͼ */
            scanf("%s%s",va,vb);
        i=LocateVex(*G,va); /* ��β */
        j=LocateVex(*G,vb); /* ��ͷ */
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=j;
        if((*G).kind==1||(*G).kind==3) /* �� */
        {
            p->info=(int *)malloc(sizeof(int));
            *(p->info)=w;
        }
        else
            p->info=NULL; /* ͼ */
        p->nextarc=(*G).vertices[i].firstarc; /* ���ڱ�ͷ */
        (*G).vertices[i].firstarc=p;
        if((*G).kind>=2) /* ����ͼ����,�����ڶ������� */
        {
            p=(ArcNode*)malloc(sizeof(ArcNode));
            p->adjvex=i;
            if((*G).kind==3) /* ������ */
            {
                p->info=(int*)malloc(sizeof(int));
                *(p->info)=w;
            }
            else
                p->info=NULL; /* ����ͼ */
            p->nextarc=(*G).vertices[j].firstarc; /* ���ڱ�ͷ */
            (*G).vertices[j].firstarc=p;
        }
    }
}

// ��ȡ������Ϣ
VertexType* GetVex(ALGraph G,int v)
{
    /* ��ʼ����: ͼG����,v��G��ĳ���������š��������: ����v��ֵ */
    if(v>=G.vexnum||v<0)
        exit(0);
    return &G.vertices[v].data;
}

// ��ȡ��һ���ڽӵ�
int FirstAdjVex(ALGraph G,VertexType v)
{
    /* ��ʼ����: ͼG����,v��G��ĳ������ */
    /* �������: ����v�ĵ�һ���ڽӶ������š���������G��û���ڽӶ���,�򷵻�-1 */
    ArcNode *p;
    int v1;
    v1=LocateVex(G,v); /* v1Ϊ����v��ͼG�е���� */
    p=G.vertices[v1].firstarc;
    if(p)
        return p->adjvex;
    else
        return -1;
}

// ��ȡĳ���ڽӵ����һ���ڽӵ�
int NextAdjVex(ALGraph G,VertexType v,VertexType w)
{
    /* ��ʼ����: ͼG����,v��G��ĳ������,w��v���ڽӶ��� */
    /* �������: ����v��(�����w��)��һ���ڽӶ������š� */
    /* ��w��v�����һ���ڽӵ�,�򷵻�-1 */
    ArcNode *p;
    int v1,w1;
    v1=LocateVex(G,v); /* v1Ϊ����v��ͼG�е���� */
    w1=LocateVex(G,w); /* w1Ϊ����w��ͼG�е���� */
    p=G.vertices[v1].firstarc;
    while(p&&p->adjvex!=w1) /* ָ��p��������ָ���㲻��w */
        p=p->nextarc;
    if(!p||!p->nextarc) /* û�ҵ�w��w�����һ���ڽӵ� */
        return -1;
    else /* p->adjvex==w */
        return p->nextarc->adjvex; /* ����v��(�����w��)��һ���ڽӶ������� */
}

/*��ȱ���*/
int visited[MAX_VERTEX_NUM]; /* ���ʱ�־����(ȫ����),δ���ʱ��0�����ʱ��1 */
void(*VisitFunc)(char* v); /* ��������(ȫ����) */

// ������ȱ���
void DFS(ALGraph G,int v)
{
    /* �ӵ�v����������ݹ��������ȱ���ͼG���㷨7.5 */
    /* ���÷��ʱ�־ΪTRUE(�ѷ���) */
    /* ���ʵ�v������ */
    /* ��v����δ���ʵ��ڽӵ�w�ݹ����DFS */
    visited[v] = true;
    VisitFunc(G.vertices[v].data);
    ArcNode *p = G.vertices[v].firstarc;
    while(p != NULL)
    {
        int w = p->adjvex;
        if(!visited[w])
        {
            DFS(G,w);
        }
        p = p->nextarc;
    }
}

// �������
void print(char *i)
{
    printf("%s ",i);
}

// ������ȱ���
void DFSTraverse(ALGraph G)
{
    /* ��ͼG��������ȱ������㷨7.4 */
    /* ʹ��ȫ�ֱ���VisitFunc,ʹDFS�����躯��ָ����� */

    /* ���ʱ�־�����ʼ�� */
    int v = 0;
    for(v = 0; v < G.vexnum; ++v)
    {
        visited[v] = false; // ��ʼ�����ж���ķ���״̬Ϊδ���ʣ�false��
    }

    /* ����δ���ʵĶ������DFS */
    VisitFunc = print; // ���÷��ʺ���Ϊprint
    for(v = 0; v < G.vexnum; ++v)
    {
        if(!visited[v]) // �������vδ�����ʹ�
        {
            DFS(G, v); // �Զ���v����������ȱ���
        }
    }
    printf("\n"); // ������з���ʹ������������
}


int main()
{
    ALGraph g;
    CreateGraph(&g);
    DFSTraverse(g);
    return 1;
}
