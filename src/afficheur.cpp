#include "../include/afficheur.hpp"

afficheur::afficheur(QTextEdit *g, QTextEdit *r, QTextEdit *f, QProcess *p)
: gen(g), reg(r), fait(f), proc(p)
{}

afficheur::~afficheur()
{}

void afficheur::run()
{
	QString nomProg = "/home/etudiant/iRobot/bin/prog.exe";
	QStringList arg;
		arg.append("ch_arriere");
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