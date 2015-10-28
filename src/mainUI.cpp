#include <Qt/QtGui>

int main( int argc, char **argv )
{
	QApplication app( argc, argv );
		QWidget w;
	QVBoxLayout *layoutW = new QVBoxLayout(&w); // Layout

	
	w.setMinimumSize(700,500);
	w.setWindowState(w.windowState() ^ Qt::WindowMaximized);
	w.show();

	return app.exec();
}