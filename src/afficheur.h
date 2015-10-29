#ifndef AFFICHEUR_H
#define AFFICHEUR_H
#include <Qt/QtGui>
#include <cstdio>
#include <iostream>

class afficheur : public QObject
{
Q_OBJECT
private slots:
	void affiche( int exitCode, QProcess::ExitStatus exitStatus);

public:
	afficheur(QTextEdit *, QProcess *);
	~afficheur();

private:
	QTextEdit *te;
	QProcess *proc;
};

#endif