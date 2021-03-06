//5: DIJKSTRAS ALGORITHM
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#define MAX 10

using namespace std;

int n,a[MAX][MAX],d[MAX],p[MAX];

void dijkstra(int source,int dest)
{
	int i,j,u,v,min;
	int s[MAX];//reachability Information
	for (i=0;i<n;i++)
	{
		d[i]=a[source][i];
		/*
		Stores the distances between all nodes from source.
		This is updated later as new and shorter paths are
		found.
		*/
		s[i]=0;
		/*
		Marking all nodes as unvisited
		*/
		p[i]=source;
		/*
		Records the path from source to dest.
		Initially no path exists from source to dest.
		Hence path takes from source to source itself.
		Later on, according to greedy technique, as partial solutions
		are created path[] contains path from source to various
		intermediate nodes
		*/
	}
	s[source]=1;//Add source to S
	cout << "\nStarting with source...\nSource : " <<source <<endl;
	for (i=1;i<n;i++)
	{
		//find u&d[u] such that d[u] is minimum and u is in V-S
		cout << "Finding nearest accessible node...\n";
		min=9999;
		u=-1;
		for (j=0;j<n;j++)
		{
			if( s[j]==0)
			{
				if (d[j]<min)
				{
					min=d[j];
					u=j;
				}
			}
		}

		if (u==-1)
		{
			cout << "No near nodes...\n";
			return;
		}

		//Add u to s
		s[u]=1;
		cout << "Nearest node : " << u << "\n";
		if (u==dest)
		{
			cout << u << " is the destination.\n";
			cout << "Destination has been reached whose path has already been calculated.\n";
			cout << "Returning...\n";
			return;
		}

		cout << "With " << u << " as the intermediate node :\n";
		//find d[v] and p[v] for every v in V-S
		for (v=0; v<n;v++)
		/*
			Finding shorter paths from source to v using u as
			intermediate node
		*/
		{
			cout << "v = " << v << endl;
			cout << "d["<<v<<"] = " <<d[v] <<endl;
			cout << "d["<<u<<"] + a["<<u<<"]["<<v<<"] = "<<d[u]+a[u][v] << endl;

			if (s[v]==0) //if v is unvisited
			{
				if (d[u]+a[u][v]<d[v])
				/*
				If the path through intermediate node
				is shorter
				*/
				{
					/*
					Then, update the distance matrix d[]
					and create a new path
					*/
					cout << "Newer path is shorter...\n";
					d[v]=d[u]+a[u][v];
					p[v]=u;
				}
			}
		}
	}
}
int main()
{
	int source,dest,i,j;
	/*
	cout<<"Enter Number of nodes"<<endl;
	cin>>n;
	cout<<"Enter Cost Adjacency Matrix"<<endl;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		cin>>a[i][j];
	}
	cout<<"Enter source Node ";
	cin>>source;
	cout<<"Enter dest";
	cin >>dest;
	cout<<endl; */

	///*
	n = 4;
	srand(time(NULL));
	cout << "Creating the adjacency matrix :\n";
	for(i = 1; i <= n; ++i)
	{
		for(j = 1; j <= n; ++j)
		a[i][j] = rand() % 100;
	}
	cout << "Done.\n";
	cout << "Randomly inserting infinity edges...\nWaiting : ";
	for(int count=5; count > 0; count--)
	{
		i = rand()%n;
		system("sleep 1");
		j = rand()%n;
		a[i][j] = 9999;
		cout << count <<" ";
	}
	cout << "Done\n";
	cout << "Matrix :\n";
	for(i = 1; i <= n; ++i)
	{
		for(j = 1; j <= n; ++j)
		{
			cout << a[i][j] <<"\t";
		}
		cout << endl;
	}
	//*/
	for (source=0;source<n;source++)
	/*
	Trying all possible sources-destination combinations
	*/
	{
		cout<<"\n OUTPUT\n ";
		for ( dest=0;dest<n;dest++)
		{
			dijkstra(source,dest);
			if (d[dest]==9999)
			cout<<dest<<" is not reachable from "<<source<<endl;
			else
			{
				//cout<<"The shortest path is shown below"<<endl;
				int i=dest;
				if (i==source)
				cout<<i<<"<--"<<i<<"="<<d[dest]<<endl;
				else
				{
					while(i!=source)
					{
						cout<<i<<"<--";
						i=p[i];
					}
					cout<<i<<"="<<d[dest]<<endl;
				}
			}
		}  //dest loop ends
		cout<<"\n***************************\n";
	}// source loop ends
    return 0;
}
