#include "Series.h"

double radian(double degree){
    return PI*(degree/180.0);
}

double nFac(unsigned int n){
    double sum = 1.0;
    while (n > 1){
        sum *= n;
        n -= 1;
    }
    return sum;
}

double sineTaylorTerm(double x, int n){
    return ((pow(-1.0, n) * pow(x, 2 * n + 1)) / nFac(2 * n + 1));
}

double sineTaylor(double x, int n){
    double sum = 0.0;
    for (int i=0; i<n+1; ++i){
        sum += sineTaylorTerm(x,i);
    }
    return sum;
}

int testTaylor(double degree, double epsilon){
    double rad = radian(degree);
    double estim = 0.0;
    int terms = 0;
    estim += sineTaylorTerm(rad, terms);
    while (abs(estim - sin(rad)) > epsilon){
        terms++;
        estim += sineTaylorTerm(rad, terms);
    }
    return (terms+1);
}

void findHighestIter(double epsilon){
    double degree = 0.0;
    int maxTerms = 0;
    double maxDegree = -1.0;
    while (degree <= 180.0){     //degree er mellom 0 0g 180 grader
        int iter = testTaylor(degree, epsilon);
        if (iter >= maxTerms){
            maxTerms = iter;
            maxDegree = degree;
        }
        degree += 1;   // kan bruke mindre steg mellom hver grad, f.eks. 0.5
    }
    std::cout << maxDegree << " : " << maxTerms << " ledd" << std::endl;
}

double nFacRobust(unsigned int n){
    if (n > NFAK_LIMIT){
        throw invalid_argument("For stort tall: " + std::to_string(n));
    }else{
        return nFac(n); 
    }
}

void testnFacRobust(){
    try{
    std::cout << nFacRobust(0) << std::endl;
    }catch(exception& e){
        std::cout << e.what() << std::endl;
    }
    try{
    std::cout << nFacRobust(NFAK_LIMIT+1) << std::endl;
    }catch(exception& e){
        std::cout << e.what() << std::endl;
    }
    try{
    std::cout << nFacRobust(8) << std::endl;
    }catch(exception& e){
        std::cout << e.what() << std::endl;
    }
}