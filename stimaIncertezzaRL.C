void stimaIncertezzaRL() {
  // Apri il file di testo
  std::ifstream infile("elabored_data/a.txt");
  if (!infile) {
    std::cerr << "Errore nell'apertura del file dati.txt" << std::endl;
    return;
  }

  // Crea l'istogramma: 50 bin tra 0 e 5 (modifica a seconda dei tuoi dati)
  TH1F* hist = new TH1F("hist", "Istogramma dei dati", 20,-2.175, -2.155);

  double val;
  while (infile >> val) {
    hist->Fill(val);
  }
  hist ->Fit("gaus");

  // Disegna l'istogramma
  TCanvas* c1 = new TCanvas("c1", "Canvas", 800, 600);
  hist->GetXaxis()->SetTitle("Valori");
  hist->GetYaxis()->SetTitle("Frequenza");
  hist->Draw();

  // Salva il grafico come immagine
  c1->SaveAs("istogramma.png");
}
