#ifndef GTKMM_NOTBEOOK_H
#define GTKMM_NOTBEOOK_H

#include <gtkmm.h>

class Notebook : public Gtk::Window
{
    public:
        Notebook();
        virtual ~Notebook();

    protected:
        void on_button_quit();
        void on_switch_page(Gtk::Widget* page, guint page_num);

        Gtk::Box vbox;
        Gtk::Notebook notebook;
        Gtk::Label lbl1, lbl2;
        Gtk::ButtonBox btnbox;
        Gtk::Button btn, btn_quit;
};

#endif