#include <gtkmm.h>

int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

  Gtk::Window window;
<<<<<<< HEAD
  window.set_default_size(200, 300);
=======
  window.set_default_size(300, 300);
>>>>>>> f7d8a432c9876c36f82a05e7ecb7b056d9c6bba0

  return app->run(window);
}
