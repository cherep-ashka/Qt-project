#include "custom.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Custom w(argv);
	w.show();
	return a.exec();
}
