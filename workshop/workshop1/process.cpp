
#include <iostream>
#include "process.h"
#include "CString.h"
using namespace std;

void process(const char* str, std::ostream& os){
        w1::CString Cstr(str);
        os << Cstr << endl;
}
