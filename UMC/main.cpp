#include "umc.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	UMC w;
	w.show();
	return a.exec();
}
