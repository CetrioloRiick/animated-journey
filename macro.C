/* void macro() {
  // Apri il file di testo
  std::ifstream infile("elabored_data/incertezzaVs.txt");
  if (!infile) {
    std::cerr << "Errore nell'apertura del file dati.txt" << std::endl;
    return;
  }

  // Crea l'istogramma: 50 bin tra 0 e 5 (modifica a seconda dei tuoi dati)
  TH1F *hist =
      new TH1F("hist", "Stima incertezza di acquizizione sulla tensione", 87,
               2.164, 2.178);

  double val;
  while (infile >> val) {
    hist->Fill(val);
  }

  gStyle->SetGridColor(16);
  gStyle->SetGridStyle(3);
  gStyle->SetGridWidth(1);

  hist->Fit("gaus");
  // Disegna l'istogramma

  hist->SetLineColor(kAzure + 1);
  hist->SetLineWidth(2);
  hist->SetFillColorAlpha(kAzure - 9, 0.35);

  hist->GetYaxis()->SetTitle("Conteggi");
  hist->GetXaxis()->SetTitle("Tensione (V)");

  hist->Draw("HIST");

  gaus->SetLineColor(kRed + 1);
  gaus->SetLineWidth(2);
  gaus->Draw("SAME");

  // Legenda
  TLegend *legend = new TLegend(0.65, 0.75, 0.88, 0.88);
  legend->SetBorderSize(0);
  legend->SetFillColorAlpha(0, 0);
  legend->SetTextFont(42);
  legend->SetTextSize(0.04);
  legend->AddEntry(hist, "Dati sperimentali", "f");
  legend->AddEntry(gaus, "Fit gaussiano", "l");
  legend->Draw();
  // Salva il grafico come immagine
} */
void macro() {
  // Apri il file di testo
  std::ifstream infile("elabored_data/incertezzaVs.txt");
  if (!infile) {
    std::cerr << "Errore nell'apertura del file incertezzaVs.txt" << std::endl;
    return;
  }

  // Crea l'istogramma
  TH1F* hist = new TH1F("hist", "Stima incertezza di acquisizione sulla
tensione", 87, 2.164, 2.178);

  double val;
  while (infile >> val) {
    hist->Fill(val);
  }



  // Imposta stile generale
  gStyle->SetOptStat(0);
  gStyle->SetTitleFont(42, "");
  gStyle->SetLabelFont(42, "XYZ");
  gStyle->SetTitleSize(0.05, "XYZ");
  gStyle->SetLabelSize(0.035, "XYZ");
  gStyle->SetTitleOffset(1.4, "X");  // Sposta il titolo X più in basso
  gStyle->SetTitleOffset(1.5, "Y");  // Sposta il titolo Y più a sinistra
  gStyle->SetFrameLineWidth(2);
  gStyle->SetCanvasColor(0);
  gStyle->SetPadColor(0);
  gStyle->SetGridColor(16);
  gStyle->SetGridStyle(3);
  gStyle->SetGridWidth(1);

  // Fit gaussiano
  TF1* gaus = new TF1("gaus", "gaus", 2.164, 2.178);
  hist->Fit(gaus, "R");

  // Canvas con margini aumentati
  TCanvas* c1 = new TCanvas("c1", "Incertezza Tensione", 900, 700);
  c1->SetLeftMargin(0.15);   // aumenta margine sinistro per farci stare Y
  c1->SetBottomMargin(0.15); // aumenta margine basso per farci stare X
  c1->SetGrid();

  hist->SetLineColor(kAzure+1);
  hist->SetLineWidth(2);
  hist->SetFillColorAlpha(kAzure-9, 0.35);

  hist->GetXaxis()->SetTitle("Tensione (V)");
  hist->GetYaxis()->SetTitle("Conteggi");
  hist->GetXaxis()->CenterTitle();
  hist->GetYaxis()->CenterTitle();

  hist->Draw("HIST");

  gaus->SetLineColor(kRed+1);
  gaus->SetLineWidth(2);
  gaus->Draw("SAME");

  // Legenda
  TLegend* legend = new TLegend(0.65, 0.75, 0.88, 0.88);
  legend->SetBorderSize(0);
  legend->SetFillColorAlpha(0, 0);
  legend->SetTextFont(42);
  legend->SetTextSize(0.04);
  legend->AddEntry(hist, "Dati sperimentali", "f");
  legend->AddEntry(gaus, "Fit gaussiano", "l");
  legend->Draw();

  c1->Update();
}