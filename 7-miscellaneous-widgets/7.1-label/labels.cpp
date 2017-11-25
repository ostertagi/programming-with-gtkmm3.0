#include "labels.h"
#include <iostream>

Labels::Labels() :
  m_hbox(Gtk::ORIENTATION_HORIZONTAL, 5),
  m_vbox(Gtk::ORIENTATION_HORIZONTAL, 5),
  m_vbox2(Gtk::ORIENTATION_HORIZONTAL, 5),
  m_frame_normal("Normal Label"),
  m_frame_multi("Multi-line Label"),
  m_frame_left("Left Label"),
  m_frame_right("Right Label"),
  m_frame_linewrapped("Line Wrapped Label"),
  m_frame_filledwrapped("Filled Wrapped Label"),
  m_frame_underlined("Underlined Label"),
  m_label_normal("_This is a Normal label", true),
  m_label_multi("This is a multi-line label.\nFirst line.\nSecond line"),
  m_label_left("This is a left-justified label.\nFirst line.\nSecond line"),
  m_label_right("This is a right-justified label.\nFirst line.\nSecond line"),
  m_label_underlined("This is a underlined label.\nThis one is underlined in quite a funky fashion")
{
  set_title("Labels");
  set_border_width(5);

  add(m_hbox);

  m_hbox.pack_start(m_vbox, Gtk::PACK_SHRINK);

  m_frame_normal.add(m_label_normal);
  m_vbox.pack_start(m_frame_normal, Gtk::PACK_SHRINK);

  m_frame_multi.add(m_label_multi);
  m_vbox.pack_start(m_frame_multi, Gtk::PACK_SHRINK);

  m_label_left.set_justify(Gtk::JUSTIFY_LEFT);
  m_frame_left.add(m_label_left);
  m_vbox.pack_start(m_frame_left, Gtk::PACK_SHRINK);

  m_label_right.set_justify(Gtk::JUSTIFY_RIGHT);
  m_frame_right.add(m_label_right);
  m_vbox.pack_start(m_frame_right, Gtk::PACK_SHRINK);

  m_hbox.pack_start(m_vbox2, Gtk::PACK_SHRINK);

  m_label_linewrapped.set_text(
    "This is an example of a line-wrapped label.  It "
    /* add a big space to the next line to test spacing */
    "should not be taking up the entire             "
    "width allocated to it, but automatically "
    "wraps the words to fit.  "
    "The time has come, for all good men, to come to "
    "the aid of their party.  "
    "The sixth sheik's six sheep's sick.\n"
    "     It supports multiple paragraphs correctly, "
    "and  correctly   adds "
    "many          extra  spaces. "
  );
  m_label_linewrapped.set_line_wrap();
  m_frame_linewrapped.add(m_label_linewrapped);
  m_vbox2.pack_start(m_frame_linewrapped, Gtk::PACK_SHRINK);

  m_label_filledwrapped.set_text(
    "This is an example of a line-wrapped, filled label.  "
    "It should be taking "
    "up the entire              width allocated to it.  "
    "Here is a sentence to prove "
    "my point.  Here is another sentence. "
    "Here comes the sun, do de do de do.\n"
    "    This is a new paragraph.\n"
    "    This is another newer, longer, better "
    "paragraph.  It is coming to an end, "
    "unfortunately."
  );
  m_label_filledwrapped.set_justify(Gtk::JUSTIFY_FILL);
  m_label_filledwrapped.set_line_wrap();
  m_frame_filledwrapped.add(m_label_filledwrapped);

  m_label_underlined.set_justify(Gtk::JUSTIFY_LEFT);
  m_label_underlined.set_pattern(
    "_________________________ _ _________ _ ______"
    "     __ _______ ___"
  );
  m_frame_underlined.add(m_label_underlined);
  m_vbox2.pack_start(m_frame_underlined, Gtk::PACK_SHRINK);

  show_all_children();
}

Labels::~Labels()
{}