//http://docs.opencv.org/doc/tutorials/core/discrete_fourier_transform/discrete_fourier_transform.html

#include "Traitements.h"
#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>


int main( int argc, char** argv )
{
    int choix;
    float frec;
	if(argc!= 2 ){
		cout << "Veuillez suivre la sytaxe suivante:./Filtres mon_image_a_traiter "<<endl;
	}
	else
	{
		cout << "Veuillez choisir le type de filtre a utiliser : "<<endl;
		cout << "Entrez 1 pour le filtre passe-bas : "<<endl;
		cout << "Entrez 2 pour le filtre passe-haut : "<<endl;
		cout << "choix :";
        cin >> choix;
        cout << "Veuillez Entrer la frequence de coupure (un nombre flottant entre 0 et 1) : ";
        cin >> frec;
		const char* NomImage = argv[1];

		// Ouverture de l'image en nuance de gris
		Mat ImageEntree = imread(NomImage, CV_LOAD_IMAGE_GRAYSCALE);

		if(!ImageEntree.data){
			cout << "Veuillez fournir une image valide "<<endl;
			return -1;
		}
		else{

			// Calcul de la transformée de fourier de l'image

			 Mat ImageTransFourier = FourierTransform(ResizeImage(ImageEntree));

			 Mat ImageTransTraitee;

			 //Application du filtre suivant le choix
			 if(choix == 1){
				 ImageTransTraitee = FiltrePasseBas(ImageTransFourier, frec);
			 }
			 else if(choix == 2){
				 ImageTransTraitee = FiltrePasseHaut(ImageTransFourier, frec);
			 }

			 //Détermination de la norme du spectre
			 Mat SpectreInitial = CadransChange(ComputeNorme(ImageTransFourier));
			 Mat SpectreTraite =  ComputeNorme(ImageTransTraitee);

			 Mat ImageTransInverse = TransFourierInverse(CadransChange(ImageTransTraitee),ImageEntree.rows, ImageEntree.cols);

			 //Affichage des différentes images
			 imshow("Image Entree", ImageEntree);
			 imshow("Spectre de Fourier Initial", SpectreInitial);
			 imshow("Spectre de Fourier Traite", SpectreTraite);
			 imshow("Image Apres Traitement", ImageTransInverse);

			 // Enregistrement de l'image originale
			 if(!imwrite("images_traitees/Image_Entree.png", ImageEntree))
			     cout<<"Erreur lors de l'enregistrement"<<endl;

			// Enregistrement de l'image du spectre initial
			 if(!imwrite("images_traitees/Spectre_initial.png", SpectreInitial))
			     cout<<"Erreur lors de l'enregistrement"<<endl;

			 // Enregistrement de l'image du spectre filtré
			 if(!imwrite("images_traitees/Spectre_traite.png", SpectreTraite))
			 			     cout<<"Erreur lors de l'enregistrement"<<endl;

			// Enregistrement de l'image de la transformée inverse de fourier du filtrage
			 if(!imwrite("images_traitees/Image_Restauree.png", ImageTransInverse))
			     cout<<"Erreur lors de l'enregistrement"<<endl;

			 waitKey();

    		 return 0;

		}
	}
}
