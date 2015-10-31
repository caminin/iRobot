#include "../include/afficheur.hpp"

afficheur::afficheur(QTextEdit *g, QTextEdit *r, QTextEdit *f, QProcess *p)
: gen(g), reg(r), fait(f), proc(p)
{}

afficheur::~afficheur()
{}

void afficheur::affiche()
{
	QString s(proc->readAllStandardOutput().data());
	QStringList lignes(s.split("\n"));
	fait->setText("");
	for (int i = 0; i < lignes.size(); ++i)
	{
		if (lignes[i].startsWith("|"))
			fait->append(lignes[i]);
		else
			gen->append(s);
	}
}