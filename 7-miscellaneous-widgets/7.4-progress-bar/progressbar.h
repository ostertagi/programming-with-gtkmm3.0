#ifndef GTKMM_PROGRESSBAR_H
#define GTKMM_PROGRESSBAR_H

#include <gtkmm.h>

class ProgressBar : public Gtk::Window
{
  public:
    ProgressBar();
    virtual ~ProgressBar();

  protected:
    void on_checkbutton_text();
    void on_checkbutton_activity();
    void on_checkbutton_inverted();
    void on_button_close();

    bool on_timeout();
    bool b_activity_mode;

    Gtk::Box vbox;
    Gtk::Grid grid;
    Gtk::ProgressBar progress_bar;
    Gtk::Separator separator;
    Gtk::CheckButton
      checkbtn_text,
      checkbtn_activity,
      checkbtn_inverted;
    Gtk::Button btn_close;

    sigc::connection connection_timeout;
};

#endif