#include <stdio.h>
#include <stdlib.h>
#include "map.h"

int max(int a, int b){
	if (a>b) return a;
	return b;
}

int min(int a, int b){
	if (a<b) return a;
	return b;
}

int function_min(int a, int b, int c, int *temp){
	if (a == -1 &&(b == -1 || c == -1)) {*temp = 0; return -1;}
	else if (b == -1 || c == -1) {*temp = 0; return a;}
	else if (a == -1) {*temp = 1; return (b+c);}
	else if (a>b+c) {*temp = 1; return b+c;}
	{*temp = 0; return a;}
}

int spaceskip(){
	int ch = getchar();
	for(;ch == ' ' || ch == '\n' || ch == '\t';ch = getchar()){}
	return ch;
}

int build_num(){
	int num, sign = 1, ch = spaceskip();
	if(ch == '-'){sign = -1;	ch = getchar();	}
	for(num = 0;ch >= '0' && ch <='9';ch = getchar()){	num = num * 10 + ch - '0';	}
	return (num * sign);
}

void *init_graph(int x, int y, int z){
	if (z >= 0){
		int ***graph = malloc(x * sizeof(int **));	if(graph == NULL) {fprintf(stderr, "Error: Malloc Failed on stage 1\n");}
		for(int i = 0;i <= x;i++){
			graph[i] = malloc((y) * sizeof(int*));	if(graph[i] == NULL) {fprintf(stderr, "Error: Malloc Failed on stage 2 with i:%d\n", i);}
			for(int j = 0;j <= i;j++){
				graph[i][j] = malloc((z) * sizeof(int));	if(graph[i][j] == NULL) {fprintf(stderr, "Error: Malloc Failed on stage 3 with i:%d\tj:%d\n", i, j);}
				for(int k = 0;k <= z;k++){
					graph[i][j][k] = -2;
				}
			}
		}
		return graph;
	}
	else if (y >= 0){
		int **graph = malloc(x * sizeof(int *));	if(graph == NULL) {fprintf(stderr, "Error: Malloc Failed on stage 1\n");}
		for(int i = 0;i <= x;i++){
			graph[i] = malloc((y+1) * sizeof(int));	if(graph[i] == NULL) {fprintf(stderr, "Error: Malloc Failed on stage 2 with i:%d\n", i);}
			for(int j = 0;j <= y && y >= 0;j++){
				graph[i][j] = -2;
			}
		}
		return graph;
	}
	else{
		int *graph = malloc(x * sizeof(int));	if(graph == NULL) {fprintf(stderr, "Error: Malloc Failed on stage 1\n");}
		for(int i = 0;i <= x && x >= 0;i++){
			graph[i] = -2;
		}
		return graph;
	}
}

void print_graph(int x, int y, int z, void *graph){
		printf("--------------------------------------\n");
	if (z >= 0){
		for(int i = 0;i <= x;i++){
			for(int j = 0;j <= i;j++){
				for(int k = 0;k <= z;k++){
					printf("[%d,%d,%d]%d\n", i, j, k, ((int***)graph)[i][j][k]);
				}
				printf("\n");
			}
		}
		printf("--------------------------------------\n");
	}
	else if (y >= 0){
		for(int i = 0;i <= x;i++){
			for(int j = 0;j <= y && y >= 0;j++){
				printf("[%d,%d]%d\t", i, j, ((int**)graph)[i][j]);
			}
			printf("\n");
		}
		printf("--------------------------------------\n");
	}
	else{
		for(int i = 0;i <= x && x >= 0;i++){
			printf("[%d]%d\n", i, ((int*)graph)[i]);
		}
		printf("--------------------------------------\n");
	}
}