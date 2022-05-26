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
        GordMenu* g;
        Szambeall* sz;
        PushButton* p;
        textBox* t;
        SzovegSzerk* s;
        CheckBox* c;
    public:
       Pelda()
        {
            screenx = XX;
            screeny = YY;
            //sz = new Szambeall(this, 10, 50, 90, 30, 23, 45);
            p = new PushButton(this, 10, 90, 40, 30, "Push", [](){});
            t = new textBox(this, 10, 150, 70, 30, "szöveg", true);
            t = new textBox(this, 10, 190, 70, 30, "szöveg", false);
            s = new SzovegSzerk(this, 150, 10, 100, 40);
            c = new CheckBox(this, 150, 60, 50, 50, [](){}, [](){});
            g = new GordMenu(this, 10, 10, 100, 30, "válassz", {"hello", "mello", "mizu"}, 2);
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
