#include "spinbuttons.h"
#include <iostream>

SpinButtons::SpinButtons() : 
  frame_notaccelerated("Not Accelerated"),
  frame_accelerated("Accelerated"),
  vbox_main(Gtk::ORIENTATION_VERTICAL, 5),
  vbox(Gtk::ORIENTATION_VERTICAL),
  vbox_day(Gtk::ORIENTATION_VERTICAL),
  vbox_month(Gtk::ORIENTATION_VERTICAL),
  vbox_year(Gtk::ORIENTATION_VERTICAL),
  vbox_accelerated(Gtk::ORIENTATION_VERTICAL),
  vbox_value(Gtk::ORIENTATION_VERTICAL),
  vbox_digits(Gtk::ORIENTATION_VERTICAL),
  lbl_day("Day: ", Gtk::ALIGN_START),
  lbl_month("Month: ", Gtk::ALIGN_START),
  lbl_year("Year: ", Gtk::ALIGN_START),
  lbl_value("Value: ", Gtk::ALIGN_START),
  lbl_digits("Digits: ", Gtk::ALIGN_START),
  adjustment_day(Gtk::Adjustment::create(1.0, 1.0, 31.0, 1.0, 5.0, 0.0)),
  adjustment_month(Gtk::Adjustment::create(1.0, 1.0, 12.0, 1.0, 5.0, 0.0)),
  adjustment_year(Gtk::Adjustment::create(2012.0, 1.0, 2200.0, 1.0, 100.0, 0.0)),
  adjustment_value(Gtk::Adjustment::create(0.0, -10000.0, 10000.0, 0.5, 100.0, 0.0)),
  adjustment_digits(Gtk::Adjustment::create(2.0, 1.0, 5.0, 1.0, 1.0, 0.0)),
  spinbtn_day(adjustment_day),
  spinbtn_month(adjustment_month),
  spinbtn_year(adjustment_year),
  spinbtn_value(adjustment_value, 1.0, 2),
  spinbtn_digits(adjustment_digits),
  checkbtn_snap("Snap to 0.5-ticks"),
  checkbtn_numeric("Numeric only input mode"),
  btn_int("Value as Int"),
  btn_float("Value as Float"),
  btn_close("Close")
{
  set_title("SpinButton");

  vbox_main.set_border_width(10);
  vbox_main.pack_start(frame_notaccelerated);

  add(vbox_main);

  vbox.set_border_width(5);

  frame_notaccelerated.add(vbox);

  // Day, month and year spinners
  vbox.pack_start(hbox_notaccelerated, Gtk::PACK_EXPAND_WIDGET, 5);
  vbox_day.pack_start(lbl_day);
  vbox_day.pack_start(spinbtn_day);
  hbox_notaccelerated.pack_start(vbox_day, Gtk::PACK_EXPAND_WIDGET, 5);

  vbox_month.pack_start(lbl_month);
  vbox_month.pack_start(spinbtn_month);
  hbox_notaccelerated.pack_start(vbox_month, Gtk::PACK_EXPAND_WIDGET, 5);

  vbox_year.pack_start(lbl_year);
  vbox_year.pack_start(spinbtn_year);
  hbox_notaccelerated.pack_start(vbox_year, Gtk::PACK_EXPAND_WIDGET, 5);

  spinbtn_day.set_wrap();
  spinbtn_month.set_wrap();
  spinbtn_year.set_wrap();
  spinbtn_year.set_size_request(55, -1);

  // Accelerated
  vbox_main.pack_start(frame_accelerated);

  frame_accelerated.add(vbox_accelerated);

  spinbtn_value.set_wrap();
  spinbtn_value.set_size_request(100, -1);

  vbox_value.pack_start(lbl_value);
  vbox_value.pack_start(spinbtn_value);

  vbox_accelerated.set_border_width(5);
  vbox_accelerated.pack_start(hbox_accelerated, Gtk::PACK_EXPAND_WIDGET, 5);
  hbox_accelerated.pack_start(vbox_value, Gtk::PACK_EXPAND_WIDGET, 5);
  hbox_accelerated.pack_start(vbox_digits, Gtk::PACK_EXPAND_WIDGET, 5);

  spinbtn_digits.signal_value_changed().connect(sigc::mem_fun(*this, &SpinButtons::on_spinbutton_digits_changed));
  
  vbox_digits.pack_start(spinbtn_digits);

  // Checkbuttons
  vbox_accelerated.pack_start(checkbtn_snap);
  checkbtn_snap.set_active();
  checkbtn_snap.signal_clicked().connect(sigc::mem_fun(*this, &SpinButtons::on_checkbutton_snap));

  vbox_accelerated.pack_start(checkbtn_numeric);
  checkbtn_numeric.set_active();
  checkbtn_numeric.signal_clicked().connect(sigc::mem_fun(*this, &SpinButtons::on_checkbutton_numeric));

  // Buttons
  vbox_accelerated.pack_start(hbox_buttons, Gtk::PACK_SHRINK, 5);
  
  btn_int.signal_clicked().connect(sigc::mem_fun(*this, &SpinButtons::on_button_getvalue), VALUE_FORMAT_INT);
  hbox_buttons.pack_start(btn_int, Gtk::PACK_EXPAND_WIDGET, 5);

  btn_float.signal_clicked().connect(sigc::mem_fun(*this, &SpinButtons::on_button_getvalue), VALUE_FORMAT_FLOAT);
  hbox_buttons.pack_start(btn_float, Gtk::PACK_EXPAND_WIDGET, 5);

  vbox_accelerated.pack_start(lbl_showvalue);
  lbl_showvalue.set_text("0");

  // Close
  btn_close.signal_clicked().connect(sigc::mem_fun(*this, &SpinButtons::on_button_close));

  vbox_main.pack_start(btn_close, Gtk::PACK_SHRINK);

  show_all_children();
}

SpinButtons::~SpinButtons()
{
}

void SpinButtons::on_button_close()
{
  hide();
}

void SpinButtons::on_checkbutton_snap()
{
  spinbtn_value.set_snap_to_ticks(checkbtn_snap.get_active());
}

void SpinButtons::on_checkbutton_numeric()
{
  spinbtn_value.set_numeric(checkbtn_numeric.get_active());
}

void SpinButtons::on_spinbutton_digits_changed()
{
  spinbtn_value.set_digits(spinbtn_digits.get_value_as_int());
}

void SpinButtons::on_button_getvalue(enumEvaluateFormats display)
{
  gchar buf[32];

  if (display == VALUE_FORMAT_INT)
    sprintf(buf, "%d", spinbtn_value.get_value_as_int());
  else
    sprintf(buf, "%0.*f", spinbtn_value.get_digits(), spinbtn_value.get_value());

  lbl_showvalue.set_text(buf);
}