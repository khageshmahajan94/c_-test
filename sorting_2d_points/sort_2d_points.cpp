#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <utility>
#include <cmath>

/*
Sort 2d points 
Write a program which will sort the list of 2d points based on distance from the origin 
There should be a command-line interface which will accept file path as input 
There should be a command-line interface which will accept a path to write the output file 
You have to decide the schema of the text file in which 2d points are stored 
You have to write a list in a file and stored it at provided output path 
Output file should contain a list of point with distance form origin 
Consider all possible test cases 
*/

float distance(float x, float y)
{
    float d = sqrt(pow(x - 0, 2) + pow(y - 0, 2));
    return d;
};


int main(int argc, char* argv[])
{
    
    std::ifstream in;
    //in.open("input_points.txt");
    in.open(argv[1]);
    std::vector<std::pair<float, float>> v;


    while(in.eof() == 0)
    {
        float x, y;
        in>>x>>y;
        v.push_back({x,y});   
    }
    
    float dist;
    std::vector<float> v1;
    for(int i =0; i<v.size(); i++)
    {  
        dist = distance(v[i].first, v[i].second);
        v1.push_back(dist);
    }
    
    for(int i =0; i<v1.size() - 1 ; i++)
    {
        for(int j = i + 1; j<v1.size(); j++)
        {
            if(v1[j] < v1[i])
            {
                std::swap(v1[i], v1[j]);
                std::swap(v[i],v[j]);
            }
        }
    }
    // for(int i=0; i<v1.size(); i++)
    // {
    //     std::cout<<v[i].first<<"    "<<v[i].second<<"     "<<v1[i]<<std::endl;
        
    // }

    std::ofstream out;
    //out.open("output_points.txt");
    out.open(argv[2]);
    // out<<"Sorted Points : "<<std::endl;
    // out<<"Points"<<"            Distance"<<std::endl;

    for(int i =0; i<v1.size(); i++)
    {
        out<<"{ "<<v[i].first<<", "<<v[i].second<<" }   "<<v1[i]<<std::endl;
    }

    in.close();
    out.close();

}