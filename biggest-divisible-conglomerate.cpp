//Author: Ahmet Volkan Turan

#include "bdc.h"

using namespace std;

string vec_to_string(vector<int> v){
    string output = "[";

    for(unsigned int i = 0; i<v.size()-1; i++){
        output += to_string(v.at(i)) + ", ";
    }
    output += to_string(v.back()) + "]";
    return output;
}

vector<int> biggest_divisible_conglomerate(vector<int> input){
    if(input.size()==0){
        return input;
    }

    //Sorts the input to make the divisibility requirement check easier
    sort(input.begin(), input.end());

    vector<int> remaining(input.begin() + 1, input.end());
    vector<int> bdcUseIt, bdcLoseIt = biggest_divisible_conglomerate(remaining);
    bool divisible = true;
    for(unsigned int i=0; i<bdcUseIt.size(); i++){
        if(input.at(0) % bdcUseIt.at(0) != 0){
            divisible = false;
            break;
        }
    }
    if(divisible){
        bdcUseIt.insert(bdcUseIt.begin(), input.at(0));
    }

    if(bdcUseIt.size()>bdcLoseIt.size()){
        return bdcUseIt;
    }

    return bdcLoseIt;
}