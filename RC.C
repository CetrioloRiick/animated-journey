#include <TCanvas.h>
#include <TF1.h>
#include <TGraph.h>

void RC() {

  TGraph *g = new TGraph("elabored_data/Prova RC_1.txt", "%lg %lg");
  /* TF1 *fRL = new TF1("fRL", "[0]/sqrt(1 + pow(2*3.1415926535*x*[1]/[2], 2))",
                     100, 5001); */
  TF1 *fRL =
      new TF1("fRL", "([0]*[1]*[3]*2*pi*x/sqrt(1+pow(([0]+[2])*[1]*2*pi*x, 2)))*[0]/([0]+[2])",
              1000, 50001);

  Double_t R = 330;
  Double_t C = 10E-9;
  Double_t r_g = 50;
  Double_t A0 = 2.5;
  // Valori iniziali di partenza (sennò spesso il fit non converge)
  fRL->SetParameter(0, R);
  fRL->SetParameter(1, C);
  fRL->SetParameter(2, r_g);
  fRL->SetParameter(3, A0);

  fRL->SetParLimits(3, A0 - 0.01, A0 + 0.01);
  fRL->SetParLimits(2, r_g - 0.5, r_g + 0.5);
  fRL->SetParLimits(0, R - 3.3, R + 3.3);
  // fRL->SetParLimits(3, A0, A0);

  g->SetTitle("Ramo RC");
  g->GetXaxis()->SetTitle("Frequenza (Hz)");
  g->GetYaxis()->SetTitle("Ampiezza (V)");

  g->Fit(fRL);
  TCanvas *c = new TCanvas("c", "Log X", 800, 600);

  // Imposto asse X logaritmico
  c->SetLogx();
  c->SetLogy();

  // Disegno il grafico
  g->Draw("ALP");
}
