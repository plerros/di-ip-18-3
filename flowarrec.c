#include <stdio.h>
#include "common.h"
#include "flowarrec.h"

int recursive(int i, int j, int k, int **graph){
	int temp;
	if(k >= 0){
		return (function_min(
				recursive(max(i,j), min(i,j), k-1, graph),
				recursive(max(i, k), min(i, k), k-1, graph),
				recursive(max(k, j), min(k, j), k-1, graph),
				&temp
		));
	}
	return (graph[i][j]);
}

void solve(int n, int **graph){
	int temp;
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= i;j++){
			if(i == j){
				printf("\n");
				continue;
			}
			temp = recursive(i, j, n, graph);
			if(temp >= 0)	printf("From node %d to node %d: Length of shortest path is %d\n", i, j, temp);
			else		printf("From node %d to node %d: There is no path\n", i, j);
		}
	}

}