// Игра "Парные картинки"
// (с) Никита Культин, 2009.


#include "About.h"

#pragma once


namespace dblPic {

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
            // загружаем файл с картинками
			pics = gcnew Bitmap(Application::StartupPath + 
				               "\\pictures.bmp");
        }
        catch (Exception^ )
        {
			MessageBox::Show("Файла 'pictures.bmp' не найден.\n",
                             "Парные картинки",
			                 MessageBoxButtons::OK,
			                 MessageBoxIcon::Error);	  
			
			this->новаяИграToolStripMenuItem->Enabled = false;

          return;
        }

		// Зададим функцию обработки события Click на форме.
		// Если функцию обработки задать обычным образом,
		// то в процедуре drawCell надо
		// контролировать, загружена ли картинка.
		// Так проще.
		this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseClick);

        // определяем размер картинки и устанавливаем
        // размер клеток игрового поля
        cw = (int)(pics->Width / np);
        ch = pics->Height;

        // установить размер клиентской области формы
        // в соответствии с размером картинок и их количеством
        // (см. определения констант cw и ch)
        this->ClientSize =
			System::Drawing::Size(nw * (cw + 2) + 1,
                      nh * (ch + 2) + 1 + menuStrip1->Height);

        // рабочая графическая поверхность
        g = this->CreateGraphics();
        
        // создать объект timer1
        timer1 = gcnew Timer();

		timer1->Tick +=
			gcnew System::EventHandler(this, &Form1::timer1_Tick);
        
		timer1->Interval = 200;
       
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
	private: System::Windows::Forms::ToolStripMenuItem^  новаяИграToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  справкаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  справкаToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  оПрограммеToolStripMenuItem;


	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->новаяИграToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->справкаToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->новаяИграToolStripMenuItem, 
				this->справкаToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(284, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// новаяИграToolStripMenuItem
			// 
			this->новаяИграToolStripMenuItem->Name = L"новаяИграToolStripMenuItem";
			this->новаяИграToolStripMenuItem->Size = System::Drawing::Size(81, 20);
			this->новаяИграToolStripMenuItem->Text = L"Новая игра";
			this->новаяИграToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::новаяИграToolStripMenuItem_Click);
			// 
			// справкаToolStripMenuItem
			// 
			this->справкаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->справкаToolStripMenuItem1, 
				this->оПрограммеToolStripMenuItem});
			this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
			this->справкаToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->справкаToolStripMenuItem->Text = L"Справка";
			// 
			// справкаToolStripMenuItem1
			// 
			this->справкаToolStripMenuItem1->Enabled = false;
			this->справкаToolStripMenuItem1->Name = L"справкаToolStripMenuItem1";
			this->справкаToolStripMenuItem1->Size = System::Drawing::Size(149, 22);
			this->справкаToolStripMenuItem1->Text = L"Справка";
			// 
			// оПрограммеToolStripMenuItem
			// 
			this->оПрограммеToolStripMenuItem->Name = L"оПрограммеToolStripMenuItem";
			this->оПрограммеToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->оПрограммеToolStripMenuItem->Text = L"О программе";
			this->оПрограммеToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::оПрограммеToolStripMenuItem_Click);
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
			this->Text = L"Парные картинки";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private:

    static int nw = 4; // кол-во клеток по горизонтали
    static int nh = 4; // кол-во клеток по вертикали
                   
    static int np = (nw * nh) / 2;  // кол-во пар картинок

    // рабочая графическая поверхность
	System::Drawing::Graphics^ g;

    // картинки (загружаются из файла) 
    Bitmap^ pics;

    // размер (ширина и высота) клетки (картинки)
    int cw, ch;

    // игровое поле: 
	static array<int,2>^ field  = gcnew array<int,2>(4,4); 
    // field[i,j] == 1 ... k - клетка закрыта
    //                         (k-номер картинки);
    // field[i,j] == 101 ... (100+k) - клетка открыта
    //                       (игрок видит картинку);
    // field[i,j] == 201 ... (200+k) – в клетке картинка,
    //                        для которой найдена пара 
    
    // кол-во открытых (найденных) пар картинок
    static int nOpened = 0;

    // количества открытых в данный момент клеток
    static int cOpened = 0;

	// координаты 1-й открытой клетки
    static array<int>^ open1 = gcnew array<int>(2);

    // координаты 2-й открытой клетки
	static array<int>^ open2 = gcnew array<int>(2);

    // таймер
	System::Windows::Forms::Timer^ timer1;


