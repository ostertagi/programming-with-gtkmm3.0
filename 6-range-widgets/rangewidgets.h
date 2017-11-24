#ifndef GTKMM_RANGEWIDGETS_H
#define GTKMM_RANGEWIDGETS_H

#include <gtkmm.h>

class RangeWidgets : public Gtk::Window
{
  public:
    RangeWidgets();
    virtual ~RangeWidgets();

  protected:
    void on_checkbutton_toggled();
    void on_combo_position();
    void on_adjustment1_changed();
    void on_adjustment2_changed();
    void on_button_quit();

    Gtk::Box 
      m_vbox_top, 
      m_vbox2,
      m_vbox_hscale,
      m_hbox_scales,
      m_hbox_combo,
      m_hbox_digits,
      m_hbox_pagesize;

    Glib::RefPtr<Gtk::Adjustment> 
      m_adjustment, 
      m_adjustment_digits, 
      m_adjustment_pagesize;

    Gtk::Scale
      m_vscale,
      m_hscale,
      m_scale_digits,
      m_scale_pagesize;

    Gtk::Separator m_separator;

    Gtk::CheckButton m_checkbutton;

    Gtk::Scrollbar m_scrollbar;

    class ModelColumns : public Gtk::TreeModel::ColumnRecord
    {
      public:
        ModelColumns()
        {
          add(m_col_position_type);
          add(m_col_title);
        }

        Gtk::TreeModelColumn<Gtk::PositionType> m_col_position_type;
        Gtk::TreeModelColumn<Glib::ustring> m_col_title;
    };

    ModelColumns m_columns;

    Gtk::ComboBox m_combobox_position;
    Gtk::Button m_button_quit;

    Glib::RefPtr<Gtk::ListStore> m_reftreemodel;
};

#endif