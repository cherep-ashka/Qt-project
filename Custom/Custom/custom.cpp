#include "custom.h"
#include <stdlib.h> 

#include <QApplication>
#include <QtWidgets/QMainWindow>





Custom::Custom(char *pargv[], QWidget *parent)
	: QMainWindow(parent)
{
	SetArgv(pargv);

	ui.setupUi(this);
	// инициализация слотов
	connect(playBackTimer, SIGNAL(timeout()), this, SLOT(PlaybackStep()));
	connect(ui.paint, SIGNAL(clicked()), this, SLOT(PaintGraph()));
	connect(ui.exp, SIGNAL(clicked()), this, SLOT(Export()));
	connect(ui.exit, SIGNAL(clicked()), this, SLOT(Exit()));
	connect(ui.animation, SIGNAL(clicked()), this, SLOT(Animate()));
	connect(ui.comboBox_1, SIGNAL(currentIndexChanged(QString)), SLOT(FirstParametr()));
	connect(ui.comboBox_2, SIGNAL(currentIndexChanged(QString)), SLOT(SecondParametr()));
	connect(ui.spinBox, SIGNAL(valueChanged(int)), SLOT(setValue(int)));
	

	QString stroka;

	QFile qwerty("Disloc1.txt");
	QTextStream str(&qwerty);
	qwerty.open(QIODevice::ReadOnly | QIODevice::Text);

	QString str_all = str.readAll();
	QStringList rows = str_all.split('\n'); //строка как элемент массива

	datas = new QString*[rows.count()];
	int count_col = (rows[0].split(QRegExp("\\s+"))).count() - 1; //подсчет количества элементов в строке
	count_row = rows.count(); //подсчет количества строк
	QStringList local_str;
	for (int i = 0; i<count_row - 1; i=i++) //пока строки не закончились
	{
		datas[i] = new QString[count_col]; //создание массивов, размерность каждого из которых равна количеству элементов в строке
		local_str = rows[i].split(QRegExp("\\s+")); //разбиение каждой строки на элементы (столбцы)

		for (int j = 0; j<count_col; j++) //пока элементы строки не закончились
		{
			datas[i][j] = local_str[j]; //запись всех элементов в общий массив построчно, где i-позиция строки, j-позиция столбца
		}

	}


	QTextDecoder *decoder = QTextCodec::codecForName("CP1251")->makeDecoder(QTextCodec::IgnoreHeader);


	ui.comboBox_1->addItem(decoder->toUnicode("Время, с"));
	ui.comboBox_1->addItem(decoder->toUnicode("Кинетич.энергия, Дж"));
	ui.comboBox_1->addItem(decoder->toUnicode("Радиус, м"));
	ui.comboBox_1->addItem(decoder->toUnicode("Скорость, м/с"));

	ui.comboBox_2->addItem(decoder->toUnicode("Время, с"));
	ui.comboBox_2->addItem(decoder->toUnicode("Кинетич.энергия, Дж"));
	ui.comboBox_2->addItem(decoder->toUnicode("Радиус, м"));
	ui.comboBox_2->addItem(decoder->toUnicode("Скорость, м/с"));


	
}



Custom::Custom(QWidget *parent)
	: QMainWindow(parent)
{

	
}




void Custom::Exit()
{
	this->close();
}

void Custom::PaintGraph()
{
	int k = 0;
	playBackTimer->stop();
	x.clear();
	y.clear();

	//заполнение массивов данными из файла (старое)
	for (int i = 0; i<count_row - 1; i=i++)
	{
		x.push_back(datas[i][p].toDouble());
		y.push_back(datas[i][v].toDouble());
	}

	//поиск макс и мин значений переменных
	max_x = x[1], max_y = y[1];
	for (int h = 2; h < x.size(); ++h)
	{
		if (max_x < x[h])
			max_x = x[h];

		if (max_y < y[h])
			max_y = y[h];
	}

	// создаем график и добавляем данные:
	ui.widget->addGraph();
	ui.widget->graph(0)->setData(x, y);
	// задаем имена осей координат
	int index1 = ui.comboBox_1->currentIndex();
	if (index1 == 0)
		ui.widget->xAxis->setLabel("t, C");
	if (index1 == 1)
		ui.widget->xAxis->setLabel("ε, Дж");
	if (index1 == 2)
		ui.widget->xAxis->setLabel("r, M");
	if (index1 == 3)
		ui.widget->xAxis->setLabel("V, M/C");

	int index2 = ui.comboBox_2->currentIndex();
	if (index2 == 0)
		ui.widget->yAxis->setLabel("t, C");
	if (index2 == 1)
		ui.widget->yAxis->setLabel("ε, Дж");
	if (index2 == 2)
		ui.widget->yAxis->setLabel("r, M");
	if (index2 == 3)
		ui.widget->yAxis->setLabel("V, M/C");


	// задаем размеры осей
	ui.widget->xAxis->setRange(0, max_x);
	ui.widget->yAxis->setRange(0, max_y);
	ui.widget->replot();
}


