#pragma once


namespace puzzle {

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
			//
			
			try
			{
				// загружаем файл картинки
				pics = gcnew Bitmap(Application::StartupPath + "\\puzzle.bmp");
			}
			catch (Exception^ )
			{
				MessageBox::Show("Файл 'puzzle.bmp' не найден.\n",
					"Puzzle game",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
				
				return;
			}

			// определяем высоту и ширину клетки (фишки)
			cw = (int)(pics->Width / nw);
			ch = (int)(pics->Height / nh);

			// установить размер клиентской области формы
			this->ClientSize =
				System::Drawing::Size(cw * nw + 1,
                            ch * nh + 1 + menuStrip1->Height);

			// рабочая графическая поверхность
			g = this->CreateGraphics();

			newGame();
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
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  MenuItem1;
	protected: 


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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->MenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->MenuItem1});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(284, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// MenuItem1
			// 
			this->MenuItem1->Name = L"MenuItem1";
			this->MenuItem1->Size = System::Drawing::Size(81, 20);
			this->MenuItem1->Text = L"Новая игра";
			this->MenuItem1->Click += gcnew System::EventHandler(this, &Form1::MenuItem1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 264);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Puzzle";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseClick);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private:
	// 4х4 - размер игрового поля
    static int nw = 4, nh = 4;

    // графическая поверхность
	System::Drawing::Graphics^ g;

    // картинка
    Bitmap^ pics;

    // размер (ширина и высота) клетки
    int cw, ch;

    // игровое поле - массив 4х4.
	// хранит номера фрагментов картинки
	static array<int,2>^ field = gcnew array<int,2>(4,4);

    // координаты пустой клетки
    int ex, ey;

    // отображать номера фишек
    static Boolean showNumbers = false; 


// новая игра
void newGame()
{
	// размместить фишки в правильном порядке
    for (int j = 0; j < nh; j++)
        for (int i = 0; i < nw; i++)
             field[i, j] = j * nw + i + 1;

    // последняя фишка - пустая
    field[nw - 1, nh - 1] = 0;
    ex = nw - 1; ey = nh - 1;

    this->mix();        // перемешиваем фишки
    this->drawField();   // рисуем игровое поле
}

// перемешивает фишки
void mix()
{
	int d; // положение (относительно пустой) перемещаемой
           // фишки: 0 - слева; 1 - справа;
           //         2 - сверху; 3 - снизу.

    int x, y; // координаты перемещаемой фишки 

    // генератор случайных чисел
    Random^ rnd = gcnew Random();

    
	// сделаем 160 сдвигов
	for (int i = 0; i < 160; i++)
    {
		x = ex;
        y = ey;

        // выберем фишку, которую будем
		// "двигать" в пустую клетку
		d = rnd->Next(4);
        switch (d)
        {
                case 0: if (x > 0) x--; break;
                case 1: if (x < nw - 1) x++; break;
                case 2: if (y > 0) y--; break;
                case 3: if (y < nh - 1) y++; break;
         }

         // здесь определили фишку, которую
         // нужно переместить в пустую клетку
         field[ex, ey] = field[x, y];
         field[x, y] = 0;

         // запоминаем координаты пустой клетки
         ex = x;
		 ey = y;
     }
}

// рисует поле
void drawField()
{
	// рисуем клетки
    for (int i = 0; i < nw; i++)
		for (int j = 0; j < nh; j++)
            {
                if (field[i, j] != 0)
				{
                    // рисуем фрагмент картинки:	
					// копируем фрагмент с одной графической
					// поверхности на другую
			
					// куда		
					Rectangle r1 =
						   Rectangle(i * cw,
                                  j * ch + menuStrip1->Height,
                                  cw, ch);
					// откуда
				    Rectangle r2 = Rectangle(
                            ((field[i, j] - 1) % nw) * cw,
                            ((field[i, j] - 1) / nw) * ch,
                            cw, ch);

					// копируем
					g->DrawImage(pics,r1,r2,GraphicsUnit::Pixel);
				}
				else
                    // выводим пустую фишку
					g->FillRectangle(SystemBrushes::Control,
                        i * cw, j * ch + menuStrip1->Height,
                         cw, ch);

                // рисуем границу
				g->DrawRectangle(Pens::Black,
                    i * cw, j * ch + menuStrip1->Height,
                    cw, ch);

                // номер фишки
                if ((showNumbers) && field[i, j] != 0)
                    g->DrawString(
					      Convert::ToString(field[i, j]),
				          // Font,
					      gcnew System::Drawing::Font("Tahoma", 12, FontStyle::Regular),
						  Brushes::Black,
						  (float)i * cw + 5,
                          (float)j * ch + 5 + menuStrip1->Height);
            }
}

// проверяет, расположены ли фишки в правильном порядке
private: Boolean finish()
{
	// координаты клетки
    int i = 0;
    int j = 0;

    int c;       // число в клетке

    // фишки расположены правильно, если
    // числа в них образуют матрицу:
    //   1  2  3  4
    //   5  6  7  8
    //   9 10 11 12
    //  13 14 15

    for (c = 1; c < nw * nh; c++)
    {
        if (field[i, j] != c) return false;

            // к следующей клетке
            if (i < nw - 1) i++;
            else { i = 0; j++; }
    }
    return true;
}

// перемещает фишку, на которой сделан щелчок,
// в соседнюю пустую клетку:
// (cx, cy) - клетка, в которой сделан щелчок,
// (ex, ey) - пустая клетка
private: void move(int cx, int cy)
{
	// проверим, возможен ли обмен
	if (!(((Math::Abs(cx - ex) == 1) && (cy - ey == 0)) ||
		((Math::Abs(cy - ey) == 1) && (cx - ex == 0))))
            return;

     // обмен. переместим фишку из (x, y) в (ex, ey)
     field[ex, ey] = field[cx, cy];
     field[cx, cy] = 0;

     ex = cx; ey = cy;

     // перерисовать поле
     this->drawField();

     // проверить, возможно фишки выстроены
	 // в правильном порядке
	 if (this->finish())
     {
            field[nw - 1, nh - 1] = nh * nw;
            this->drawField();

            // игра закончена. сыграть еще раз?
            // No  - завершить работу программы,
            // Yes - новая игра
			if (MessageBox::Show(
                   "Вы справились с поставленной задачей!\n" +
                   "Еще раз?", "Puzzle game",
				   MessageBoxButtons::YesNo,
				   MessageBoxIcon::Question)
				   == System::Windows::Forms::DialogResult::No)
                this->Close();
            else this->newGame();
        }
    }



	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
			 {
				 drawField();
			 }


// щелчок кнопкой мыши на игровом поле
private: System::Void Form1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
        // преобразуем координаты мыши в координаты клетки
        move( e->X/cw, (e->Y-menuStrip1->Height)/ch);

}


// команда Новая игра
private: System::Void MenuItem1_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 this->newGame();
		 }
};
}

