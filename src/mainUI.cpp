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
						QWidget *woptions = new QWidget(wdroite);
						
							QHBoxLayout *Boptions = new QHBoxLayout(woptions); 	
								QWidget *wboutons = new QWidget(woptions);
									QVBoxLayout *Bboutons = new QVBoxLayout(wboutons);
										QPushButton *lanceAvant = new QPushButton("Lancer le chainage avant", wdroite);
										QPushButton *lanceArriere = new QPushButton("Lancer le chainage arrière", wdroite);
								QWidget *wintervalle = new QWidget(woptions);
									QVBoxLayout *Bintervalle = new QVBoxLayout(wintervalle);
										QLabel *labelIntervalle = new QLabel("Intervalle des étapes (en secondes):", wintervalle);
										QSpinBox *intervalle = new QSpinBox(wintervalle);
					
		intervalle->setValue(2);
		intervalle->setMinimum(0);

		affichage->setText("");
		affichage->setReadOnly(true);

		regle->setText("");
		regle->setReadOnly(true);

		fait->setText("");
		fait->setReadOnly(true);


	QProcess *main = new QProcess();
		main->setReadChannel(QProcess::StandardOutput);

	afficheur *ui = new afficheur(affichage,regle,fait,intervalle,main);
	
	QObject::connect(main,SIGNAL(readyReadStandardOutput()),ui,SLOT(affiche()));
	QObject::connect(lanceAvant,SIGNAL(clicked()),ui,SLOT(runAvant()));	
	QObject::connect(lanceArriere,SIGNAL(clicked()),ui,SLOT(runArriere()));	

	Bintervalle->addWidget(labelIntervalle);
	Bintervalle->addWidget(intervalle);

	Bboutons->addWidget(lanceAvant);
	Bboutons->addWidget(lanceArriere);

	Boptions->addWidget(wboutons);
	Boptions->addWidget(wintervalle);

	Bregle->addWidget(labelRegle);
	Bregle->addWidget(regle);
	Bregle->addWidget(woptions);
	etatActuel->addWidget(wregle);

	Bfait->addWidget(labelFait);
	Bfait->addWidget(fait);
	etatActuel->addWidget(wfait);

	droite->addWidget(etatActuel);

	general->addWidget(affichage);
	general->addWidget(wdroite);
	general->setStretchFactor(0,2);

	layoutH->addWidget(general);

	w.setMinimumSize(700,500);
	w.setWindowState(w.windowState() ^ Qt::WindowMaximized);
	w.show();

	return app.exec();
}