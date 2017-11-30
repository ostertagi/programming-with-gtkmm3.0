#include "alignment.h"
#include <iostream>

Alignment::Alignment() : btn("_Close", true)
{
  set_title("Alignment");
  set_border_width(10);
  set_default_size(200,50);

  btn.set_halign(Gtk::ALIGN_END);
  btn.set_valign(Gtk::ALIGN_CENTER);

  add(btn);

  btn.signal_clicked().connect(sigc::mem_fun(*this, &Alignment::on_button_clicked));

  show_all_children();
}

Alignment::~Alignment()
{}

void Alignment::on_button_clicked()
{
  hide();
}