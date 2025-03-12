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
    for(unsigned int i = 0; i<input.size()-1; i++){
        int minIndex = i;
        for(unsigned int j = i+1; j<input.size(); j++){
            if(input.at(j)<input.at(minIndex)){
                minIndex = j;
            }
        }
        int temp = input.at(i);
        input.at(i) = input.at(minIndex);
        input.at(minIndex) = temp;
    }
}


//Helper function to find the biggest list, takes in reference values so that it can update the biggest list and the current list
//i is used as an index to go through every element in the input, the recursion only terminates when it reaches the end of the input
void biggest_divisible_conglomerate_finder(vector<int>& input, vector<int>& biggest, vector<int>& curr, int i){

    //Updates the biggest list if the current is bigger than the previous biggest
    if(curr.size()>biggest.size()){
        biggest = curr;
    }

    //When all the elements in the input are checked, it terminates the function
    if(i < 0){
        return;
    }
    
    //If current is empty, or if the element we are checking to use divides the next element in the conglomerate
    //We have two options, either add it or not add it
    if(curr.empty() || curr.at(0)%input.at(i) == 0){
        //First we use the element and call the recursive function with the added version
        curr.insert(curr.begin(), input.at(i));
        biggest_divisible_conglomerate_finder(input, biggest, curr, i-1);
        //Then we remove it so we can call the lose it version because it might end up giving a bigger conglomerate
        curr.erase(curr.begin());
    }

    //Calls the recursive function for the lose it case
    biggest_divisible_conglomerate_finder(input, biggest, curr, i-1);
}

vector<int> biggest_divisible_conglomerate(vector<int> input){
    if(input.size()<=1){
        return input;
    }

    //Sorts the input to make the divisibility requirement check easier
    //Because the added element would only be needed to compare the next element in the conglomerate
    //If the current element is divisible with the next element it is automatically divisible by the rest of them in a sorted list
    selection_sort(input);

    vector<int> curr, biggest;
    biggest_divisible_conglomerate_finder(input, biggest, curr, input.size()-1);
    return biggest;
}