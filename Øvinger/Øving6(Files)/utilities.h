#include "std_lib_facilities.h"


//Opg. 1
void writeToFile();
void addLineNumberToFile();

//Opg. 2
void characterCount(string filename);

//Opg. 3
class CourseCatalog{
    private:
        map<string,string> catalog;
    public:
        CourseCatalog()
        {}
        friend ostream& operator<<(ostream& out, const CourseCatalog&);
        void addCourse(string courseCode, string courseName);
        void removeCourse(string courseCode);
        string getCourse(string courseCode);
        void saveToFile(string filename);
        void readFromFile(string filename);
};

CourseCatalog addSpesifiedCourses();

//Opg. 4
class Temps{
    private:
        float max;
        float min;
    public:
        Temps()
            :max{0.0},min{0.0}{}
        friend ostream& operator<<(ostream& os, Temps& t);
        friend istream& operator>>(istream& is, Temps& t);
        double getMax() const {return max;}
        double getMin() const {return min;} 
};
vector<Temps> readTempsFromFile(string filename); 
