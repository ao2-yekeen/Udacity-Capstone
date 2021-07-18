#include "notepad.h"
#include "ui_notepad.h"
#include "QFile"
#include "QFileDialog"
#include "QTextStream"
#include "QMessageBox"
#include "QMouseEvent"
#include "QPainter"
#include "QKeyEvent"

Thread::Thread(Notepad &&w,std::promise<QString> && prms){
 w.show();
 prms.set_value("I have used promise and future in my application");
}


Notepad::Notepad(std::unique_ptr<QWidget> parent ): QMainWindow(parent.get()), ui(new Ui::Notepad)  //RAII (memory allocation of new ui class)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);


    this->setMouseTracking(true); //this is required to read mouseMoveEvent xy-position
    ui->centralwidget->setMouseTracking(true); //have to set both ways in order to work properly, dont know why

    //always initialize your custom variables
    mouseX = 0;
    mouseY = 0;
    drawX = 0;
    drawY = 0;

}


void Notepad::mouseMoveEvent(QMouseEvent *event)
{
   mouseX = event->x();
   mouseY = event->y();
   this->update(); //add the instruction to repaint the widget to a list of paint instructions
}

void Notepad::paintEvent(QPaintEvent *)
{                                          /*This function allows that a red box appear when u point the cursor at the toolbars*/
   QPainter painter(this);
   painter.fillRect(QRect(mouseX,mouseY,80,80), QColor(Qt::red));
   painter.end();
}

Notepad::~Notepad()
{
      //RAII  (memory deallocation)
}

void Notepad::keyPressEvent(QKeyEvent *event){   /*This function allows you to use the arrow keys to move the position of the cursor in the application*/
    switch (event->key()){
    case (Qt::Key_Left):
        drawX--;
        break;
      case (Qt::Key_Right):
        drawX++;
        break;
      case (Qt::Key_Up):
        drawY--;
        break;
      case (Qt::Key_Down):
        drawY++;
        break;
    }
    this->update();
}

template <typename T>
T sendText(T a) {    //Use of function templates

    std::unique_ptr<int> unique(new int); // create a unique pointer on the stack
    *unique = 2;
    return a;
}

void Notepad::on_actionAbout_Notepad_triggered()
{
  QString about_text;
  about_text = "Author : Yekeen Abdulbasit\n";
  about_text+="Date : 14/07/2021\n";
  about_text += "(C) Notepad (R)";


  QMessageBox::about(this,"About Notepad",sendText(about_text));
}


void Notepad::on_actionNew_triggered()
{
    file_path = "";
    ui->textEdit->setText("");
}


void Notepad::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open the File");
    QFile file(file_name);
    file_path = file_name;
    if(!file.open(QFile::ReadOnly| QFile::Text)){
        QMessageBox::warning(this,"..","file not open");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void Notepad::on_actionOpen_triggered(std::shared_ptr<Ui::Notepad> ui)
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open the File");
    QFile file(file_name);
    file_path = file_name;
    if(!file.open(QFile::ReadOnly| QFile::Text)){
        QMessageBox::warning(this,"..","file not open");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void Notepad::on_actionSave_triggered()
{

    QFile file(file_path);
    if(!file.open(QFile::WriteOnly| QFile::Text)){
        QMessageBox::warning(this,"..","file not open");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}


void Notepad::on_actionSave_as_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this,"Open the File");
    QFile file(file_name);
    if(!file.open(QFile::WriteOnly| QFile::Text)){
        QMessageBox::warning(this,"..","file not open");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}


void Notepad::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void Notepad::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void Notepad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void Notepad::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void Notepad::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

