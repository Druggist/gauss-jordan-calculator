#ifndef GAUSS_JORDAN_H
#define GAUSS_JORDAN_H

//#include "mpreal.h"
#include <QObject>
#include <QString>
#include <QStringList>
#include <vector>

#include <QDebug>

using std::vector;
//using mpfr::mpreal;

class GaussJordan : public QObject {

    Q_OBJECT
public:
    explicit GaussJordan(QObject *parent = 0);
    Q_INVOKABLE void pass_data(QString);
    Q_INVOKABLE QString results_standard();
    Q_INVOKABLE QString results_interval();

private:
    vector<vector<double>> sMatrix;
    //vector<vector<vector<mpreal>>> iMatrix;
    vector<vector<int>> permutations;
    bool iComputed = false, sComputed = false;
    bool load_data(QString);
    void compute_standard();
    void compute_interval();
};

#endif // GAUSS_JORDAN_H
