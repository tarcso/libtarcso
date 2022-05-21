#ifndef CHECKBOX_HPP_INCLUDED
#define CHECKBOX_HPP_INCLUDED

#include "widgets.hpp"
#include <functional>
#include "graphics.hpp"

class CheckBox : public Widget
{
    private:
        bool m_is_checked;
        std::function<void()> m_checkedFunc;
        std::function<void()> m_uncheckedFunc;

    public:
        CheckBox(Window* window, int x, int y, int sx, int sy, std::function<void()> f, std::function<void()> uf);
        void handle(const genv::event& ev);
        void draw() const;
        void unfocus(){}
};

#endif //CHECKBOX_HPP_INCLUDED
