#ifndef FISHES_H
#define FISHES_H

#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class FisheSData;

class FisheS
{
    Q_OBJECT
public:
    FisheS();
    FisheS(const FisheS &);
    FisheS &operator=(const FisheS &);
    ~FisheS();

private:
    QSharedDataPointer<FisheSData> data;
};

#endif // FISHES_H
