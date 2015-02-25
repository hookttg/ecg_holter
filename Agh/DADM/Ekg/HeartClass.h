#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include "ResultKeeper.h"
#include "HeartClassResult.h"
#include "AbstractModule.h"
#ifndef HEART_CLASS_H
#define HEART_CLASS_H

using namespace std;

class HeartClass : public AbstractModule<HeartClassResult>{
	
	public:
		
		//TODO dowiedzie� si� skad wziac frequency
		double frequency;
		
		map<int, vector<double> > signalMap;
		map<int, vector<double> > yQRS;
		map<int, vector<double> > samplesBetweenMax;

		vector<double> artifactsClass;
		vector<double> artifactsForClassification;
		vector<double> goodQrsNumber;

		vector<double> qrsMinAmplitudes;
		vector<double> qrsMaxAmplitudes;
		vector<double> qrsMinAmplitudesSamples;
		vector<double> qrsMaxAmplitudesSamples;
		
		vector<double> maxArea;
		vector<double> maxSamplesBetween;
		vector<double> minSamplesBetween;
		vector<double> qrsOnset;
		vector<double> qrsEnd;
		vector<double> signalFromEcg;
		
		double meanMaxAmplitude;
		double meanMinAmplitude;
		double meanMaxArea;
		double meanSamplesBetweenMax;
		double meanSamplesBetweenMin;
		
		HeartClassResult* compute(ResultKeeper* rkp);
		HeartClass(ResultKeeper* rkp);
		
		void InputPrepare();
		double ComplexArea(vector<double>* tempArea);
		void Amplitudes();
		void FrameLocator();
		void MeanAmplitude();
		void SamplesBetween();
		void Conditioning(HeartClassResult& heartClassResults);
};

#endif // HEART_CLASS_H

