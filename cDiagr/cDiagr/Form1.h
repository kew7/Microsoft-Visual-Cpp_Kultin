// Рисует круговую диаграмму.
// Данные считываются из файла.
// Максимальное количество рядов данных - 8.
#pragma once


namespace cDiagr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	
	
private:
	String^ header;  // заголовок диаграммы

    // количество элементов данных
    int N;
      
    array<double>^ dat; // ряд данных
    array<double>^ p;   // доля категории в общей сумме

    // подписи данных
   array<String^>^ title;

	
	public:
		Form1(void)
		{
			InitializeComponent();
			
			System::IO::StreamReader^ sr;

			
	try
    {

			sr = gcnew System::IO::StreamReader(
				Application::StartupPath + "\\date.dat",
				System::Text::Encoding::GetEncoding(1251));

            // считываем заголовок диаграммы
            header = sr->ReadLine();

            // считываем данные о количестве записей
			N = Convert::ToInt16(sr->ReadLine());
            
			// и инициализируем массивы
			dat = gcnew array<double>(N);
            p = gcnew array<double>(N);
            title = gcnew array<String^>(N);

            // читаем данные
            int i = 0;
            String^ st;
            st = sr->ReadLine();
			while ((st != String::Empty) && (i < N))
            {
				title[i] = st;

                st = sr->ReadLine();
			    dat[i++] = Convert::ToDouble(st);

                st = sr->ReadLine();
            }

            // закрываем поток
            sr->Close();

            // данные загружены
			// задаем функцию обработки события Paint
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::drawDiagram);
              
            double sum = 0;
            int j = 0;
                
            // вычислить сумму
            for (j = 0; j < N; j++)
				sum += dat[j];

            // вычислить долю каждой категории
            for (j = 0; j < N; j++)
                    p[j] = (double)(dat[j] / sum);
       }
       catch (System::IO::FileNotFoundException^ ex)
            {
				MessageBox::Show(ex->Message,
                    "Диаграмма",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
            }


		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(454, 264);
			this->MinimumSize = System::Drawing::Size(470, 300);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Круговая диаграмма";
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion

// рисует круговую диаграмму 
void drawDiagram(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
{
	// графическая поверхность
	System::Drawing::Graphics^ g = e->Graphics;

    // шрифт заголовка	 
			System::Drawing::Font^ hFont = gcnew System::Drawing::Font("Tahoma", 12);
       
    // выводим заголовок
    int w = (int)g->MeasureString(header, hFont).Width;
    int x = (ClientSize.Width - w) / 2;

    g->DrawString(header,hFont, Brushes::Black, x, 10);

    // шрифт легенды
	System::Drawing::Font^ lFont = gcnew System::Drawing::Font("Tahoma", 9);

    // диаметр диаграммы
    int d = ClientSize.Height - 80;

    int x0 = 30;
    int y0 = (ClientSize.Height - d) / 2 + 10;

    // координаты верхнего левого угла
    // области легенды
    int lx = 60 + d;
    int ly = y0 + (d - N * 20 + 10) / 2;

    int swe; // длинна дуги сектора

    // кисть для заливки сектора диаграммы
	System::Drawing::Brush^  fBrush = Brushes::White;

    // начальная точка дуги сектора
    int sta = -90;
            
    // рисуем диаграмму
    for (int i = 0; i < N; i++)
    {
		// длинна дуги
        swe = (int)(360 * p[i]);

		// задать цвет сектора
        switch (i)
        {
			case 0:
				fBrush = Brushes::YellowGreen;
				break;
            case 1:
				fBrush = Brushes::Gold;
				break;
            case 2:
				fBrush = Brushes::Pink;
				break;
            case 3:
				fBrush = Brushes::Violet;
				break;
            case 4:
				fBrush = Brushes::OrangeRed;
				break;
            case 5:
				fBrush = Brushes::RoyalBlue;
				break;
            case 6:
				fBrush = Brushes::SteelBlue;
				break;
            case 7:
				fBrush = Brushes::Chocolate;
				break;
            case 8:
				fBrush = Brushes::LightGray;
				break;
		}

        // из-за округления возможна ситуация
        // при которой будет промежуток между
        // последним и первым секторами
        if (i == N - 1)
			// последний сектор
            swe = 270 - sta;
                

        // рисуем сектор
        g->FillPie(fBrush, x0, y0, d, d, sta, swe);

        // рисуем границу сектора
		g->DrawPie(Pens::Black, x0, y0,
                        d, d, sta, swe);
                
        // прямоугольник легенды
        g->FillRectangle(fBrush,
                          lx, ly + i * 20, 20, 10);
		g->DrawRectangle(Pens::Black,
                          lx, ly + i * 20, 20, 10);

        // подпись
        g->DrawString( title[i] + " - " +
					p[i].ToString("P"),
					lFont, Brushes::Black,
                          lx + 24, ly + i * 20 - 3);

        // начальная точка дуги для следующего сектора
        sta = sta + swe; 
	}
}


private: System::Void Form1_Resize(System::Object^  sender, System::EventArgs^  e)
			 {
				 this->Refresh();
			 }




};
}

