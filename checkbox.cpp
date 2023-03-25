#include "checkbox.hpp"
#include "graphics.hpp"

using namespace genv;

CheckBox::CheckBox(Window *window, int x, int y, int sx, int sy,
                   std::function<void()> f, std::function<void()> uf)
    : Widget(window, x, y, sx, sy), m_checkedFunc(f), m_uncheckedFunc(uf) {
  m_is_checked = false;
}

void CheckBox::handle(const event &ev) {
  if (is_selected(ev.pos_x, ev.pos_y) && ev.type == ev_mouse &&
      ev.button == btn_left)
    m_is_checked = !m_is_checked;

  if (m_is_checked)
    m_checkedFunc();
  else
    m_uncheckedFunc();
}

void CheckBox::draw() const {
  gout << move_to(m_x, m_y) << color(255, 255, 255) << box(m_size_x, m_size_y);
  gout << move_to(m_x + 2, m_y + 2) << color(150, 150, 150)
       << box(m_size_x - 4, m_size_y - 4);
  if (m_is_checked)
    gout << move_to(m_x, m_y) << color(255, 255, 255)
         << line(m_size_x, m_size_y) << move_to(m_x + m_size_x - 1, m_y)
         << line(-m_size_x, m_size_y);
}
