#include "app.h"

int main(int argc, char* argv[])
{
  auto app = App::create();

  return app->run(argc, argv);
}