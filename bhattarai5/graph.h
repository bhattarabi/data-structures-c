//File:      graph.h
//Name:      Binaya Bhattarai
//Class:     CSIS 352
//Program:   assignment 5
//Date:      3/30/2016

//This file contains declaration and implementation of Graph class.

#ifndef _GRAPH_
#define _GRAPH_

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

namespace GraphNameSpace
{
	const int MAXSIZE = 100;
	
	//graph categories
	enum graphType {WEIGHTED, UNWEIGHTED, DIRECTED, UNDIRECTED};
	
	//get string representation of given graphType variable
	string getEnumName(graphType gt)
	{
		switch (gt)
		{
			case UNDIRECTED:
				return "UNDIRECTED";
				
			case DIRECTED:
				return "DIRECTED";
				
			case WEIGHTED:
				return "WEIGHTED";
				
			case UNWEIGHTED:
				return "UNWEIGHTED";
				
			default:
				return " ";
		}
	}
	
	//return true if two parameters are in conflict with each other
	bool conflicting(graphType g1, graphType g2)
	{
		if ((g1 == WEIGHTED && g2 == UNWEIGHTED) ||
			(g1 == UNWEIGHTED && g2 == WEIGHTED) ||
			(g1 == DIRECTED && g2 == UNDIRECTED) ||
			(g1 == UNDIRECTED && g2 == DIRECTED))
			return true;
		
		return false;
	}
	
	//struct that models a row in the adjacency matrix 
	//the vector of ints represents weights of the edges 
	//going out from this vertex
	template <class T>
	struct gphVertex
	{
		T vertex;
		vector<int> connections;
	};
	
	//class that models a graph containing upto 100 vertices
	template <class T>
	class Graph
	{
	public:
		//parameterless constructor creates undirected and unweighted graph
		Graph();
		
		//constructor that takes any one argument of enum graphType
		Graph(graphType);
		
		//constructor that takes any two arguments of enum graphType
		//precondition: the two enum parameters do not contradict each other
		//				for example: a graph cannot be both WEIGHTED and UNWEIGHTED 
		Graph(graphType, graphType);
		
		//delete all vertices and edges
		//postconditions: vector adjMatrix is emptied
		void destroy();
		
		//return true if there are no vertices in graph
		bool isEmpty() const;
		
		//return true if number of vertices is 100
		bool isFull() const;
		
		//return true if there is an edge going from fromVertex to toVertex,
		//or in the opposite direction, in case of undirected graphs
		bool isAdjacentTo(const T&, const T&) const;
		
		//return weight of the edge between the two parameter vertices
		int edgeWeight(const T&, const T&) const;
		
		//number of edges and vertices
		int edgeCount() const;
		int vertexCount() const;
		
		//insert a new vertex to graph
		//throws exception if graph is full or if graph already contains the vertex
		//postconditions: a gphVertex instance is created using the given vertex 
		//				which is added to adjMatrix
		void insertVertex(const T&);
		
		//insert a new edge to graph
		//throws exception if edge already exists, or if the graph does not contain 
		//either one or both of the vertices
		//precondition: graph contains both vertices
		//postconditions: int value found at index of toVertex in the vector 
		//				connections of fromVertex is assigned the new weight
		void insertEdge(const T&, const T&, int wght=1);
		
		//delete an edge from the graph
		//throws exception if the graph doesn't contain both vertices
		//	or if the edge doesn't exist
		//precondition: graph contains the edge
		//postconditions: int value found at index of toVertex in the vector 
		//				connections of fromVertex is assigned -1
		void deleteEdge(const T&, const T&);
		
		//delete a vertex from graph
		//throws exception if graph doesn't contain the vertex
		//precondition: the graph contains the vertex
		//postconditions: the vertex is deleted from adjMatrix 
		//				all edges that are incident to the vertex are deleted
		void deleteVertex(const T&);
		
		//index of the vertex
		//return -1 if graph doesn't contain the vertex
		int findVertex(const T&) const;
		
		//display all vertices and edges 
		void dump() const;
	private:
		vector<gphVertex<T> > adjMatrix;	//adjacency matrix
		int vcount;							//count of vertices
		graphType direct;					//is the graph directed
		graphType weight;					//is the graph weighted
		
		//initialize an empty unweighted and undirected graph
		void init();
	};
	
	template <class T>
	void Graph<T>::init()
	{
		vcount = 0;
		adjMatrix.resize(MAXSIZE);
		direct = UNDIRECTED;
		weight = UNWEIGHTED;
	}
	
	template <class T>
	Graph<T>::Graph()
	{
		init();
	}
	
	template <class T>
	Graph<T>::Graph(graphType category)
	{
		init();
		switch(category)
		{
			case WEIGHTED:
				weight = WEIGHTED;
				break;
			case DIRECTED:
				direct = DIRECTED;
				break;
			default:
				break;
		}
	}
		
	template <class T>
	Graph<T>::Graph(graphType category1, graphType category2)
	{
		if (conflicting(category1, category2))
			throw logic_error(
						"GraphException: graph categories are contradictory");
			
		init();
		switch(category1)
		{
			case WEIGHTED:
			case UNWEIGHTED:
				weight = category1;
				direct = category2;
				break;
			default:
				weight = category2;
				direct = category1;
				break;
		}
	}
	
