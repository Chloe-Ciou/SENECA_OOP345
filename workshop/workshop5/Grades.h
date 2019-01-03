#ifndef SICT_GRADES_H
#define SICT_GRADES_H
#include <iomanip>

namespace sict {
    class Grades{
        size_t m_count = 0u;
        unsigned* m_studentNum = nullptr;
        double* m_grade = nullptr;
    public:
        Grades(){}
        Grades(const char* fileName);
        Grades(const Grades&) = delete;
        Grades& operator=(const Grades&) = delete;
        Grades(Grades&&) = delete;
        Grades& operator=(Grades&&) = delete;
        virtual ~Grades();
        
        template<typename F>
        void displayGrades(std::ostream& os, F func) const{
            if(m_count){
                os << std::fixed << std::setprecision(2);
                for(size_t i = 0u; i < m_count; ++i){
                    auto letter = func(m_grade[i]);
                    os << std::setw(10) << std::right << m_studentNum[i] << ' ';
                    os << std::setw(5) << m_grade[i] << ' ';
                    os << std::setw(4) << std::left<< convert(letter) << std::endl;
                }
                os << std::right << std::setprecision(6);
            }
        }
    };
}

#endif
