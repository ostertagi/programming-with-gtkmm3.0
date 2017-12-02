#include "assistant.h"
#include <iostream>

Assistant::Assistant() :
    box(Gtk::ORIENTATION_VERTICAL, 12),
    lbl1("Type text to allow the assistant to continue: "),
    lbl2("Confirmation page"),
    checkbtn("Optional extra information")
{
    set_title("Gtk::Assistant");
    set_border_width(12);
    set_default_size(400, 300);

    box.pack_start(lbl1);
    box.pack_start(entry);

    append_page(box);
    append_page(checkbtn);
    append_page(lbl2);

    set_page_title(*get_nth_page(0), "Page 1");
    set_page_title(*get_nth_page(1), "Page 2");
    set_page_title(*get_nth_page(2), "Confirmation");

    set_page_complete(checkbtn, true);
    set_page_complete(lbl2, true);

    set_page_type(box, Gtk::ASSISTANT_PAGE_INTRO);
    set_page_type(lbl2, Gtk::ASSISTANT_PAGE_CONFIRM);

    signal_apply().connect(sigc::mem_fun(*this, &Assistant::on_assistant_apply));
    signal_cancel().connect(sigc::mem_fun(*this, &Assistant::on_assistant_cancel));
    signal_close().connect(sigc::mem_fun(*this, &Assistant::on_assistant_close));
    signal_prepare().connect(sigc::mem_fun(*this, &Assistant::on_assistant_prepare));

    entry.signal_changed().connect(sigc::mem_fun(*this, &Assistant::on_entry_changed));
    
    show_all_children();
}

Assistant::~Assistant()
{}

void
Assistant::get_result(bool& check_state, Glib::ustring& entry_text)
{
    check_state = checkbtn.get_active();
    entry_text = entry.get_text();
}

void
Assistant::on_assistant_apply()
{
    std::cout << "Apply was clicked.";
    print_status();
}

void
Assistant::on_assistant_cancel()
{
    std::cout << "Cancel was clicked";
    print_status();
    hide();
}

void
Assistant::on_assistant_close()
{
    std::cout << "Assistant was closed";
    print_status();
    hide();
}

void
Assistant::on_assistant_prepare(Gtk::Widget* /* widget */)
{
    set_title(Glib::ustring::compose("Gtk::Assistant example (Page %1 of %2)",
    get_current_page() + 1, get_n_pages()));
}

void
Assistant::on_entry_changed()
{
    if(entry.get_text_length())
        set_page_complete(box, true);
    else
        set_page_complete(box, false);
}

void
Assistant::print_status()
{
  std::cout << ", entry contents: \"" << entry.get_text() << "\", checkbutton status: " << checkbtn.get_active() << std::endl;
}