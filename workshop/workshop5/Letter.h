#ifndef SICT_LETTER_H
#define SICT_LETTER_H
#include <string>

namespace sict{
    enum class Letter {A, A_, B, B_, C, C_, D, D_, F, NA};
    template<typename T>
    const char* convert(const T& letter){
        switch (letter) {
            case Letter::A:
                return "A+";
            case Letter::A_:
                return "A";
            case Letter::B:
                return "B+";
            case Letter::B_:
                return "B";
            case Letter::C:
                return "C+";
            case Letter::C_:
                return "C";
            case Letter::D:
                return "D+";
            case Letter::D_:
                return "D";
            case Letter::F:
                return "F";
            default:
                return "NA";
        }
    }
}

#endif
