#include "ekg.h"
#include "MajorPlot.h"
#include "CurvePlot.h"
#include "ScatterPlot.h"
#include "HistogramPlot.h"
#include "Table.h"
#include "plot3D.h"

#include <QtWidgets/QApplication>
#include <iostream>
#include <fftw3.h>
#include <gsl\gsl_sf_bessel.h>
#include <qdebug.h>
#include <qapplication.h>
#include <qwt_plot.h> 
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_symbol.h>
#include <qwt_legend.h>
#include <wfdb.h>
#include <QVector>
#include <QtWidgets/QPushButton>
#include <qwt_samples.h>
#include <QMap>
#include <QtGui>

#define FFTW_DLL

int main(int argc, char *argv[])
{
	 QApplication a( argc, argv );

/*********************przyk�adowe wektory*****************************************************************/
	QVector<double> vectorY(500);
	vectorY << -0.295 <<-0.290 <<-0.290 <<-0.295 <<-0.305 <<-0.305 <<-0.310 <<-0.300 <<-0.290 <<-0.285 <<-0.305 <<-0.295 <<-0.310 <<-0.310 <<-0.300 <<-0.305 <<-0.315 <<-0.325 <<-0.320 <<-0.305 <<-0.305 <<-0.320 <<-0.315 <<-0.330 <<-0.325 <<-0.325 <<-0.315 <<-0.305 <<-0.320 <<-0.340 <<-0.330 <<-0.320 <<-0.320 <<-0.320 <<-0.325 <<-0.335 <<-0.335 <<-0.345 <<-0.330 <<-0.320 <<-0.325 <<-0.340 <<-0.345 <<-0.340 <<-0.320 <<-0.315 <<-0.335 <<-0.345 <<-0.335 <<-0.335 <<-0.330 <<-0.335 <<-0.335 <<-0.340 <<-0.340 <<-0.330 <<-0.320 <<-0.330 <<-0.335 <<-0.345 <<-0.350 <<-0.335 <<-0.325 <<-0.320 <<-0.330 <<-0.340 <<-0.345 <<-0.330 <<-0.325 <<-0.325 <<-0.335 <<-0.345 <<-0.340 <<-0.345 <<-0.320 <<-0.315 <<-0.330 <<-0.335 <<-0.340 <<-0.330 <<-0.330 <<-0.325 <<-0.320 <<-0.335 <<-0.330 <<-0.325 <<-0.315 <<-0.315 <<-0.330 <<-0.340 <<-0.330 <<-0.325 <<-0.310 <<-0.305 <<-0.310 <<-0.310 <<-0.325 <<-0.315 <<-0.300 <<-0.300 <<-0.305 <<-0.310 <<-0.310 <<-0.300 <<-0.290 <<-0.280 <<-0.275 <<-0.265 <<-0.265 <<-0.230 <<-0.180 <<-0.110 <<0.00500 <<0.260 <<0.645 <<0.890 <<0.800 <<0.455 <<0.190 <<0.100 <<0.0950 <<0.120 <<0.120 <<0.110 <<0.105 <<0.110 <<0.100 <<0.120 <<0.120 <<0.125 <<0.0950 <<0.0750 <<0.0600 <<0.0650 <<0.0800 <<0.0600 <<0.0300 <<-0.0150 <<-0.0500 <<-0.0800 <<-0.115 <<-0.170 <<-0.225 <<-0.290 <<-0.350 <<-0.405 <<-0.465 <<-0.545 <<-0.600 <<-0.625 <<-0.590 <<-0.550 <<-0.505 <<-0.475 <<-0.455 <<-0.460 <<-0.455 <<-0.460 <<-0.445 <<-0.440 <<-0.430 <<-0.410 <<-0.390 <<-0.340 <<-0.295 <<-0.295 <<-0.300 <<-0.315 <<-0.355 <<-0.330 <<-0.330 <<-0.345 <<-0.355 <<-0.350 <<-0.350 <<-0.330 <<-0.320 <<-0.295 <<-0.305 <<-0.305 <<-0.310 <<-0.310 <<-0.300 <<-0.290 <<-0.280 <<-0.290 <<-0.285 <<-0.285 <<-0.275 <<-0.260 <<-0.270 <<-0.270 <<-0.270 <<-0.255 <<-0.255 <<-0.260 <<-0.260 <<-0.255 <<-0.265 <<-0.260 <<-0.240 <<-0.240 <<-0.240 <<-0.240 <<-0.250 <<-0.240 <<-0.225 <<-0.210 <<-0.220 <<-0.215 <<-0.215 <<-0.200 <<-0.200 <<-0.195 <<-0.200 <<-0.200 <<-0.195 <<-0.185 <<-0.170 <<-0.160 <<-0.150 <<-0.150 <<-0.160 <<-0.145 <<-0.140 <<-0.140 <<-0.140 <<-0.140 <<-0.140 <<-0.135 <<-0.125 <<-0.125 <<-0.110 <<-0.115 <<-0.125 <<-0.0900 <<-0.0800 <<-0.0800 <<-0.0800 <<-0.0900 <<-0.0950 <<-0.0850 <<-0.0800 <<-0.0750 <<-0.0800 <<-0.0900 <<-0.0850 <<-0.0850 <<-0.0800 <<-0.0900 <<-0.100 <<-0.110 <<-0.135 <<-0.130 <<-0.125 <<-0.135 <<-0.150 <<-0.175 <<-0.190 <<-0.200 <<-0.200 <<-0.195 <<-0.210 <<-0.230 <<-0.220 <<-0.230 <<-0.220 <<-0.220 <<-0.245 <<-0.270 <<-0.255 <<-0.255 <<-0.250 <<-0.255 <<-0.260 <<-0.255 <<-0.265 <<-0.265 <<-0.250 <<-0.255 <<-0.255 <<-0.270 <<-0.275 <<-0.270 <<-0.265 <<-0.270 <<-0.265 <<-0.275 <<-0.280 <<-0.275 <<-0.270 <<-0.275 <<-0.285 <<-0.295 <<-0.295 <<-0.290 <<-0.275 <<-0.285 <<-0.305 <<-0.300 <<-0.295 <<-0.295 <<-0.290 <<-0.290 <<-0.290 <<-0.305 <<-0.310 <<-0.315 <<-0.295 <<-0.305 <<-0.310 <<-0.315 <<-0.330 <<-0.320 <<-0.320 <<-0.315 <<-0.330 <<-0.345 <<-0.340 <<-0.335 <<-0.325 <<-0.335 <<-0.325 <<-0.330 <<-0.340 <<-0.335 <<-0.320 <<-0.330 <<-0.335 <<-0.335 <<-0.345 <<-0.335 <<-0.330 <<-0.330 <<-0.340 <<-0.350 <<-0.340 <<-0.340 <<-0.330 <<-0.325 <<-0.330 <<-0.340 <<-0.340 <<-0.335 <<-0.330 <<-0.330 <<-0.330 <<-0.340 <<-0.350 <<-0.340 <<-0.330 <<-0.330 <<-0.330 <<-0.335 <<-0.340 <<-0.345 <<-0.330 <<-0.335 <<-0.335 <<-0.340 <<-0.335 <<-0.325 <<-0.320 <<-0.320 <<-0.320 <<-0.330 <<-0.320 <<-0.315 <<-0.310 <<-0.320 <<-0.330 <<-0.335 <<-0.335 <<-0.320 <<-0.315 <<-0.330 <<-0.325 <<-0.315 <<-0.310 <<-0.305 <<-0.285 <<-0.295 <<-0.295 <<-0.305 <<-0.320 <<-0.305 <<-0.280 <<-0.275 <<-0.285 <<-0.290 <<-0.300 <<-0.290 <<-0.285 <<-0.280 <<-0.295 <<-0.295 <<-0.295 <<-0.285 <<-0.285 <<-0.280 <<-0.280 <<-0.280 <<-0.275 <<-0.270 <<-0.260 <<-0.230 <<-0.210 <<-0.160 <<-0.0850 <<0.0950 <<0.420 <<0.810 <<0.935 <<0.735 <<0.385 <<0.185 <<0.140 <<0.150 <<0.155 <<0.145 <<0.145 <<0.145 <<0.150 <<0.155 <<0.140 <<0.130 <<0.110 <<0.115 <<0.110 <<0.125 <<0.115 <<0.100 <<0.0650 <<0.0400 <<0.0200 <<-0.0100 <<-0.0700 <<-0.140 <<-0.195 <<-0.250 <<-0.295 <<-0.365 <<-0.455 <<-0.530 <<-0.580 <<-0.560 <<-0.530 <<-0.475 <<-0.455 <<-0.460 <<-0.460 <<-0.470 <<-0.465 <<-0.455 <<-0.430 <<-0.425 <<-0.385 <<-0.330 <<-0.290 <<-0.270 <<-0.280 <<-0.315 <<-0.320 <<-0.310 <<-0.320 <<-0.320 <<-0.320 <<-0.315 <<-0.315 <<-0.285 <<-0.255 <<-0.245 <<-0.250 <<-0.260 <<-0.250 <<-0.250 <<-0.235 <<-0.235 <<-0.245 <<-0.240 <<-0.245 <<-0.230 <<-0.220 <<-0.210 <<-0.235 <<-0.230 <<-0.225 <<-0.205 <<-0.195 <<-0.210 <<-0.185 <<-0.195 <<-0.195 <<-0.180 <<-0.175 <<-0.175 <<-0.165 <<-0.190 <<-0.185 <<-0.175 <<-0.165;
	QVector<double> vectorX(500);
	vectorX << 500  << 501  << 502  << 503  << 504  << 505  << 506  << 507  << 508  << 509  << 510  << 511  << 512  << 513  << 514  << 515  << 516  << 517  << 518  << 519  << 520  << 521  << 522  << 523  << 524  << 525  << 526  << 527  << 528  << 529  << 530  << 531  << 532  << 533  << 534  << 535  << 536  << 537  << 538  << 539  << 540  << 541  << 542  << 543  << 544  << 545  << 546  << 547  << 548  << 549  << 550  << 551  << 552  << 553  << 554  << 555  << 556  << 557  << 558  << 559  << 560  << 561  << 562  << 563  << 564  << 565  << 566  << 567  << 568  << 569  << 570  << 571  << 572  << 573  << 574  << 575  << 576  << 577  << 578  << 579  << 580  << 581  << 582  << 583  << 584  << 585  << 586  << 587  << 588  << 589  << 590  << 591  << 592  << 593  << 594  << 595  << 596  << 597  << 598  << 599  << 600  << 601  << 602  << 603  << 604  << 605  << 606  << 607  << 608  << 609  << 610  << 611  << 612  << 613  << 614  << 615  << 616  << 617  << 618  << 619  << 620  << 621  << 622  << 623  << 624  << 625  << 626  << 627  << 628  << 629  << 630  << 631  << 632  << 633  << 634  << 635  << 636  << 637  << 638  << 639  << 640  << 641  << 642  << 643  << 644  << 645  << 646  << 647  << 648  << 649  << 650  << 651  << 652  << 653  << 654  << 655  << 656  << 657  << 658  << 659  << 660  << 661  << 662  << 663  << 664  << 665  << 666  << 667  << 668  << 669  << 670  << 671  << 672  << 673  << 674  << 675  << 676  << 677  << 678  << 679  << 680  << 681  << 682  << 683  << 684  << 685  << 686  << 687  << 688  << 689  << 690  << 691  << 692  << 693  << 694  << 695  << 696  << 697  << 698  << 699  << 700  << 701  << 702  << 703  << 704  << 705  << 706  << 707  << 708  << 709  << 710  << 711  << 712  << 713  << 714  << 715  << 716  << 717  << 718  << 719  << 720  << 721  << 722  << 723  << 724  << 725  << 726  << 727  << 728  << 729  << 730  << 731  << 732  << 733  << 734  << 735  << 736  << 737  << 738  << 739  << 740  << 741  << 742  << 743  << 744  << 745  << 746  << 747  << 748  << 749  << 750  << 751  << 752  << 753  << 754  << 755  << 756  << 757  << 758  << 759  << 760  << 761  << 762  << 763  << 764  << 765  << 766  << 767  << 768  << 769  << 770  << 771  << 772  << 773  << 774  << 775  << 776  << 777  << 778  << 779  << 780  << 781  << 782  << 783  << 784  << 785  << 786  << 787  << 788  << 789  << 790  << 791  << 792  << 793  << 794  << 795  << 796  << 797  << 798  << 799  << 800  << 801  << 802  << 803  << 804  << 805  << 806  << 807  << 808  << 809  << 810  << 811  << 812  << 813  << 814  << 815  << 816  << 817  << 818  << 819  << 820  << 821  << 822  << 823  << 824  << 825  << 826  << 827  << 828  << 829  << 830  << 831  << 832  << 833  << 834  << 835  << 836  << 837  << 838  << 839  << 840  << 841  << 842  << 843  << 844  << 845  << 846  << 847  << 848  << 849  << 850  << 851  << 852  << 853  << 854  << 855  << 856  << 857  << 858  << 859  << 860  << 861  << 862  << 863  << 864  << 865  << 866  << 867  << 868  << 869  << 870  << 871  << 872  << 873  << 874  << 875  << 876  << 877  << 878  << 879  << 880  << 881  << 882  << 883  << 884  << 885  << 886  << 887  << 888  << 889  << 890  << 891  << 892  << 893  << 894  << 895  << 896  << 897  << 898  << 899  << 900  << 901  << 902  << 903  << 904  << 905  << 906  << 907  << 908  << 909  << 910  << 911  << 912  << 913  << 914  << 915  << 916  << 917  << 918  << 919  << 920  << 921  << 922  << 923  << 924  << 925  << 926  << 927  << 928  << 929  << 930  << 931  << 932  << 933  << 934  << 935  << 936  << 937  << 938  << 939  << 940  << 941  << 942  << 943  << 944  << 945  << 946  << 947  << 948  << 949  << 950  << 951  << 952  << 953  << 954  << 955  << 956  << 957  << 958  << 959  << 960  << 961  << 962  << 963  << 964  << 965  << 966  << 967  << 968  << 969  << 970  << 971  << 972  << 973  << 974  << 975  << 976  << 977  << 978  << 979  << 980  << 981  << 982  << 983  << 984  << 985  << 986  << 987  << 988  << 989  << 990  << 991  << 992  << 993  << 994  << 995  << 996  << 997  << 998  << 999  << 1000 ;
	QVector<double> r_peaks(2);
	r_peaks << 615 << 912;
	QVector<double> r_peaks_value(2);
	r_peaks_value << 0.89 << 0.935;

	//mapa do histogramu
	QMap<QString, QVector<double>> histmap;
	histmap["value"] << 5 << 3 << 1 << 4 << 6 << 5 << 3 << 1 << 6 ;
	histmap["start_time"] << 0 << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8;
	histmap["end_time"] << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9;
	//QVector<QwtIntervalSample> hist(7);
	//hist << QwtIntervalSample(5,0,1) << QwtIntervalSample(3,1,2) << QwtIntervalSample(1,2,3)<< QwtIntervalSample(4,3,4)<< QwtIntervalSample(6,4,5)<< QwtIntervalSample(5,5,6)<< QwtIntervalSample(3,6,7); 
	
	//mapa do tabeli
	QMap<QString, double> map;
	 map["one"] = 1;
	 map["three"] = 3;
	 map["seven"] = 7;

	 //wektor jednostek do tabeli
	 QVector<QString> units(3);
	  units[0] = "mm" ;
	  units[1] = "min" ;
	  units[2] = "s^2" ;

	/**************************************Wektory do VCG**************************************************************/
	QVector<double> X(126);
	QVector<double> Y(126);
	QVector<double> Z(126);
    double z = 0.0f;
    double angle = 0.0f;
	int i = 0;

    for ( angle = 0.0; angle <= twoPi * 2.0; angle += 0.1, z += 0.5 )
    {
        X[i]= 20.0 * sin( angle );
        Y[i] = 30.0 * cos( angle );
		Z[i] = z;
		i++;
    }

/*****************Wywo�uj� obiekt klasy g��wnej************************************************/
		
		//MajorPlot mp;
	

/*****************Wywo�uj� obiekty klas pochodnych dla r�nych typ�w wykres�w*************************/	
/*****************Uwaga: na obiekcie klasy g��wnej mog� narysowa� dowoln�*************************/	
/**********************************ilo�� wykres�w klas pochodnych*************************/	
		
		//CurvePlot cp; //obiekt1
		//cp.CurvePlotInit(2, Qt::blue, vectorX,vectorY,mp.plotarea,"original ECG");
		//cp.setCurvePlotArea(mp, 500.0,1000.0, 100.0, -1.0,1.0,0.5, "time [s]", "amplitude [mV]", "sampleECG");
		//
		//ScatterPlot sp; //obiekt2
		//sp.ScatterPlotInit(8, Qt:: red, r_peaks,r_peaks_value,mp.plotarea,"R-Peaks",QwtPlotCurve::CurveStyle::Dots, QwtSymbol::Style::Star2);


/***********************Histogram*****************************************************************************/
		
		MajorPlot mp2;
		//mp2.PlotAreaInit(0,400,0,0,600,0,"","","VCG");
		HistogramPlot hp;
		hp.HistogramPlotInit(histmap, mp2.plotarea);
		hp.setHistogramPlotArea(mp2,histmap["start_time"].first(),histmap["end_time"].last(),1,0,1,1,"RRx","value","sample Histogram");

		//Table t(map, units, mp2.plotarea->canvas());

		//Plot3D p(X,Z,Y); // wykres VCG - trzeba poda� najpierw wektor Y a potem Z;
		//p.show();

		return a.exec();
}
 