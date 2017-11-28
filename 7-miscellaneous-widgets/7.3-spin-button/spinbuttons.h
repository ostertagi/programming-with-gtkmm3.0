#ifndef GTKMM_SPINBUTTON_H
#define GTKMM_SPINBUTTON_H

#include <gtkmm.h>

class SpinButtons : public Gtk::Window
{
  public:
    SpinButtons();
    virtual ~SpinButtons();

  protected:
    void on_checkbutton_snap();
    void on_checkbutton_numeric();
    void on_spinbutton_digits_changed();
    void on_button_close();

    enum enumEvaluateFormats
    {
      VALUE_FORMAT_INT,
      VALUE_FORMAT_FLOAT
    };
    void on_button_getvalue(enumEvaluateFormats display);

    Gtk::Frame
      frame_notaccelerated, 
      frame_accelerated;
    Gtk::Box
      hbox_notaccelerated,
      hbox_accelerated,
      hbox_buttons,
      vbox,
      vbox_main,
      vbox_day,
      vbox_month,
      vbox_year,
      vbox_accelerated,
      vbox_value,
      vbox_digits;
    Gtk::Label
      lbl_day,
      lbl_month,
      lbl_year,
      lbl_value,
      lbl_digits,
      lbl_showvalue;
    Gtk::SpinButton
      spinbtn_day,
      spinbtn_month,
      spinbtn_year,
      spinbtn_value,
      spinbtn_digits;
    Gtk::CheckButton
      checkbtn_snap,
      checkbtn_numeric;
    Gtk::Button
      btn_int,
      btn_float,
      btn_close;
    Glib::RefPtr<Gtk::Adjustment> 
      adjustment_day,
      adjustment_month,
      adjustment_year,
      adjustment_value,
      adjustment_digits;
};

#endif