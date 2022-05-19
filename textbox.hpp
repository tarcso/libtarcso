#ifndef TEXTBOX_HPP_INCLUDED
#define TEXTBOX_HPP_INCLUDED

#include "widgets.hpp"

class textBox : Widget
{
    private:
        std::string m_szov;
    public:
        textBox(Window* window, int x, int y, int sx, int sy, std::string s);
        void handle(const genv::event& ev);
        void draw() const;
        void setText(std::string s);
        void addText(std::string s);
        void unfocus(){}
};

#endif //TEXTBOX_HPP_INCLUDED
