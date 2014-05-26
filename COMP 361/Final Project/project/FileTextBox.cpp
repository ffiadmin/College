#include "FileTextBox.h"


FileTextBox::FileTextBox(QWidget* parent): QLineEdit(parent)
{
}


FileTextBox::~FileTextBox(void)
{
}
		
void FileTextBox::buttonInput(void)
{
	emit sendFilename(text().toStdString());
}