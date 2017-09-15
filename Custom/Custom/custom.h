#ifndef CUSTOM_H
#define CUSTOM_H

#include <QtWidgets/QMainWindow>
#include "ui_custom.h"
#include <QtGui>

class Custom : public QMainWindow
{
	Q_OBJECT
	QString** datas;
	char* argv;
	

public:
	Custom(char *pargv[],QWidget *parent = 0);
	Custom(QWidget *parent = 0);
	~Custom();
	void SetArgv(char *pargv[]);
	QVector<double> x, y;
	QVector<double> x2, y2;
	int TimeElapsed=0;
	QTimer* playBackTimer = new QTimer(this);
	int count_point;
	

private:
	Ui::CustomClass ui;
	private slots:
	void PaintGraph();
	void FirstParametr();
	void SecondParametr();
	void Export();
	void Exit();
	void Animate();
	//int count_point;
	

	
private slots:

    void PlaybackStep();
};

#endif // CUSTOM_H
