#include <stdio.h>
#include <vector>
#include <utility>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;


/**************************************************************
 * Input: Map of the maze, number of rows, number of columns  *
 * Output: A graph with vertices as cells implemented as      *
 *         an adjacency list                                 *
 * Graph takes a map and by checking what is stored in each   *
 * cell of the maze, creating vertices for every cell, and    *
 * adding the possible connections creates an adjacency list  *
 * ************************************************************/
vector<vector<int> > graph(vector<string> map, int r, int c)
{
    vector<vector<int> > graph; //Create a 2-d vector to store implement an adjacency matrix
    int goal; //Create a variable to store the goal cell
    vector<int> final; //Create a vector to store the goal cell

    for (int i = 0; i < map.size(); i++) //Runs trough the map
    {
        graph.push_back(vector<int>()); //Adds an empty vector to the end of the graph
        if (map.at(i).compare("X") == 0) //Checks if the cell is an unreachable cell
        {
            continue; //If it is go to next cell
        }
        else if (map.at(i).compare("S") == 0) //Checks if the cell's direction is south
        {
            if (i + (3 * c) > r * c - 1 || (i + (3 * c)) / c > 3 + i / c) //Checks if the movement is valid (goes out of bonds)
            {
                continue; //If it goes, go to next cell
            }

            graph.at(i).push_back(i + (3 * c)); //Stores the destination cell to current vertex adjacency list

            if (i + (4 * c) > r * c - 1 || (i + (4 * c)) / c > 4 + i / c) //Checks if the movement is valid (goes out of bonds)
            {
                continue; //If it goes, go to next cell
            }

            graph.at(i).push_back(i + (4 * c)); //Stores the destination cell to current vertex adjacency list
        }
        else if (map.at(i).compare("N") == 0) //Checks if the cell's direction is north
        {
            if (i - (3 * c) < 0 || (i - (3 * c)) / c < -3 + i / c) //Checks if the movement is valid (goes out of bonds)
            {
                continue; //If it goes, go to next cell
            }

            graph.at(i).push_back(i - (3 * c)); //Stores the destination cell to current vertex adjacency list

            if (i - (4 * c) < 0 || (i - (4 * c)) / c < -4 + i / c) //Checks if the movement is valid (goes out of bonds)
            {
                continue; //If it goes, go to next cell
            }

            graph.at(i).push_back(i - (4 * c)); //Stores the destination cell to current vertex adjacency list
        }
        else if (map.at(i).compare("W") == 0) //Checks if the cell's direction is west
        {
            if (i - 3 < 0 || (i - 3) / c < i / c) //Checks if the movement is valid (goes out of bonds)
            {
                continue; //If it goes, go to next cell
            }

            graph.at(i).push_back(i - 3); //Stores the destination cell to current vertex adjacency list

            if (i - 4 < 0 || (i - 4) / c < i / c) //Checks if the movement is valid (goes out of bonds)
            {
                continue; //If it goes, go to next cell
            }

            graph.at(i).push_back(i - 4); //Stores the destination cell to current vertex adjacency list
        }
        else if (map.at(i).compare("E") == 0) //Checks if the cell's direction is east
        {
            if (i + 3 > c * r - 1 || (i + 3) / c > i / c) //Checks if the movement is valid (goes out of bonds)
            {
                continue; //If it goes, go to next cell
            }

            graph.at(i).push_back(i + 3); //Stores the destination cell to current vertex adjacency list

             if (i + 4 > r * c - 1 || (i + 4) / c > i / c) //Checks if the movement is valid (goes out of bonds)
            {
                continue; //If it goes, go to next cell
            }

            graph.at(i).push_back(i + 4); //Stores the destination cell to current vertex adjacency list
        }
        else if (map.at(i).compare("SE") == 0) //Checks if the cell's direction is south-east
        {
            if (i + (3 * c) + 3 > r * c - 1 || (i + (3 * c) + 3) / c > 3 + i / c) //Checks if the movement is valid (goes out of bonds)
            {
                continue; //If it goes, go to next cell
            }

            graph.at(i).push_back(i + (3 * c) + 3); //Stores the destination cell to current vertex adjacency list

            if (i + (4 * c) + 4 > r * c - 1 || (i + (4 * c) + 4) / c > 4 + i / c) //Checks if the movement is valid (goes out of bonds)
            {
                continue; //If it goes, go to next cell
            }

            graph.at(i).push_back(i + (4 * c) + 4); //Stores the destination cell to current vertex adjacency list
        }
        else if (map.at(i).compare("SW") == 0) //Checks if the cell's direction is south-west
        {
            if (i + (3 * c) - 3 > c * r - 1 || (i + (3 * c) - 3) / c < 3 + i / c) //Checks if the movement is valid (goes out of bonds)
            {
                continue; //If it goes, go to next cell
            }

            graph.at(i).push_back(i + (3 * c) - 3); //Stores the destination cell to current vertex adjacency list

            if (i + (4 * c) - 4 > r * c - 1 || (i + (4 * c) - 4) / c < 4 + i / c) //Checks if the movement is valid (goes out of bonds)
            {
                continue; //If it goes, go to next cell
            }

            graph.at(i).push_back(i + (4 * c) - 4); //Stores the destination cell to current vertex adjacency list
        }
        else if (map.at(i).compare("NE") == 0) //Checks if the cell's direction is north-east
        {
            if (i - (3 * c) + 3 < 0 || (i - (3 * c) + 3) / c > -3 + i / c) //Checks if the movement is valid (goes out of bonds)
            {
                continue; //If it goes, go to next cell
            }

            graph.at(i).push_back(i - (3 * c) + 3); //Stores the destination cell to current vertex adjacency list

            if (i - (4 * c) + 4 < 0 || (i - (4 * c) + 4) / c > -4 + i / c) //Checks if the movement is valid (goes out of bonds)
            {
                continue; //If it goes, go to next cell
            }

            graph.at(i).push_back(i - (4 * c) + 4); //Stores the destination cell to current vertex adjacency list
        }
        else if (map.at(i).compare("NW") == 0) //Checks if the cell's direction is north-west
        {
            if (i - (3 * c) - 3 > c * r - 1 || (i - (3 * c) - 3) / c < -3 + i / c) //Checks if the movement is valid (goes out of bonds)
            {
                continue; //If it goes, go to next cell
            }

            graph.at(i).push_back(i - (3 * c) - 3); //Stores the destination cell to current vertex adjacency list

            if (i - (4 * c) - 4 > r * c - 1 || (i - (4 * c) - 4) / c < -4 + i / c) //Checks if the movement is valid (goes out of bonds)
            {
                continue; //If it goes, go to next cell
            }

            graph.at(i).push_back(i + (4 * c) - 4); //Stores the destination cell to current vertex adjacency list
        }
        else if (map.at(i).compare("J") == 0) //Checks if the current cell is the goal cell
        {
            goal = i; //Stores the goal cell
        }

    }
    final.push_back(goal); //Adds the goal to a vector
    graph.push_back(final); //Adds the vector to the graph
    return graph; //Returns the graph
}

