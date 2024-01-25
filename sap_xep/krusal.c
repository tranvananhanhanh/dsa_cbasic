
#include <stdio.h> 
#include <stdlib.h> 
//so sánh theo trọng số
int comparator(const void* p1, const void* p2) 
{ 
	const int(*x)[3] = p1; 
	const int(*y)[3] = p2; 

	return (*x)[2] - (*y)[2]; 
} 
//khởi tạo rank các đỉnh đều bằng 0
void makeSet(int parent[], int rank[], int n) 
{   //duyệt qua các đỉnh
	for (int i = 0; i < n; i++) { 
        //định danh node gốc
		parent[i] = i;

		rank[i] = 0; 
	} 
}
//trả về định danh tập chứa x
int findParent(int parent[], int component) 
{ 
	if (parent[component] == component) 
		return component; 

	return parent[component] 
		= findParent(parent, parent[component]); 
} 

// Function to unite two sets 
void unionSet(int u, int v, int parent[], int rank[], int n) 
{ 
	// Finding the parents 
	u = findParent(parent, u); 
	v = findParent(parent, v); 
    //Biến một trong hai nút r1, hoặc r2 làm nút con của nút còn lại
    // (tiêu chí nút nào có độ cao thấp hơn thì biến thành nút con của nút còn lại để đảm bảo duy trì độ cao của các cây thấp)

	if (rank[u] < rank[v]) { 
		parent[u] = v; 
	} 
	else if (rank[u] > rank[v]) { 
		parent[v] = u; 
	} 
	else { 
		parent[v] = u; 

		// Since the rank increases if 
		// the ranks of two sets are same 
		rank[u]++; 
	} 
} 

// Function to find the MST 
void kruskalAlgo(int n, int edge[n][3]) 
{    
    //sắp xếp theo thứ tự tăng dần trọng số các đỉnh trong đồ thị 
	qsort(edge, n, sizeof(edge[0]), comparator); 

	int parent[n]; 
	int rank[n]; 

	makeSet(parent, rank, n); 

	// To store the minimun cost 
	int minCost = 0; 

	//hợp nhất các cạnh nếu khác cha
	for (int i = 0; i < n; i++) { 
        //tìm cha của cạnh
		int v1 = findParent(parent, edge[i][0]); 
		int v2 = findParent(parent, edge[i][1]); 
		int wt = edge[i][2]; 

		// If the parents are different that 
		// means they are in different sets so 
		// union them (tránh trường hợp tạo thành chu trình)
		if (v1 != v2) { 
			unionSet(v1, v2, parent, rank, n); 
            //tăng trọng số khung sau khi hợp nhất
			minCost += wt; 
			
		} 
	} 

	printf("%d", minCost); 
} 

int main() 
{    int V, E;
    scanf("%d %d", &V, &E);

    // Mảng chứa các cạnh của đồ thị và trọng số
    int edges[E][3];
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

	

	kruskalAlgo(E, edges); 

	return 0; 
}

