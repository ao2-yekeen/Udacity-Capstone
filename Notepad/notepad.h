#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include "QLabel"
#include <QtCore>


QT_BEGIN_NAMESPACE
namespace Ui { class Notepad; }
QT_END_NAMESPACE


class Notepad : public QMainWindow
{

    Q_OBJECT

public:

    // std::unique_ptr<QWidget> parent(new QWidget);
    // std::unique_ptr<int> unique(new int);

    Notepad(std::unique_ptr<QWidget> parent = nullptr);
    ~Notepad();

    Notepad(Notepad &&source) // 4 : move constructor
    {

       mouseX = source.mouseX;
       mouseY = source.mouseY;
       drawY = source.drawY;
       drawX = source.drawY;
       file_path = source.file_path;
       ui = source.ui;

       source.ui= nullptr;
       source.mouseX = 0;
       source.mouseY = 0;
       source.drawX = 0;
       source.drawY = 0;
       source.file_path = "";
    }

    Notepad(Notepad &source) // 4 : copy constructor
    {

       mouseX = source.mouseX;
       mouseY = source.mouseY;
       drawY = source.drawY;
       drawX = source.drawY;
       file_path = source.file_path;
       ui = source.ui;

       source.ui= nullptr;
       source.mouseX = 0;
       source.mouseY = 0;
       source.drawX = 0;
       source.drawY = 0;
       source.file_path = "";
    }

    Notepad &operator=(Notepad &&source) // 5 : move assignment operator
     {

         if (this == &source)
             return *this;

        // delete ui;

         mouseX = source.mouseX;
         mouseY = source.mouseY;
         drawY = source.drawY;
         drawX = source.drawY;
         file_path = source.file_path;
         ui = source.ui;

         source.ui= nullptr;
         source.mouseX = 0;
         source.mouseY = 0;
         source.drawX = 0;
         source.drawY = 0;
         source.file_path = "";

         return *this;
     }

    Notepad &operator=(Notepad &source) // 5 : copy assignment operator
     {

         if (this == &source)
             return *this;

         //delete ui;

         mouseX = source.mouseX;
         mouseY = source.mouseY;
         drawY = source.drawY;
         drawX = source.drawY;
         file_path = source.file_path;
         ui = source.ui;

         source.ui= nullptr;
         source.mouseX = 0;
         source.mouseY = 0;
         source.drawX = 0;
         source.drawY = 0;
         source.file_path = "";

         return *this;
     }

private slots: //slots are triggered when the user clicks the icons
    void on_actionAbout_Notepad_triggered();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();
    void on_actionOpen_triggered(std::shared_ptr<Ui::Notepad> ui); //Function Overloading
    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionRedo_triggered();

    void on_actionUndo_triggered();

private:

    std::shared_ptr<Ui::Notepad> ui;
    QString file_path;
  int mouseX;
  int mouseY;
    int drawX;
    int drawY;

protected:

    /*The most common aspects of GUI interaction you might want to take over are mouse, keyboard, or painting events.
     * QWidget has the following protected functions keyPressEvent, keyReleaseEvent, mousePressEvent, mouseMoveEvent,
     * mouseReleaseEvent, paintEvent. By overriding any of these protected functions, you can customize how the QWidget operates.*/
     void paintEvent(QPaintEvent *);
    // std::unique_ptr


  //std::shared_ptr<QMouseEvent> event(new QMouseEvent)
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);//Overide base class functions from the QWidget class

};


class Thread:public QThread{
public:
    Thread(Notepad && w,std::promise<QString> && prms);
       //Qthread has a public function run that is been overwritten by class Notepad
Notepad j;
};
#endif // NOTEPAD_H
