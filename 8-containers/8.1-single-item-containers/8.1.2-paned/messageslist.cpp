#include "messageslist.h"
#include <sstream>

MessagesList::MessagesList()
{
  set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  add(tree_view);

  // Create list store
  list_store = Gtk::ListStore::create(columns);
  tree_view.set_model(list_store);

  // Add some messages
  for (int i = 0; i < 10; i++)
  {
    std::ostringstream text;

    text << "Message #" << i;

    Gtk::TreeModel::Row row = *(list_store->append());
    row[columns.col_text] = text.str();
  }

  // Add the model's column to the view's columns
  tree_view.append_column("Messages", columns.col_text);

  show_all_children();
}

MessagesList::~MessagesList()
{
}