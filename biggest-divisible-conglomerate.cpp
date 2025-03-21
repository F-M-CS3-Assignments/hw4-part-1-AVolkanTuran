//Author: Ahmet Volkan Turan

#include "bdc.h"
#include <iostream>

using namespace std;

string vec_to_string(vector<int> v){
    if(v.size()==0){
        return "[]";
    }
    
    string output = "[";

    for(unsigned int i = 0; i<v.size()-1; i++){
        output += to_string(v.at(i)) + ", ";
    }
    output += to_string(v.back()) + "]";

    return output;
}

//Simple selection sort to make it easier to check the divisibility requirement and give the answer in an nice sorted manner
void selection_sort(vector<int>& input){
    if(input.size()==0){
        return;
    }
    for(int i = 0; i<input.size()-1; i++){
        int minIndex = i;
        for(int j = i+1; j<input.size(); j++){
            if(input.at(j)<input.at(minIndex)){
                minIndex = j;
            }
        }
        int temp = input.at(i);
        input.at(i) = input.at(minIndex);
        input.at(minIndex) = temp;
    }
}


//Helper function to find the biggest list
vector<int> biggest_divisible_conglomerate_finder(vector<int> input){
    //Base case where the input size is less than or equal to 1
    if(input.size()<=1){
        return input;
    }

    //If there are any zeros, removes them because they can't divide any number
    if(input.at(0)==0){
        vector<int> noZeroInput(input.begin()+1, input.end());
        return biggest_divisible_conglomerate_finder(noZeroInput);
    }

    //Creates a candidates vector to keep track of the possible conglomerates
    vector<vector<int>> candidates;

    for(unsigned int i = 0; i<input.size(); i++){
        vector<int> left = {input.at(i)};

        //Finds the position of the next number divisible the current element we are checking at i
        int j = i+1;
        while(j<input.size() && input.at(j)%input.at(i)!=0){
            j++;
        }

        //If such an item exists, create a subproblem starting from that item, otherwise right is just an empty vector
        vector<int> right;
        if(j<input.size()){
            vector<int> rightSubVector(input.begin()+j, input.end());
            right = biggest_divisible_conglomerate_finder(rightSubVector);
        }

        //The candidate is the current item at i combined with all the items it can divide in the subproblem
        vector<int> cand(left);
        for(int k = 0; k<right.size(); k++){
            if(right.at(k)%cand.at(0)==0){
                cand.push_back(right.at(k));
            }
        }

        //Adds the candidate to the possible candidates list
        candidates.push_back(cand);
    }

    //Finds the index for the bdc
    unsigned int maxSizeIndex = 0;
    for(unsigned int i = 1; i<candidates.size(); i++){
        if(candidates.at(i).size() > candidates.at(maxSizeIndex).size()){
            maxSizeIndex = i;
        }
    }
    
    //If there are no candidates, returns a vector consisting of the largest value in the input, otherwise returns the bdc
    if(candidates.empty()){
        return {input.back()};
    }
    return candidates.at(maxSizeIndex);
}

vector<int> biggest_divisible_conglomerate(vector<int> input){
    //Sorts the input because it makes finding the bdc much easier
    selection_sort(input);
    //Finds the bdc
    return biggest_divisible_conglomerate_finder(input);
}