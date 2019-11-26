#pragma once


namespace drawString {

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
			//TODO: добавьте код конструктора
			//
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
			this->SuspendLayout();
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(418, 199);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"DrawString";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	
// обработка событи€ Paint
private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
{
	       int x,y;
		   int w,h; // размер области отображени€ текста

		   x = 10;
		   y = 10;
	       

		   String^ st =
                   "Microsoft Visual C++ Express Edition";

		   // вывод текста шрифтом, заданным значением
           // свойства Font формы. Brushes - коллекци€
		   // стандартных кистей.
           e->Graphics->DrawString(st,
			   this->Font, Brushes::DarkGreen, x, y);

          
		   // определить размер области отображени€
		   // выведенной строки

		    h = (int)e->Graphics->MeasureString(st, this->Font).Height;

			// вычислить Y координату области отображени€
			// второй строки
			y = y + h;
		   
		   // вывод текста шрифтом, созданным программистом:
		   System::Drawing::Font^ aFont = 
			              gcnew System::Drawing::Font("Tahoma", 10,
						         			FontStyle::Regular);

            e->Graphics->DrawString(st,
									aFont, Brushes::Black, x, y);

            // вывод текста в центре формы
            System::Drawing::Font^ hFont = gcnew System::Drawing::Font("Tahoma", 14,
									FontStyle::Italic);
            

            // размер области отображени€ текста зависит от
            // характеристик шрифта, которым он отображаетс€

            // определить размер области отображени€ текста
            w = (int)e->Graphics->
                        MeasureString(st, hFont).Width;
            h = (int)e->Graphics->
                        MeasureString(st, hFont).Height;

            // вычислить координаты левого верхнего угла 
            // области отображени€ текста, так чтобы текст был 
            // размещен в центре формы по горизонтали и
            // вертикали. ClientSize.Width - размер внутренней
            // области формы
            x = (this->ClientSize.Width - w) / 2;
            y = (this->ClientSize.Height - h) / 2;

            // вывести текст в центре формы
            e->Graphics->DrawString(st, hFont,
				System::Drawing::Brushes::DarkGreen, x, y);

            // выведем текст еще раз
            e->Graphics->DrawString(st, hFont,
				System::Drawing::Brushes::DarkGreen, x, y + h);	 
}

// изменилс€ размер формы
private: System::Void Form1_Resize(System::Object^  sender, System::EventArgs^  e)
{
	// сообщить системе о необходимости
    // перерисовать окно. ¬ результате будет
    // сгенерировано событие Paint.
	this->Refresh();
}



};
}

