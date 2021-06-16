#include "linearreg.h"

double sum(vector<double>& x){
    double sum = 0.0;
    for (unsigned int i=0; i<x.size(); ++i){ 
        sum += x[i];
    }
    return sum;
}

double mean(vector<double>& x){
    double mean = sum(x)/x.size();
    return mean;
}

void read_csv(string filename, vector<double>& x, vector<double>& y){
    ifstream ist{filename};
    if (!ist){
        throw string("Couldn't read file " + filename);
    }
    string s;
    double xVal,yVal;
    while (getline(ist,s)){
        stringstream ss(s);
        ss >> xVal >> yVal;
        x.push_back(xVal);
        y.push_back(yVal);
    }
}

pair<double, double> linreg(vector<double>& x, vector<double>& y){
    double yMean = mean(y);
    double xMean = mean(x);
    int n = static_cast<int>(x.size());
    double cov = 0.0;
    double var = 0.0;
    for (int i=0; i<n; ++i){
        var += (x[i]-xMean)*(x[i]-xMean);
        cov += (x[i]-xMean)*(y[i]-yMean);
    }
    var = var/n;
    cov = cov/n;
    double a = cov/var;
    double b = yMean - a*xMean;
    pair<double,double> p{a,b};
    return p;
}

vector<double> linpred(vector<double>& x, double a, double b){
    vector<double> y;
    for (unsigned int i=0; i<x.size(); ++i){
        y.push_back(a*x[i]+b);
    }
    return y;
}

double r2(vector<double>& y, vector<double>& y_pred){
    double nominator = 0.0;
    double denominator = 0.0;
    double yMean = mean(y);
    for (unsigned int i=0; i<y.size(); ++i){
        nominator += (y[i]-y_pred[i])*(y[i]-y_pred[i]);
        denominator += (y[i]-yMean)*(y[i]-yMean);
    }
    double r = 1.0 - nominator/denominator;
    return r;
}

void menu(){
    vector<double> x;
    vector<double> y;
    read_csv("data.csv",x,y);
    pair<double,double> coeff = linreg(x,y);
    vector<double> y_pred = linpred(x,coeff.first,coeff.second);
    double r = r2(y,y_pred);
    cout << "a=" << coeff.first << " b=" << coeff.second << " og R2=" << r << endl;
}
