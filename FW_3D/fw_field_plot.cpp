#include "fw_field_plot.h"

FW_Field_Plot::FW_Field_Plot(QWidget *parent) : QWidget(parent)
{

}

bool FW_Field_Plot::init(QGridLayout *layout)
{
    if(layout == nullptr)
        return false;

    //save pointer to ui layout
    layout_in_ui = layout;

    //init scatter plot
    graph_scatter = new Q3DScatter();
    container_widget_scatter = createWindowContainer(graph_scatter);
    layout_in_ui->addWidget(container_widget_scatter, 0, 0);
    graph_scatter->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetDirectlyAbove);
    graph_scatter->activeTheme()->setWindowColor(Qt::white);

    state_ui_init = true;
    return true;
}

bool FW_Field_Plot::clear()
{
    if(!state_ui_init)
        return false;

    if(!state_something_plotted)
        return false;

    while(!graph_scatter->seriesList().isEmpty())
    {
        QScatter3DSeries *series = graph_scatter->seriesList().at(0);
        graph_scatter->removeSeries(series);
        series->dataProxy()->deleteLater();
        series->deleteLater();
    }

    state_something_plotted = false;
    return true;
}

bool FW_Field_Plot::plot(FW_Field *pField)
{
    if(!state_ui_init)
        return false;

    clear();

    //series
    vector<QScatter3DSeries *>  vSeries(MARKER_NUMBER_OF);
    for(size_t i = 0; i < MARKER_NUMBER_OF; i++)
    {
        //create series
        vSeries[i] = new QScatter3DSeries;

        //style
        vSeries[i]->setItemLabelFormat(QStringLiteral("@xTitle: @xLabel @yTitle: @yLabel @zTitle: @zLabel"));
        vSeries[i]->setMeshSmooth(true);
        vSeries[i]->setMesh(QAbstract3DSeries::Mesh::MeshSphere);

        //color
        switch (i) {
        case MARKER_BOT:    vSeries[i]->setBaseColor(QSl_Colors[COL_BOT]);      break;
        case MARKER_PLAYER: vSeries[i]->setBaseColor(QSl_Colors[COL_PLAYER]);   break;
        case MARKER_EMPTY:  vSeries[i]->setBaseColor(QSl_Colors[COL_EMPTY]);    break;
        default:                                                                return false;}

        if(i == MARKER_BOT || i == MARKER_PLAYER)
            vSeries[i]->setItemSize(0.90);
        else
            vSeries[i]->setItemSize(0.05);

        //series to graph
        graph_scatter->addSeries(vSeries[i]);
    }

    state_something_plotted = true;

    //axis
    graph_scatter->axisX()->setTitle("X");   //default x axis
    graph_scatter->axisY()->setTitle("Z");   //graph z axis is img y axis
    graph_scatter->axisZ()->setTitle("Y");   //graph y axis is img z axis
    graph_scatter->axisX()->setTitleVisible(true);
    graph_scatter->axisY()->setTitleVisible(true);
    graph_scatter->axisZ()->setTitleVisible(true);
    graph_scatter->axisX()->setSegmentCount(FIELD_SIZE - 1);
    graph_scatter->axisY()->setSegmentCount(FIELD_SIZE - 1);
    graph_scatter->axisZ()->setSegmentCount(FIELD_SIZE - 1);
    graph_scatter->axisX()->setMin(0);
    graph_scatter->axisY()->setMin(0);
    graph_scatter->axisZ()->setMin(0);
    graph_scatter->axisX()->setMax(FIELD_SIZE - 1);
    graph_scatter->axisY()->setMax(FIELD_SIZE - 1);
    graph_scatter->axisZ()->setMax(FIELD_SIZE - 1);

    //style
    graph_scatter->activeTheme()->setGridEnabled(true);
    graph_scatter->activeTheme()->setBackgroundEnabled(true);
    graph_scatter->setShadowQuality(QAbstract3DGraph::ShadowQuality::ShadowQualityNone);

    //data to arrays
    vector<QScatterDataArray> vDataArray(MARKER_NUMBER_OF);
    for(int x = 0; x < FIELD_SIZE; x++)
        for(int y = 0; y < FIELD_SIZE; y++)
            for(int z = 0; z < FIELD_SIZE; z++)
            {
                vDataArray[pField->get_marker(x, y, z)].append(
                            QVector3D(
                                float(x),
                                float(z),
                                float(y)));
            }

    //add data to series
    for(size_t s = 0; s < MARKER_NUMBER_OF; s++)
        vSeries[s]->dataProxy()->addItems(vDataArray[s]);

    return true;
}

void FW_Field_Plot::set_color(QString col_string)
{
    graph_scatter->activeTheme()->setWindowColor(QColor(col_string));
}
