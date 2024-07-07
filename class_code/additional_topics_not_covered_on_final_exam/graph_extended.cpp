#include<iostream>
#include<list>
#include<vector>
#include<cstdlib>    
#include<ctime>
#include<queue>
#include<limits>

#include"priority_queue.H"
#include "DisjSets.h"   

using namespace std;

struct Vertex
{
    int name_;
    int in_degree_;
    int out_degree_;
    int topological_number_;

    Vertex(){}
    Vertex(int name, int in_degree, int out_degree, int topological_number):
           name_(name), in_degree_(in_degree), out_degree_(out_degree),
           topological_number_(topological_number){}

    friend bool operator<(Vertex first, Vertex second) 
    {
        return first.in_degree_ < second.in_degree_;
    }

     friend bool operator>(Vertex first, Vertex second) 
    {
        return first.in_degree_ > second.in_degree_;
    }

    friend std::ostream &operator<<(std::ostream &out, Vertex v) 
    {
        cout<<"("<<v.name_<<", "<<v.in_degree_<<", "<<v.out_degree_
            <<", "<<v.topological_number_<<")";
        return out;
    }
};

struct Edge
{
    int source_vertex_;
    int target_vertex_;
    int weight_;

    Edge(){}
    Edge(int source, int target, int weight): source_vertex_(source), 
                                              target_vertex_(target), 
                                              weight_(weight) {}

    friend bool operator<(Edge first, Edge second) 
    {
        return first.weight_ < second.weight_;
    }

     friend bool operator>(Edge first, Edge second) 
    {
        return first.weight_ > second.weight_;
    }

    friend std::ostream &operator<<(std::ostream &out, Edge e) 
    {
        cout<<"("<<e.source_vertex_<<", "<<e.target_vertex_<<", "<<e.weight_<<")";
        return out;
    }
};

class Graph
{
private:
    int num_vertices_;
    int num_edges_;
    vector<list<Edge>> adj_list_;
    vector<bool> visited_;
    bool bi_directed_; 

public:
    Graph(int v, bool b=false): num_vertices_(v), bi_directed_(b), 
                                visited_(vector<bool>(v,false)), 
                                adj_list_(vector<list<Edge>>(v)),num_edges_(0){}

    int GetNumVertices()
    {
        return num_vertices_;
    }

    int GetNumEdges()
    {
        return num_edges_;
    }

    void AddEdge(int vertex, int destination, int weight)
    {
        if( vertex >= num_vertices_ || destination >= num_vertices_)
        {
            cout<<"invalid vertex"<<endl;
            return;
        }

        adj_list_[vertex].push_back(Edge(vertex, destination, weight));

        if(bi_directed_)
            adj_list_[destination].push_back(Edge(destination, vertex, weight));
        
        num_edges_++;
    }

    friend std::ostream &operator<<(std::ostream &out, Graph g) 
    {     
        for(int i = 0; i < g.num_vertices_; i++)
        {
            cout<<"list edges at vertex "<<i<<": ";
            for(auto& e: g.adj_list_[i])
                cout<<e<<" ";
        }

        return out;
    }

    void BFS(int start_vertex)
    {
        if( start_vertex >= num_vertices_)
        {
            cout<<"invalid vertex"<<endl;
            return;
        }

        ResetVisited();
        queue<int> q;

        // mark starting_vertex as visited
        cout<<start_vertex;
        visited_[start_vertex] = true;
        q.push(start_vertex);

        while(!q.empty())
        {
            int next_vertex = q.front();
            q.pop();

            for (auto& i : adj_list_[next_vertex])
            {
                if(!visited_[i.target_vertex_])
                {
                    cout <<" -> "<< i.target_vertex_;
                    visited_[i.target_vertex_] = true;
                    q.push(i.target_vertex_);
                }
            }

            if (q.empty())
            {
                int count = 0;
                for (auto i : visited_)
                {
                    if (!i)
                    {
                        cout<< " -> " << count;
                        i = true;
                        q.push(count);
                        break;
                    }
                    count++;
                }
            }
            
        }
    }

    void ResetVisited()
    {
        for (int i =0; i<num_vertices_; i++)
            visited_[i] = false;
    }

    void DFS(int vertex)
    {
        if( vertex >= num_vertices_)
        {
            cout<<"invalid vertex"<<endl;
            return;
        }

        if(visited_[vertex])
            return;
        
        else 
        {
            visited_[vertex] = true;
            cout<<vertex<<" -> ";
        }

        for (auto& neighbor : adj_list_[vertex])
            DFS(neighbor.target_vertex_);
        
    }

    void DisconnectedDFS(int start_vertex)
    {
        DFS(start_vertex);
        for(int i = 0; i < visited_.size(); i++)
            if(!visited_[i])
                DFS(i);
    }

    void ReadGraphIntoHeapArray(Edge arr[])
    {
        int i = 0;
        for (auto v : adj_list_)
            for(auto e : v)
            {
                arr[i]=e;
                i++;
            }
    }

    list<Edge> kruskal(Edge arr[])
    {
        ReadGraphIntoHeapArray(arr);
        PriorityQueue<Edge> h(arr,num_edges_,false);
        int uset , vset;
        DisjSets s(num_vertices_); 
        list <Edge> edge_list; // list of edges in the minimum spanning tree
        int edges_accepted = 0;
        while (edges_accepted < num_vertices_-1)
        {
            Edge e = h.DeleteRoot(); // assume e = (u , v )
            uset = s.Find(e.source_vertex_);
            vset = s.Find(e.target_vertex_);
            if ( uset != vset )
            {
            // add the edge to the list of edges in the tree and increment count
                edge_list.push_back(e);
                edges_accepted ++;
                s.Union(uset,vset);
            }
        }

        return edge_list;        
    }

