#include "liststore.h"

ListStore::ListStore() :
    box(Gtk::ORIENTATION_VERTICAL),
    btn_quit("Quit")
{
    set_title("Gtk::tree_view (ListStore)");
    set_border_width(5);
    set_default_size(400, 200);

    add(box);

    /* 
    Add the tree_view, inside a ScrolledWindow, with the button underneath,
    showing scrollbars where necessary.
     */
    scrolledwindow.add(tree_view);
    scrolledwindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

    box.pack_start(scrolledwindow);
    box.pack_start(btnbox, Gtk::PACK_SHRINK);

    btnbox.pack_start(btn_quit, Gtk::PACK_SHRINK);
    btnbox.set_border_width(5);
    btnbox.set_layout(Gtk::BUTTONBOX_END);
    
    btn_quit.signal_clicked().connect(sigc::mem_fun(*this, &ListStore::on_button_quit));

    /* Create the tree model */
    tree_model = Gtk::ListStore::create(columns);
    tree_view.set_model(tree_model);

    /* Fill the tree model */
    Gtk::TreeModel::Row row = *(tree_model->append());
    row[columns.col_id] = 1;
    row[columns.col_name] = "Billy Bob";
    row[columns.col_no] = 7;
    row[columns.col_perc] = 77;

    row = *(tree_model->append());
    row[columns.col_id] = 2;
    row[columns.col_name] = "Sandy";
    row[columns.col_no] = 4;
    row[columns.col_perc] = 12;

    /* Add the tree_view's view columns */
    tree_view.append_column("ID", columns.col_id);
    tree_view.append_column("Name", columns.col_name);
    tree_view.append_column_numeric("Formatter #", columns.col_no, "%010d"); /* 10 digits, using leading zeroes. */

    /* Display a progress bar instead of decimal number */
    auto cell = Gtk::manage(new Gtk::CellRendererProgress);
    int cols_count = tree_view.append_column("Percentage", *cell);
    auto pcol = tree_view.get_column(cols_count - 1);

    if (pcol)
    {
        pcol->add_attribute(cell->property_value(), columns.col_perc);
    }

    /* Make all columns reorderable */
    for (guint i = 0; i < 2; i++)
    {
        auto col = tree_view.get_column(i);
        col->set_reorderable();
    }
    
    show_all_children();
}

ListStore::~ListStore()
{}

void
ListStore::on_button_quit()
{
    hide();
}