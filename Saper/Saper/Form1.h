// »гра —апер
// (c) Ќикита  ультин
// ѕример из книги:  ультин Ќ.Ѕ. Microsoft Visual C++ в задачах и примерах
#pragma once

#include "AboutForm.h"

namespace Saper {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Form1
	///
	/// ¬нимание! ѕри изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") дл€ средства компил€ции управл€емого ресурса,
	///          св€занного со всеми файлами с расширением .resx, от которых зависит данный класс. ¬ противном случае,
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
			// ¬ неотображаемые эл-ты массива, соответствующие
      // клеткам границы игрового пол€ запишем число -3.
      // Ёто значение используетс€ процедурой open()
      // дл€ завершени€ рекурсивного процесса открыти€
      // соседних пустых клеток
      for(int row = 0; row <= MR+1; row++)
      {
          Pole[row,0] = -3;
          Pole[row,MC+1] = -3;
      }
          
      for(int col = 0; col <= MC+1; col++)
      {
          Pole[0,col] = -3;
          Pole[MR+1,col] = -3;            
      }

      // устанавливаем размер формы в соответствии
      // с размером игрового пол€
	  this->ClientSize = System::Drawing::Size(W*MC + 1,
                     H*MR +  menuStrip1->Height +  1);

      newGame(); // нова€ игра

      // графическа€ поверхность
      g = panel1->CreateGraphics();

		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::ToolStripMenuItem^  нова€»граToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  справкаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  правилаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  оѕрограмме—аперToolStripMenuItem;
	private: System::Windows::Forms::HelpProvider^  helpProvider1;
	protected: 

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->нова€»граToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->правилаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оѕрограмме—аперToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->helpProvider1 = (gcnew System::Windows::Forms::HelpProvider());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->нова€»граToolStripMenuItem, 
				this->справкаToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(284, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// нова€»граToolStripMenuItem
			// 
			this->нова€»граToolStripMenuItem->Name = L"нова€»граToolStripMenuItem";
			this->нова€»граToolStripMenuItem->Size = System::Drawing::Size(81, 20);
			this->нова€»граToolStripMenuItem->Text = L"Ќова€ игра";
			this->нова€»граToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::нова€»граToolStripMenuItem_Click);
			// 
			// справкаToolStripMenuItem
			// 
			this->справкаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->правилаToolStripMenuItem, 
				this->оѕрограмме—аперToolStripMenuItem});
			this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
			this->справкаToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->справкаToolStripMenuItem->Text = L"—правка";
			// 
			// правилаToolStripMenuItem
			// 
			this->правилаToolStripMenuItem->Name = L"правилаToolStripMenuItem";
			this->правилаToolStripMenuItem->Size = System::Drawing::Size(186, 22);
			this->правилаToolStripMenuItem->Text = L"ѕравила";
			this->правилаToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::правилаToolStripMenuItem_Click);
			// 
			// оѕрограмме—аперToolStripMenuItem
			// 
			this->оѕрограмме—аперToolStripMenuItem->Name = L"оѕрограмме—аперToolStripMenuItem";
			this->оѕрограмме—аперToolStripMenuItem->Size = System::Drawing::Size(186, 22);
			this->оѕрограмме—аперToolStripMenuItem->Text = L"ќ программе —апер";
			this->оѕрограмме—аперToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::оѕрограмме—аперToolStripMenuItem_Click);
			// 
			// panel1
			// 
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 24);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(284, 240);
			this->panel1->TabIndex = 1;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel1_Paint);
			this->panel1->Click += gcnew System::EventHandler(this, &Form1::panel1_Click);
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel1_MouseClick);
			// 
			// helpProvider1
			// 
			this->helpProvider1->HelpNamespace = L"E:\\Users\\Ќикита\\Documents\\Visual Studio 2008\\CppProjects\\Saper\\help\\saper.chm";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 264);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"—апер";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private:

  static int
    MR = 10, // кол-во клеток по вертикали
    MC = 10, // кол-во клеток по горизонтали
    NM = 10, // кол-во мин
    W = 40,  // ширина клетки
    H = 40;  // высота клетки

  // игровое (минное) поле
  static array<int,2>^ Pole = gcnew array<int,2>(MR + 2,MC + 2);
  // значение элемента массива:
  // 0..8 - количество мин в соседних клетках
  // 9 - в клетке мина
  // 100..109 - клетка открыта
  // 200..209 - в клетку поставлен флаг

  int nMin;  // кол-во найденных мин
  int nFlag; // кол-во поставленных флагов

  // статус игры
  int status;
  // 0 - начало игры,
  // 1 - игра,
  // 2 Ц результат

  // графическа€ поверхность формы
  System::Drawing::Graphics^ g;


