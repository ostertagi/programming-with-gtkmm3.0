#include "entry.h"
#include <iostream>

Entry::Entry() :
  m_vbox(Gtk::ORIENTATION_VERTICAL),
  m_button_close("Close"),
  m_checkbutton_editable("Editable"),
  m_checkbutton_visible("Visible")
{
  set_size_request(200, 100);
  set_title("Entry");

  add(m_vbox);

  m_entry.set_max_length(50);
  m_entry.set_text("Hello");
  m_entry.set_text(m_entry.get_text() + " World");
  m_entry.select_region(0, m_entry.get_text_length());
  
  m_vbox.pack_start(m_entry);
  m_vbox.add(m_hbox);

  m_hbox.pack_start(m_checkbutton_editable);
  m_checkbutton_editable.signal_toggled().connect(sigc::mem_fun(*this, &Entry::on_checkbox_editable_toggled));
  m_checkbutton_editable.set_active(true);

  m_hbox.pack_start(m_checkbutton_visible);
  m_checkbutton_visible.signal_toggled().connect(sigc::mem_fun(*this, &Entry::on_checkbox_visible_toggled));
  m_checkbutton_visible.set_active(true);

  m_button_close.signal_clicked().connect(sigc::mem_fun(*this, &Entry::on_button_close));
  m_button_close.set_can_default();
  m_button_close.grab_default();

  m_vbox.pack_start(m_button_close);

  show_all_children();
}

Entry::~Entry()
{}

void Entry::on_checkbox_editable_toggled()
{
  m_entry.set_editable(m_checkbutton_editable.get_active());
}

void Entry::on_checkbox_visible_toggled()
{
  m_entry.set_visible(m_checkbutton_visible.get_active());
}

void Entry::on_button_close()
{
  hide();
}