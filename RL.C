#include <TCanvas.h>
#include <TF1.h>
#include <TGraph.h>

void RL() {

  TGraph *g = new TGraph("elabored_data/Prova RL_1.txt", "%lg %lg");
  /* TF1 *fRL = new TF1("fRL", "[0]/sqrt(1 + pow(2*3.1415926535*x*[1]/[2], 2))",
                     100, 5001); */
  TF1 *fRL = new TF1(
      "fRL", "[0]*[2]/sqrt(pow([2]+[3], 2) + pow(2*pi*x*[1], 2))", 100, 5001);

  Double_t A0 = 2.5;
  Double_t L = 10.0E-3;
  Double_t R = 329.7;
  Double_t R_resto = 169;
  // Valori iniziali di partenza (sennò spesso il fit non converge)
  fRL->SetParameter(0, A0);      // A0
  fRL->SetParameter(1, L);       // L in mH (modifica se serve)
  fRL->SetParameter(2, R);       // R in ohm (modifica se serve)
  fRL->SetParameter(3, R_resto); // Rl+r in ohm (modifica se serve)

  fRL->SetParLimits(0, A0 - 0.01, A0 + 0.01);
  // fRL->SetParLimits(1, L - 0.001, L + 0.001);
  fRL->SetParLimits(2, R - 0.1, R + 0.1);
  fRL->SetParLimits(3, R_resto - (0.5 + 1.2), R + 0.5 + 1.2);
  /* fRL->FixParameter(0, 2.5);
  fRL->FixParameter(2, 1000.0); */

  g->SetTitle("Ramo RL");
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
