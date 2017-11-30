#include "packbox.h"

PackBox::PackBox(bool homogeneous, int spacing, Gtk::PackOptions options, int padding) :
  Gtk::Box(Gtk::ORIENTATION_VERTICAL, spacing),
  btn1("box.pack_start("),
  btn2("button, "),
  btn3((options == Gtk::PACK_SHRINK) ? "Gtk::PACK_SHRINK" : ((options == Gtk::PACK_EXPAND_PADDING) ? "Gtk::PACK_EXPAND_PADDING" : "Gtk::PACK_EXPAND_WIDGET"))
{
  set_homogeneous(homogeneous);

  pack_start(btn1, options, padding);
  pack_start(btn2, options, padding);
  pack_start(btn2, options, padding);

  pbtn4 = new Gtk::Button(Glib::ustring::format(padding) + ");");
  pack_start(*pbtn4, options, padding);
}

PackBox::~PackBox()
{
  delete pbtn4;
}