#include "infobar.h"
#include <iostream>

InfoBar::InfoBar() :
  vbox(Gtk::ORIENTATION_VERTICAL, 6),
  btn_close("_Quit", true),
  btn_clear("_Clear", true)
{
  set_title("Gtk::InfoBar");
  set_border_width(6);
  set_default_size(400, 200);

  add(vbox);

  auto infobar_container = dynamic_cast<Gtk::Container*>(info_bar.get_content_area());

  if (infobar_container)
  {
    infobar_container->add(lbl_message);
  }

  info_bar.add_button("_Ok", 0);

  vbox.pack_start(info_bar, Gtk::PACK_SHRINK);

  ref_txt_buffer = Gtk::TextBuffer::create();
  txt_view.set_buffer(ref_txt_buffer);

  scrolled_window.add(txt_view);
  scrolled_window.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  vbox.pack_start(scrolled_window);
  vbox.pack_start(btn_box, Gtk::PACK_SHRINK);

  btn_box.pack_start(btn_clear, Gtk::PACK_SHRINK);
  btn_box.pack_start(btn_close, Gtk::PACK_SHRINK);
  btn_box.set_spacing(6);
  btn_box.set_layout(Gtk::BUTTONBOX_END);

  info_bar.signal_response().connect(sigc::mem_fun(*this, &InfoBar::on_infobar_response));
  btn_close.signal_clicked().connect(sigc::mem_fun(*this, &InfoBar::on_button_close));
  btn_clear.signal_clicked().connect(sigc::mem_fun(*this, &InfoBar::on_button_clear));
  ref_txt_buffer->signal_changed().connect(sigc::mem_fun(*this, &InfoBar::on_textbuffer_changed));

  show_all();

  info_bar.hide();

  btn_clear.set_sensitive(false);
}

InfoBar::~InfoBar()
{}

void InfoBar::on_infobar_response(int)
{
  lbl_message.set_text("");
  info_bar.hide();
}

void InfoBar::on_textbuffer_changed()
{
  btn_clear.set_sensitive(ref_txt_buffer->size() > 0);
}

void InfoBar::on_button_clear()
{
  ref_txt_buffer->set_text("");
  lbl_message.set_text("Text cleared.");
  info_bar.set_message_type(Gtk::MESSAGE_INFO);
  info_bar.show();
}

void InfoBar::on_button_close()
{
  hide();
}