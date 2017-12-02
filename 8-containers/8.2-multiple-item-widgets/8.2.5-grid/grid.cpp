#include "grid.h"
#include <iostream>

Grid::Grid() :
    btn1("Button 1"),
    btn2("Button 2"),
    btn_quit("Quit")
{
    set_title("Gtk::Grid");
    set_border_width(12);

    add(grid);

    grid.add(btn1);
    grid.add(btn2);
    grid.attach_next_to(btn_quit, btn1, Gtk::POS_BOTTOM, 2, 1);

    btn1.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Grid::on_button_numbered), "Button 1"));
    btn2.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Grid::on_button_numbered), "Button 2"));
    btn_quit.signal_clicked().connect(sigc::mem_fun(*this, &Grid::on_button_quit));

    show_all_children();
}

Grid::~Grid()
{}

void
Grid::on_button_quit()
{
    hide();
}

void
Grid::on_button_numbered(const Glib::ustring& data)
{
    std::cout << data << " was pressed." << std::endl;
}