void Custom::Animate()
{
	/*x.clear();
	y.clear();
	for (int i = 0; i<count_row - 1; i=i+10)
	{
		x.push_back(datas[i][p].toDouble());
		y.push_back(datas[i][v].toDouble());
	}

	max_x = x[1];
	max_y = y[1];
	for (int h = 2; h < x.size(); ++h)
	{
		if (max_x < x[h])
			max_x = x[h];

		if (max_y < y[h])
			max_y = y[h];
	}*/

	//определение ширины экрана
	QDesktopWidget *d = QApplication::desktop();
	int cur_x = d->width();
	int count_intv = cur_x/5 - 1;

	//поиск макс и мин значений переменных
	max_x = x[1], max_y = y[1];
	double min_x = x[1], min_y = y[1];
	for (int h = 2; h < x.size(); ++h)
	{
		if (max_x < x[h])
			max_x = x[h];

		if (max_y < y[h])
			max_y = y[h];

		if (min_x > x[h])
			min_x = x[h];

		if (min_y > y[h])
			min_y = y[h];
	}

	//определение длины интервала/шага
	float length_intv = (max_x - min_x) / count_intv;

	//создание массива размерностью, равной ширине экрана
	//double x_next = new double[cur_x];
	
	/*double x_last = x[1];
	double y_last = y[1];
	double x_next = x[2];
	double y_next = y[2];*/
	double x_zvezda = x[1] + length_intv;
	double y_zvezda;

	x_animation.clear();
	y_animation.clear();
	x_animation.push_back(x[1]);
	y_animation.push_back(y[1]);
	//определение граничных x
	for (int h = 2; h < x.size(); ++h)
	{
		if (x[h] > x_zvezda) {
			y_zvezda = y[h-1] + ((y[h] - y[h-1]) / (x[h] - x[h-1]))*(x_zvezda - x[h-1]);
			//проверить, а не является (хзвезда, узвезда) точкой макс или мин)
			x_animation.push_back(x_zvezda);
			y_animation.push_back(y_zvezda);
			//сохранение мин
			//сохранение макс
			x_zvezda += length_intv;
		}
		else
		{
		
		}

		/*x_last = x_next;
		y_last = y_next;
		x_next = x[h];
		y_next = y[h];*/
	}
	x_animation.push_back(x[x.size() - 1]);
	y_animation.push_back(y[y.size() - 1]);

	x2.clear();
	y2.clear();

	//int sp = ui.spinBox->value;
	playBackTimer->start(ui.spinBox->value());
	ui.widget->addGraph();
	count_point = 1;
}



void Custom::PlaybackStep()
{

	if (x_animation.size() == count_point) {
		playBackTimer->stop(); 
		return;
	}
	//TimeElapsed += 50; // 50 - частота срабатывания таймера (в мс)
	/*x2.clear();
	y2.clear();*/
	//for (int i = 0; i < count_point; i++)
	//{
		//if (TimeElapsed >= x[i])
		//{
			x2.push_back(x_animation[count_point-1]);
			y2.push_back(y_animation[count_point-1]);
			/*x.pop_front();
			y.pop_front();*/
			//i = 0; // если во временном промежутке несколько подходящих "точек", то после pop_front() мы можем
				   // упустить одну. i = 0 запускает заново цикл, чтобы ничего "не потерять"
		//}
	//}
	++count_point;
	
	ui.widget->graph(0)->setData(x2, y2);
	//end of playback check
	ui.widget->xAxis->setRange(0, max_x);
	ui.widget->yAxis->setRange(0, max_y);
	//
	ui.widget->replot();

}

void Custom::FirstParametr()
{
	int index = ui.comboBox_1->currentIndex();
	if (index == 0)
		p = 0;
	if (index == 1)
		p = 1;
	if (index == 2)
		p = 2;
	if (index == 3)
		p = 3;
}


void Custom::SecondParametr()
{
	int index = ui.comboBox_2->currentIndex();
	if (index == 0)
		v = 0;
	if (index == 1)
		v = 1;
	if (index == 2)
		v = 2;
	if (index == 3)
		v = 3;
}

void Custom::Export()
{
	QString fileName = QFileDialog::getSaveFileName(this,
		tr("Choose a filename to save under"),
		QString(),
		tr("PNG(*.png);;JPG(*.jpg);;PDF(*.pdf);;BMP(*.bmp);;All Files(*)")
	);
	if (!fileName.isEmpty())
	{
		if (fileName.endsWith(".png", Qt::CaseInsensitive))
		{
			ui.widget->savePng(fileName);
		}
		else if (fileName.endsWith(".jpg", Qt::CaseInsensitive))
		{
			ui.widget->saveJpg(fileName);
		}
		else if (fileName.endsWith(".pdf", Qt::CaseInsensitive))
		{
			ui.widget->savePdf(fileName);
		}
		else if (fileName.endsWith(".bmp", Qt::CaseInsensitive))
		{
			ui.widget->saveBmp(fileName);
		}
		else
		{
			fileName += ".png";
			ui.widget->savePng(fileName);
		}
	}
}

void Custom::SetArgv(char *pargv[])
{
	size_t len = strlen(/*pargv[1]*/"Disloc1.txt");
	argv = (char*)malloc(len + 1);
	if (argv == NULL)
	{
		/* allocation failed */
	}
	strcpy(argv, /*pargv[1]*/"Disloc1.txt");
}


Custom::~Custom()
{

}

