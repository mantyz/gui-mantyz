#include <gtkmm.h>
#include <iostream>

using std::cerr;
using std::endl;

Gtk::Dialog* pDialog = nullptr;

static void on_button_clicked()
{
	if(pDialog)
	{
		pDialog->hide();
	}
}

int main(int argc, char *argv[])
{
	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

	auto refBuilder = Gtk::Builder::create();
	try
	{
		refBuilder->add_from_file("test.glade");
	}
	catch(const Glib::FileError& ex)
	{
		cerr << "FileError: " << ex.what() << endl;
		return 1;
	}
	catch(const Glib::MarkupError& ex)
	{
		cerr << "MarkupError: " << ex.what() << endl;
		return 1;
	}
	catch(const Gtk::BuilderError& ex)
	{
		cerr << "BuilderError: " << ex.what() << endl;
		return 1;
	}

	refBuilder->get_widget("DialogBasic", pDialog);
	if (pDialog)
	{
		Gtk::Button* pButton = nullptr;
		refBuilder->get_widget("quit_button", pButton);
		if (pButton)
		{
			pButton->signal_clicked().connect(sigc::ptr_fun(&on_button_clicked));
		}

		app->run(*pDialog);
	}

	delete pDialog;

	return 0;
}
