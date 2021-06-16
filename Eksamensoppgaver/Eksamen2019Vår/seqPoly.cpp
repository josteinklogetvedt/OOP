// Assignment 3 - Open Assignment
#include "seqPoly.h"

vector<string> getSequence(string s){
    stringstream ss{s};
    string t;
    vector<string> coordinates;
    while (getline(ss, t,',')){
        string num;
        for (unsigned int i=0; i<t.size(); ++i){
            if (isdigit(t[i])){
                num += t[i];
            }
        }
        coordinates.push_back(num);
    }
    return coordinates;
}

vector<string> fileToSequence(string filename){
    ifstream ist{filename};
    if(!ist){
        throw invalid_argument("could not open file " + filename);
    }
    string s;
    getline(ist, s);
    vector<string> coordinates= getSequence(s);
    return coordinates;
}


vector<Point> seqToPoints(vector<string> coordinates){
    if (coordinates.size() % 2 != 0){
        throw invalid_argument("Odd number of coordinates.");
    }else if(coordinates.size() < 4){
        throw invalid_argument("Need two sets of coordinates.");
    }
    vector<Point> points;
    int x;
    int y;
    for (int i=0; i<coordinates.size();++i){
        if (i%2 == 0){
            x = stoi(coordinates[i]);
        }else{
            y = stoi(coordinates[i]);
            points.push_back(Point{x,y});
            x=y=0;
        }
    }
    return points;
}

  
void drawPoints(vector<Point> points, Simple_window& win){
    Open_polyline opl;
    for (unsigned int i=0; i<points.size(); ++i){
        opl.add(points[i]);
    }
    opl.draw_lines();
    win.attach(opl);
    win.wait_for_button();
}

void menu(){
    cout << "Draw points. Do you have a sequencue from file or the board? (1=file,2=board)" << endl;
    int answer;
    vector<string> coordinates;
    string s;
    cin >> answer;
    getline(cin,s);   //to erase \n from the buffer
    switch (answer){
        case 1:
            cout << "Write your filename:";
            cin >> s;
            coordinates = fileToSequence(s);
            break;
        case 2:
            cout << "Write a sequence of coordinates x1,y1,x2,y2,..." << endl;
            getline(cin,s);
            coordinates = getSequence(s);
            break;
        default:
            cout << "Ok then." << endl;
            return;
    }

    try{
        vector<Point> points = seqToPoints(coordinates);
        Simple_window win{Point{100,100}, 600,500,"Points"};
        drawPoints(points, win);
    }
    catch(invalid_argument e){
        cout << e.what() << endl;
    }
}