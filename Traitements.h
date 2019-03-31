////****************************************************************************************************////
////        TP2 2eme Partie: Programme d'application des traitements fréquentiels au spectre            ////
////                         d'une image préalablement donnée en argument        				        ////
////																									////
////             Auteur: HOUSSOU Noudéhouénou Lionel Jaderne                             				////
////             Promotion: Promotion 19 - IFI                                 							////
////																									////
////             Compilation: 1- make      												 				////
////						  2- ./Filtres nom_image										 			////
////																									////
////		     Description: Ce programme permet d'appliquer les filtres passe-bas et passe-haut  		////
////                          au spectre d'une image préalablement donnée en argument   				////
////                          								                                     		////
////													 												////
//// Ce programmage a été inspiré du programme de transformee de fourier à la page:                     ////
////http://docs.opencv.org/doc/tutorials/core/discrete_fourier_transform/discrete_fourier_transform.html////
////****************************************************************************************************////

#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat ResizeImage (Mat ImageEntree);
Mat FourierTransform (Mat ImageRedimensionnee);
Mat ComputeNorme (Mat ImageTransFourier);
Mat CadransChange (Mat ImageNormeFourier);
Mat TransFourierInverse (Mat ImageTransFourier, int nblignes, int nbcolones);
Mat FiltrePasseBas (Mat ImageTransFourier, float freqcoupure );
Mat FiltrePasseHaut (Mat ImageTransFourier, float freqcoupure );

