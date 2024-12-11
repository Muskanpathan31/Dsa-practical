/*prims*/
#include <iostream>
#include <string.h>
using namespace std;
class graph
{
  int G[20][20], n;
  public: 
void accept()
{
    int i,j,e;
    int src,dest,cost;
    cout<<"\nEnter the no of vertices:";
    cin>>n;
      for(i=0;i<n;i++)
        { 
          for (j=0;j<n;j++)
            {
              G[i][j]=0;
            }
        }
    cout<<"\nEnter no of edges:";
    cin>>e;
      for(i=0;i<e;i++)
      {
        cout<<"\nEnter source:";
        cin>>src;
        cout<<"\nDestination:";
        cin>>dest;
        cout<<"\nCost:";
        cin>>cost;
        G[src][dest]=cost;
        G[dest][src]=cost;
     }
}
void display()
{
    int i,j;
    for (i=0;i<n;i++)
      {
      cout<<"\n";
        for(j=0;j<n;j++)
          {
            cout <<"\t"<<G[i][j];
          }
      }
}
void prims()
{
  int i,j,R[20][20];
  int src,dest,costcount,min;
  int total=0;
  int visited[20];
    for(i=0;i<n;i++)
      {
        for(j=0;j<n;j++)
          {
            if(G[i][j]==0)
              {
                R[i][j]=999;
              }
            else
              {
               R[i][j]=G[i][j];
              }
          }
      }
    for(i=0;i<n;i++)
      {
        visited[i]=0;
      }
    cout<<"\nEnter start vertex:";
    cin>>src;
    visited[src]=1;
    int count=0;
   while (count<n-1)
    {
      min=999;
        for(i=0;i<n;i++)
          {
            if (visited[j]!=1)
            {
              if (min>R[i][j])
              {
                min=R[i][j];
                src=i;
                dest=j;
              }
            }
          }
    cout << "\nEdge from "<<src<<"to"<<dest<<"\twith cost:"<<min;
    total=total+min;
    visited[dest]=1;
    count++;
    }
    cout<<"\nTotal cost:"<<total<<"\n";
    }
};

int main()
  {
    graph g;
    g.accept();
    g.display();
    g.prims();
  }

 

