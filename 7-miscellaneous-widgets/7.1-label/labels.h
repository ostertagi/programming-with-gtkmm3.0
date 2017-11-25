#ifndef GTKMM_LABELS_H
#define GTKMM_LABELS_H

#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/frame.h>
#include <gtkmm/label.h>

class Labels : public Gtk::Window
{
  public:
    Labels();
    virtual ~Labels();

  protected:
    Gtk::Box 
      m_hbox, 
      m_vbox, 
      m_vbox2;
    Gtk::Frame
      m_frame_normal, 
      m_frame_multi, 
      m_frame_left,
      m_frame_right,
      m_frame_linewrapped,
      m_frame_filledwrapped,
      m_frame_underlined;
    Gtk::Label
      m_label_normal,
      m_label_multi,
      m_label_left,
      m_label_right,
      m_label_linewrapped,
      m_label_filledwrapped,
      m_label_underlined;
};

#endif