	template <class T>
	void Graph<T>::destroy()
	{
		adjMatrix.clear();
		vcount = 0;
	}
	
	template <class T>
	bool Graph<T>::isEmpty() const
	{
		if (vcount == 0)
			return true;
		
		return false;
	}
	
	template <class T>
	bool Graph<T>::isFull() const
	{
		if (vcount == 100)
			return true;
		
		return false;
	}
	
	template <class T>
	bool Graph<T>::isAdjacentTo(const T& fromVertex, const T& toVertex) const
	{
		int fromIndex = findVertex(fromVertex);
		int toIndex = findVertex(toVertex);
		
		if (adjMatrix[fromIndex].connections[toIndex] != 0)
			return true;
		
		return false;
	}
	
	template <class T>
	int Graph<T>::edgeWeight(const T& fromVertex, const T& toVertex) const
	{
		if (!isAdjacentTo(fromVertex, toVertex))
			throw logic_error("GraphException: edge doesn't exist");
		
		int fromIndex = findVertex(fromVertex);
		int toIndex = findVertex(toVertex);
		
		return adjMatrix[fromIndex].connections[toIndex];
	}
	
	template <class T>
	int Graph<T>::vertexCount() const
	{		
		return vcount;
	}	
	
	template <class T>
	int Graph<T>::edgeCount() const
	{
		int count =0;
		
		for (int i=0; i<vcount; i++)
			for (int j=0; j<vcount; j++)
				if (adjMatrix[i].connections[j] != 0)
					count++;
		
		if (direct == UNDIRECTED)
			count /= 2;
		
		return count;
	}	
	
	template <class T>
	void Graph<T>::insertVertex(const T& vert)
	{
		if (isFull())
			throw logic_error(
				"GraphException: cannot add vertex to full graph");
		else if (findVertex(vert) != -1)
			throw logic_error(
				"GraphException: graph already contains the vertex");
		else
		{
			gphVertex<T> tmp;
			tmp.vertex = vert;
			tmp.connections.resize(MAXSIZE);
			for (int i=0; i<MAXSIZE; i++)
				tmp.connections[i] = 0;
			adjMatrix[vcount++] = tmp;
		}
	}
	
	template <class T>
	void Graph<T>::insertEdge(const T& fromVertex, 
							  const T& toVertex, int wght)
	{
		if (weight == UNWEIGHTED && wght != 1)
			throw logic_error(
				"GraphException: cannot insert weighted edge in unweighted graph");
		
		int fromIndex = findVertex(fromVertex);
		int toIndex = findVertex(toVertex);
		
		if (fromIndex == -1 || toIndex == -1)
			throw logic_error(
				"GraphException: graph doesn't contain both vertices");
		
		if (adjMatrix[fromIndex].connections[toIndex] != 0)
			throw logic_error("GraphException: edge already exists");
		
		adjMatrix[fromIndex].connections[toIndex] = wght;
		
		if (direct == UNDIRECTED)
			adjMatrix[toIndex].connections[fromIndex] = wght;
	}
	
	template <class T>
	void Graph<T>::deleteEdge(const T& fromVertex, const T& toVertex)
	{
		if (!isAdjacentTo(fromVertex, toVertex))
			throw logic_error("GraphException: edge doesn't exist");
		
		int fromIndex = findVertex(fromVertex);
		int toIndex = findVertex(toVertex);
		
		adjMatrix[fromIndex].connections[toIndex] = 0;
		
		if (direct == UNDIRECTED)
			adjMatrix[toIndex].connections[fromIndex] = 0;
	}
	
	template <class T>
	void Graph<T>::deleteVertex(const T& vert)
	{
		int index = findVertex(vert);
		if (index == -1)
			throw logic_error(
				"GraphException: graph doesn't contain the vertex");
		
		for (int i=0; i<vcount; i++)
			adjMatrix[i].connections[index] = 0;
		
		adjMatrix.erase(adjMatrix.begin()+index);
		vcount--;
	}
	
	template <class T>
	void Graph<T>::dump() const
	{
		cout << "Dumping graph:\t" << getEnumName(direct) << "  " << 
			getEnumName(weight) << '\t' << "vertices:" << vertexCount() << 
			"\tedges:" << edgeCount() << endl;
			
		cout << "VERTEX" << "\t\t" << "ADJACENT VERTICES" << endl;
		cout << "--------------" << '\t' << "-------------------------------------------" << endl;
		
		for (int i=0; i<vcount; i++)
		{
			cout << "[" << i << "]" << adjMatrix[i].vertex << '\t';
			
			for (int j=0; j<vcount; j++)
			{
				int tmpWt = adjMatrix[i].connections[j];
				if (tmpWt != 0)
					cout << "[" << j << "]" << adjMatrix[j].vertex << "(" << tmpWt << ")"<< "  "; 
			}
			cout << endl;		
		}
	}
	
	template <class T>
	int Graph<T>::findVertex(const T& vert) const
	{		
		for (int i=0; i<vcount; i++)
		{
			if (adjMatrix[i].vertex == vert)
				return i;
		}
		
		return -1;
	}
}
#endif
