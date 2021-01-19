#include "opencv2/opencv.hpp"
#include "mylib.h"
///////////////////////detection de contours/////////////////////
Mat contours (Mat frame) {
Mat out2,in_gray;
	    // Capture frame-by-frame
	cvtColor(frame,in_gray,CV_BGR2GRAY);///convertir l'image de base en couleur en noir et blanc
	out2.create(frame.rows,frame.cols,CV_8UC1);

		for (int i=1;i<frame.rows;i++){
			for (int j=1;j<frame.cols;j++){
short temp;
				temp = (-1)*in_gray.at<uchar>(i,j-1)+(-1)*in_gray.at<uchar>(i-1,j)+(-1)*in_gray.at<uchar>(i,j+1)+(-1)*in_gray.at<uchar>(i+1,j)+4*in_gray.at<uchar>(i,j); //paramètre du filtre de contours

out2.at<uchar>(i,j)=(uchar)abs(temp);//on prend que les valeur postives

		if(out2.at<uchar>(i,j)>23) out2.at<uchar>(i,j)=255; /// faire un intervalle entre les valeurs
		else { out2.at<uchar>(i,j)=0;
			}

			}
		}


return(out2);

}
///////////////////////////////////////////seuillage du rouge au vert///////////////////////////////////
Mat seuillageRtoV (Mat frame){
float nr;
for (int i=0;i<frame.rows;i++){

			for (int j=0;j<frame.cols;j++){
				uchar r,v,b;

				b=frame.at<Vec3b>(i,j)[0];
				v=frame.at<Vec3b>(i,j)[1];
				r=frame.at<Vec3b>(i,j)[2];
				nr=r/sqrt((r*r)+(b*b)+(v*v));


		if(nr>0.75)
			{
				frame.at<Vec3b>(i,j)[0]=0;
				frame.at<Vec3b>(i,j)[1]=r;
				frame.at<Vec3b>(i,j)[2]=0;

			}

		else{
			frame.at<Vec3b>(i,j)[0]=b;
			frame.at<Vec3b>(i,j)[1]=v;
			frame.at<Vec3b>(i,j)[2]=r;
		}
	


			}
		}
return (frame);
}

////////////////////////////////////filtre noir et blanc/////////////////////////
Mat NBfilter(Mat frame){
Mat in_gray;

cvtColor(frame,frame,CV_BGR2GRAY);

return frame;

}


////////////////////////////seuillage bleu vers magenta////////////////////

Mat seuillageBtoM (Mat frame){
float nr;
for (int i=0;i<frame.rows;i++){ ///traitement sur les lignes

			for (int j=0;j<frame.cols;j++){///traitement sur les colonnes
				uchar r,v,b;

				b=frame.at<Vec3b>(i,j)[0];///declaration des couleur 
				v=frame.at<Vec3b>(i,j)[1];
				r=frame.at<Vec3b>(i,j)[2];
				nr=b/sqrt((r*r)+(b*b)+(v*v));///on choisit la couleur pour la changer


		if(nr>0.8)
			{
				frame.at<Vec3b>(i,j)[0]=b;/// couleur choisie qui change la couleur 
				frame.at<Vec3b>(i,j)[1]=0;
				frame.at<Vec3b>(i,j)[2]=b;

			}

		else{
			frame.at<Vec3b>(i,j)[0]=b;///// couleur autour del'objet
			frame.at<Vec3b>(i,j)[1]=v;
			frame.at<Vec3b>(i,j)[2]=r;
		}
	


			}
		}
return (frame);
}


////////////////////////////////gaussien//////////////////////////////////////

Mat gausien (Mat frame) {
Mat out2,in_gray;
	 
 GaussianBlur( frame, out2, Size( 15, 15 ), 10);


return(out2);

}
/////////////////////////////////miroir//////////////////////////////////
Mat mirroir(Mat frame)
{

float nr=1;
	
		for (int i=1;i<frame.rows;i++)
		{
			for (int j=1;j<frame.cols;j++)
			{uchar r,v,b;
				
				b=frame.at<Vec3b>(i,j)[0];
				v=frame.at<Vec3b>(i,j)[1];
				r=frame.at<Vec3b>(i,j)[2];

if(nr>0.0)
{frame.at<Vec3b>(i,1280-j)[0]=b;
			frame.at<Vec3b>(i,1280-j)[1]=v;
			frame.at<Vec3b>(i,1280-j)[2]=r;
}
}
			}
		
return(frame);

}
