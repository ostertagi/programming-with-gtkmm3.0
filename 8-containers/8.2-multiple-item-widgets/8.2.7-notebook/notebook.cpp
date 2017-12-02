#include "notebook.h"
#include <iostream>

Notebook::Notebook() :
    vbox(Gtk::ORIENTATION_VERTICAL),
    lbl1("Contents of tab 1"),
    lbl2("Contents of tab 2"),
    btn_quit("Quit")
{
    set_title("Gtk::Notebook");
    set_border_width(10);
    set_default_size(400, 200);

    add(vbox);

    notebook.set_border_width(10);
    vbox.pack_start(notebook);
    vbox.pack_start(btnbox, Gtk::PACK_SHRINK);

    btnbox.pack_start(btn_quit, Gtk::PACK_SHRINK);
    btn_quit.signal_clicked().connect(sigc::mem_fun(*this, &Notebook::on_button_quit));

    notebook.append_page(lbl1, "First");
    notebook.append_page(lbl2, "Second");
    notebook.signal_switch_page().connect(sigc::mem_fun(*this, &Notebook::on_switch_page));

    show_all_children();
}

Notebook::~Notebook()
{}

void
Notebook::on_button_quit()
{
    hide();
}

void
Notebook::on_switch_page(Gtk::Widget* /* page */, guint page_num)
{
    std::cout << "Switched to tab " << page_num << std::endl;
}