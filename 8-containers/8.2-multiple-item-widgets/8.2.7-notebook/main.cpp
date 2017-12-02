#include "notebook.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.notebook.example");

    Notebook window;

    return app->run(window);
}