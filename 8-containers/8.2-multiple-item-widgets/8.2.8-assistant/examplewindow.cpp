#include "examplewindow.h"

ExampleWindow::ExampleWindow() :
    btn("Show the assistant"),
    lbl1("State of the assistant checkbutton:", Gtk::ALIGN_START, Gtk::ALIGN_CENTER),
    lbl2("State of the assistant entry:", Gtk::ALIGN_START, Gtk::ALIGN_CENTER)
{
    set_title("Gtk::Assistant");
    set_border_width(10);

    btn.set_hexpand(true);
    btn.set_valign(Gtk::ALIGN_CENTER);

    checkbtn.set_halign(Gtk::ALIGN_START);
    checkbtn.set_sensitive(false);

    entry.set_hexpand(true);
    entry.set_sensitive(false);

    grid.set_row_homogeneous(true);
    grid.attach(btn, 0, 0, 2, 1);
    grid.attach(lbl1, 0, 1, 1, 1);
    grid.attach(lbl2, 0, 2, 1, 1);
    grid.attach(entry, 1, 2, 1, 1);

    btn.signal_clicked().connect(sigc::mem_fun(*this, &ExampleWindow::on_button_clicked));
    assistant.signal_apply().connect(sigc::mem_fun(*this, &ExampleWindow::on_assistant_apply));

    add(grid);
    
    show_all_children();
}

ExampleWindow::~ExampleWindow()
{}

void
ExampleWindow::on_assistant_apply()
{
    bool check_state;
    Glib::ustring entry_text;

    assistant.get_result(check_state, entry_text);
    checkbtn.set_active(check_state);
    entry.set_text(entry_text);
}

void 
ExampleWindow::on_button_clicked()
{
  assistant.show();
}