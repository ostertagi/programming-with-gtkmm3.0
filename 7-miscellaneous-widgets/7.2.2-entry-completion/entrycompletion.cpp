#include "entrycompletion.h"
#include <iostream>

EntryCompletion::EntryCompletion() :
  m_vbox(Gtk::ORIENTATION_VERTICAL),
  m_label("Press 'a' or 'b' for possible completions"),
  m_button_close("Close")
{
  set_title("Entry Completion");

  add(m_vbox);

  m_vbox.pack_start(m_entry, Gtk::PACK_SHRINK);
  m_vbox.pack_start(m_label, Gtk::PACK_EXPAND_WIDGET);

  m_button_close.signal_clicked().connect(sigc::mem_fun(*this, &EntryCompletion::on_button_close));
  m_button_close.set_can_default();
  m_button_close.grab_default();
  m_vbox.pack_start(m_button_close, Gtk::PACK_SHRINK);

  auto completion = Gtk::EntryCompletion::create();
  m_entry.set_completion(completion);

  auto refcompletionmodel = Gtk::ListStore::create(m_columns);
  completion->set_model(refcompletionmodel);
  completion->set_match_func(sigc::mem_fun(*this, &EntryCompletion::on_completion_match));

  Gtk::TreeModel::Row row = *(refcompletionmodel->append());
  row[m_columns.m_col_id] = 1;
  row[m_columns.m_col_name] = "Abc";
  row[m_columns.m_col_id] = 2;
  row[m_columns.m_col_name] = "Def";
  row[m_columns.m_col_id] = 3;
  row[m_columns.m_col_name] = "Ghi";

  completion->set_text_column(m_columns.m_col_name);

  m_completion_actions[0] = "Use Wizard";
  m_completion_actions[1] = "Browse for Filename";

  for (const auto& the_pair : m_completion_actions)
  {
    auto position = the_pair.first;
    auto title = the_pair.second;

    completion->insert_action_text(title, position);
  }

  completion->signal_action_activated().connect(sigc::mem_fun(*this, &EntryCompletion::on_completion_activated));

  show_all_children();
}

EntryCompletion::~EntryCompletion()
{}

void EntryCompletion::on_button_close()
{
  hide();
}

void EntryCompletion::on_completion_activated(int index)
{ 
  type_actions_map::iterator iter = m_completion_actions.find(index);

  if (iter != m_completion_actions.end())
  {
    Glib::ustring title = iter->second;

    std::cout << "Acion selected: " << title << std::endl;
  }
}

bool EntryCompletion::on_completion_match(const Glib::ustring& key, const Gtk::TreeModel::const_iterator& iter)
{
  if (!iter) 
  {
    return false;
  }

  Gtk::TreeModel::Row row = *iter;

  Glib::ustring::size_type key_length = key.size();
  Glib::ustring filter_string = row[m_columns.m_col_name];
  Glib::ustring filter_string_start = filter_string.substr(0, key_length);

  filter_string_start = filter_string_start.lowercase();

  return true;
}