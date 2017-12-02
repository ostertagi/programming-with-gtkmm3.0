#ifndef GTKMM_BUTTONBOX_H
#define GTKMM_BUTTONBOX_H

#include <gtkmm.h>

class ButtonBox : public Gtk::Frame
{
    public:
        ButtonBox(bool horizontal, const Glib::ustring title, gint spacing, Gtk::ButtonBoxStyle layout);
        virtual ~ButtonBox();

    protected:
        Gtk::Button btn_ok, btn_cancel, btn_help;
};

#endif