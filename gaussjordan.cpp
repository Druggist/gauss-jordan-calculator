#include "gaussjordan.h"

GaussJordan::GaussJordan(QObject *parent) : QObject(parent) {

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

    rx.setPattern("(((\\-)?[0-9]+(\\.)?[0-9]*_)*((\\-)?[0-9]+(\\.)?[0-9]*)\\=((\\-)?[0-9]+(\\.)?[0-9]*)\\;)");
    if(!rx.exactMatch(data)) return false;

    rx.setPattern("(\\;)");
    QStringList query = data.split(rx);

    rx.setPattern("(\\_|\\=)");
    for (int i = 0; i < query.size(); i++) {
        vector<double> sRow;
        QStringList values = query.at(i).split(rx);

        for(int j = 0; j < values.size();j++) {
            sRow.push_back(values.at(j).toDouble());
        }

        sMatrix.push_back(sRow);
    }

    return true;
}

QString GaussJordan::results_standard() {
    if(!sComputed) return "Results has not been computed yet!";
    return "";
}

QString GaussJordan::results_interval() {
    if(!iComputed) return "Results has not been computed yet!";
    return "";
}

void GaussJordan::compute_standard() {
    sComputed = true;
}

void GaussJordan::compute_interval() {
    iComputed = true;
}
