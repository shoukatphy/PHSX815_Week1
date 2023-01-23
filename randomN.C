#include"TRandom.h"
#include"TH1D.h"
#include<iostream>
using namespace std;

//random is root macro/also a func name
void randomN(long num=8888){

        //declaring a random instance
        TRandom *randm = new TRandom();

	//declaring 1D histo
       TH1D *h = new TH1D("h", "Random number plot", 3000, -10, 10);

        //declare the file
        ofstream outputFile;
        //open it
        outputFile.open("myFile.txt"); 

         int max = 10000; //declared a maxima for loop
	//making loop
for(int i=0; i<max; i++){
         outputFile << randm->Rndm() <<endl;//filling the numbers into the file
	h->Fill(randm->Rndm()); //filling the histogram
}
         outputFile.close();//closed output file


//creat the canvas 
TCanvas *c = new TCanvas();
//draw the histo
h->SetLineColor(3);
h->GetXaxis()->SetTitle("Range"); //giving titles to axis
h->GetYaxis()->SetTitle("Entry Number");
h->Draw();
//save the plot

c->SaveAs("Histo.pdf");
}

