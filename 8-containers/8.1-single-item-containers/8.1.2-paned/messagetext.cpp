#include "messagetext.h"

MessageText::MessageText()
{
  set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
  
  add(text_view);

  insert_text();

  show_all_children();
}

MessageText::~MessageText()
{}

void MessageText::insert_text()
{
  auto txt_buffer = text_view.get_buffer();

  Gtk::TextBuffer::iterator iter = txt_buffer->get_iter_at_offset(0);

  txt_buffer->insert(iter,
    "From: pathfinder@nasa.gov\n"
    "To: mom@nasa.gov\n"
    "Subject: Made it!\n"
    "\n"
    "We just got in this morning. The weather has been\n"
    "great - clear but cold, and there are lots of fun sights.\n"
    "Sojourner says hi. See you soon.\n"
    " -Path\n");
}