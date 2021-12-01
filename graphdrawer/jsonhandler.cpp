#include "jsonhandler.h"

JSONHandler::JSONHandler()
{

}

QLineSeries* JSONHandler::getSeriesFromJSONFile(){
    std::ifstream input("input.json");
    QLineSeries* s;

    if(input.is_open()){

        json data;
        input >> data;

        //QString name(data["Name"]);

        foreach(auto value, data["list"]){
            QPointF p(value["x"], value["y"]);
            s->append(p);
        }

    }
    return s;
}
