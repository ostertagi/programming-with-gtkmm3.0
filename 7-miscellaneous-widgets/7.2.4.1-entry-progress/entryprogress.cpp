#include "entryprogress.h"
#include <iostream>

EntryProgress::EntryProgress() :
  m_vbox(Gtk::ORIENTATION_VERTICAL),
  m_button_close("Close")
{
  set_title("Entry with Progress");

  add(m_vbox);

  m_entry.set_max_length(50);
  m_entry.set_text("Hello World");
  m_vbox.pack_start(m_entry, Gtk::PACK_SHRINK);

  Glib::signal_timeout().connect(sigc::mem_fun(*this, &EntryProgress::on_timeout), 100);

  m_button_close.signal_clicked().connect(sigc::mem_fun(*this, &EntryProgress::on_button_close));
  m_button_close.set_can_default();
  m_button_close.grab_default();

  m_vbox.pack_start(m_button_close, Gtk::PACK_SHRINK);

  show_all_children();
}

EntryProgress::~EntryProgress()
{}

bool EntryProgress::on_timeout()
{
  static double fraction = 0;

  m_entry.set_progress_fraction(fraction);

  fraction += 0.01;

  if (fraction > 1)
  {
    fraction = 0;
  }

  return true;
}

void EntryProgress::on_button_close()
{
  hide();
}