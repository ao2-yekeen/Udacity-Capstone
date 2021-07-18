#include "notepad.h"
#include <QApplication>
#include <QLabel>
#include <future>
#include <QDebug>
#include <QString>


bool done = false;
int myAmount = 0;
std::mutex m;
std::condition_variable cv;
void Increment(){
    std::lock_guard<std::mutex> lg(m);
    myAmount++;
    done = true;
    cv.notify_one();

}
void Mission(){
    std::unique_lock<std::mutex> ul(m);
    done = true;
    cv.wait(ul,[] {return done;});
}

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QString message = "";
      // create promise and future
  std::promise<QString> prms;
  std::future<QString> ftr = prms.get_future();
  Notepad w;
  std::thread t1(Increment);
  std::thread t2(Increment);
  Thread mThread(std::move(w),std::move(prms));
  message = ftr.get();
  mThread.wait();
  t1.join();
  t2.join();

  qDebug() << myAmount << "\n";
  qDebug() << "condition variable is used:" << done << "\n";
  qDebug() << message;
 return a.exec();

}
