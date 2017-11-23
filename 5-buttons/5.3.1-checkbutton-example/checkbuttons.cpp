#include "checkbuttons.h"
#include <iostream>

CheckButtons::CheckButtons() : m_check_button("Check me")
{
  set_title("Checkbutton example");
  set_border_width(10);

  m_check_button.signal_clicked().connect(sigc::mem_fun(*this, &CheckButtons::on_button_clicked));

  add(m_check_button);

  show_all_children();
}

CheckButtons::~CheckButtons()
{}

void CheckButtons::on_button_clicked()
{
  std::cout << "The button was clicked. State: " << (m_check_button.get_active() ? "active" : "unactive") << std::endl;
}