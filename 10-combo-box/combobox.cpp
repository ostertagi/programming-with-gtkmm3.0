#include "combobox.h"
#include <iostream>

ComboBox::ComboBox()
{
    set_title("Gtk::ComboBox");
    set_border_width(10);
    
    tree_model = Gtk::ListStore::create(columns);
    combo.set_model(tree_model);

    /* Fill the ComboBox's TreeModel */
    Gtk::TreeModel::Row row = *(tree_model->append());
    row[columns.col_id] = 1;
    row[columns.col_name] = "Foo Bar";
    row[columns.col_extra] = "Lorem";

    row = *(tree_model->append());
    row[columns.col_id] = 2;
    row[columns.col_name] = "Boo Far";
    row[columns.col_extra] = "Ipsum";

    row = *(tree_model->append());
    row[columns.col_id] = 3;
    row[columns.col_name] = "Coo Far";
    
    combo.set_cell_data_func(cell, sigc::mem_fun(*this, &ComboBox::on_cell_data_extra));
    combo.pack_start(cell);
    combo.signal_changed().connect(sigc::mem_fun(*this, &ComboBox::on_changed));

    add(combo);

    show_all_children();
}

ComboBox::~ComboBox()
{}

void
ComboBox::on_cell_data_extra(const Gtk::TreeModel::const_iterator& iter)
{
    auto row = *iter;
    const Glib::ustring extra = row[columns.col_extra];

    if (extra.empty())
        cell.property_text() = row[columns.col_name];
    else
        cell.property_text() = row[columns.col_name] + " - " + extra + " -";

    cell.property_foreground() = (extra.empty() ? "red" : "green");
}

void
ComboBox::on_changed()
{
    Gtk::TreeModel::iterator iter = combo.get_active();

    if (iter)
    {
        Gtk::TreeModel::Row row = *iter;

        if (row)
        {
            int id = row[columns.col_id];
            Glib::ustring name = row[columns.col_name];

            std::cout << "ID: " << id << ", name: " << name << std::endl;
        }
    }
    else
        std::cout << "Invalid iter" << std::endl;
}