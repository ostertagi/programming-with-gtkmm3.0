#include "examplewindow.h"
#include "packbox.h"
#include <iostream>

ExampleWindow::ExampleWindow(int which) :
  box(Gtk::ORIENTATION_VERTICAL),
  btn_quit("Quit")
{
  set_title("Gtk::Box");

  PackBox *pb1, *pb2, *pb3;

  switch (which)
  {
    case 1:
    {
      lbl1.set_text("Gtk::Box(Gtk::ORIENTATION_HORIZONTAL); set_homogeneous(false);");

      lbl1.set_halign(Gtk::ALIGN_START);
      lbl1.set_valign(Gtk::ALIGN_START);
      box.pack_start(lbl1, Gtk::PACK_SHRINK);

      pb1 = Gtk::manage(new PackBox(false, 0, Gtk::PACK_SHRINK));
      box.pack_start(*pb1, Gtk::PACK_SHRINK);

      pb2 = Gtk::manage(new PackBox(false, 0, Gtk::PACK_EXPAND_PADDING));
      box.pack_start(*pb2, Gtk::PACK_SHRINK);

      box.pack_start(sep, Gtk::PACK_SHRINK, 5);

      lbl2.set_text("Gtk::Box(Gtk::ORIENTATION_HORIZONTAL); set_homogeneous(true);");
      lbl2.set_halign(Gtk::ALIGN_START);
      lbl2.set_valign(Gtk::ALIGN_START);
      box.pack_start(lbl2, Gtk::PACK_SHRINK);

      pb3 = Gtk::manage(new PackBox(false, 0, Gtk::PACK_EXPAND_WIDGET));
      box.pack_start(*pb3, Gtk::PACK_SHRINK);

      break;
    }
    case 2:
    {
      lbl1.set_text("Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 10); set_homogeneous(false);");

      lbl1.set_halign(Gtk::ALIGN_START);
      lbl1.set_valign(Gtk::ALIGN_START);
      box.pack_start(lbl1, Gtk::PACK_SHRINK);

      pb1 = Gtk::manage(new PackBox(false, 10, Gtk::PACK_SHRINK));
      box.pack_start(*pb1, Gtk::PACK_SHRINK);

      pb2 = Gtk::manage(new PackBox(false, 10, Gtk::PACK_EXPAND_PADDING));
      box.pack_start(*pb2, Gtk::PACK_SHRINK);

      box.pack_start(sep, Gtk::PACK_SHRINK, 5);

      lbl2.set_text("Gtk::Box(Gtk::ORIENTATION_HORIZONTAL); set_homogeneous(true);");
      lbl2.set_halign(Gtk::ALIGN_START);
      lbl2.set_valign(Gtk::ALIGN_START);
      box.pack_start(lbl2, Gtk::PACK_SHRINK);

      pb3 = Gtk::manage(new PackBox(false, 0, Gtk::PACK_SHRINK, 10));
      box.pack_start(*pb3, Gtk::PACK_SHRINK);

      break;
    }
  }
}

ExampleWindow::~ExampleWindow()
{}