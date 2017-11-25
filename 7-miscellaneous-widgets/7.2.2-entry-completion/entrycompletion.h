#ifndef GTKMM_ENTRYCOMPLETION_H
#define GTKMM_ENTRYCOMPLETION_H

#include <gtkmm.h>

class EntryCompletion : public Gtk::Window
{
  public:
    EntryCompletion();
    virtual ~EntryCompletion();

  protected:
    void on_button_close();
    void on_completion_activated(int index);
    bool on_completion_match(const Glib::ustring& key, const Gtk::TreeModel::const_iterator& iter);

    class ModelColumns : public Gtk::TreeModel::ColumnRecord
    {
      public:
        ModelColumns()
        {
          add(m_col_id);
          add(m_col_name);
        }

        Gtk::TreeModelColumn<unsigned int> m_col_id;
        Gtk::TreeModelColumn<Glib::ustring> m_col_name;
    };

    ModelColumns m_columns;

    typedef std::map<int, Glib::ustring> type_actions_map;
    type_actions_map m_completion_actions;

    Gtk::Box m_hbox, m_vbox;
    Gtk::Entry m_entry;
    Gtk::Label m_label;
    Gtk::Button m_button_close;
};

#endif