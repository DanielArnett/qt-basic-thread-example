#ifndef WORKER_H
#define WORKER_H
#include <QtCore>

class Worker: public QThread
{
public:
    Worker();
    void run() Q_DECL_OVERRIDE;
    void setInput(int newInput);
    int getInput();
    void stop();
    const int MaxInt = 2147483647;
private:
    bool haltFlag = false;
    QMutex inputMutex;
    int input;

};

#endif // WORKER_H
