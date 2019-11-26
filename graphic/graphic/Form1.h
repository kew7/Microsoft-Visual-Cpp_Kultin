#pragma once


namespace graphic {

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
	public:
		Form1(void)
		{
			InitializeComponent();
			
			// чтение данных из файла в массив
			System::IO::StreamReader^ sr; // поток для чтения
            try
            {
				sr = gcnew System::IO::StreamReader(
					Application::StartupPath + "\\usd.dat");

                // cоздаем массив 
                d = gcnew array<double>(10);

                // читаем данные из файла
                int i = 0;
                String^ t = sr->ReadLine();
				while ((  t != String::Empty) && (i < d->Length))
                {
                    // записываем считанное число в массив
					d[i++] = Convert::ToDouble(t);
                    t = sr->ReadLine();
                }

                // закрываем поток
                sr->Close();


			    // данные загружены
				// задаем функцию обработки события Paint
				this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::drawDiagram);
                
            }
            
			// обработка исключений:
            // - файл данных не найден
			catch (System::IO::FileNotFoundException^ ex)
            { 
				MessageBox::Show( ex->Message + "\n",
                    "График",
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
			this->ClientSize = System::Drawing::Size(429, 264);
			this->MinimumSize = System::Drawing::Size(320, 240);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"График";
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion


private:
        
// данные
array<double>^ d;      

// строит график 
void drawDiagram(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
{
	// графическая поверхность
	System::Drawing::Graphics^ g = e->Graphics;

    // шрифт подписей данных
    System::Drawing::Font^ dFont = gcnew System::Drawing::Font("Tahoma", 9);

   
    // шрифт заголовка
    System::Drawing::Font^ hFont = gcnew System::Drawing::Font("Tahoma", 13,
				FontStyle::Regular);
    String^ header = "Изменение курса доллара";

    // ширина области отображения текста
    int wh =(int)g->MeasureString(header, hFont).Width;

    int x = (this->ClientSize.Width - wh) / 2; 
            
    g->DrawString(header,hFont, Brushes::DarkGreen, x, 5);

    /* Область построения графика.
       Отступы:
	       сверху - 100;
           снизу - 20;
           слева - 20;
           справа - 20.
             
        ClientSize - размер внутренней области окна
             
        График строим в отклонениях от минимального
        значения ряда данных, так, чтобы он занимал
        всю область построения
	*/
            
    double max = d[0]; // максимальный эл-т массива
    double min = d[0]; // минимальный эл-т массива

    for (int i = 1; i < d->Length; i++)
    {
		if (d[i] > max) max = d[i];
        if (d[i] < min) min = d[i];
    }

	// рисуем график
    int x1, y1, x2, y2;

    // расстояние между точками графика (шаг по Х )
    int sw = (int)((this->ClientSize.Width - 40) /
                            (d->Length - 1));

    // первая точка
    x1 = 20;
    y1 = this->ClientSize.Height - 20 -
                (int)((this->ClientSize.Height - 100) *
                (d[0] - min) / (max - min));

    // маркер первой точки
	g->DrawRectangle(Pens::Black,
                x1 - 2, y1 - 2, 4, 4);

    // подпись численного значения первой точки
	g->DrawString(Convert::ToString(d[0]),
		dFont, Brushes::Black,
                x1 - 10, y1 - 20);

    // остальные точки
    for (int i = 1; i < d->Length; i++)
    {                
		x2 = 8 + i * sw;
        y2 = this->ClientSize.Height - 20 -
                    (int)((this->ClientSize.Height - 100) *
                    (d[i] - min) / (max - min));

        // маркер точки
		g->DrawRectangle(Pens::Black,
                      x2 - 2, y2 - 2, 4, 4);

        // соединим текущую точку с предыдущей
		g->DrawLine(Pens::Black,
                    x1, y1, x2, y2);

        // подпись численного значения
		g->DrawString(Convert::ToString(d[i]), 
			dFont, Brushes::Black,
                    x2 - 10, y2 - 20);

        x1 = x2;
        y1 = y2;
    }
}

private: System::Void Form1_Resize(System::Object^  sender, System::EventArgs^  e)
{
	this->Refresh();
}

};
}

