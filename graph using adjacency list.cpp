// author: Rahul Raj
/*

	Implementation of graph using Adjacency List
	And Depth First Search(DFS) using recursion
	(This is just for reference. In different questions, there will be some slight modification)

*/

// Adjacency list implementation
#include<iostream>

using namespace std;
#define MAX 100 // put the maximum possible value of node (check from constraint of question)

struct node {
  int data;
  node * ptr;
};

int gN; // global value of N (so that no need to pass in function argument)
node * graph[MAX]; //graph implementation using adjacency list, all initialized to 0 as it is global variable
bool visited[MAX]; // visited array for dfs, all initialized to 0 as it is global variable

node * getNewNode(int data) {
  node * t = (node * ) new node;
  t - > data = data;
  t - > ptr = 0;
  return t;
}

// generally use insert to front of the list in adjacency list
// This helps to reduce time complexity as compared to insert at last of the list.
// which requires O(n) to traverse the list

node * insertAtFront(node * head, int data) {
  node * t = getNewNode(data);
  t - > ptr = head;
  return t;
}

void dfs(int start) {
  cout << start << endl; // printing visited nodes
  visited[start] = 1;
  for (node * temp = graph[start]; temp != 0; temp = temp - > ptr) // traversing the list (same as while loop)  
  {
    if (!visited[temp - > data]) {
      dfs(temp - > data);
    }
  }
  /*
	
	// above code can be done as while loop as below. for loop is prefered as we sometimes forget 
	// this line ->  temp = temp->ptr; in while loop
	
	node* temp=graph[start];
	while(temp)
	{
		if(!visited[temp->data])
		{
			dfs(temp->data);
		}
		temp = temp->ptr;
	}
	
  */
}

int main() {
  int n, e; // 'n' nodes and 'e' edges in the graph
  cin >> n >> e;
  gN = n; //putting n value to gN so that no need to pass 'n' value
  for (int i = 0; i < e; i++) {
    int x, y;
    cin >> x >> y;
    // creating undirected graph
    // connect 'y' node to 'x' and as well as connect 'x' node to 'y' 
    graph[x] = insertAtFront(graph[x], y);
    graph[y] = insertAtFront(graph[y], x);
    /*
        // if graph is directed, use the below code.
	// only the first line i.e., connect 'y' node to 'x'
	graph[x]=insertAtFront(graph[x],y);
        
    */
  }

  // if the graph is connected, we can start the dfs from any node.
  // if the graph is not connected, we need to run the loop as follows:
  /*
	for(int i=0;i<n;i++)
	{
		if(!visited[i]) dfs(i);
	}
  */
  dfs(0); // here starting the dfs from 0th node
  return 0;
}
