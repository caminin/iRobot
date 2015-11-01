#include <Qt/QtGui>
#include <cstdio>
#include <iostream>
using namespace std;

class afficheur : public QObject
{
Q_OBJECT
private slots:
	void affiche();
	void runAvant();
	void runArriere();

public:
	afficheur(QTextEdit *, QTextEdit *, QTextEdit *, QSpinBox*, QProcess *);
	~afficheur();

private:
	QTextEdit *gen;
	QProcess *proc;
	QTextEdit *reg;
	QTextEdit *fait;
	QSpinBox *spin;
};
