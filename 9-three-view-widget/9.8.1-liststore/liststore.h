#ifndef GTKMM_LISTSTORE_H
#define GTKMM_LISTSTORE_H

#include <gtkmm.h>

class ListStore : public Gtk::Window
{
    public:
        ListStore();
        virtual ~ListStore();

    protected:
        void on_button_quit();

        class ModelColumns : public Gtk::TreeModel::ColumnRecord
        {
            public:
                ModelColumns()
                {
                    add(col_id);
                    add(col_name);
                    add(col_no);
                    add(col_perc);
                }

                Gtk::TreeModelColumn<unsigned int> col_id;
                Gtk::TreeModelColumn<Glib::ustring> col_name;
                Gtk::TreeModelColumn<short> col_no;
                Gtk::TreeModelColumn<int> col_perc;
        };

        ModelColumns columns;

        Gtk::Box box;
        Gtk::ScrolledWindow scrolledwindow;
        Gtk::TreeView tree_view;
        Gtk::ButtonBox btnbox;
        Gtk::Button btn_quit;

        Glib::RefPtr<Gtk::ListStore> tree_model;
};

#endif