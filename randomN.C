#include"TRandom.h"
#include"TH1D.h"
#include<iostream>
using namespace std;

//random is root macro/also a func name
void randomN(long num=6000){

//declaring a random instance

	TRandom *randm = new TRandom();
//declaring 1D histo

	TH1D *h = new TH1D("h", "Random number plot", 3000, -10, 10);
	//loop the filling histogram with random numbers
	int max=10000;
for(int i=0; i<max; i++){
h->Fill(randm->Rndm());
}

//creat the canvas 
TCanvas *c = new TCanvas();
//draw the histo

h->SetLineColor(3);
h->Draw();
//save the plot
c->SaveAs("Histo.pdf");
}

