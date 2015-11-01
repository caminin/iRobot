#include <Qt/QtGui>
#include <cstdio>
#include <iostream>

class afficheur : public QObject
{
Q_OBJECT
private slots:
	void affiche();
	void run();

public:
	afficheur(QTextEdit *, QTextEdit *, QTextEdit *, QProcess *);
	~afficheur();

private:
	QTextEdit *gen;
	QProcess *proc;
	QTextEdit *reg;
	QTextEdit *fait;
};
