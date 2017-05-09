#ifndef GAUSS_JORDAN_H
#define GAUSS_JORDAN_H

#include "interval.h"
#include <QObject>
#include <QString>
#include <QPoint>
#include <QStringList>
#include <vector>
#include <algorithm>
#include <cmath>

#include <QDebug>

using std::vector;
using interval_arithmetic::Interval;

class GaussJordan : public QObject {

    Q_OBJECT
public:
    explicit GaussJordan(QObject *parent = 0, int = 15);
    Q_INVOKABLE void pass_data(QString);
    Q_INVOKABLE QString results_standard();
    Q_INVOKABLE QString results_interval();
    Q_INVOKABLE QString print_sMatrix();
    Q_INVOKABLE QString print_iMatrix();

private:
    int precision;
    vector<vector<double>> sMatrix;
    vector<vector<Interval<double>>> iMatrix;
    vector<unsigned int> sColumns, iColumns;
    bool iComputed = false, sComputed = false;
    bool load_data(QString);
    void compute_standard();
    void compute_interval();
    QPoint maxElement(bool, int n = 0);

};

#endif // GAUSS_JORDAN_H
