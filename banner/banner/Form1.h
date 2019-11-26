#pragma once


namespace banner {

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
            bm = gcnew
                 System::Drawing::Bitmap
                 (Application::StartupPath + "\\banner.png");
        }
        catch (System::Exception^ e)
        {
            MessageBox::Show(
               "Ошибка загрузки банера (" +
                Application::StartupPath + "\\banner.png)", 
               "Бегущая строка",
               MessageBoxButtons::OK,
               MessageBoxIcon::Error);
            this->Close();// закрываем форму
            return;
        }

        // определяем графическую поверхность
        g = this->CreateGraphics();

        // определяем область отображения баннера
        rct.X = 0;
        rct.Y = 0;
        rct.Width = bm->Width;
        rct.Height = bm->Height;

        // настройка таймера
        timer1->Interval = 25;
        timer1->Enabled = true;
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
	private: System::Windows::Forms::Timer^  timer1;
	protected: 
	private: System::ComponentModel::IContainer^  components;

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
			this->ClientSize = System::Drawing::Size(335, 169);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Form1";
			this->Text = L"Бегущая строка";
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->ResumeLayout(false);

		}
#pragma endregion
	
private:
    // баннер
    System::Drawing::Bitmap^  bm;

    // графическая поверхность
    Graphics^ g;

    // область вывода баннера
    Rectangle rct;


	
	// сигнал от таймера    
private: System::Void timer1_Tick(System::Object^ sender,
                                  System::EventArgs^  e) 
{
    // сместить область отображения
    // банера влево
    rct.X -= 1;

    // если область отображения целиком
    // "уехала" за левую границу формы,
    // вернем ее обратно
    if (Math::Abs(rct.X) > rct.Width)
        rct.X += rct.Width;

    // т.к. область отображения едет влево, то после
    // вывода в "съехавшую" область, выведем банер
    // еще раз (как минимум один, если ширина формы
    // равна ширине банера)
    for (int i = 0; i <= Convert::ToInt16(
                 this->ClientSize.Width / rct.Width) + 1; i++)
         g->DrawImage(bm, rct.X + i * rct.Width, rct.Y);
}

	// перемещение указателя мыши
private: System::Void Form1_MouseMove(System::Object^ sender,
                   System::Windows::Forms::MouseEventArgs^ e)
{
    // при наведении указателя мыши на баннер,
    // его прокрутка (движение) приостанавливается
    if ((e->Y < rct.Y + rct.Height) && (e->Y > rct.Y))
    {
        // указатель в области отображения банера
        if (timer1->Enabled )
            // строка "бежит"
            timer1->Enabled = false;
    }
    else
        // указатель не на банере
        {
            if ( ! timer1->Enabled )
                // строка "стоит",
                // запустим ее
                timer1->Enabled = true;
        }
}

	};
}

