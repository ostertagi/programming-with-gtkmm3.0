#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include "assistant.h"
#include <gtkmm.h>

class ExampleWindow : public Gtk::Window
{
    public:
        ExampleWindow();
        virtual ~ExampleWindow();

    protected:
        void on_button_clicked();
        void on_assistant_apply();

        Gtk::Grid grid;
        Gtk::Button btn;
        Gtk::Label lbl1, lbl2;
        Gtk::CheckButton checkbtn;
        Gtk::Entry entry;

        Assistant assistant;
};

#endif