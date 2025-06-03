#include <TCanvas.h>
#include <TGraph.h>

void RL() {
  

  TGraph* g = new TGraph("elabored_data/Prova RL_1.txt", "%lg %lg");   // Crea l'istogramma: 50 bin tra 0 e 5 (modifica a seconda dei tuoi dati)
T
  g->SetTitle("Ramo RL");
  g->GetXaxis()->SetTitle("Frequenza (Hz)");
  g->GetYaxis()->SetTitle("Ampiezza (V)");

  TCanvas *c = new TCanvas("c", "Log X", 800, 600);

  // Imposto asse X logaritmico
  c->SetLogx();
  c->SetLogy();

  // Disegno il grafico
  g->Draw("ALP");
}
