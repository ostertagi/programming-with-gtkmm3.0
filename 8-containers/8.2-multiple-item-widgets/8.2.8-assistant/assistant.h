#ifndef GTKMM_ASSISTANT_H
#define GTKMM_ASSISTANT_H

#include <gtkmm.h>

class Assistant : public Gtk::Assistant
{
    public:
        Assistant();
        virtual ~Assistant();

        void get_result(bool& check_state, Glib::ustring& entry_text);

    protected:
        void on_assistant_apply();
        void on_assistant_cancel();
        void on_assistant_close();
        void on_assistant_prepare(Gtk::Widget* widget);
        void on_entry_changed();
        void print_status();

        Gtk::Box box;
        Gtk::Label lbl1, lbl2;
        Gtk::CheckButton checkbtn;
        Gtk::Entry entry;
};

#endif