// нова€ игра
void newGame()
{
    int row, col;    // индексы клетки
    int n = 0;       // количество поставленных мин
    int k;           // кол-во мин в соседних клетках

    // очистить поле
    for(row = 1; row <= MR; row++)
        for(col = 1; col <= MC; col++)
            Pole[row,col] = 0;

    // генератор случайных чисел
    Random^ rnd = gcnew Random();

    // расставим мины
    do
    {
        row = rnd->Next(MR) + 1;
        col = rnd->Next(MC) + 1;

        if (Pole[row,col] != 9)
        {
            Pole[row,col] = 9;
            n++;
        }
    }
    while (n != NM);

    // дл€ каждой клетки вычислим кол-во 
    // мин в соседних клетках
    for(row = 1; row <= MR; row++)
        for(col = 1; col <= MC; col++)
            if (Pole[row,col] != 9)
            {
                k = 0;

                if (Pole[row-1,col-1] == 9) k++;
                if (Pole[row-1,col]   == 9) k++;
                if (Pole[row-1,col+1] == 9) k++;
                if (Pole[row,col-1]   == 9) k++;
                if (Pole[row,col+1]   == 9) k++;
                if (Pole[row+1,col-1] == 9) k++;
                if (Pole[row+1,col]   == 9) k++;
                if (Pole[row+1,col+1] == 9) k++;

                Pole[row,col] = k;
            }

    status = 0;      // начало игры
    nMin   = 0;      // нет обнаруженных мин
    nFlag  = 0;      // нет поставленных флагов
  }

// рисует поле
void showPole(Graphics^ g, int status)
{
    for(int row = 1; row <= MR; row++)
        for(int col = 1; col <= MC; col++)
            this->kletka(g, row, col, status);
}

// рисует клетку
void kletka(Graphics^ g,
    int row, int col, int status)
{
    int x,y;// координаты левого верхнего угла клетки
    
    x = (col - 1) * W + 1;
    y = (row-1)* H + 1;

    // не открытые клетки - серые
    if (Pole[row,col] < 100)
		g->FillRectangle(SystemBrushes::ControlLight,
            x-1, y-1, W, H);

    // открытые или помеченные клетки
    if (Pole[row,col] >= 100) {

        // открываем клетку, открытые - белые
        if (Pole[row,col] != 109)
			g->FillRectangle(Brushes::White,
                x-1, y-1, W, H);
        else
            // на этой мине подорвались!
			g->FillRectangle(Brushes::Red,
                x-1, y-1, W, H);

        // если в соседних клетках есть мины,
        // указываем их количество
        if ((Pole[row,col] >= 101) && (Pole[row,col] <= 108))
			g->DrawString((Pole[row,col]-100).ToString(),
			gcnew System::Drawing::Font("Tahoma", 10,
				System::Drawing::FontStyle::Regular),
				Brushes::Blue, (float)x+3, (float)y+2);
    }

    // в клетке поставлен флаг
    if (Pole[row,col] >= 200)
        this->flag(g, x, y);

    // рисуем границу клетки
	g->DrawRectangle(Pens::Black,
        x-1, y-1, W, H);

    // если игра завершена (status = 2),
    // показываем мины
    if ((status == 2) && ((Pole[row,col] % 10) == 9))
        this->mina(g, x, y);
  }

  // открывает текущую и все соседние с ней клетки,
  // в которых нет мин
  void open(int row, int col)
  {
    // координаты области вывода
    int x = (col-1)* W + 1,
        y = (row-1)* H + 1;
    
    if (Pole[row,col] == 0)
    {
        Pole[row,col] = 100;

        // отобразить содержимое клетки
        this->kletka(g, row, col, status);

        // открыть примыкающие клетки
        // слева, справа, сверху, снизу
        this->open(row, col-1);
        this->open(row-1, col);
        this->open(row, col+1);
        this->open(row+1, col);

        //примыкающие диагонально
        this->open(row-1,col-1);
        this->open(row-1,col+1);
        this->open(row+1,col-1);
        this->open(row+1,col+1);
    }
    else
        if ((Pole[row,col] < 100) &&
             (Pole[row,col] != -3))
        {
            Pole[row,col] += 100;
            // отобразить содержимое клетки
            this->kletka(g, row, col, status);
        }
  }

  // рисует мину
  void mina(Graphics^ g, int x, int y)
  {
    // корпус
	  g->FillRectangle(Brushes::Green,
        x+16, y+26, 8, 4);
	  g->FillRectangle(Brushes::Green,
        x+8, y+30, 24, 4);
	  g->DrawPie(Pens::Black,
        x+6, y+28, 28, 16, 0, -180);
	  g->FillPie(Brushes::Green,
        x+6, y+28, 28, 16, 0, -180);

    // полоса на корпусе
	  g->DrawLine(Pens::Black,
        x+12, y+32, x+28, y+32);

    // вертикальный "ус"
	  g->DrawLine(Pens::Black,
        x+20, y+22, x+20, y+26);

    // боковые "усы"
	  g->DrawLine(Pens::Black,
        x+8, y+30, x+6, y+28);
	  g->DrawLine(Pens::Black,
        x+32, y+30, x+34, y+28);
  }

  // рисует флаг
  void flag(Graphics^ g, int x, int y)
  {
    array<Point>^ p = gcnew array<Point>(3);
    array<Point>^ m = gcnew array<Point>(5);
    //Point[] m = new Point[5];            

    // флажок
    p[0].X = x+4;   p[0].Y = y+4;
    p[1].X = x+30;  p[1].Y = y+12;
    p[2].X = x+4;   p[2].Y = y+20;
	g->FillPolygon(Brushes::Red, p);

    // древко
	g->DrawLine(Pens::Black,
        x+4, y+4, x+4, y+35);

    // буква M на флажке
    m[0].X = x+8;   m[0].Y = y+14;
    m[1].X = x+8;   m[1].Y = y+8;
    m[2].X = x+10;  m[2].Y = y+10;
    m[3].X = x+12;  m[3].Y = y+8;
    m[4].X = x+12;  m[4].Y = y+14;
	g->DrawLines(Pens::White, m);
  }


