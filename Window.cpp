#include "Window.hpp"
#include <iostream>

using namespace genv;

Window::Window()
{

}

void Window::event_loop() {
    event ev;
    Widget* focus = nullptr;
    for (Widget * w : widgets) {
        w->draw();
    }
    gout << refresh;
    while(gin >> ev && ev.keycode != key_escape)
    {
        //if(focus != nullptr) focus->handle(ev);
        if(ev.type == ev_mouse && ev.button == btn_left)
        {
            if(focus != nullptr) focus->unfocus();
            for(Widget* w: widgets)
            if(w->is_selected(ev.pos_x, ev.pos_y))
            {
                focus = w;
                break;
            }
        }
        if(focus != nullptr) focus->handle(ev);

        //elozo = focus;

        gout << move_to(0, 0) << color(0, 0, 0) << box(screenx, screeny);
        for (Widget * w : widgets) {
            w->draw();
        }

        /*if(ev.type == ev_key && ev.keycode == 'a')
        {
            esemeny("update");
        }*/
        esemeny("update");

        gout << refresh;
    }
}

void Window::torolWidget(Widget* w)
{
    std::vector<Widget*>::iterator itt;
    for (std::vector<Widget*>::iterator it = widgets.begin();
         it != widgets. end();
         ++it)
    {
        if(*it == w) itt = it;
    }
    
    widgets.erase(itt);
}
