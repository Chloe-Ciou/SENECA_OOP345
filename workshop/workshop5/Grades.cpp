#include <exception>
#include <string>
#include <fstream>
#include "Grades.h"

using namespace std;

namespace sict {
    Grades::Grades(const char* fileName){
        ifstream f(fileName);
        if(!f.is_open())
            throw "file open failed.";
        string temp;
        while (!f.eof()) {
            getline(f, temp);
            if(!temp.empty()) ++m_count;
        }
        
        if(m_count){
            f.clear();
            f.seekg(0);
            m_studentNum = new unsigned[m_count];
            m_grade = new double[m_count];
            for(size_t i = 0u; i < m_count; ++i){
                f >> m_studentNum[i];
                f.ignore();
                f >> m_grade[i];
                f.ignore();
            }
        }
        f.close();
    }
    
    Grades::~Grades(){
        delete [] m_studentNum;
        delete [] m_grade;
    }
}

