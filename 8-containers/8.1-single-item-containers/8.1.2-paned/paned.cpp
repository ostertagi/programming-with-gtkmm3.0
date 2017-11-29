#include "paned.h"

Paned::Paned() :
  vpaned(Gtk::ORIENTATION_VERTICAL)
{
  set_title("Gtk::Paned");
  set_border_width(10);
  set_default_size(450, 400);

  add(vpaned);

  vpaned.add1(list);
  vpaned.add2(text);

  show_all_children();
}

Paned::~Paned()
{}