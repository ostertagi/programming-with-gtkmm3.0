#include "buttonbox.h"
#include "buttonboxes.h"

ButtonBoxes::ButtonBoxes() :
    vbox_main(Gtk::ORIENTATION_VERTICAL),
    vbox(Gtk::ORIENTATION_VERTICAL),
    frame_h("Horizontal button boxes"),
    frame_v("Vertical button boxes")
{
    set_title("Gtk::ButtonBox");

    add(vbox_main);

    vbox_main.pack_start(frame_h, Gtk::PACK_EXPAND_WIDGET, 10);
    vbox.set_border_width(10);
    frame_h.add(vbox);

    vbox.pack_start(*Gtk::manage(new ButtonBox(true, "Spread (spacing 40)", 40, Gtk::BUTTONBOX_SPREAD)), Gtk::PACK_EXPAND_WIDGET);
    vbox.pack_start(*Gtk::manage(new ButtonBox(true, "Edge (spacing 30)", 30, Gtk::BUTTONBOX_EDGE)), Gtk::PACK_EXPAND_WIDGET, 5);
    vbox.pack_start(*Gtk::manage(new ButtonBox(true, "Start (spacing 20)", 20, Gtk::BUTTONBOX_START)), Gtk::PACK_EXPAND_WIDGET, 5);
    vbox.pack_start(*Gtk::manage(new ButtonBox(true, "End (spacing 10)", 10, Gtk::BUTTONBOX_END)), Gtk::PACK_EXPAND_WIDGET, 5);

    vbox_main.pack_start(frame_v, Gtk::PACK_EXPAND_WIDGET, 10);
    hbox.set_border_width(10);
    frame_v.add(hbox);

    hbox.pack_start(*Gtk::manage(new ButtonBox(false, "Spread (spacing 5)", 5, Gtk::BUTTONBOX_SPREAD)), Gtk::PACK_EXPAND_WIDGET);
    hbox.pack_start(*Gtk::manage(new ButtonBox(false, "Edge (spacing 30)", 30, Gtk::BUTTONBOX_EDGE)), Gtk::PACK_EXPAND_WIDGET, 5);
    hbox.pack_start(*Gtk::manage(new ButtonBox(false, "Start (spacing 20)", 20, Gtk::BUTTONBOX_START)), Gtk::PACK_EXPAND_WIDGET, 5);
    hbox.pack_start(*Gtk::manage(new ButtonBox(false, "End (spacing 10)", 10, Gtk::BUTTONBOX_END)), Gtk::PACK_EXPAND_WIDGET, 5);

    show_all_children();
}

ButtonBoxes::~ButtonBoxes()
{}

void ButtonBoxes::on_button_clicked()
{
    hide();
}