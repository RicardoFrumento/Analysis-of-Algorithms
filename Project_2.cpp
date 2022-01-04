#include <stdio.h>
#include <map>
#include <vector>
#include <iterator>
#include <iostream>
#include <fstream>
using namespace std;

/*
    IterMAS function
    Input: Vector target sequence, vector first sequence, vector second sequence
    Output: 
*/
vector<double> IterMAS(vector<double>& target, vector<double>& first, vector<double>& second)
{
    double score1; //Variables to compare the result of the next possible element
    double score2;
    double max; //Max result after comparing score1 and score 2
    int r = first.size(); //Number of rows
    int c = second.size(); //Number of columns
    int counter1 = 1; //Counter to run through sequence 1
    int counter2 = 1; //Coumter to run thourgh sequence 2

    vector < vector < double > > lookUpTable(first.size() + 1, vector< double >(second.size() + 1, 0)); //Creating a 2-D vector to store the results

    vector<double> sequence(target.size() + 1, 0); //Creating a n+m+1 vector to store the sequence and the alignment score

    for (int i = 0; i <= first.size(); i++) //Runs through all the rows of the 2-D vector
    {
        for (int j = 0; j <= second.size(); j++) //Rund through all the columns of the 2-D vector
        {
            if (i == 0 && j == 0) //Base case 1: if both sequences are empty
            {
                max = 0; //Returns 0
            }
            else if (i == 0 && j > 0) //If first sequence is empty but not the second
            {
                max = lookUpTable[i][j-1] + target[i+j-1] * second[j-1]; //Next element must be in the second sequence
            }
            else if (i > 0 && j == 0) //If first sequence is not empty but the second is
            {
                max = lookUpTable[i-1][j] + target[i+j-1] * first[i-1]; //Next element must be in the first sequence
            }
            else //All other cases
            {
                score1 = lookUpTable[i-1][j] + target[i+j-1] * first[i-1]; //Checks if the next element is in the first sequence
                score2 = lookUpTable[i][j-1] + target[i+j-1] * second[j-1]; //Checks if the next element is in the second sequence
                if (score1 > score2) //If the first is bigger
                {
                    max  = score1; //Max is the first score
                }
                else
                {
                    max = score2; //Else, max is the second score
                } 
            }
            lookUpTable[i][j] = max; //Store max to the 2-D vector
        }
    }
    
    sequence.at(sequence.size()-1) = lookUpTable[first.size()][second.size()]; //Add the alignment score to the returned vector

    for (int i = 0; i <= first.size(); i++) //Runs through all the rows of the 2-D vector
    {
        for (int j = 0; j <= second.size(); j++) //Runs through all the columns of the 2-D vector
        {
            if (i == 0 && j == 0) //Repeated base cases from the last for loops
            {
                max = 0;
            }
            else if (i == 0 && j > 0)
            {
                max = lookUpTable[i][j-1] + target[i+j-1] * second[j-1];
            }
            else if (i > 0 && j == 0)
            {
                max = lookUpTable[i-1][j] + target[i+j-1] * first[i-1];
            }
            else
            {
                score1 = lookUpTable[i-1][j] + target[i+j-1] * first[i-1];
                score2 = lookUpTable[i][j-1] + target[i+j-1] * second[j-1];
                if (score1 > score2)
                {
                    max  = score1;
                    lookUpTable[i][j-1] = 0; //Only change is here, make the other option zero
                }
                else
                {
                    max = score2;
                    lookUpTable[i-1][j] = 0; //Make the other option zero
                } 
            }
            lookUpTable[i][j] = max;
        }
    }
    
    for (int k = 0; k < sequence.size() - 1; k++) //Runs through the returned vector
    {    
        if (abs(lookUpTable[r-1][c]) > abs(lookUpTable[r][c-1]) || counter2 == second.size()+1) //Checks if the next position is above or to the right or if the second sequence is done
        {
            sequence.at(k) = first[first.size() - counter1]; //If it is, the current element in the returned vector is from the first sequence
            if (r == 1 || r == 0) //Checks if the current element is in the first or second rows
            {
                r = r; //Sets the next locations to look
                c = c - 1;
            }
            else
            {
                r = r - 1;
                c = c;
            }
            counter1 = counter1 + 1; //Increments the position of sequence 1
        }
        else
        {
            sequence.at(k) = second[second.size() - counter2]; //Repeats analysis for the second sequence
            if (c == 1 || c == 0)
            {
                r = r - 1;
                c = c;
            }
            else
            {
                r = r;
                c = c - 1;
            }
            counter2 = counter2 + 1;
        }
    }
    
    return sequence; //Returns the sequence vector with the last element as the alignment score
}

int main()
{
    vector<double> alignmentScore; //Variable to store the alignment score
    vector<double> target; //Vector to store the target sequence
    target.reserve(100); //Reserving memory for the vector (While retrieving the data from file it would seg fault, this fixed it)
    vector<double> seq1; //Vector to store the first sequence
    seq1.reserve(100);
    vector<double> seq2; //Vector to store the second sequence
    seq2.reserve(100);

    string line; //String to store the input data
    int n; //Integer to store the size of the first sequence
    int m; //Integer to store the size of the second sequence

    ifstream input("input.txt"); //Input file stream
    vector<string> data; //Vector to store the data read
    string element; //String to store the element being read

    while (input >> element) //While there is data to be read in the file, add to the vector data
    {
        data.push_back(element);
    }
    
    input.close(); //Closes the file stream

    n = stoi(data.at(0)); //Asigns first element read to n
    m = stoi(data.at(1)); //Assigns second element read to m

    for (int i = 2; i < n + 2; i++) //Reads the first sequence elements from data
    {
        seq1.push_back(stod(data.at(i)));
    }
    for (int j = n + 2; j < m + n + 2; j++) //Reads the second sequence elements from data
    {
        seq2.push_back(stod(data.at(j)));
    }
    for (int k = m + n + 2; k < m + n + m + n + 2; k++) //Reads the target sequence elements from data
    {
        target.push_back(stod(data.at(k)));
    }

    alignmentScore = IterMAS(target, seq1, seq2); //Calls the iterative function

    ofstream output("output.txt"); //Opens the output file stream

    output << alignmentScore.at(alignmentScore.size() - 1) << endl; //Writes to the file the last element of the returned vector

    for (int l = alignmentScore.size() - 2; l >= 0; l--) //Writes to the file the sequence that results in the maximum alignment score
    {
        output << alignmentScore.at(l) << " ";
    }

    output.close(); //Closes the file stream
}