#ifndef FW_FIELD_PLOT_H
#define FW_FIELD_PLOT_H

#include <QWidget>
#include <FW_Enum.h>
#include <fw_field.h>

//Qt-Datavisualization
#include <QtDataVisualization>
#include <QtDataVisualization/q3dscatter.h>
#include <QtDataVisualization/qabstract3dseries.h>
#include <QtDataVisualization/qscatterdataproxy.h>
#include <QtDataVisualization/qvalue3daxis.h>
#include <QtDataVisualization/q3dscene.h>
#include <QtDataVisualization/q3dcamera.h>
#include <QtDataVisualization/qscatter3dseries.h>
#include <QtDataVisualization/q3dtheme.h>

using namespace std;
using namespace QtDataVisualization;

class FW_Field_Plot : public QWidget
{
    Q_OBJECT
public:
    explicit    FW_Field_Plot(QWidget *parent = nullptr);

    bool        init(QGridLayout *layout);
    bool        clear();
    bool        plot(FW_Field *pField);
    void        set_color(QString col_string);

signals:

private:

    bool        state_ui_init = false;
    bool        state_something_plotted = false;

    QGridLayout *layout_in_ui;
    QWidget     *container_widget_scatter;
    Q3DScatter  *graph_scatter;
};

#endif // FW_FIELD_PLOT_H
