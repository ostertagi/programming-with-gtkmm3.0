#include "frame.h"
#include <iostream>

Frame::Frame()
{
  set_title("Gtk::Frame");
  set_size_request(300, 300);
  set_border_width(10);

  add (frame);

  frame.set_label("Gtk::Frame");
  frame.set_label_align(Gtk::ALIGN_START, Gtk::ALIGN_END);
  frame.set_shadow_type(Gtk::SHADOW_ETCHED_OUT);

  show_all_children();
}

Frame::~Frame()
{}