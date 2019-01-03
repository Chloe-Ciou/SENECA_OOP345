#include <iostream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {
    
    std::cout << "Command Line: ";
    for (int i = 0; i < argc; i++)
        std::cout << argv[i] << ' ';
    std::cout << std::endl;
    
    if (argc == 1) {
        std::cerr << "\n*** Insufficient number of arguments ***\n";
        std::cerr << "Usage: " << argv[0] << " fileName \n";
        return 1;
    }
    else if (argc != 2) {
        std::cerr << "\n*** Too many arguments ***\n";
        std::cerr << "Usage: " << argv[0] << " fileName \n";
        return 2;
    }
    
    //TODO: Update the main functions as per the specifications here
    try{
        Grades grades(argv[1]);
        auto letter = [](double grade){
            if(grade >= 0 && grade < 50)
                return Letter::F;
            if(grade < 55)
                return Letter::D_;
            if(grade < 60)
                return Letter::D;
            if(grade < 65)
                return Letter::C_;
            if(grade < 70)
                return Letter::C;
            if(grade < 75)
                return Letter::B_;
            if(grade < 80)
                return Letter::B;
            if(grade < 90)
                return Letter::A_;
            if(grade <= 100)
                return Letter::A;
            return Letter::NA;
        };
        grades.displayGrades(std::cout, letter);
        
    }catch(const char* errorMsg){
        std::cout << argv[1] << ' ' << errorMsg << std::endl;
    }catch(...){
        std::cout << "Error!";
    }
    return 0;
}
