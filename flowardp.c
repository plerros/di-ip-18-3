#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "flowardp.h"
#include "map.h"

#define PATH

void solve(int n, int **map){
	int **next = init_map(n+1, -2, -2);
	int **new_map = init_map(n+1, -1, 0);
	int i, j, u, v, temp;
	copy_map(map, new_map);

	for(i = 0;i <= n;i++){
		for(j = 0;j <= i;j++){
			next[i][j] = j;
		}
	}

	for(int k = 0;k <= n;k++){
		for(i = 0;i <= n;i++){
			for(j = 0;j < i;j++){
				new_map[max(i, j)][min(i, j)] = function_min(
						new_map[i][j],
						new_map[max(i, k)][min(i, k)],
						new_map[max(k, j)][min(k, j)],
						&temp
				);
				if(temp && i != j){next[max(i, j)][min(i, j)] = k;}
			}
		}
	}

	for(i = 0;i <= n;i++){
		for(j = 0;j < i;j++){
			if(new_map[i][j] >= 0)	printf("From node %d to node %d: Length of shortest path is %d\n", i, j, new_map[i][j]);
			else{printf("From node %d to node %d: There is no path\n", i, j);continue;}
#ifdef PATH
			u = i;
			v = j;

			if(next[u][v] == -2){continue;}
			printf("\tShortest path is: %d", u);
			while (u != v){
				if(next[u][v] > v){
					u = next[u][v];
					printf("->%d", u);
				}
				else if(next[u][v] < v){
					temp = next[u][v];
					u = v;
					v = temp;
					printf("->%d", v);
				}
				else{break;}
			}
			printf("->%d\n", j);
#endif
		}
		printf("\n");
	}
	free_map(new_map);
	free_map(next);
}