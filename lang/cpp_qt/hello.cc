#include <QtGui/QtGui>

int
main (int argc, char **argv)
{
	/* Can't omit this line */
	QApplication app(argc, argv);
	QWidget *window = new QWidget;
	window->setWindowTitle("Qt4 Hello");
	
	QLabel *label = new QLabel(
		"<h2><font color='red'>Hello</font>, world!<h2>");
	QPushButton *button = new QPushButton("&Quit");
	QSpinBox *spinBox = new QSpinBox;
	QSlider *slider = new QSlider(Qt::Horizontal);
	QTextEdit *textedit = new QTextEdit;
	QVBoxLayout *layout = new QVBoxLayout;
	QCheckBox *checkbox = new QCheckBox("&Checkbox");
	QCheckBox *checkbox2 = new QCheckBox("Checkbox2");

	QObject::connect(button, SIGNAL(clicked()), &app, SLOT(quit())); 
	QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox,
		SLOT(setValue(int)));
	QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider,
		SLOT(setValue(int)));
	QObject::connect(checkbox, SIGNAL(stateChanged(int)), textedit,
		SLOT(clear()));

	spinBox->setRange(0,130);
	slider->setRange(0,130);
	spinBox->setValue(35);

	layout->addWidget(spinBox);
	layout->addWidget(slider);
	layout->addWidget(label);
	layout->addWidget(button);
	layout->addWidget(textedit);
	layout->addWidget(checkbox);
	layout->addWidget(checkbox2);
	window->setLayout(layout);

	window->show();

	/* Enter into loop */
	return app.exec();
}
