#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <iostream>

using namespace std;
 // function to find the minimum vetex with minimum key value
 int min_weight_vertex (int key[], bool MSTset [],int V){

     int min = INT_MAX, min_index;

     for (int v = 0; v < V; v++)
        if (MSTset[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
  return min_index;


 }
void PrintGraph (int MSTarry[],int Graph[6][6]){
cout << "EDGE : Weight" << "\n";
  for (int i=1;i <6;i++){
        cout<<MSTarry[i]<<" : " << i << "    " <<Graph[i][MSTarry[i]]<<endl;


  }



}

 void primsAlogorithm (int Graph[6][6], int V,int start_index){
// crete the MST graph using array
  int MSTarray[V];
// store the edge weight using array
  int key[V];

// check whethere the vertex add or not
  bool MSTset[V];


  // intialize the wight and as a not add vertex

  for (int i=0;i < V;i++){
    key[i]=INT_MAX;

    MSTset[i]=false;
}

key[0]=start_index;
MSTarray[0]=-1;



for (int x = 0; x < V - 1; x++) {


        int u = min_weight_vertex(key, MSTset,V);


        MSTset[u] = true;


        for (int i = 0; i < V; i++)


            if (Graph[u][i] && MSTset[i] == false && Graph[u][i] < key[i])
                {        MSTarray[i] = u,

                       key[i] = Graph[u][i];}

    }

PrintGraph ( MSTarray, Graph);

}










int main()
{
    int graph[6][6] = { { 0, 3, 0, 0, 0,1 },
                        { 3, 0, 2, 1, 10,0 },
                        { 0, 2, 0, 3, 0,5 },
                        { 0, 1, 3, 0, 5,0 },
                        { 0, 10, 0, 5, 0,4 },
                        {1,0,5,0,4,0} };

    // Print the solution
    primsAlogorithm (graph,6,3);

    return 0;
}
