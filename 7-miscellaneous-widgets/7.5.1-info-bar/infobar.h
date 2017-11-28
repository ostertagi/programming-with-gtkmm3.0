#ifndef GTKMM_INFOBAR_H
#define GTKMM_INFOBAR_H

#include <gtkmm.h>

class InfoBar : public Gtk::Window
{
  public:
    InfoBar();
    virtual ~InfoBar();

  protected:
    void on_infobar_response(int response);
    void on_button_close();
    void on_button_clear();
    void on_textbuffer_changed();

    Gtk::Box vbox;
    Gtk::ScrolledWindow scrolled_window;
    Gtk::TextView txt_view;
    Gtk::InfoBar info_bar;
    Gtk::Label lbl_message;
    Gtk::ButtonBox btn_box;
    Gtk::Button btn_close, btn_clear;

    Glib::RefPtr<Gtk::TextBuffer> ref_txt_buffer;
};

#endif