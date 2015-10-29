#include <Qt/QtGui>
#include "./afficheur.h"
using namespace std;


int main( int argc, char **argv )
{
	// UTF-8 Encoding
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	
	QApplication app( argc, argv );
		QWidget w;
	QVBoxLayout *layoutW = new QVBoxLayout(&w); // Layout

	QTextEdit *affichage = new QTextEdit();
		affichage->setReadOnly(true);

	QString nomProg = "/home/etudiant/iRobot/bin/prog.exe";
	QStringList arg;
		arg.append("ch_avant");


	layoutW->addWidget(affichage);

	w.setMinimumSize(700,500);
	w.setWindowState(w.windowState() ^ Qt::WindowMaximized);
	w.show();

	QProcess *main = new QProcess();
		main->setReadChannel(QProcess::StandardOutput);

	afficheur *ui = new afficheur(affichage,main);
	
	QObject::connect(main,SIGNAL(finished( int, QProcess::ExitStatus)),ui,SLOT(affiche(int, QProcess::ExitStatus)));
		main->start(nomProg,arg);




	return app.exec();
}