#include "tooltip.h"
#include <vector>

const Glib::ustring app_title = "Tooltips";
const Glib::ustring tip = "A tip appears now";
const Glib::ustring m_tip = "A <b>marked up</b> tip appears now";

Tooltip::Tooltip() :
  vbox(Gtk::ORIENTATION_VERTICAL, 3),
  checkbtn("Click to alternate markup in tooltip"),
  lbl("Label"),
  btn("Custom widget tooltip window"),
  btn_tooltip_window(Gtk::WINDOW_POPUP)
{
  set_title(app_title);
  set_size_request(400, 600);

  add(vbox);

  // Checkbutton
  checkbtn.set_tooltip_text(m_tip);
  vbox.pack_start(checkbtn, Gtk::PACK_SHRINK);

  // Label
  lbl.set_tooltip_text("Another tooltip");
  vbox.pack_start(lbl, Gtk::PACK_SHRINK);

  // Textview
  prepare_textview();

  // Button
  btn.set_tooltip_window(btn_tooltip_window);
  vbox.pack_start(btn, Gtk::PACK_SHRINK);

  // Button's custom tooltip window
  btn_tooltip_window.set_default_size(250, 30);
  Gtk::Label* label = Gtk::manage(new Gtk::Label("A label in a custom tooltip window"));
  label->show();
  btn_tooltip_window.add(*label);

  // connect_signals();

  show_all_children();
}

Tooltip::~Tooltip()
{}

void Tooltip::prepare_textview()
{
  Gtk::TextIter iter;

  std::vector<Glib::RefPtr<Gtk::TextTag>> tags;

  // Set up a scrolled window
  scrolled_window.add(txt_view);
  scrolled_window.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
  vbox.pack_start(scrolled_window);

  // Create a text buffer with some text
  txt_buffer = Gtk::TextBuffer::create();

  iter = txt_buffer->end();
  txt_buffer->insert(iter, "Hover over the text");

  // Insert some text with a tag. Show tooltip when mouse hovers
  bold_tag = txt_buffer->create_tag("Bold");
  bold_tag->set_property("weight", Pango::WEIGHT_BOLD);

  tags.push_back(bold_tag);

  iter = txt_buffer->end();
  txt_buffer->insert_with_tags(iter, " in bold ", tags);

  iter = txt_buffer->end();
  txt_buffer->insert(iter, " to see its tooltips");

  txt_view.set_buffer(txt_buffer);
  txt_view.set_size_request(320, 50);
  txt_view.set_has_tooltip();
}

void Tooltip::connect_signals()
{
  if (checkbtn.get_active() == true)
    checkbtn.set_tooltip_markup(m_tip);
  else
    checkbtn.set_tooltip_markup(tip);
}

bool Tooltip::on_textview_query_tooltip(int x, int y, bool keyboard_tooltip, const Glib::RefPtr<Gtk::Tooltip>& tooltip)
{
  Gtk::TextIter iter;

  if (keyboard_tooltip)
  {
    int offset = txt_buffer->property_cursor_position().get_value();
    iter = txt_buffer->get_iter_at_offset(offset);
  }
  else
  {
    int mouse_x, mouse_y, trailing;
    txt_view.window_to_buffer_coords(Gtk::TEXT_WINDOW_TEXT, x, y, mouse_x, mouse_y);
    txt_view.get_iter_at_position(iter, trailing, mouse_x, mouse_y);
  }

  if (iter.has_tag(bold_tag))
  {
    tooltip->set_markup("<b>Information</b> attached to a text tag");
    tooltip->set_icon_from_icon_name("dialog-information", Gtk::ICON_SIZE_MENU);
  }
  else
  {
    return false;
  }

  return true;
}

bool Tooltip::on_button_query_tooltip(int, int, bool, const Glib::RefPtr<Gtk::Tooltip>&)
{
  return true;
}