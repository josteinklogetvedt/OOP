#include "Observasjoner.h"

vector<Obs> readFromFile(string filename){
    ifstream ist{filename};
    if (!ist){
        error("Could not open file", filename);
    }
    vector<Obs> vec;
    while (true){
        string line;
        getline(ist, line);
        stringstream t{line};
        Obs obs;

        string numX;
        getline(t,numX, ' ');
        obs.x = stoi(numX);
        if (obs.x == -1){
            break;
        }
        string numY;
        getline(t,numY);
        obs.y = stoi(numY);
        vec.push_back(obs);
    }
    return vec;
}

bool operator<(Obs lhs, Obs rhs){
    if (lhs.x == rhs.x){
        return lhs.y < rhs.y;
    }
    return lhs.x < rhs.x;
}

void report(vector<Obs> vec, int threshold){
    map<Obs,int> obsFreq;
    for (unsigned int i=0; i<vec.size(); ++i){
        ++obsFreq[vec[i]];
    }
    for (auto p : obsFreq){
        if (p.second > threshold){
            cout << p.first.x << " " << p.first.y << " " << p.second << endl;
        }
    }
}
