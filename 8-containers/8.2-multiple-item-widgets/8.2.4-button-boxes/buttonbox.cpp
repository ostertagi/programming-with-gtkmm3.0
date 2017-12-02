#include "buttonbox.h"

ButtonBox::ButtonBox(bool horizontal, const Glib::ustring title, gint spacing, Gtk::ButtonBoxStyle layout) :
    Gtk::Frame(title),
    btn_ok("Ok"),
    btn_cancel("Cancel"),
    btn_help("Help")
{
    Gtk::ButtonBox* bbox = nullptr;

    if (horizontal)
        bbox = Gtk::manage(new Gtk::ButtonBox(Gtk::ORIENTATION_HORIZONTAL));
    else
        bbox = Gtk::manage(new Gtk::ButtonBox(Gtk::ORIENTATION_VERTICAL));

    bbox->set_border_width(5);

    add(*bbox);

    bbox->set_layout(layout);
    bbox->set_spacing(spacing);
    bbox->add(btn_ok);
    bbox->add(btn_cancel);
    bbox->add(btn_help);
}

ButtonBox::~ButtonBox()
{}