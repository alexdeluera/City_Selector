#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QDir>
#include <chrono>

#include <iostream>

#include "City.h"
#include "MaxHeap.h"
#include "MinHeap.h"

using namespace std;
using namespace std::chrono;

class InputWindow : public QWidget {
public:
    InputWindow(QWidget *parent = nullptr);

private slots:
    void onSubmit();

private:
    QLineEdit *inputField1;
    QLineEdit *inputField2;
    QLineEdit *inputField3;
    QLabel *resultLabel;
};

InputWindow::InputWindow(QWidget *parent) : QWidget(parent) {
    setWindowTitle("City Selector");

    inputField1 = new QLineEdit(this);
    inputField2 = new QLineEdit(this);
    inputField3 = new QLineEdit(this);

    QPushButton *submitButton = new QPushButton("Submit", this);

    resultLabel = new QLabel(this);
    resultLabel->setText("Results will be displayed here.");

    QLabel *instructionLabel = new QLabel("Please enter inputs below:", this);
    instructionLabel->setAlignment(Qt::AlignLeft);  // Center the text

    QVBoxLayout *layout = new QVBoxLayout(this);

    QFormLayout *formLayout = new QFormLayout();
    formLayout->addRow("Country:", inputField1);
    formLayout->addRow("Population, Integer 1-5: ", inputField2);
    formLayout->addRow("Weather, Integer 1-5: ", inputField3);

    layout->addWidget(instructionLabel);
    layout->addLayout(formLayout);
    layout->addWidget(submitButton);
    layout->addWidget(resultLabel);

    connect(submitButton, &QPushButton::clicked, this, &InputWindow::onSubmit);

    setLayout(layout);
}

void InputWindow::onSubmit() {
    QString country = inputField1->text();
    QString population = inputField2->text();
    QString weather = inputField3->text();

    string countryStr = country.toStdString();
    int populationInt = population.toInt();
    int weatherInt = weather.toInt();

    qDebug() << "QDir::currentPath(): "<<QDir::currentPath();
    qDebug() << "QApplication::: "<<QApplication::applicationDirPath();
    qDebug() << "QCoreApplication::: "<<QCoreApplication::applicationDirPath();

    vector<City> cities = City::getInfo("worldcities.csv", countryStr, populationInt, weatherInt);

    auto start_timer_maxHeap = high_resolution_clock::now();
    MaxHeap maxheap(cities);
    string maxOutput = maxheap.top_5_str();
    auto end_timer_maxHeap = high_resolution_clock::now();

    auto maxHeap_runtime = duration_cast<duration<double, milli>>(end_timer_maxHeap - start_timer_maxHeap);
    double maxHeap_run = maxHeap_runtime.count();

    stringstream max_ss;
    max_ss << "MaxHeap execution time: " << std::fixed << std::setprecision(3) << maxHeap_run << " milliseconds. \n \n";
    string maxRunTime = max_ss.str();

    auto start_timer_minHeap = high_resolution_clock::now();
    MinHeap minHeap(cities);
    string minOutput = minHeap.top_5_str();
    auto end_timer_minHeap = high_resolution_clock::now();

    auto minHeap_runtime = duration_cast<duration<double, milli>>(end_timer_minHeap - start_timer_minHeap);
    double minHeap_run = minHeap_runtime.count();

    stringstream min_ss;
    min_ss << "MinHeap execution time: " << std::fixed << std::setprecision(3) << minHeap_run << " milliseconds. \n";
    string minRunTime = min_ss.str();

    QString output = QString::fromStdString(maxOutput);

    output+=maxRunTime+minOutput+minRunTime;

    resultLabel->setText(output);
}

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    InputWindow window;
    window.show();

    return app.exec();
}
