#ifndef GTKMM_MESSAGESLIST_H
#define GTKMM_MESSAGESLIST_H

#include <gtkmm.h>

class MessagesList : public Gtk::ScrolledWindow
{
  public:
    MessagesList();
    virtual ~MessagesList();

    class ModelColumns : public Gtk::TreeModel::ColumnRecord
    {
      public:
        ModelColumns()
        {
          add(col_text);
        }

        Gtk::TreeModelColumn<Glib::ustring> col_text;
    };

    ModelColumns columns;

  protected:
    Glib::RefPtr<Gtk::ListStore> list_store;

    Gtk::TreeView tree_view;
};

#endif