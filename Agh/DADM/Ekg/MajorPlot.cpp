#include "MajorPlot.h"


MajorPlot :: MajorPlot() {
	plotarea = new QwtPlot();
	picker = new QwtPlotPicker(plotarea->canvas());
	zoomer = new QwtPlotZoomer(plotarea->canvas());
	panner = new QwtPlotPanner(plotarea->canvas());
}

void MajorPlot:: PlotAreaInit(double xMin, double xMax, double xStep,double yMin, double yMax, double yStep, QString xTitle, QString yTitle, QString plotTitle ){
	plotarea->setCanvasBackground( Qt::white );
	plotarea->setTitle(plotTitle);
	plotarea->setAutoReplot(true);
	plotarea->setAxisScale(QwtPlot::xBottom, xMin, xMax, xStep);
	plotarea->setAxisScale(QwtPlot::yLeft, yMin, yMax, yStep);
	plotarea->setAxisTitle( QwtPlot::xBottom, xTitle);
	plotarea->setAxisTitle( QwtPlot::yLeft, yTitle);
	plotarea->resize(600,400);
	plotarea->show();
}

void MajorPlot:: PlotPickerInit(){
	picker->setEnabled(true);
	picker->setTrackerMode(QwtPicker::DisplayMode::AlwaysOn);
	picker->setRubberBand(QwtPicker::RubberBand::CrossRubberBand);
}

void MajorPlot:: PlotZoomerInit(){
	zoomer->setRubberBandPen(QColor(Qt::red));
	zoomer->setTrackerPen(QColor(Qt::white));
	zoomer->initMousePattern(2);
	zoomer->setMousePattern(QwtEventPattern::MouseSelect1, Qt::LeftButton);
	zoomer->setZoomBase(false);
	zoomer->setMaxStackDepth(3);
}