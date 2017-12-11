#include "combobox.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.combobox.example");

    ComboBox window;

    return app->run(window);
}