/**************************************************************
 * Input: Adjacency list, starting cell, goal cell            *
 * Output: The path from starting cell to goal cell           *
 * bfs runs through the adjacency list by checking the        *
 * vertices in the neighborhood of the current vertex being   *
 * explored, adding them to a queue, and exploring vertex by  *
 * the queue order. The path is found by storing every parent *
 * and running bacwards starting at the goal cell             *
 * ************************************************************/
vector<int> bfs(vector<vector<int> > adjList, int start, int last)
{
    queue<int> fila; //Creates a queue to store cells to be explored
    vector<int> path; //Creates a vector to store path
    vector<bool> visited(adjList.size()+1); //Creates a vector to store if the cell was already visited
    vector<int> distances(adjList.size()); //Creates a vector to store the distances to the cell being checked
    vector<int> parentNode(adjList.size()); //Creates a vector to stores the parent node
    int vertex; //Creates a variable to hold the current vertex

    fila.push(start); //Adds the starting cell to the queue
    distances.at(start) = 0; //Adds the distance to the starting cell
    visited.at(start) = true; //Marks the starting cell as visited
    parentNode.at(start) = -1; //Stores the parent cell of the starting cell as non-existent

    while (!fila.empty()) //Runs the code as long as there are elements in the queue
    {
        vertex = fila.front(); //Stores the front of the queue to the variable
        fila.pop(); //Remove the first element from queue
        for (int i = 0; i < adjList.at(vertex).size(); i++) //Runs through all the neighborhoods
        {
            if (!visited.at(adjList.at(vertex).at(i))) //If the neihgbor is not visited
            {
                visited.at(adjList.at(vertex).at(i)) = true; //Check the neighbor as visited
                fila.push(adjList.at(vertex).at(i)); //Add the neighbor to the queue to be explored
                distances.at(adjList.at(vertex).at(i)) = distances.at(vertex) + 1; //Add the distance to the neighbor
                parentNode.at(adjList.at(vertex).at(i)) = vertex; //Store the parent node of the neighbor as the current vertex being explored
            }

        }

    }

    for (int j = last; j != -1; j = parentNode[j]) //Runs backwards through the parent nodes vector
    {
        path.push_back(j); //Adds the vertex to the path
    }
    return path; //Returns path
}

/**************************************************************
 * Input:                                                     *
 * Output:                                                    *
 * main reads a txt file to create a map of the maze, then    *
 * calls graoph to create a graph based on the maze, and uses *
 * the returned graph to find out a path by calling bfs. After*
 * that it writes the path found to another txt file          *
 * ************************************************************/
