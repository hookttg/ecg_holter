#include "selectmodulesprivate.h"

#include <QAction>

SelectModulesPrivate::SelectModulesPrivate(QObject *parent)
{
    rPeeksDetection = new QAction("R peeks detection", parent);
    qrsDetection = new QAction("QRS detection", parent);

    qrsAnalysis = new QAction("QRS Analysis", parent);
    qrsClassification = new QAction("QRS classification", parent);
    stAnalysis = new QAction("ST analysis", parent);
    tAlternans = new QAction("T alternans", parent);
    qtLengthTAnalysis = new QAction("QT length / T analysis", parent);

    hrv = new QAction("HRV", parent);
    freqAndTimeDomainAnalysis = new QAction("Frequency and Time Domain Analysis", parent);
    dfa = new QAction("DFA", parent);
    geometricAnalysis = new QAction("Geometric analysis", parent);

    hrt = new QAction("HRT", parent);
    vcg = new QAction("VCG", parent);
    sleepApnea = new QAction("Sleep apnea", parent);
    atrialFibrilation = new QAction("Atrial fibrilation", parent);

    //allModules
    allModules.append(rPeeksDetection);
    allModules.append(qrsDetection);
    allModules.append(qrsAnalysis);
    allModules.append(qrsClassification);
    allModules.append(stAnalysis);
    allModules.append(tAlternans);
    allModules.append(qtLengthTAnalysis);
    allModules.append(hrv);
    allModules.append(freqAndTimeDomainAnalysis);
    allModules.append(dfa);
    allModules.append(geometricAnalysis);
    allModules.append(hrt);
    allModules.append(vcg);
    allModules.append(sleepApnea);
    allModules.append(atrialFibrilation);

    //mainModules
    mainModules.append(rPeeksDetection);
    mainModules.append(qrsDetection);

    //otherModules
    otherModules.append(qrsAnalysis);
    otherModules.append(hrv);
    otherModules.append(hrt);
    otherModules.append(vcg);
    otherModules.append(sleepApnea);
    otherModules.append(atrialFibrilation);
}
