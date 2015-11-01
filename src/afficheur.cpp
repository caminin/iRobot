#include "../include/afficheur.hpp"



afficheur::afficheur(QTextEdit *g, QTextEdit *r, QTextEdit *f,QSpinBox *s, QProcess *p)
: gen(g), reg(r), fait(f), spin(s), proc(p)
{}

afficheur::~afficheur()
{}

void afficheur::runAvant()
{
	gen->setText("");
	reg->setText("");
	fait->setText("");
	QString nomProg = "/home/etudiant/iRobot/bin/prog.exe";
	QStringList arg;
		arg.append("ch_avant");
		arg.append(QString::number(spin->value()));
	proc->start(nomProg,arg);
}

void afficheur::runArriere()
{
	gen->setText("");
	reg->setText("");
	fait->setText("");
	QString nomProg = "/home/etudiant/iRobot/bin/prog.exe";
	QStringList arg;
		arg.append("ch_arriere");
		arg.append(QString::number(spin->value()));	
	proc->start(nomProg,arg);
}

void afficheur::affiche()
{
	QString s(proc->readAllStandardOutput().data());
	QStringList lignes(s.split("\n"));
	for (int i = 0; i < lignes.size(); ++i)
	{
		if (lignes[i].startsWith("|"))
			fait->append(lignes[i].remove(0,1));
		else
			if (lignes[i].startsWith(";"))
				reg->append(lignes[i].remove(0,1));
			else
				if (lignes[i].startsWith(">"))
				{		
					gen->append(lignes[i]);
				}
				else
					gen->append(lignes[i]);
	}
}