#include "ResultKeeper.h"
#include "AbstractResult.h"
#include "ReturnType.h"
#include <iostream>

ResultKeeper::ResultKeeper()
{
  //this->atrialFibrillation=0;
  //this->ecgBaseline=0;
  //this->hrv2=0;
  //this->rawSignalADU=0;
  //this->rawSignalMV=0;
  //this->sigEDR=0;
  //this->waves=0;
}

ResultKeeper::~ResultKeeper()
{
    //dtor
}

 ResultKeeper& ResultKeeper :: getInstance() {
	// ResultKeeper();
	 static ResultKeeper instance;
	 return instance;
} 

 

  Input ResultKeeper::getSignalHandler() {
	return Input();
 }

 //AtrFibr* ResultKeeper::getAtrialFibrillation() {
	//return atrialFibrillation;
 //}

 BaselineResult* ResultKeeper::getECGBaseline(){
	return ecgBaseline;
 }

 RPeaksResult* ResultKeeper::getRPeaks() {
	return rPeaks;
 }

 //Hrv2Result* ResultKeeper::getHrv2() {
	//return hrv2;
 //}

 SigEDResult* ResultKeeper::getSIG_EDR() {
	return sigEDR;
 }



 void ResultKeeper::setECGBaseline(BaselineResult* baseline) {
	this->ecgBaseline = baseline;
 }
  

 void ResultKeeper::setRPeaks(RPeaksResult* rPeaks) {
	this->rPeaks = rPeaks;
 }


 vector<double> ResultKeeper:: getSingleChannel(char* path, int channelNumber) {
	Input input = this->getSignalHandler();
	input.Open(path);
	int numbOfChannels = input.GetNumberOfChannels();
	char** channelsNames = input.GetChannelsNames();
	char* singleChannel = channelsNames[channelNumber];
	input.SelectChannel(singleChannel);
	vector<double> single = input.vdGetChannelData();

	input.Close();
	return single;

 }


 void ResultKeeper::setWaves(WavesResult* wr) {
	this->wavesResult = wr;
 }

 WavesResult* ResultKeeper:: getWaves() {
	return this->wavesResult;
 }
 //void ResultKeeper::setAtrialFibrillation(AtrfibrResult* atr) {
	//this->atrialFibrillation = atr;
 //}

 //void ResultKeeper::setHrv2(Hrv2Result* hrv2) {
	//this->hrv2 = hrv2;
 //}

 void ResultKeeper::setSIG_EDR(SigEDResult* sig) {
	this->sigEDR = sig;
 }

 //void ResultKeeper::setWaves(WavesResult* waves) {
	//this->waves = waves;
 //}