#ifndef GTKMM_COMBO_BOX_H
#define GTKMM_COMBO_BOX_H

#include <gtkmm.h>

class ComboBox : public Gtk::Window
{
    public:
        ComboBox();
        virtual ~ComboBox();

    protected:
        void on_cell_data_extra(const Gtk::TreeModel::const_iterator& iter);
        void on_changed();

        class ModelColumns : public Gtk::TreeModel::ColumnRecord
        {
            public:
                ModelColumns()
                {
                    add(col_id);
                    add(col_name);
                    add(col_extra);
                }

                Gtk::TreeModelColumn<int> col_id;
                Gtk::TreeModelColumn<Glib::ustring> col_name, col_extra;
        };

        ModelColumns columns;

        Gtk::ComboBox combo;
        Gtk::CellRendererText cell;
        Glib::RefPtr<Gtk::ListStore> tree_model;
};

#endif