public ref class Timer : public System::Windows::Forms::Form
{ 			//Zmienne dla licznika czasu
 private:	
 
 			int CzasLicznik; //Ilość sekund do końca odliczania
 			int srednica, promien, szer, wys, lok_Y;
 			float kat;
 			float powiekszenie_kata;
 			PointF point_tekst;
			SizeF rozmiar_lan;
			
			System::Drawing::Graphics^ g;
 			Rectangle prostokat;
			static SolidBrush^ zielony = gcnew SolidBrush(Color::LimeGreen);
 			static SolidBrush^ zolty = gcnew SolidBrush(Color::FromArgb(227,217,15));
			static SolidBrush^ pomarancz = gcnew SolidBrush(Color::DarkOrange);
			static SolidBrush^ czerwony = gcnew SolidBrush(Color::Red); 			
    			 static SolidBrush^ bialy = gcnew SolidBrush(Color::White);
      			static Pen^ pioro = gcnew Pen( Color::Black, 0.0f ); //Niewidoczne obramowanie
      			static Drawing::Font^ czcionka_timer;
		
//Funkcja rysuje niepełne koło i napis z liczbą sek. pozostałych do końca odliczania 
private: System::Void timerLicznik_Tick(System::Object^  sender, System::EventArgs^  e) {

			if (CzasLicznik <= 0)
				timerLicznik->Stop()

			else
			 {
				 --CzasLicznik;
				 kat += powiekszenie_kata; //Zwiększ kąt wycinka koła

				g->Clear(panelZegar->BackColor); //Wyczyść tło

			//Rysuj elipsę na polu prostokąta rect
			g->DrawEllipse(blackPen, rect);

			//Wypełnij wycinek koła kolorem na podst. pozostałych sekund
			if (CzasLicznik > 9)
				g->FillPie( zielony, rect, 270.0F, kat);
			else
				if (CzasLicznik > 6)
				g->FillPie( zolty, rect, 270.0F, kat);
				else
					if (CzasLicznik > 3)
						g->FillPie( pomarancz, rect, 270.0F, kat);
					else
						g->FillPie( czerwony, rect, 270.0F, kat);

			//Zmierz rozmiar napisu
			rozmiar_lan = g->MeasureString( CzasLicznik.ToString(), drawFont);

			//Oblicz lewy, górny punkt wypoœrodkowanego napisu 
			point_tekst = PointF((szer - rozmiar_lan.Width)/2, lok_Y);	//Wypośrodkowany napis

			//Narysuj licznę pozostałych sekund
			g->DrawString(CzasLicznik.ToString(), drawFont, drawBrush, point_tekst);
		 }
  }