// обработка событи€ Paint
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
			 {

				 showPole(g, status);
			 }


		 
		 
		 
// щелчок в клетке игрового пол€
private: System::Void panel1_Click(System::Object^  sender, System::EventArgs^  e)
{	    

}

// щелчок в клетке игрового пол€
private: System::Void panel1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{

	if (status == 2)
		// игра завершена
		return;

    if (status == 0)
		// первый щелчок
		status = 1;
        
    // преобразуем координаты мыши в индексы
    // клетки пол€, в которой был сделан щелчок;
    // (e.X, e.Y) - координаты точки формы,
    // в которой была нажата кнопка мыши
    int row,col;
	
	
	row = e->Y/H + 1;
    col = e->X/W + 1;

    // координаты области вывода
    int x = (col-1)* W + 1,
        y = (row-1)* H + 1;

    // щелчок левой кнопки мыши
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
    {                
        // открыта клетка, в которой есть мина
        if (Pole[row,col] == 9)
        {                
            Pole[row,col] += 100;

            // игра закончена
            status = 2;

            // перерисовать форму
            this->panel1->Invalidate();
        }
        else
            if (Pole[row,col] < 9)
				// открыть клетку
                this->open(row,col);
    }

    // щелчок правой кнопки мыши
	if (e->Button == System::Windows::Forms::MouseButtons::Right) {

        // в клетке не было флага, ставим его
        if (Pole[row,col] <= 9) {
            nFlag += 1;

            if (Pole[row,col] == 9)
                nMin += 1;

            Pole[row,col] += 200;

            if ((nMin == NM) && (nFlag == NM)) {
                // игра закончена
                status = 2;

                // перерисовываем все игровое поле
                this->Invalidate();
            }
            else
                // перерисовываем только клетку
                this->kletka(g, row, col, status);
        }
        else
            // в клетке был поставлен флаг,
            // повторный щелчок правой кнопки мыши
            // убирает его и закрывает клетку
            if (Pole[row,col] >= 200)
            {                                 
                nFlag -= 1;
                Pole[row,col] -= 200;

                // перерисовываем клетку
                this->kletka(g, row, col, status);
            }
  }  
}

// команда Ќова€ игра
private: System::Void нова€»граToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 newGame();
             showPole(g, status);

		 }

// ¬ыбор в меню —правка команды ѕравила
private: System::Void правилаToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 { 
			 Help::ShowHelp(this,helpProvider1->HelpNamespace,"saper_02.htm");
			 
		 }

// ¬ыбор в меню —правка команды ќ программе
private: System::Void оѕрограмме—аперToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			AboutForm^ frm = gcnew AboutForm();

			frm->ShowDialog();
		 }



};
}

