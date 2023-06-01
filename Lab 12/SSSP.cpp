#include <iostream>
#include <climits>
#include <vector>

#define INFINITY 9999
#define max 6

using namespace std;
// get the average time using this
void AverageTime (int sum){
  float average=sum/5;
    cout<<"AverageTime :"<< average<<endl;
}




void dijkstra(int G[max][max], int n, int startNode) {
    int Sum=0;
    int cost[max][max], Time[max], previous[max];
    bool visited[max];
    int count, mindistance, nextNode, i, j;

    // intialize the cost matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];
        }
    }

    // Initializing pred[], distance[] and visited[]
    for (i = 0; i < n; i++) {
        Time[i] = cost[startNode][i];
       previous[i] = startNode;
        visited[i] = false;
    }

   Time[startNode] = 0;
    visited[startNode] = true;
    count = 1;

    while (count < n - 1) {
        mindistance = INFINITY;

        // Next node gives the node at minimum distance
        for (i = 0; i < n; i++) {
            if (Time[i] < mindistance && !visited[i]) {
                mindistance = Time[i];
                nextNode = i;
            }
        }

        // Checking if a better path
        visited[nextNode] = true;

        for (i = 0; i < n; i++) {

            if (!visited[i]) {
                if (mindistance + cost[nextNode][i] < Time[i]) {
                   Time[i] = mindistance + cost[nextNode][i];
                    previous[i] = nextNode;
                }
            }
        }
        count++;


    }

    // Printing the shortest distance and path
    for (i = 0; i < n; i++) {
        if (i != startNode) {
               Sum+=Time[i];
            cout << "Shortest times from city " << startNode << " to City " << i << ":" << endl;
            cout << "City " << startNode << " to City " << i << ": " << Time[i] << endl;

            cout << "Path: " << i;
            j = i;
            do {
                j = previous[j];
                cout << " <- " << j;
            } while (j != startNode);

            cout << endl << endl;
        }
    }

AverageTime ( Sum);
}


int main() {
    int G[max][max] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };



    dijkstra(G, 6, 4);

    return 0;
}

