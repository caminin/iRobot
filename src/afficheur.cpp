#include "./afficheur.h"

afficheur::afficheur(QTextEdit *ten, QProcess *p)
: te(ten), proc(p)
{}

afficheur::~afficheur()
{}

void afficheur::affiche( int exitCode, QProcess::ExitStatus exitStatus)
{
	QString s(proc->readAllStandardOutput().data());
	te->setText(s);
}