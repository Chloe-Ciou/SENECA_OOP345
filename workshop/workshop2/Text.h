#ifndef W2_TEXT_H
#define W2_TEXT_H
#include <string>

namespace w2{
    class Text{
        std::string *m_str {nullptr};
        size_t m_size {0u};
    public:
        Text(){}
        Text(const std::string& str);
        Text(const Text& text);
        Text(Text&& text);
        Text& operator=(const Text& text);
        Text& operator=(Text&& text);
        ~Text();
        size_t size() const;
    };
}
#endif
