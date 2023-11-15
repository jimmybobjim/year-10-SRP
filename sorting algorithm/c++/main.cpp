#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <sstream>

using namespace std;
using namespace std::chrono;



vector<int> bubbleSort(vector<int> elems) {
    bool swapped;

    for (int i = 0; elems.size(); i++) {
        swapped = false;

        for (int j = 0; j<elems.size()-1; j++) {
            if (elems.at(j) > elems.at(j+1)) {
                swapped = true;

                int temp = elems.at(j);
                elems.at(j) = elems.at(j+1);
                elems.at(j+1) = temp;
            }

            //cout<<"i: "<<i<<" j: "<<j<<endl;
        }

        if (!swapped) break;
    }

    return elems;
}



int main(int argc, char *argv[]) {
    bool print = false;
    string file;
    if (argc == 1) {
        file = "reversed.csv";
    } else {
        file = argv[1];
    }

    ifstream data("../.numbers/" + file);

    vector<int> vect;
    
    string line;
    for (int i = 0; getline(data, line); i++) vect.push_back(stoi(line));                   //generate vector<int>

    
    auto startTime = high_resolution_clock::now();                                          //time function
    vector<int> vectResult = bubbleSort(vect);
    auto endTime = high_resolution_clock::now();

    int64_t executionTime = duration_cast<nanoseconds>(endTime - startTime).count();        //calculate execution time
    
    if (print) {
        stringstream ssResult;
        copy(vectResult.begin(), vectResult.end(), ostream_iterator<int>(ssResult, ", "));  //turn vector<int> into stringstream
        string result = ssResult.str().c_str();                                             //turn stringstream into string

        cout << result << endl << endl;
    }

    cout << "execution time (ns): " << executionTime;

    return 0;
}