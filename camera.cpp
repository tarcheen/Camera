/*
Developer: Hamed Mirlohi
Date: 09/29/2019

In this program, a security camera has added the ability to detect vehicles driving down the street using multiple cameras. The computer vision team can send you lists of vehicles that they have detected and they want to find out which vehicles have been detected by each camera.
*/

#include <iostream>
#include <map>
#include <vector>

using std::map;
using std::vector;

vector<int> captured_all_cams(const vector<vector<int>> all_cameras)
{
    vector<int> result;
    // map that records all cars captured by all cameras and increment if other cameras catch it
    map<int,unsigned int> camera_Hash;
    
    // going through all cameras
    for(int i = 0; i < all_cameras.size(); i++)
    {
        for(int j = 0; j < all_cameras[i].size(); ++j)
        {
            // if element does not exist in the hash table, insert it in the table
            if(camera_Hash.find(all_cameras[i][j]) == camera_Hash.end())
                camera_Hash.insert(std::pair<int,unsigned int>(all_cameras[i][j],1));
            // else increment the element found in the table
            else
                camera_Hash[all_cameras[i][j]]++;
        }
    }
    
    // go through the table and find all elements that caught by all cameras
    for(auto& i : camera_Hash)
    {
        if(i.second == all_cameras.size())
            result.push_back(i.first);
    }
    
    return result;
}


int main()
{
    // list of cars captured by first camera
    vector<int> c1 = {1,3,4,8,9,16,32,40};
    // list of cars captured by second camera
    vector<int> c2 = {0,1,6,7,8,12,40,62,72};
    
    // list of all cars captured by all cameras sent to you
    vector<vector<int>> all_cameras = {c1, c2};
    
    // grab the list of all cars captured by all cameras
    auto result = captured_all_cams(all_cameras);
    
    // printout all the cars captured by the cameras
    std::cout << " { ";
    for(auto& i : result)
        std::cout << i << " ";
    std::cout << "}" << std::endl;
    
}