#include "progressbar.h"
#include <iostream>

ProgressBar::ProgressBar() :
  vbox(Gtk::ORIENTATION_VERTICAL, 5),
  checkbtn_text("Show text"),
  checkbtn_activity("Activity mode"),
  checkbtn_inverted("Right to left"),
  btn_close("Close"),
  b_activity_mode(false)
{
  set_resizable();
  set_title("Gtk::ProgressBar");

  add(vbox);

  vbox.set_border_width(5);
  vbox.pack_start(progress_bar, Gtk::PACK_SHRINK, 5);

  progress_bar.set_halign(Gtk::ALIGN_CENTER);
  progress_bar.set_valign(Gtk::ALIGN_CENTER);
  progress_bar.set_text("Lorem Ipsum");
  progress_bar.set_show_text(false);

  connection_timeout = Glib::signal_timeout().connect(sigc::mem_fun(*this, &ProgressBar::on_timeout), 50);

  vbox.pack_start(separator, Gtk::PACK_SHRINK);
  vbox.pack_start(grid);

  grid.set_row_homogeneous(true);
  grid.attach(checkbtn_text, 0, 0, 1, 1);
  checkbtn_text.property_margin() = 5;
  checkbtn_text.signal_clicked().connect(sigc::mem_fun(*this, &ProgressBar::on_checkbutton_text));

  grid.attach(checkbtn_activity, 0, 1, 1, 1);
  checkbtn_activity.property_margin() = 5;
  checkbtn_activity.signal_clicked().connect(sigc::mem_fun(*this, &ProgressBar::on_checkbutton_activity));

  grid.attach(checkbtn_inverted, 0, 2, 1, 1);
  checkbtn_inverted.property_margin() = 5;
  checkbtn_inverted.signal_clicked().connect(sigc::mem_fun(*this, &ProgressBar::on_checkbutton_inverted));

  vbox.pack_start(btn_close, Gtk::PACK_SHRINK);
  btn_close.signal_clicked().connect(sigc::mem_fun(*this, &ProgressBar::on_button_close));
  btn_close.set_can_default();
  btn_close.grab_default();

  show_all_children();
}

ProgressBar::~ProgressBar()
{}

void ProgressBar::on_checkbutton_text()
{
  progress_bar.set_show_text(checkbtn_text.get_active());
}

void ProgressBar::on_checkbutton_activity()
{
  if (checkbtn_activity.get_active())
    progress_bar.pulse();
  else
    progress_bar.set_fraction(0.0);
}

void ProgressBar::on_checkbutton_inverted()
{
  progress_bar.set_inverted(checkbtn_inverted.get_active());
}

void ProgressBar::on_button_close()
{
  hide();
}

bool ProgressBar::on_timeout()
{
  if (b_activity_mode)
    progress_bar.pulse();
  else
  {
    double new_val = progress_bar.get_fraction() + 0.01;

    if (new_val > 1.0)
      new_val = 0;
    
    progress_bar.set_fraction(new_val);
  }

  return true;
}