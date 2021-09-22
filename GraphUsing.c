#include "./queue.c"
#include "./stack.c"
#include "./mtk.c"

int mark[100];
int p[100];


void init_Mark(int n){
	int i;
	for(i=1;i<=n;i++)
		mark[i]=0;
}

void init_Parents(int n){
	int i;
	for(i=1;i<=n;i++)
		p[i]=0;
}

//BFS (chieu rong)

Queue Q;

void BFS(Graph *pG, int u){
	
	enQueue(&Q,u);
	
	int v;
	
	do{
		u = front(&Q);
		deQueue(&Q);
		
		if(!mark[u]){
			
			printf("%d\n",u);
			mark[u]=1;
			
			for(v=1;v<=pG->n;v++){
				if(adjacent(pG,u,v)){
					if(!mark[v]){
						enQueue(&Q,v);
						if(p[v]==0) p[v] = u;
					}
				}
			}
		}
		
	}while(!emptyQueue(&Q));
}

void BFS_ToanBo(Graph *pG){
	init_Mark(pG->n);
	init_Parents(pG->n);
	initQueue(&Q);
	
	int u;
	for(u=1;u<=pG->n;u++){
		if(!mark[u]) BFS(pG,u);
	}
}

#if 0
// DFS de quy (chieu sau)
void DFS(Graph *pG, int u){
	
	printf("%d\n",u);
	mark[u]=1;
	int v;
	for(v=1;v<=pG->n;v++){
		if(adjacent(pG,u,v)){
			if(!mark[v]){
				DFS(pG, v);
				p[v] = u;
			}
		}
	}
}

void DFS_ToanBo(Graph *pG){
	init_Mark(pG->n);
	init_Parents(pG->n);
	
	int u;
	for(u=1;u<=pG->n;u++){
		if(!mark[u]) DFS(pG,u);
	}
}

#else
// DFS ngan xep (chieu sau)

Stack S;

void DFS(Graph *pG, int u){
	
	push(&S, u);
	
	int v;
	
	do{
		u = Top(&S);
		pop(&S);
		
		if(!mark[u]){
			
			printf("%d\n",u);
			mark[u]=1;
			
			for(v=1;v<=pG->n;v++){
				if(adjacent(pG,u,v)){
					if(!mark[v]){
						push(&S, v);
						p[v] = u;
					}
				}
			}
		}
	
	}while(!emptyStack(&S));
	
	
	
}

void DFS_ToanBo(Graph *pG){
	init_Mark(pG->n);
	init_Parents(pG->n);
	initStack(&S);
	
	int u;
	for(u=1;u<=pG->n;u++){
		if(!mark[u]) DFS(pG,u);
	}
}

#endif

int EULER_path(Graph *pG){
	int u;
	int oddDegEdges = 0;
	for(u=1;u<=pG->n;u++){
		if(degree(pG, u)%2) oddDegEdges++;
	}
	return oddDegEdges==2;
}




