#pragma once


namespace rectangle {

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
			//TODO: добавьте код конструктора
			//
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
			this->ClientSize = System::Drawing::Size(284, 178);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Прямоугольники";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->SizeChanged += gcnew System::EventHandler(this, &Form1::Form1_SizeChanged);
			this->ResumeLayout(false);

		}
#pragma endregion
	
private:

// обработка события Paint
System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
{
	int w,h;   // размер флага
	int ws;    // ширина полосы
	int x0,y0; // координаты левого верхнего угла флага

	int x,y;   // координаты левого верхнего угла полосы

	w = 83;
	h = 60;
	
	// разместим флаг в центре формы:
	// this->ClientSize.Width - ширина внутренней области формы;
    // this->ClientSize.Height - высота внутренней области формы;
    
	x0 = (this->ClientSize.Width - w) / 2;
	y0 = (this->ClientSize.Height - h) /2;

	ws = w / 3; // флаг из трех вертикальных полос

	// рисуем флаг
	x = x0;
	y = y0;
	
	// зеленая полоса
	e->Graphics->FillRectangle(Brushes::Green,x,y,ws,h);
	
	// белая полоса
	x = x + ws+1;
	e->Graphics->FillRectangle(System::Drawing::Brushes::White,x,y,ws,h);
	
	// красная полоса
	x = x + ws+1;
	e->Graphics->FillRectangle(System::Drawing::Brushes::Red,x,y,ws,h);

    // окантовка
	e->Graphics->DrawRectangle(System::Drawing::Pens::Black,x0,y0,w,h);
}


// событие SizeChanged возникает при изменении размера формы
private: System::Void Form1_SizeChanged(System::Object^  sender, System::EventArgs^  e)
{
	// метод Refresh информирует систему о необходимости
	// перерисовать (обновить) форму. В результате
	// генерируется событие Paint
	this->Refresh(); // обновить форму
}

	
};
}

