#include <stdio.h>
#include "map.h"

#define Debug 0

int main(){
	int i;
	scanf("%d", &i);

	int **map = init_map(i, -1, 0);
	scan_map(map);
	i--;
#if Debug == 1
	print_map(map);
#endif
	solve(i, map);

	free_map(map);
	return 0;
}