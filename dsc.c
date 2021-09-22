#define MAX_M 100

typedef struct {
	int u,v;
}edge;

typedef struct {
	int n,m;
	edge edges[MAX_M];
}Graph;

void init_graph(Graph *pG, int n){
	pG->n=n;
	pG->m=0;
}

void add_edge(Graph *pG, int u, int v){
	if(u>=1 && u<=pG->n && v>=1 && v<=pG->n){
		pG->edges[pG->m].u=u;
		pG->edges[pG->m++].v=v;
	}
}

void nhap_graph(Graph *pG){
	int m;
    scanf("%d",&m);
    int i;
    int u,v;
    for(i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        add_edge(pG,u,v);
    }
}



//void add_edge(Graph *pG, int u, int v){
//	int i, flag=1;
//	for(i=0;i<pG->m && flag;i++){
//		if(pG->edges[i].u==u && pG->edges[i].v==v)
//			flag=0;
//	}
//	
//	if(flag && u>=1 && u<=pG->n && v>=1 && v<=pG->n){
//		pG->edges[pG->m].u=u;
//		pG->edges[pG->m++].v=v;
//	}
//}

//void add_edge(Graph *pG, int u, int v){
//	int i, flag=1;
//	for(i=0;i<pG->m && flag;i++){
//		if((pG->edges[i].u==u && pG->edges[i].v==v) || (pG->edges[i].u==v && pG->edges[i].v==u))
//			flag=0;
//	}
//	
//	if(flag && u>=1 && u<=pG->n && v>=1 && v<=pG->n){
//		pG->edges[pG->m].u=u;
//		pG->edges[pG->m++].v=v;
//	}
//}

int adjacent(Graph *pG, int u, int v) {
	int i;
	int check=0;
	for(i=0;i<pG->m;i++){
		if((pG->edges[i].u==u && pG->edges[i].v==v) || (pG->edges[i].u==v && pG->edges[i].v==u))
		check=1;
	}
	return check;
}

//int adjacent(Graph *pG, int u, int v) {
//	int i;
//	int check=0;
//	for(i=0;i<pG->m;i++){
//		if(pG->edges[i].u==u && pG->edges[i].v==v)
//		check=1;
//	}
//	return check;
//}


int degree(Graph *pG, int u){
	int i;
	int count=0;
	for(i=0;i<pG->m;i++){
		if(pG->edges[i].u==u){
			if(pG->edges[i].v==u){
				count+=2;
			}else count++;
		}
		else if(pG->edges[i].v==u) count++;
	
	}
	return count;
}

void neighbours(Graph *pG, int u){
	int j;
	for(j=1;j<=pG->n;j++){
		if(adjacent(pG,u,j))
			printf("%d ",j);
	}
	printf("\n");
}


