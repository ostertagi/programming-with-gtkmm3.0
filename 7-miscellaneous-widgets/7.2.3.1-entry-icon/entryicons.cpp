#include "entryicons.h"
#include <iostream>

EntryIcons::EntryIcons() :
  m_vbox(Gtk::ORIENTATION_VERTICAL),
  m_button_close("Close")
{
  set_title("Entry with Icons");

  add(m_vbox);

  m_entry.set_max_length(50);
  m_entry.set_text("Hello");
  m_entry.set_icon_from_icon_name("edit-find");
  m_entry.signal_icon_press().connect(sigc::mem_fun(*this, &EntryIcons::on_icon_pressed));

  m_button_close.signal_clicked().connect(sigc::mem_fun(*this, &EntryIcons::on_button_close));
  m_button_close.set_can_default();
  m_button_close.grab_default();

  m_vbox.pack_start(m_entry, Gtk::PACK_SHRINK);
  m_vbox.pack_start(m_button_close, Gtk::PACK_SHRINK);

  show_all_children();
}

EntryIcons::~EntryIcons()
{}

void EntryIcons::on_icon_pressed(Gtk::EntryIconPosition /* icon_pos */, const GdkEventButton* /* event */)
{
  std::cout << "Icon pressed." << std::endl;
}

void EntryIcons::on_button_close()
{
  hide();
}