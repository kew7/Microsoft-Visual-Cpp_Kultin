#pragma once


namespace Plane_2 {

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
				sky = gcnew  System::Drawing::Bitmap(Application::StartupPath + "\\sky.bmp");
				plane = gcnew  System::Drawing::Bitmap(Application::StartupPath + "\\plane.bmp");
			}
			catch (System::Exception^ e)
            {
				MessageBox::Show(
					"Ошибка загрузки битового образа: " + e->Message, 
				   "Полет",MessageBoxButtons::OK,MessageBoxIcon::Error);
                this->Close();// закрываем форму
                return;
			}

			// сделать прозрачным фон
            plane->MakeTransparent();

            // установить размер формы равным
            // размеру фонового рисунка
			this->ClientSize = sky->Size;

			 // задать фоновый рисунок формы
             this->BackgroundImage = gcnew Bitmap(sky);

           
            // g - графическая поверхность, на которой
            // будем формировать рисунок
			 // определяем графическую поверхность
            g = this->CreateGraphics();

            // инициализация генератора случ. чисел
			rnd = gcnew System::Random();

            // исходное положение самолета
            rct.X = -40;
            rct.Y = 20 + rnd->Next(20);

            rct.Width = plane->Width;
            rct.Height = plane->Height;

            /*
            скорость полета определяется периодом следования
            сигналов от таймера и величиной
            приращения координаты X
           */

            dx = 2; // скорость полета - 2 пикселя/тик_таймера

            timer1->Interval = 20;
            timer1->Enabled = true;
		}

 private: System::Windows::Forms::Timer^  timer1;

	
	private:
		System::Drawing::Bitmap^  sky;
		System::Drawing::Bitmap^ plane;

		// рабочая графическая поверхность
		Graphics^ g;

		// приращение координаты X,
        // определяет скорость полета
        int dx;

        // область, в которой находится объект
        Rectangle rct;

		// генератор случайных чисел
		System::Random^ rnd;

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
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(401, 264);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Полет";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
private:

System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
{
}


private:
System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
{	 
	// Стереть изображение объекта - вывести
	// фрагмент фона в ту область
	// графической поверхности, в которой
	// сейчас находится объект
    g->DrawImage(sky,
		         Rectangle(rct.X,rct.Y,rct.Width,rct.Height),
		         Rectangle(rct.X,rct.Y,rct.Width,rct.Height),
				 GraphicsUnit::Pixel);

    // вычислить новое положение объекта
    if (rct.X < this->ClientRectangle.Width)
           rct.X += dx;
    else
	{
		// объект достиг правой границы,
        // перемещаем его к левой границе
        rct.X = -40;
        rct.Y = 20 + rnd->Next(40);

        // скорость полета от 2 до 5
        // пикселей/тик_таймера
        dx = 2 + rnd->Next(4);
    }

	g->DrawImage(plane,rct.X,rct.Y);
}


};
}

