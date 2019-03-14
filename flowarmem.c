#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "flowarmem.h"

int recursive_with_memory(int i, int j, int k, int **graph, int ***memory){					//printf("i:%d j:%d k:%d\n", i, j, k);
	int temp;
	if(k > 0 && i >= 0 && j >= 0){
		if(memory[max(i, j)][min(i,j)][k-1] == -2){							//printf("%d\n", memory[max(i, j)][min(i,j)][k-1]);
			memory[max(i, j)][min(i,j)][k-1] = recursive_with_memory(i, j, k-1, graph, memory);
		}
		if(memory[max(i, k)][min(i, k)][k-1] == -2){							//printf("%d\n", memory[max(i, k)][min(i, k)][k-1]);
			memory[max(i, k)][min(i, k)][k-1] = recursive_with_memory(i, k, k-1, graph, memory);
		}
		if(memory[max(k, j)][min(k, j)][k-1] == -2){							//printf("%d\n", memory[max(k, j)][min(k, j)][k-1]);
			memory[max(k, j)][min(k, j)][k-1] = recursive_with_memory(k, j, k-1, graph, memory);
		}
		return (function_min(
			memory[max(i, j)][min(i,j)][k-1],
			memory[max(i, k)][min(i, k)][k-1],
			memory[max(k, j)][min(k, j)][k-1],
			&temp
		));
	}
	return (function_min(
		graph[max(i, j)][min(i,j)],
		graph[max(i, k)][min(i, k)],
		graph[max(k, j)][min(k, j)],
		&temp
	));
}


void solve(int n, int **graph){
	int temp;
	int ***memory = init_graph(n, n, n);
	//print_graph(n, n, n, memory);
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= i;j++){
			if(i == j){
				printf("\n");
				continue;
			}
			temp = recursive_with_memory(i, j, n, graph, memory);
			if(temp >= 0)	printf("From node %d to node %d: Length of shortest path is %d\n", i, j, temp);
			else		printf("From node %d to node %d: There is no path\n", i, j);
		}
	}

}