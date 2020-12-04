#include <stdio.h>
#include <stdlib.h>
#define INFINITE 9999
int find_min_weighted_vertex(int weight[], int *not_selected, int vertices_number) { //Finds minimum weighted vertex.
	int min;
	for (int i = 0; i < vertices_number; i++) {
		if (not_selected[i]) { //Previous function results are selected nodes.
			min = weight[i];
			break;
		}
	}
	for (int i = 0; i < vertices_number; i++) {
		if (weight[i] < min && not_selected[i]) min = weight[i];
	}
	for (int i = 0; i < vertices_number; i++) {
		if (weight[i] == min && not_selected[i]) {
			not_selected[i] = 0;
			return i;
		}
	}
	printf("FAILURE\n");
	exit(1);
}
void min_distance(int min_weighted_node, int *graph, int *weight, int path[], int vertices_number) { //Implements the edge relaxation.
	for (int i = 0; i < vertices_number; i++) {
		if (weight[min_weighted_node] + *(graph + min_weighted_node * vertices_number + i) < weight[i]) {
			weight[i] = weight[min_weighted_node] + *(graph + min_weighted_node * vertices_number + i);
			path[i] = min_weighted_node; //Tracks path.
		}
	}
}
void display_result(int weight[], int path[], int vertices_number, int source_vertex) { //Displays shortest distances and paths.
	printf("Vertex\tDistance from source\tPath\n");
	for (int i = 0; i < vertices_number; i++) {
		printf("%d\t", i);
		if(weight[i]!= INFINITE)printf("%d\t\t\t", weight[i]);
		else printf("INFINITE\t\t");
		if (weight[i]!= INFINITE) {
			int destination = i;
			if (i != source_vertex) {
				int j = i;
				int *temp = (int *)malloc(vertices_number * sizeof(int));
				int k = 0;
				do {
					j = path[j];
					temp[k++] = j; //Inserts the path into temp array, reversely.
				} while (j != source_vertex);
				for (int i = k - 1; i >= 0; i--) {
					printf("%d-", temp[i]);
				}
			}
			printf("%d", destination);
		}
		else {
			printf("No path.");
		}
		printf("\n");
	}
	printf("\n");
}
void dijkstra(int *graph, int vertices_number, int source_vertex) { //Finds shortest distances from source and paths by using the Dijkstra's Algorithm.
	int *weight = (int *)malloc(vertices_number * sizeof(int));
	int *not_selected = (int *)malloc(vertices_number * sizeof(int));
	int *path = (int *)malloc(vertices_number * sizeof(int));
	for (int i = 0; i < vertices_number; i++) {
		path[i] = source_vertex;
	}
	int min_weighted_vertex;
	for (int i = 0; i < vertices_number; i++) { //Beginning of the Dijkstra's Algorithm.
		if (i == source_vertex) weight[i] = 0;
		else weight[i] = INFINITE;
		not_selected[i] = 1;
	}
	for (int i = 0; i < vertices_number; i++) { //Main of dijkstra function.
		min_weighted_vertex = find_min_weighted_vertex(weight, not_selected, vertices_number);
		min_distance(min_weighted_vertex, graph, weight, path, vertices_number);
	}
	display_result(weight, path, vertices_number, source_vertex);
}
int main() {
	int graph_existing[8][8] = //This graph is taken from our presentation and this link: https://youtu.be/jT3c45XkPTg (Last visited Dec. 4, 2020.)
						{ { 0, 20, INFINITE, 80, INFINITE, INFINITE, 90, INFINITE },
						{ INFINITE, 0, INFINITE, INFINITE, INFINITE, 10, INFINITE, INFINITE},
						{ INFINITE, INFINITE, 0, 10, INFINITE, 50, INFINITE, 20},
						{ INFINITE, INFINITE, 10, 0, INFINITE, INFINITE, 20, INFINITE },
						{ INFINITE, 50, INFINITE, INFINITE, 0, INFINITE, 30, INFINITE },
						{ INFINITE, INFINITE, 10, 40, INFINITE, 0, INFINITE, INFINITE },
						{ 20, INFINITE, INFINITE, INFINITE, INFINITE, INFINITE, 0, INFINITE },
						{ INFINITE, INFINITE, INFINITE, INFINITE, INFINITE, INFINITE, INFINITE, 0} };
	do {
		printf("---Dijkstra's Algorithm---\n");
		printf("1. Work on the existing graph.\n");
		printf("2. Enter a new graph.\n");
		printf("3. Exit.\n");
		printf("Select an option: ");
		int option;
		scanf_s("%d", &option);
		switch (option) {
		case 1:
			printf("\n");
			dijkstra((int*)graph_existing, 8, 0);
			break;
		case 2:
			printf("\nEnter the number of vertices: ");
			int vertices_number;
			scanf_s("%d", &vertices_number);
			int *graph_new = (int *)malloc(vertices_number * vertices_number * sizeof(int));
			printf("Enter the vertices (For infinite value, enter 9999):\n");
			for (int i = 0; i < vertices_number; i++)
				for (int j = 0; j < vertices_number; j++)
					scanf_s("%d", (graph_new + i * vertices_number + j));
			printf("Enter the source vertex: ");
			int source_vertex;
			scanf_s("%d", &source_vertex);
			printf("\n");
			dijkstra((int*)graph_new, vertices_number, source_vertex);
			break;
		default:
			return 0;
		}
	} while (1);
	
}
