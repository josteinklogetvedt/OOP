#include "windmill.h"

int checkAlarm(const double value, const double threshold){
    if (value > threshold && value <= MAX_WIND){return 1;}
    if (value < 0.0 || value > MAX_WIND){return -1;}
    return 0;
}
 
void printAlarm(const int id, const double wind, const int dir){
    cout << "ALARM " << id << ": " << setprecision(2) << wind << " fra ";
    string direction;
    if (dir >= 315 || dir <=44){direction = "Nord";}
    else if (dir >=225){direction = "Vest";}
    else if (dir >=135){direction = "Syd";}
    else{direction = "Ost";}
    cout << direction << endl;
}

ostream& operator<<(ostream& os, const Sample& s){
    os << s.id << " " << s.wind << " " << s.dir;
    return os;
}

void readMeasurements(const char* filename){
    string file{filename};
    ifstream ist{file};
    if(!ist){
        throw invalid_argument("Could not open file " + file);
    }
    string line;
    for (int j=0; j<N_SAMPLES; ++j){
        for (int i=0; i<N_MILLS; ++i){
            getline(ist,line);
            stringstream ss{line};
            Sample s;
            ss >> s.id >> s.wind >> s.dir;
            measurements[i][j] = s;
        }
    }
}

vector<Sample> calcStats(){
    vector<Sample> average;
    for (int i=0; i<N_MILLS; ++i){
        Sample ave{i+1,0.0,0};
        for (int j=0; j<N_SAMPLES; ++j){
            ave.wind += measurements[i][j].wind;
            ave.dir += measurements[i][j].dir;  
        }
        ave.wind = ave.wind/N_SAMPLES;
        ave.dir = ave.dir/N_SAMPLES;  //Heltallsdivisjon
        average.push_back(ave);
    }
}

bool operator<(const Sample &lhs, const Sample &rhs){  //Antar man sorterer etter vindstyrke.
    if (lhs.wind == rhs.wind){
        return lhs.id < rhs.id;
    }
    return lhs.wind < rhs.wind;
}

void checkMeasurements(){
    int missingTot = 0;
    for (int i=0; i<N_MILLS; ++i){
        int missingSample = 0;
        for (int j=0; j<N_SAMPLES; ++j){
            if (measurements[i][j].wind==-1){
                missingSample += 1;
                if (missingSample >= 2){
                    throw i+1;
                }
            }
        }
        missingTot += missingSample;
    }
}

void repairMeasurements(){
    for (int i=0; i<N_MILLS; ++i){
        int j = 0;
        while (j < N_SAMPLES){
            if (measurements[i][j].wind == -1){
                if (j == 0){measurements[i][j].wind = measurements[i][j+1].wind;}
                else if(j==N_SAMPLES-1){measurements[i][j].wind = measurements[i][j-1].wind;}
                else{measurements[i][j].wind = 0.5*(measurements[i][j-1].wind + measurements[i][j+1].wind);}
                break;
            }
            j += 1;
        }
    }
}