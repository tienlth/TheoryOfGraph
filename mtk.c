#define MAX_LENGTH 100

typedef struct {
	int A[MAX_LENGTH][MAX_LENGTH];
	int n,m;
}Graph;

void init_Graph(Graph *pG, int n){
	pG->n=n;
	pG->m=0;
	int i,j;
	for(i=1;i<=pG->n;i++){
		for(j=1;j<=pG->n;j++){
			pG->A[i][j]=0;
		}
	}
}

//vo huong
void add_edge(Graph *pG, int u, int v){
	pG->A[u][v]++;
	if(u!=v) pG->A[v][u]++;
	
	pG->m++;
}

////co huong
//void add_edge(Graph *pG, int u, int v){
//	pG->A[u][v]++;
//}

int adjacent(Graph *pG, int u, int v){
	return pG->A[u][v]>0;
}

void neighbors(Graph *pG, int u){
	int i;
	for(i=1;i<=pG->n;i++){
		if(i!=u && adjacent(pG,u,i)) printf("%d ",i);
	}
	printf("\n");
}

void input_Graph(Graph *pG){
	int i;
	int u,v;
	int m;
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		add_edge(pG,u,v);
	}
}

int degree(Graph *pG, int u){
	int deg = 0;
	int j;
	for(j=1;j<=pG->n;j++){
		if(u!=j) deg+=pG->A[u][j];
		else deg=deg+pG->A[u][j]*2;
	}
		
	return deg;
}

void print_Graph(Graph *pG){
	int i,j;
	for(i=1;i<=pG->n;i++){
		for(j=1;j<=pG->n;j++){
			printf("%d ",pG->A[i][j]);
		}
		printf("\n");
	}
}