// нарисовать клетку:
    // - картинку, если клетка открыта;
    // - границу, если клетка закрыта;
    // - фон, если в клетке картинка, для которой найдена пара
    void drawCell(int i, int j)
    {
        int x,y;  // координаты левого верхнего угла клетки

        // между меду картинками
        // оставляем промежутки в 1 пиксель
        x = i * (cw + 2);
        y = j * (ch + 2) + menuStrip1->Height;

        if (field[i,j] > 200)
            // для этой клетки найдена пара,
            // картинку отображать не надо
			g->FillRectangle(SystemBrushes::Control,
                x, y, cw + 2, ch + 2);

        if ((field[i, j] > 100) && (field[i, j] < 200))
        {
            // клетка открыта - отобразить картинку:
			// скопировать фрагмент с одной графической
			// поверхности на другую
			Rectangle r1 = Rectangle(x + 1, y + 1, cw, ch);
			Rectangle r2 = Rectangle
				           ((field[i, j] - 101) * cw, 0, cw, ch);
            
			g->DrawImage (pics, r1,r2,
			  GraphicsUnit::Pixel);
				
				g->DrawRectangle(Pens::Black,
                x + 1, y + 1, cw, ch);
        }

        if ((field[i, j] > 0) && (field[i, j] < 100))
        {
            // клетка закрыта. рисуем контур
			g->FillRectangle(SystemBrushes::Control,
                x + 1, y + 1, cw, ch);
			g->DrawRectangle(Pens::Black,
                x + 1, y + 1, cw, ch);
        }
    }

    // нарисовать поле
    void drawField()
    {
        for (int i = 0; i < nw; i++)
            for (int j = 0; j < nh; j++)
                drawCell(i, j);
    }

    // новая игра
    void newGame()
    {
        // Раскидаем пары картинок по игровому полю:
        // запишем в массив field случайные числа
        // от 1 до k, где к - количество картинок.
        // Каждое число должно быть записано
        // в массив field два раза.
        
        Random^ rnd; // генератор случайных чисел
        int rndN;   // случайное число
        
		rnd = gcnew Random(); 

        array<int>^ buf = gcnew array<int>(np);
        // np - кол-во картинок;
        // в buf[i] записываем, сколько i чисел 
        // (индентификаторов картинок) записали в массив field

        for (int i = 0; i < nw; i++)
            for (int j = 0; j < nh; j++)
            {
                do
                {
					rndN = rnd->Next(np) + 1;
                } while (buf[rndN - 1] == 2);

                field[i, j] = rndN;
                buf[rndN - 1]++;
            }

        nOpened = 0;
        cOpened = 0;

        this->drawField();
    }

    // обработка события таймера
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
    
    {
        // отрисовать клетки
        drawCell(open1[0], open1[1]);
        drawCell(open2[0], open2[1]);

        // остановить таймер
        timer1->Enabled = false;

        if (nOpened == np)
        {
			MessageBox::Show
                    ("Вы справились с поставленной задачей!",
					 "Собери картинку");               
        }
    }

// обработка события Click на форме
private: System::Void Form1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
    {
            int i,j; // индексы элемента массива field,
                     // соответствующего клетке, в кот.
                     // сделан щелчок

            i = e->X / (cw +3);  
			j = (e->Y - menuStrip1->Height) / (ch+3);  

            // если таймер работает, это значит что в данный 
            // момент открыты две клеткаи, в которых находятся
            // одинаковые картинки, но они еще не "стерты".
            // Если щелчок сделан в одной из этих картинок,
            // то ни чего делать не надо.
            if ((timer1->Enabled) && (field[i,j] > 200))
           {
               return;
           }

            // щелчок на месте одной из двух уже найденных
            // парных картинок
            if (field[i, j] > 200) return;

            // открытых клеток нет
            if (cOpened == 0)
            {
                cOpened++;

                // записываем координаты 1-й открытой клетки
                open1[0] = i; open1[1] = j;

                // клетка помечается как открытая
                field[i, j] += 100;

                // отрисовать клетку
                drawCell(i, j);

                return;
            }

            // открыта одна клетка, надо открыть вторую
            if (cOpened == 1)
            {
                // записываем координаты 2-й открытой клетки
                open2[0] = i; open2[1] = j;

                // если открыта одна клетка, и щелчок сделан
                // в той же клетке, ничего не происходит
                if ((open1[0] == open2[0]) &&
                                      (open1[1] == open2[1]))
                    return;
                else
                {
                    // теперь открыты две клетки
                    cOpened++;

                    // клетка помечается как открытая
                    field[i, j] += 100;

                    // отрисовать клетку
                    drawCell(i, j);

                    // открыты 2 одинаковые картинки
                    if (field[open1[0], open1[1]] ==
                        field[open2[0], open2[1]])
                    {
                      nOpened++;

                      // пометим клетки как найденные
                      field[open1[0], open1[1]] += 100;
                      field[open2[0], open2[1]] += 100;

                      cOpened = 0;

                      // Запускаем таймер. Процедура обработки
                      // сигнала от таймера "сотрет" открыые клетки,
                      // клетки, с одинаковыми картинками
                      timer1->Enabled = true;
                    }
                }
                return;
            }

            // открыты 2 клетки но в них разные картинками,
            // закроем их и откроем ту клетку, в которой
            //  сделан щелчок
            if (cOpened == 2)
            {
                // закрываем открытые клетки
                field[open1[0], open1[1]] -= 100;
                field[open2[0], open2[1]] -= 100;

                drawCell(open1[0], open1[1]);
                drawCell(open2[0], open2[1]);

                // записываем в open1 номер текущей клетки
                open1[0] = i; open1[1] = j;

                cOpened = 1;        // счетчик открытых клеток

                // открыть клетку, в которой сделан щелчок
                field[i, j] += 100;
                drawCell(i, j);
            }
        }
}

// Выбор в меню команды "Новая игра"
private: System::Void новаяИграToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 this->newGame();
		 }

// обработка события Paint
private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
		 {
			 this->drawField();
		 }

private: System::Void оПрограммеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {

			 About^ frm = gcnew About();

			 frm->ShowDialog();

		 }


};
}

