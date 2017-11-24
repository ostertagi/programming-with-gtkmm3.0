#include "radiobuttons.h"
#include <iostream>

RadioButtons::RadioButtons() :
  m_box_top(Gtk::ORIENTATION_VERTICAL),
  m_box1(Gtk::ORIENTATION_VERTICAL, 10),
  m_box2(Gtk::ORIENTATION_VERTICAL, 10),
  m_rb1("Radiobutton 1"), 
  m_rb2("Radiobutton 2"), 
  m_rb3("Radiobutton 3"), 
  m_button_close("Close")
{
  set_title("Radiobuttons");
  set_border_width(0);

  m_rb2.join_group(m_rb1);
  m_rb3.join_group(m_rb1);

  add(m_box_top);

  m_box_top.pack_start(m_box1);
  m_box_top.pack_start(m_separator);
  m_box_top.pack_start(m_box2);

  m_box1.set_border_width(10);
  m_box2.set_border_width(10);

  m_box1.pack_start(m_rb1);
  m_box1.pack_start(m_rb2);
  m_box1.pack_start(m_rb3);

  m_rb2.set_active();

  m_box2.pack_start(m_button_close);

  m_button_close.set_can_default();
  m_button_close.grab_default();
  m_button_close.signal_clicked().connect(sigc::mem_fun(*this, &RadioButtons::on_button_clicked));

  show_all_children();
}

RadioButtons::~RadioButtons()
{}

void RadioButtons::on_button_clicked()
{
  hide();
}