int main()
{
    int counter = 0; //Initializes a counter to keep track which data is being read from the file
    vector<string> map; //Creates a vector of strings to store the information of the file
    vector<vector<int> > adjList; //Creates a 2-d vector to implement the graph as an adjacency list
    vector<int> path; //Creates a vecotr of ints to store the cells on the path
    int r; //Creates an int variable to store the number of rows
    int c; //Creates an int variable to store the numnber of columns
    int rt; //Creates an int variable to store the starting cell row
    int ct; //Creates an int variable to store the starting cell column
    int start; //Creates an int variable to store the starting cell
    int last; //Creates an inte variable to store the goal cell
 
    ifstream input("large.txt"); //Starts an input file strem
    vector<string> data; //Creates a vector to store the data read from file
    string element; // Creates a string to store the data being read one by one from file

    while (input >> element) //Runs through the whole file
    {
        data.push_back(element); //Adds the data to the vector
    }

    input.close(); //Closes the input file stream

    r = stoi(data.at(counter++)); //Assigns the first elements of the vetos to the row variable
    c = stoi(data.at(counter++)); //To the column variable 
    rt = stoi(data.at(counter++)); //To the starting cell row
    ct = stoi(data.at(counter++)); //To the starting cell column

    start = (rt - 1) * c + (ct - 1); //Figures out the starting cell and assigns it to the starting cell variable

    for (int i = 0; i < r * c; i++) //Runs through the map vector size
    {
        map.push_back(data.at(counter++)); //Stores the data to the map vactor
    }

    adjList = graph(map, r, c); //Calls graph function and stores returned vector of vectors to the adjacency list

    last = adjList.back().at(0); //Assigns goal cell to the goal cell variable
    adjList.pop_back(); //Removes the goal cell information of the path

    path = bfs(adjList, start, last); //Calls bfs and stores returned vetor to the path

    ofstream output("output.txt"); //Opens a output file stream

    for (int i = path.size() - 1; i > 0; i--) //Runs through the path vector
    {
        if (path.at(i) - path.at(i - 1) == 3) //Checks if the current cell is 3 units bigger than the previous cell in path
        {
            output << "W-3 "; //Stores the movement on file
        }
        else if (path.at(i) - path.at(i - 1) == 4) //Checks if the current cell is 4 units bigger than the previous cell in path
        {
            output << "W-4 "; //Stores the movement on file
        }
        else if (path.at(i) - path.at(i - 1) == -3) //Checks if the current cell is 3 units smaller than the previous cell in path
        {
            output << "E-3 "; //Stores the movement on file
        }
        else if (path.at(i) - path.at(i - 1) == -4) //Checks if the current cell is 4 units smaller than the previous cell in path
        {
            output << "E-4 "; //Stores the movement on file
        }
        else if (path.at(i) - path.at(i - 1) == 3 * c) //Checks if the current cell is 3*columns units bigger than the previous cell in path
        {
            output << "N-3 "; //Stores the movement on file
        }
        else if (path.at(i) - path.at(i - 1) == 4 * c) //Checks if the current cell is 4*columns units bigger than the previous cell in path
        {
            output << "N-4 "; //Stores the movement on file
        }
        else if (path.at(i) - path.at(i - 1) == -(3 * c)) //Checks if the current cell is 3*columns units smaller than the previous cell in path
        {
            output << "S-3 "; //Stores the movement on file
        }
        else if (path.at(i) - path.at(i - 1) == -(4 * c)) //Checks if the current cell is 4*columns units smaller than the previous cell in path
        {
            output << "S-4 "; //Stores the movement on file
        }
        else if (path.at(i) - path.at(i - 1) == (3 * c) + 3) //Checks if the current cell is 3*columns+3 units bigger than the previous cell in path
        {
            output << "NW-3 "; //Stores the movement on file
        }
        else if (path.at(i) - path.at(i - 1) == (4 * c) + 4) //Checks if the current cell is 4*columns+4 units bigger than the previous cell in path
        {
            output << "NW-4 "; //Stores the movement on file
        }
        else if (path.at(i) - path.at(i - 1) == (3 * c) - 3) //Checks if the current cell is 3*columns-3 units bigger than the previous cell in path
        {
            output << "NE-3 "; //Stores the movement on file
        }
        else if (path.at(i) - path.at(i - 1) == (4 * c) - 4) //Checks if the current cell is 4*columns-4 units bigger than the previous cell in path
        {
            output << "NE-4 "; //Stores the movement on file
        }
        else if (path.at(i) - path.at(i - 1) == -(3 * c) + 3) //Checks if the current cell is 3*columns+3 units smaller than the previous cell in path
        {
            output << "SW-3 "; //Stores the movement on file
        }
        else if (path.at(i) - path.at(i - 1) == -(4 * c) + 4) //Checks if the current cell is 4*columns+3 units smaller than the previous cell in path
        {
            output << "SW-4 "; //Stores the movement on file
        }
        else if (path.at(i) - path.at(i - 1) == -(3 * c) - 3) //Checks if the current cell is 3*columns-3 units smaller than the previous cell in path
        {
            output << "SE-3 "; //Stores the movement on file
        }
        else if (path.at(i) - path.at(i - 1) == -(4 * c) - 4) //Checks if the current cell is 4*columns-4 units smaller than the previous cell in path
        {
            output << "SE-4 "; //Stores the movement on file
        }
        
    }

    output.close(); //Closes the output file stream


    return 0;
}
