#include "gaussjordan.h"

GaussJordan::GaussJordan(QObject *parent, int precision) : QObject(parent) {
    this->precision = precision;
}

void GaussJordan::pass_data(QString data) {
    if(load_data(data)){
        compute_standard();
        //compute_interval();
    }
}

bool GaussJordan::load_data(QString data) {
    sMatrix.erase(sMatrix.begin(),sMatrix.end());
    //iMatrix.erase(iMatrix.begin(),iMatrix.end());

    QRegExp rx("(\\ |\\t|\\n|\\+)");
    data.replace(rx,"");

    rx.setPattern("((((\\-)?[0-9]+(\\.)?[0-9]*_)*((\\-)?[0-9]+(\\.)?[0-9]*)\\=((\\-)?[0-9]+(\\.)?[0-9]*)\\;)+)");
    if(!rx.exactMatch(data)) return false;



    rx.setPattern("(\\;)");
    QStringList query = data.split(rx);

    rx.setPattern("(\\_|\\=)");

    unsigned int n = query.size() - 1;

    for (unsigned int i = 0; i < n; i++) {
        vector<double> sRow;
        QStringList values = query.at(i).split(rx);

        for(int j = 0; j < values.size();j++) {
            sRow.push_back(values.at(j).toDouble());
        }
        if(sRow.size() != n + 1) {
            sMatrix.erase(sMatrix.begin(),sMatrix.end());
            return false;
        }
        sMatrix.push_back(sRow);
    }

    return true;
}

QString GaussJordan::results_standard() {
    if(!sComputed) return "Results has not been computed yet!";

    QString result;

    for(unsigned int i = 0; i < sMatrix.size(); i++){
       result += "X" + QString::number(i) + " = " + QString::number(sMatrix[i][i],'f', this->precision) + "\n";
    }

    return result;
}

QString GaussJordan::results_interval() {
    if(!iComputed) return "Results has not been computed yet!";

    QString result;
    /*
    for(unsigned int i = 0; i < sMatrix.size(); i++){
       result += "X" + QString::number(i) + " = " + QString::number(sMatrix[i][i],'f', this->precision) + "\n";
    }*/

    return result;
}

QString GaussJordan::print_sMatrix()
{
    QString text = "Standard Matrix:\n";

    for(unsigned int i = 0; i < sMatrix.size(); i++){
       for(unsigned int j = 0; j < sMatrix[i].size(); j++) text += ((j == sMatrix[i].size() - 1) ? "|  " : "") + QString::number(sMatrix[i][j],'f', this->precision) + "\t";
       text += "\n";
    }

    return text;
}

QString GaussJordan::print_iMatrix()
{
    QString text = " Interval Matrix:\n";

   /* for(unsigned int i = 0; i < permutations.size(); i++){
       for(unsigned int j = 0; j < permutations[i].size(); j++) text += QString::number(permutations[i][j]) + "\t";
       text += "\n";
    }*/

    return text;
}

QString GaussJordan::print_permutations()
{
    QString text = " Permutation Matrix:\n";

    for(unsigned int i = 0; i < permutations.size(); i++){
       for(unsigned int j = 0; j < permutations[i].size(); j++) text += QString::number(permutations[i][j]) + "\t";
       text += "\n";
    }

    return text;
}

void GaussJordan::compute_standard() {
    for(unsigned int i = 0; i < sMatrix.size(); i++) {
        QPoint firstElement = maxElement(true, i);
        //swap rows
        if(firstElement.x() != i) sMatrix[i].swap(sMatrix[firstElement.x()]);
        //swap columns
        if(firstElement.y() != i) for(unsigned int j = 0; j < sMatrix.size(); j++) iter_swap(sMatrix[j].begin() + i, sMatrix[j].begin() + firstElement.y());


    }

    sComputed = true;
}

void GaussJordan::compute_interval() {
    iComputed = true;
}

QPoint GaussJordan::maxElement(bool standard, int n) {
    QPoint maxElement(n,n);

    if(standard) {
        for(unsigned int i = n; i < sMatrix.size(); i++){
            for(unsigned int j = n; j < sMatrix[i].size() - 1; j++){
                if(sMatrix[maxElement.x()][maxElement.y()] < sMatrix[i][j]) {
                    maxElement.setX(i);
                    maxElement.setY(j);
                }
            }
        }
   /* } else {
        for(int i = n; i < sMatrix.size(); i++){
            for(int j = n; j < sMatrix[i].size(); j++){
                if(sMatrix[maxElement.x()][maxElement.y()] < sMatrix[i][j]) {
                    maxElement.setX(i);
                    maxElement.setY(j);
                }
            }
        }*/
    }

    return maxElement;
}
