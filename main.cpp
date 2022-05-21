#include "gordmenu.hpp"
#include "menuelem.hpp"
#include "szambeall.hpp"
#include "pushbutton.hpp"
#include "Window.hpp"
#include "textbox.hpp"
#include "szovegszerk.hpp"
#include "checkbox.hpp"
#include <vector>
#include <fstream>
#include <functional>
#include <vector>

using namespace genv;

const int XX = 500;
const int YY = 400;

class Pelda: public Window
{
    private:
        CheckBox* ch;

    public:
       Pelda()
        {
            screenx = XX;
            screeny = YY;
        }

        void esemeny(const std::string& ki_mondta)
        {
        }
};

int main()
{
    gout.open(XX, YY);
    gout.load_font("LiberationSans-Regular.ttf");
    Pelda* p = new Pelda;
    p->event_loop();
    return 0;
}
