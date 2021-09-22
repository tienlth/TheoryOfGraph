#include <stdio.h>
#include "./GraphUsing.c"

int main() {
   	
   	freopen("./input.txt","r",stdin);
   	Graph G;
   	int n;
   	scanf("%d",&n);
   	
   	init_Graph(&G,n);
   	input_Graph(&G);
   	
   	DFS_ToanBo(&G);
	
    return 0;
}
