#ifndef GTKMM_TOOLTIP_H
#define GTKMM_TOOLTIP_H

#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/label.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/textview.h>
#include <gtkmm/button.h>
#include <gtkmm/textbuffer.h>
#include <gtkmm/texttag.h>
#include <gtkmm/tooltip.h>

class Tooltip : public Gtk::Window
{
  public:
    Tooltip();
    virtual ~Tooltip();

  protected:
    // Methods
    void prepare_textview();
    void connect_signals();

    // Signal handlers
    void on_markup_checkbutton_click();
    bool on_textview_query_tooltip(int x, int y, bool keyboard_tooltip, const Glib::RefPtr<Gtk::Tooltip>& tooltip);
    bool on_button_query_tooltip(int x, int y, bool keyboard_tooltip, const Glib::RefPtr<Gtk::Tooltip>& tooltip);

    // Child widgets
    Gtk::Box vbox;
    Gtk::CheckButton checkbtn;
    Gtk::Label lbl;
    Gtk::ScrolledWindow scrolled_window;
    Gtk::TextView txt_view;
    Gtk::Button btn;
    Gtk::Window btn_tooltip_window;

    Glib::RefPtr<Gtk::TextBuffer> txt_buffer;
    Glib::RefPtr<Gtk::TextTag> bold_tag;
};

#endif