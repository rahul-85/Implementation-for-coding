// author: Rahul Raj
/*

	Implementation of graph using Adjacency Matrix
	And Depth First Search(DFS) using recursion
	(This is just for reference. In different questions, there will be some slight modification)

*/


// adjacency matrix implementation
#include<iostream>
using namespace std;
#define MAX 100  // put the maximum possible value of node (check from constraint of question)

int gN;  // global value of N (so that no need to pass in function argument)
int graph[MAX][MAX]; // here adjacency matrix is used. maximum value can be 1000 only.
// if the maximum value of node in graph is greater than 1000, use adjacency list implementation.
// adjacency matrix will not work
bool visited[MAX]; // visited array for dfs, all initialized to 0 as it is global variable


void dfs(int start)
{
	cout<< start<< endl; // printing visited nodes
    visited[start]=1;
    for(int i=0;i<gN;i++) // traversing the adjacency matrix   
    {
    	// if 'i' vertex is connected to 'start' vertex and if not visited earlier
        if(!visited[i] && graph[start][i]==1)
        {
            dfs(i);
        }
    }
}

int main()
{
    int n,e; // 'n' nodes and 'e' edges in the graph
    cin>>n>>e;
    gN = n; //putting n value to gN so that no need to pass 'n' value
    for(int i=0;i<e;i++) // traverse through number of edges.
    {
        int x,y;
        cin>>x>>y;
        // creating undirected graph
        // connect 'y' vertex to 'x' and as well as connect 'x' vertex to 'y' 
        graph[x][y]=1; 
        graph[y][x]=1;
        /*
        // if graph is directed, use the below code.
		 // only the first line i.e., connect 'y' node to 'x'
		 graph[x][y]=1;
        
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


