#include <Qt/QtGui>
#include "../include/afficheur.hpp"
using namespace std;


int main( int argc, char **argv )
{
	// UTF-8 Encoding
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	
	QApplication app( argc, argv );
	
	QWidget w;
	QHBoxLayout *layoutH = new QHBoxLayout(&w); // Layout
		
		QSplitter *general = new QSplitter(Qt::Horizontal,&w);

		QTextEdit *affichage = new QTextEdit(&w);
		QWidget *wdroite = new QWidget(&w);
			QVBoxLayout *droite = new QVBoxLayout(wdroite);
			QSplitter *etatActuel = new QSplitter(Qt::Vertical,wdroite);
				QWidget *wregle = new QWidget(wdroite);
					QVBoxLayout *Bregle = new QVBoxLayout(wregle);
						QLabel *labelRegle = new QLabel("Base de règle:");
						QTextEdit *regle = new QTextEdit(wregle);
				
				QWidget *wfait = new QWidget(wdroite);
					QVBoxLayout *Bfait = new QVBoxLayout(wfait);
						QLabel *labelFait = new QLabel("Base de fait:");
						QTextEdit *fait = new QTextEdit(wdroite);
						QPushButton *lance = new QPushButton("Lancer", wdroite);
	
		affichage->setText("");
		affichage->setReadOnly(true);

		regle->setText("");
		regle->setReadOnly(true);

		fait->setText("");
		fait->setReadOnly(true);

	QString nomProg = "/home/etudiant/iRobot/bin/prog.exe";
	QStringList arg;
		arg.append("ch_avant");


	QProcess *main = new QProcess();
		main->setReadChannel(QProcess::StandardOutput);

	afficheur *ui = new afficheur(affichage,regle,fait,main);
	
	QObject::connect(main,SIGNAL(readyReadStandardOutput()),ui,SLOT(affiche()));
	QObject::connect(lance,SIGNAL(clicked()),ui,SLOT(run()));	



	Bregle->addWidget(labelRegle);
	Bregle->addWidget(regle);
	Bregle->addWidget(lance);
	etatActuel->addWidget(wregle);

	Bfait->addWidget(labelFait);
	Bfait->addWidget(fait);
	etatActuel->addWidget(wfait);

	droite->addWidget(etatActuel);

	general->addWidget(affichage);
	general->addWidget(wdroite);

	layoutH->addWidget(general);

	w.setMinimumSize(700,500);
	w.setWindowState(w.windowState() ^ Qt::WindowMaximized);
	w.show();

	return app.exec();
}