    void SetInAndOutDegrees(const list<Edge> arr_edges, Vertex arr_vertices[])
    {
        for(int i = 0; i < num_vertices_; i++)
            arr_vertices[i]=Vertex(i,0,0,0);

        for(auto e:arr_edges)
        {
            arr_vertices[e.source_vertex_].out_degree_++;
            arr_vertices[e.target_vertex_].in_degree_++;
        }
    }

    bool TopologicalSort(const list<Edge> arr_edges,Vertex arr_vertices[])
    {
        SetInAndOutDegrees(arr_edges,arr_vertices);
        // Find all nodes with in-degree 0
        queue<Vertex> q;
        for(int i = 0; i < num_vertices_; i++)
            if(arr_vertices[i].in_degree_ == 0)
                q.push(arr_vertices[i]);

        // Start processing with a count of 1
        int counter = 1;
        while (!q.empty())
        {
            Vertex v = q.front();
            q.pop(); // v has in-degree 0
            arr_vertices[v.name_].topological_number_ = counter++;
 
            for(auto e:arr_edges)
                if(e.source_vertex_ == v.name_)
                {
                    arr_vertices[e.target_vertex_].in_degree_--;
                    if (arr_vertices[e.target_vertex_].in_degree_==0)
                        q.push(arr_vertices[e.target_vertex_]);
                }                           
        }

        if(counter != num_vertices_+1)
        {
            cout<<"cycle found "<<counter<<endl;
            return false;
        }

        else return true;
    }

    vector<int> Dijkstras(int start_vertex)
    {
        vector<int> distances(num_vertices_,numeric_limits<int>::max());
        for(auto i :adj_list_[start_vertex])
            distances[i.target_vertex_] = i.weight_;
        distances[start_vertex]=0;

        // Initialize the set T to contain only the vertex s
        vector<int> T = {start_vertex};

        ResetVisited();
        visited_[start_vertex]=true;

        // Iterate until every vertex from V has been added to T
        while (T.size() != num_vertices_)
        {
            int min_dist=numeric_limits<int>::max();
            int v = 0;
            for(int i = 0; i< num_vertices_; i++)
                if(!visited_[i] and min_dist >= distances[i])
                {
                    min_dist=distances[i];
                    v=i;
                }
            T.push_back(v);
            visited_[v]=true;

            for(auto u : adj_list_[v])
                distances[u.target_vertex_] = min(distances[u.target_vertex_], 
                                                  distances[v] + u.weight_);
        }
        ResetVisited();
        return distances;
    }

    vector<vector<int>> FloydWarshall()
    {
        vector<vector<int>>adj_mat = GetAdjacencyMatrix();
    
        int max_num = numeric_limits<int>::max();
        for(int k = 0; k<num_vertices_; k++)
            for(int i = 0; i<num_vertices_; i++)
                for(int j = 0; j<num_vertices_; j++)
                    if(adj_mat[i][k] != max_num and
                       adj_mat[k][j] != max_num and
                       adj_mat[i][j] > adj_mat[i][k] + adj_mat[k][j])
                        adj_mat[i][j]=adj_mat[i][k] + adj_mat[k][j];

        return adj_mat;
    }

    vector<vector<int>> GetAdjacencyMatrix()
    {
        vector<vector<int>> adj_mat(num_vertices_,vector<int>(num_vertices_,
                                                  numeric_limits<int>::max()));

        for(auto v : adj_list_)
            for(auto e : v)    
                adj_mat[e.source_vertex_][e.target_vertex_]=e.weight_;
            
        for(int i = 0; i < num_vertices_; i++)
            adj_mat[i][i]=0;

        return adj_mat;
    }
};

Graph FirstClassExample()
{
    Graph g(7,true);
    g.AddEdge(0,1,2);
    g.AddEdge(0,3,1);
    g.AddEdge(0,2,4); 
    g.AddEdge(1,3,3);
    g.AddEdge(1,4,10);
    g.AddEdge(2,3,2);
    g.AddEdge(2,5,5);
    g.AddEdge(3,4,7);
    g.AddEdge(3,6,4);
    g.AddEdge(3,5,8);
    g.AddEdge(4,6,6);
    g.AddEdge(5,6,1);
    return g;
}

Graph SecondClassExample()
{
    Graph g(6);
    g.AddEdge(0,1,5);
    g.AddEdge(0,2,1);
    g.AddEdge(0,5,8);
    g.AddEdge(1,0,2);
    g.AddEdge(1,2,2);
    g.AddEdge(1,4,4);
    g.AddEdge(2,3,2);
    g.AddEdge(3,4,4);
    g.AddEdge(3,5,2);
    g.AddEdge(4,1,1);
    g.AddEdge(5,4,1);
    return g;
}

int main()
{
    Graph g = SecondClassExample();
    vector<vector<int>> floyds=g.FloydWarshall();
    for(auto i : floyds)
        {
            for(auto j : i)
                cout<<j<<" ";
            cout<<endl;
        }
    return 0;
}