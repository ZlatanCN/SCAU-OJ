#include"string.h"
#include"malloc.h" /* malloc()等 */
#include"stdio.h" /* EOF(=^Z或F6),NULL */
#include"stdlib.h" /* exit() */
using namespace std;

typedef int InfoType; /* 顶点权值类型 */
#define MAX_NAME 3 /* 顶点字符串的最大长度+1 */
typedef char VertexType[MAX_NAME]; /* 字符串类型 */

/*图的邻接表存储表示 */
#define MAX_VERTEX_NUM 20
typedef enum {DG,DN,AG,AN} GraphKind; /* {有向图,有向网,无向图,无向网} */

// 边表结点
typedef struct ArcNode
{
    int adjvex; /* 该弧所指向的顶点的位置 */
    struct ArcNode *nextarc; /* 指向下一条弧的指针 */
    InfoType *info; /* 网的权值指针） */
} ArcNode;

// 顶点表结点
typedef struct
{
    VertexType data; /* 顶点信息 */
    ArcNode *firstarc; /* 第一个表结点的地址,指向第一条依附该顶点的弧的指针 */
} VNode, AdjList[MAX_VERTEX_NUM];

// 图
typedef struct
{
    AdjList vertices;
    int vexnum,arcnum; /* 图的当前顶点数和弧数 */
    int kind; /* 图的种类标志 */
} ALGraph;

// 定位顶点 u 的位置
int LocateVex(ALGraph G,VertexType u)
{
    /* 初始条件: 图G存在,u和G中顶点有相同特征 */
    /* 操作结果: 若G中存在顶点u,则返回该顶点在图中位置;否则返回-1 */
    int i;
    for(i=0; i<G.vexnum; ++i)
        if(strcmp(u,G.vertices[i].data)==0)
            return i;
    return -1;
}

// 创建图
void CreateGraph(ALGraph *G)
{
    /* 采用邻接表存储结构,构造没有相关信息的图G(用一个函数构造4种图) */
    int i,j,k;
    int w; /* 权值 */
    VertexType va,vb;
    ArcNode *p;

    scanf("%d",&(*G).kind); // 输入图的类型
    scanf("%d%d",&(*G).vexnum,&(*G).arcnum); // 输入顶点数和边数

    for(i=0; i<(*G).vexnum; ++i) /* 构造顶点向量 */
    {
        scanf("%s",(*G).vertices[i].data);
        (*G).vertices[i].firstarc=NULL;
    }

    for(k=0; k<(*G).arcnum; ++k) /* 构造表结点链表 */
    {
        if((*G).kind==1||(*G).kind==3) /* 网 */
            scanf("%d%s%s",&w,va,vb);
        else /* 图 */
            scanf("%s%s",va,vb);
        i=LocateVex(*G,va); /* 弧尾 */
        j=LocateVex(*G,vb); /* 弧头 */
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=j;
        if((*G).kind==1||(*G).kind==3) /* 网 */
        {
            p->info=(int *)malloc(sizeof(int));
            *(p->info)=w;
        }
        else
            p->info=NULL; /* 图 */
        p->nextarc=(*G).vertices[i].firstarc; /* 插在表头 */
        (*G).vertices[i].firstarc=p;
        if((*G).kind>=2) /* 无向图或网,产生第二个表结点 */
        {
            p=(ArcNode*)malloc(sizeof(ArcNode));
            p->adjvex=i;
            if((*G).kind==3) /* 无向网 */
            {
                p->info=(int*)malloc(sizeof(int));
                *(p->info)=w;
            }
            else
                p->info=NULL; /* 无向图 */
            p->nextarc=(*G).vertices[j].firstarc; /* 插在表头 */
            (*G).vertices[j].firstarc=p;
        }
    }
}

// 获取顶点信息
VertexType* GetVex(ALGraph G,int v)
{
    /* 初始条件: 图G存在,v是G中某个顶点的序号。操作结果: 返回v的值 */
    if(v>=G.vexnum||v<0)
        exit(0);
    return &G.vertices[v].data;
}

// 获取第一个邻接点
int FirstAdjVex(ALGraph G,VertexType v)
{
    /* 初始条件: 图G存在,v是G中某个顶点 */
    /* 操作结果: 返回v的第一个邻接顶点的序号。若顶点在G中没有邻接顶点,则返回-1 */
    ArcNode *p;
    int v1;
    v1=LocateVex(G,v); /* v1为顶点v在图G中的序号 */
    p=G.vertices[v1].firstarc;
    if(p)
        return p->adjvex;
    else
        return -1;
}

// 获取某个邻接点的下一个邻接点
int NextAdjVex(ALGraph G,VertexType v,VertexType w)
{
    /* 初始条件: 图G存在,v是G中某个顶点,w是v的邻接顶点 */
    /* 操作结果: 返回v的(相对于w的)下一个邻接顶点的序号。 */
    /* 若w是v的最后一个邻接点,则返回-1 */
    ArcNode *p;
    int v1,w1;
    v1=LocateVex(G,v); /* v1为顶点v在图G中的序号 */
    w1=LocateVex(G,w); /* w1为顶点w在图G中的序号 */
    p=G.vertices[v1].firstarc;
    while(p&&p->adjvex!=w1) /* 指针p不空且所指表结点不是w */
        p=p->nextarc;
    if(!p||!p->nextarc) /* 没找到w或w是最后一个邻接点 */
        return -1;
    else /* p->adjvex==w */
        return p->nextarc->adjvex; /* 返回v的(相对于w的)下一个邻接顶点的序号 */
}

/*深度遍历*/
int visited[MAX_VERTEX_NUM]; /* 访问标志数组(全局量),未访问标记0，访问标记1 */
void(*VisitFunc)(char* v); /* 函数变量(全局量) */

// 深度优先遍历
void DFS(ALGraph G,int v)
{
    /* 从第v个顶点出发递归地深度优先遍历图G。算法7.5 */
    /* 设置访问标志为TRUE(已访问) */
    /* 访问第v个顶点 */
    /* 对v的尚未访问的邻接点w递归调用DFS */
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

// 输出函数
void print(char *i)
{
    printf("%s ",i);
}

// 深度优先遍历
void DFSTraverse(ALGraph G)
{
    /* 对图G作深度优先遍历。算法7.4 */
    /* 使用全局变量VisitFunc,使DFS不必设函数指针参数 */

    /* 访问标志数组初始化 */
    int v = 0;
    for(v = 0; v < G.vexnum; ++v)
    {
        visited[v] = false; // 初始化所有顶点的访问状态为未访问（false）
    }

    /* 对尚未访问的顶点调用DFS */
    VisitFunc = print; // 设置访问函数为print
    for(v = 0; v < G.vexnum; ++v)
    {
        if(!visited[v]) // 如果顶点v未被访问过
        {
            DFS(G, v); // 对顶点v进行深度优先遍历
        }
    }
    printf("\n"); // 输出换行符，使输出结果更美观
}


int main()
{
    ALGraph g;
    CreateGraph(&g);
    DFSTraverse(g);
    return 1;
}
