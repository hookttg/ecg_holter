#ifndef RESULTKEEPER_H
#define RESULTKEEPER_H

#include <vector>
#include <Input.h>
#include "AbstractResult.h"
#include "AtrfibrResult.h"
#include <RPeaksResult.h>
#include "BaselineResult.h"
#include <WavesResult.h>
#include "SigEDResult.h"
#include "Hrv2Result.h"
#include "HRV1Result.h"
#include "SleepApneaResult.h"
#include "TWavesAltResult.h"
#include "HeartClassResult.h"
#include <stsegmentresult.h>
#include "ECGFiltrationMethod.h"
#include "RPeaksDetectionAlgorithms.h"
#include "SleepApneaMetrics.h"
#include <ResultVCG.h>
#include <QTDispResult.h>
#include "MajorPlot.h"

using namespace std;

class ResultKeeper
{

    public:
		static ResultKeeper& getInstance();


		/************GETTERS && SETTERS******************/
		

		//vector<int>* getRawSignalADU();
		//void setRawSignalADU(vector<int>* signal);

		//vector<double>* getRawSignalMV();
		//void setRawSignalMV(vector<double>* signal);

		Input getSignalHandler();

		AtrfibrResult* getAtrialFibrillation();
		TWavesAltResult* getTWaves();		
		Hrv2Result* getHrv2();
		RPeaksResult* getRPeaks();
		HRV1Result* getHRV1();
		HeartClassResult* getHeartClass();
		BaselineResult* getECGBaseline();
		char* pathToFile;
	//	EctopicBeat* getEctopicBeat();
		STSegmentResult* getSTSegmentResult();
	//	HRT* getHRT();
		SleepApneaResult* getSleepApnea();
	//	QTDisp* getQTDisp();
	//	Input* getInput();
	//	RaportGenerator* getRaportGenerator();
		SigEDResult* getSIG_EDR();
		ResultVCG* getVCG();
		QTDispResult* getQTDispersion();

		void setVCG(ResultVCG* vcg);
		void setAtrialFibrillation(AtrfibrResult* atr);
		void setHrv2(Hrv2Result* hrv2);
		void setRPeaks(RPeaksResult* rpr);
	//	HeartClass* getHeartClass();
		void setECGBaseline(BaselineResult *baseline);
		void setHRV1(HRV1Result *hrv1);
		void setSleepApnea(SleepApneaResult *sleepApnea);
		void setTWaves(TWavesAltResult *tWaves);
		void setQTDispersion(QTDispResult* qtDisp);
	//	EctopicBeat* getEctopicBeat();
	
	//	HRT* getHRT();
	//	QTDisp* getQTDisp();
		Input* getInput();
		void setWaves(WavesResult* wr);
		void setHeartClass(HeartClassResult* ptrHeartClassRes);
		WavesResult* getWaves();
	//	RaportGenerator* getRaportGenerator();
		void setSIG_EDR(SigEDResult* sigEdr);
		
	
		 vector<double>  getSingleChannel(char* path, int channelNumber);

		 void setECGBaselineMethod(ECGFiltrationMethod ecgBaselineMethod);
		ECGFiltrationMethod getECGBaselineMethod();

		void setRPeaksDetectionAlgorithm(RPeaksDetectionAlgorithm rPeaksDetectionAlgorithm);
		RPeaksDetectionAlgorithm getRPeaksDetectionAlgorithm();

		void setSleepApneaMetrics(SleepApneaMetrics sleepApneaMetrics);
		SleepApneaMetrics getSleepApneaMetrics();

		void setStSegmentResult(STSegmentResult *st);

		vector<double> getTimeDomain();

		MajorPlot &ecgBaselineGraph();
        
    private:
		ResultKeeper();
		virtual ~ResultKeeper();
		ResultKeeper(ResultKeeper const&);
		void operator=(ResultKeeper const&);

	private:
		ECGFiltrationMethod m_ecgBaselineMethod;
		RPeaksDetectionAlgorithm m_rPeaksDetectionAlgorithm;
		SleepApneaMetrics m_sleepApneaMetrics;
		MajorPlot m_ecgBaselineGraph;


/********* MODULES DATA ***********/
		//vector<int>* rawSignalADU;
		//vector<double>* rawSignalMV;
		Input handler;
		AtrfibrResult *atrialFibrillation;
		Hrv2Result *hrv2;
		RPeaksResult *rPeaks;
		HRV1Result *hrv1;
		TWavesAltResult *tWaves;
	//	HRV1 *hrv1;
		HeartClassResult *heartClass;
		BaselineResult *ecgBaseline;
		WavesResult *wavesResult;
		SleepApneaResult *sleepApnea;
	//	EctopicBeat *ectopicBeat;
		STSegmentResult *stSegmentResult;
	
	//	HRT *hrt;
		
		QTDispResult* qtDisp;  
	//	Input *input;
	//	RaportGenerator *raportGenerator;
		SigEDResult *sigEDR;
		ResultVCG* vcgResult;
		
};


#endif // RESULTKEEPER_H
