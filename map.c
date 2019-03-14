#include <stdlib.h>
#include <stdio.h>
#include "map.h"
#include "common.h"

int **init_map(int y, int def, int diag){
	int **map = malloc((y+1) * sizeof(int *));
	for(int j = 0;j < y;j++){
		map[j] = malloc((j+1) * sizeof(int));
		for(int k = 0;k < j;k++){
			map[j][k] = def;
		}
		map[j][j] = diag;
	}
	map[y] = NULL; 
	return map;
}

void scan_map(int **map){
	for(int i = 0;map[i] != NULL;i++){
		for(int j = 0;j < i;j++){
			map[i][j] = build_num();
		}
		map[i][i] = 0;
	}
}

void copy_map(int **map_a, int **map_b){
	for(int x = 0;map_a[x] != NULL;x++){
		for(int y = 0;y <= x;y++){
			map_b[x][y] = map_a[x][y];
		}
	}
}

void print_map(int **map){
	for(int j = 0;map[j] != NULL;printf("\n"), j++){
		for(int k = 0;k <= j;printf("[%d,%d]%d ", j, k, map[j][k]), k++){}
	}
}

void free_map(int **map){
	for(int j = 0;map[j] != NULL;j++){	free(map[j]);	}
	free(map);
}
