#include "utilities.h"

//Opg. 1
void writeToFile(){
    string filename;
    cout << "Please enter name of output file: ";
    cin >> filename;
    ofstream ost {filename};
    cout << "Write to file. 'quit'=quit writing" << endl;
    string input;
    while (input != "quit"){
        cin >> input;
        if (input=="quit"){
            break;
        }
        ost << input << endl;
    }
}

void addLineNumberToFile(){
    try{
        string filename;
        cout << "Please enter name of input file: ";
        cin >> filename;
        ifstream ist{filename};
        if (!ist) error("can't open input file ", filename);
    
        string newfilename = "Numbered" + filename;
        ofstream ost{newfilename};
        string line;
        int count = 0;
        while (getline(ist,line)){
            ++count;
            line = to_string(count) + "\t" + line;
            ost << line << endl;
        }
    }
    catch (runtime_error& e){
        cerr << "runtime error:" << e.what() << endl;
    }
}

//Opg. 2
void characterCount(string filename){
    ifstream ist{filename};
    if (!ist) error("can't open input file ", filename);
    
    vector<int> vec(26);
    char ch;
    char a = 'a';
    while (ist.get(ch)){
        if ((ch > -1) && (ch < 256)){        
            if (isalpha(ch)){           
                char c = tolower(ch);
                int index = c-a;
                ++vec[index];
            }
        }
    }
    int count = 0;
    for (int i=0; i<vec.size(); ++i){
        count+=1; 
        if (count == 3){
            cout << static_cast<char>(a+i) << ": " << vec[i] << "\n";
            count = 0;
        }else{
            cout << static_cast<char>(a+i) << ": " << vec[i] << "\t";
        }
    }
    cout << endl;
}

//Opg. 3
ostream& operator<<(ostream& out, const CourseCatalog& coursecatalog){
    for (auto const x: coursecatalog.catalog){
        out << x.first << " " << x.second << endl;
    }
    return out;
}

void CourseCatalog::addCourse(string courseCode, string courseName){
    //catalog.insert({courseCode, courseName});
    catalog[courseCode] = courseName;
}

void CourseCatalog::removeCourse(string courseCode){
    catalog.erase(courseCode);
}

string CourseCatalog::getCourse(string courseCode){
    return catalog[courseCode];
}

CourseCatalog addSpesifiedCourses(){
    CourseCatalog cat;
    cat.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
    cat.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
    cat.addCourse("TMA4100", "Matematikk 1");
    return cat;
}

void CourseCatalog::saveToFile(string filename){
    ofstream ost {filename};
    for (auto const x: catalog){
        ost << x.first << " " << x.second << endl;
    }
}

void CourseCatalog::readFromFile(string filename){
    ifstream ist {filename};
    string line;
    while (getline(ist,line)){
        string key = line.substr(0,7);
        string value = line.substr(8);
        catalog[key] = value;
    }
}

//Opg. 4
istream& operator>>(istream& is, Temps& t){
    is >> t.max >> t.min;
    return is;                    
}
ostream& operator<<(ostream& os, Temps& t){
    cout << t.max << " " << t.min << endl;
    return os;
}
vector<Temps> readTempsFromFile(string filename){
    ifstream temp_file{filename};
    vector<Temps> vec_temp;
    Temps t;
    while (temp_file>>t){
        vec_temp.push_back(t);
    }
    return vec_temp;
}

