#include "rangewidgets.h"
#include <iostream>

RangeWidgets::RangeWidgets() :
  m_vbox_top(Gtk::ORIENTATION_VERTICAL, 0),
  m_vbox2(Gtk::ORIENTATION_VERTICAL, 20),
  m_vbox_hscale(Gtk::ORIENTATION_VERTICAL, 10),
  m_hbox_scales(Gtk::ORIENTATION_VERTICAL, 10),
  m_hbox_combo(Gtk::ORIENTATION_VERTICAL, 10),
  m_hbox_digits(Gtk::ORIENTATION_VERTICAL, 10),
  m_hbox_pagesize(Gtk::ORIENTATION_VERTICAL, 10),

  // value, lower, upper, step_increment, page_increment, page_size
  m_adjustment(Gtk::Adjustment::create(0.0, 0.0, 101.0, 0.1, 1.0, 1.0)),
  m_adjustment_digits(Gtk::Adjustment::create(1.0, 0.0, 5.0, 1.0, 2.0)),
  m_adjustment_pagesize(Gtk::Adjustment::create(1.0, 1.0, 101.0)),

  m_vscale(m_adjustment, Gtk::ORIENTATION_VERTICAL),
  m_hscale(m_adjustment, Gtk::ORIENTATION_HORIZONTAL),
  m_scale_digits(m_adjustment_digits),
  m_scale_pagesize(m_adjustment_pagesize),

  m_checkbutton("Display value on scale widgets", 0),

  m_scrollbar(m_adjustment),

  m_button_quit("Quit")
{
  set_title("Range controls");
  set_default_size(600, 650);

  m_vscale.set_digits(1);
  m_vscale.set_value_pos(Gtk::POS_TOP);
  m_vscale.set_draw_value();
  m_vscale.set_inverted();

  m_hscale.set_digits(1);
  m_hscale.set_value_pos(Gtk::POS_TOP);
  m_hscale.set_draw_value();

  add(m_vbox_top);

  m_vbox_top.pack_start(m_vbox2);
  m_vbox2.set_border_width(10);
  m_vbox2.pack_start(m_hbox_scales);

  m_hbox_scales.pack_start(m_vscale);
  m_hbox_scales.pack_start(m_vbox_hscale);

  m_vbox_hscale.pack_start(m_hscale);
  m_vbox_hscale.pack_start(m_scrollbar);

  m_checkbutton.set_active();
  m_checkbutton.signal_toggled().connect(sigc::mem_fun(*this, &RangeWidgets::on_checkbutton_toggled));

  m_vbox2.pack_start(m_checkbutton, Gtk::PACK_SHRINK);
  
  m_reftreemodel = Gtk::ListStore::create(m_columns);
  m_combobox_position.set_model(m_reftreemodel);
  m_combobox_position.pack_start(m_columns.m_col_title);

  Gtk::TreeModel::Row row = *(m_reftreemodel->append());
  row[m_columns.m_col_position_type] = Gtk::POS_TOP;
  row[m_columns.m_col_title] = "Top";
  row = *(m_reftreemodel->append());
  row[m_columns.m_col_position_type] = Gtk::POS_BOTTOM;
  row[m_columns.m_col_title] = "Bottom";
  row = *(m_reftreemodel->append());
  row[m_columns.m_col_position_type] = Gtk::POS_LEFT;
  row[m_columns.m_col_title] = "Left";
  row = *(m_reftreemodel->append());
  row[m_columns.m_col_position_type] = Gtk::POS_RIGHT;
  row[m_columns.m_col_title] = "Right";
  row = *(m_reftreemodel->append());

  m_vbox2.pack_start(m_hbox_combo, Gtk::PACK_SHRINK);
  m_hbox_combo.pack_start(*Gtk::manage(new Gtk::Label("Scale Value Position:", 0)), Gtk::PACK_SHRINK);
  m_hbox_combo.pack_start(m_combobox_position);

  m_combobox_position.signal_changed().connect(sigc::mem_fun(*this, &RangeWidgets::on_combo_position));
  m_combobox_position.set_active(0);

  m_scale_digits.set_digits(0);
  m_adjustment_digits->signal_value_changed().connect(sigc::mem_fun(*this, &RangeWidgets::on_adjustment1_changed));

  m_hbox_digits.pack_start(*Gtk::manage(new Gtk::Label("Scale Digits:", 0)), Gtk::PACK_SHRINK);
  m_hbox_digits.pack_start(m_scale_digits);

  m_scale_pagesize.set_digits(0);
  m_adjustment_pagesize->signal_value_changed().connect(sigc::mem_fun(*this, &RangeWidgets::on_adjustment2_changed));

  m_hbox_pagesize.pack_start(*Gtk::manage(new Gtk::Label("Scrollbar Page Size:", 0)), Gtk::PACK_SHRINK);
  m_hbox_pagesize.pack_start(m_scale_pagesize);

  m_vbox2.pack_start(m_hbox_digits, Gtk::PACK_SHRINK);
  m_vbox2.pack_start(m_hbox_pagesize, Gtk::PACK_SHRINK);
  m_vbox2.pack_start(m_separator, Gtk::PACK_SHRINK);
  m_vbox2.pack_start(m_button_quit, Gtk::PACK_SHRINK);

  m_button_quit.set_can_default();
  m_button_quit.grab_default();
  m_button_quit.signal_clicked().connect(sigc::mem_fun(*this, &RangeWidgets::on_button_quit));
  m_button_quit.set_border_width(10);

  show_all_children();
}

RangeWidgets::~RangeWidgets()
{}

void RangeWidgets::on_checkbutton_toggled()
{
  m_vscale.set_draw_value(m_checkbutton.get_active());
  m_hscale.set_draw_value(m_checkbutton.get_active());
}

void RangeWidgets::on_combo_position()
{
  Gtk::TreeModel::iterator iter = m_combobox_position.get_active();

  if (!iter) return;

  Gtk::TreeModel::Row row = *iter;

  if (!row) return;

  const Gtk::PositionType POSype = row[m_columns.m_col_position_type];

  m_vscale.set_value_pos(POSype);
  m_hscale.set_value_pos(POSype);
}

void RangeWidgets::on_adjustment1_changed()
{
  const double val = m_adjustment_digits->get_value();

  m_vscale.set_digits((int)val);
  m_hscale.set_digits((int)val);
}

void RangeWidgets::on_adjustment2_changed()
{
  const double val = m_adjustment_pagesize->get_value();

  m_adjustment->set_page_size(val);
  m_adjustment->set_page_increment(val);
}

void RangeWidgets::on_button_quit()
{
  hide();
}