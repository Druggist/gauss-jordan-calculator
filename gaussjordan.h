#ifndef GAUSS_JORDAN_H
#define GAUSS_JORDAN_H

//#include "mpreal.h"
#include <QObject>
#include <QString>
#include <QPoint>
#include <QStringList>
#include <vector>
#include <algorithm>

#include <QDebug>

using std::vector;
//using mpfr::mpreal;

class GaussJordan : public QObject {

    Q_OBJECT
public:
    explicit GaussJordan(QObject *parent = 0, int = 15);
    Q_INVOKABLE void pass_data(QString);
    Q_INVOKABLE QString results_standard();
    Q_INVOKABLE QString results_interval();
    Q_INVOKABLE QString print_sMatrix();
    Q_INVOKABLE QString print_iMatrix();
    Q_INVOKABLE QString print_permutations();

private:
    int precision;
    vector<vector<double>> sMatrix;
    //vector<vector<vector<mpreal>>> iMatrix;
    vector<vector<int>> permutations;
    bool iComputed = false, sComputed = false;
    bool load_data(QString);
    void compute_standard();
    void compute_interval();
    QPoint maxElement(bool, int n = 0);

};

#endif // GAUSS_JORDAN_H
