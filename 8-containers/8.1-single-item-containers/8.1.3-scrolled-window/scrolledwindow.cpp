#include "scrolledwindow.h"
#include <iostream>

ScrolledWindow::ScrolledWindow()
{
  set_title("Gtk::ScrolledWindow");
  set_border_width(10);
  set_size_request(300, 300);

  window.set_border_width(10);

  /* 
   * The policy is one of Gtk::POLICY AUTOMATIC, or Gtk::POLICY_ALWAYS.
   * Gtk::POLICY_AUTOMATIC will automatically decide whether you need
   * scrollbars, whereas Gtk::POLICY_ALWAYS will always leave the scrollbars
   * there.  The first one is the horizontal scrollbar, the second,
   * the vertical.
   */
  window.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_ALWAYS);
  get_content_area()->pack_start(window);

  grid.set_row_spacing(10);
  grid.set_column_spacing(10);
  window.add(grid);

  /* Generate a grid of buttons */
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      char buffer[32];

      sprintf(buffer, "Button (%d,%d)\n", i, j);

      auto btn = Gtk::manage(new Gtk::ToggleButton(buffer));

      grid.attach(*btn, i, j, 1, 1);
    }
  }

  /* Add a close button */
  add_button("_Close", Gtk::RESPONSE_CLOSE);
  signal_response().connect(sigc::mem_fun(*this, &ScrolledWindow::on_dialog_response));
  set_default_response(Gtk::RESPONSE_CLOSE);

  show_all_children();
}

ScrolledWindow::~ScrolledWindow()
{
}

void ScrolledWindow::on_dialog_response(int id)
{
  switch (id)
  {
    case Gtk::RESPONSE_CLOSE:
    case Gtk::RESPONSE_DELETE_EVENT:
      hide();
      break;
    default:
      std::cout << "Unexpected response id: " << id << std::endl;
  }
}