#ifndef JSONHANDLER_H
#define JSONHANDLER_H

#include <QObject>
#include <fstream>
#include <QtCharts>
#include <QLineSeries>
#include "json.hpp"

using json = nlohmann::json;

class JSONHandler
{
public:
    JSONHandler();
    QLineSeries* getSeriesFromJSONFile();
};

#endif // JSONHANDLER_H
