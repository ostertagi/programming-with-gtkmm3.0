#ifndef GTKMM_GRID_H
#define GTKMM_GRID_H

#include <gtkmm.h>

class Grid : public Gtk::Window
{
    public:
        Grid();
        virtual ~Grid();

    protected:
        void on_button_quit();
        void on_button_numbered(const Glib::ustring& data);

        Gtk::Grid grid;
        Gtk::Button btn1, btn2, btn_quit;
};

#endif