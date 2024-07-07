#include <list>
#include<iostream>
#include<vector>
#include <cstdlib>    
#include <ctime>   

using namespace std;

class graph
{
    private:
        int vertices;
        vector<list<int>> adj_list;
        vector<vector<int>> adj_matrix;
        vector<bool> visited;
        bool bi_directed; 

    public:
        graph(int v, bool b): vertices(v), bi_directed(b), 
                              visited(vector<bool>(v,false)), 
                              adj_list(vector<list<int>>(v,list<int>())),
                              adj_matrix(vector<vector<int>>(v,vector<int>(v,0)))  
        {
            for(int i = 0; i < v; i++)    
                adj_matrix[i][i] = 1;
        }

        int GetNumVertices()
        {
            return vertices;
        }

        void AddEdge(int vertex, int destination)
        {
            if( vertex >= vertices || destination >= vertices)
            {
                cout<<"invalid vertex"<<endl;
                return;
            }
            adj_list[vertex].push_back(destination);
            adj_matrix[vertex][destination] = 1;

            if(bi_directed)
            {
                adj_list[destination].push_back(vertex);
                adj_matrix[destination][vertex] = 1;
            }
        }

        void PrintEdgesAtVertex(int vertex)
        {
            cout<<"list edges at vertex "<<vertex<<endl;
            for(auto& b: adj_list[vertex])
                cout<<b<<endl;
        }

        void BFS(int start_vertex)
        {
            if( start_vertex >= vertices)
            {
                cout<<"invalid vertex"<<endl;
                return;
            }

            ResetVisited();
            list<int> queue;

            // mark starting_vertex as visited
            cout<<start_vertex;
            visited[start_vertex] = true;
            queue.push_back(start_vertex);

            while(!queue.empty())
            {
                start_vertex = queue.front();
                queue.pop_front();

                for (auto& i : adj_list[start_vertex])
                {
                    if(!visited[i])
                    {
                        cout <<" -> "<< i;
                        visited[i] = true;
                        queue.push_back(i);
                    }
                }
                if (queue.empty())
                {
                    int count = 0;
                    for (auto i : visited)
                    {
                        if (!i)
                        {
                            cout<< " -> " << count;
                            i = true;
                            queue.push_back(count);
                            break;
                        }
                        count++;
                    }
                }
                
            }
        }

        void ResetVisited()
        {
            for (auto f  : visited)
                f = false;
        }

        void DFS(int vertex)
        {
            if( vertex >= vertices)
            {
                cout<<"invalid vertex"<<endl;
                return;
            }

            if(visited[vertex])
                return;
            
            else 
            {
                visited[vertex] = true;
                cout<<vertex<<" -> ";
            }

            for (auto& neighbor : adj_list[vertex])
                DFS(neighbor);
            
        }

        void DisconnectedDFS(int vertex)
        {
            DFS(vertex);
            for(int i = 0; i < visited.size(); i++)
                if(!visited[i])
                    DFS(i);
        }
};

int main()
{
    graph test(7, true);
    test.AddEdge(0,1);
    test.AddEdge(0,2);
    test.AddEdge(1,3);
    test.AddEdge(1,4);
    test.AddEdge(2,5);
    test.AddEdge(2,6);

    for (int i = 0; i < test.GetNumVertices(); i++)
    {
        cout<<"Breadth First Search: ";
        test.BFS(i);
        cout<<endl;
    }
    
    /*for(int i = 0; i < test.GetNumVertices(); i++)
    {
        test.ResetVisited();
        cout<<"Depth First Search: ";
        test.DFS(i);
        cout<<endl;
    }
    srand (time(NULL));
    iSecret = rand() % 10 + 1;
    for(int i = 0; i < test.GetNumVertices(); i++)
    {
        test.ResetVisited();
        cout<<"Disconnected Depth First Search: ";
        test.DisconnectedDFS(i);
        cout<<endl;
    }*/

    return 0;
}