#include <stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)

int n,i,cost[10], value[10],weight,current_weight,maxi,used[10];
float total_value;
void read()
{   printf("Nr of objects: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		printf("Object #%d cost: ", i);
		scanf("%d", &cost[i]);
		printf("Object #%d value: ", i);
		scanf("%d", &value[i]);
	}
	printf("Maximum weight: ");
	scanf("%d", &weight);
}
int main() {
	read();
	for (i = 1; i <=n; i++)
		used[i] = 0; 

	current_weight = weight;
	while (current_weight > 0) { 
		maxi = -1;
		for (i = 0; i < n; ++i)
			if ((used[i] == 0) &&
				((maxi == -1) || ((float)value[i] / cost[i] > (float)value[maxi] / cost[maxi])))
				maxi = i;

		used[maxi] = 1; 
		current_weight -= cost[maxi]; 
		total_value += value[maxi];
		if (current_weight >= 0)
			printf("Added object %d (%d$, %dKg) completely in the bag. Space left: %d.\n", maxi + 1, value[maxi], cost[maxi], current_weight);
		else {
			printf("Added %d%% (%d$, %dKg) of object %d in the bag.\n", (int)((1 + (float)current_weight / cost[maxi]) * 100), value[maxi], cost[maxi], maxi + 1);
			total_value -= value[maxi];
			total_value += (1 + (float)current_weight / cost[maxi]) * value[maxi];
		}
	}

	printf("Filled the bag with objects worth %.2f$.\n", total_value);
}
