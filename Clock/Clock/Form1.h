#pragma once


namespace Clock {

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
			
			// g - графическая поверхность, на которой
            // будем формировать рисунок
			// определяем графическую поверхность
            g = this->CreateGraphics();

	R =70;
	
	// зададим размер формы
    // в соответствии с размером циферблата
	
	this->ClientSize =
		System::Drawing::Size((R + 30)*2,(R + 30)*2);
   
	x0  =  R + 30;
    y0  =  R + 30;

    // Определить положение стрелок.
    // Угол между метками (цифрами) часов, например, цифрами 2 и 3, - 30 градусов.
    // Угол между метками минут - 6 градусов.
    // Угол отсчитываем от 12-ти часов
	ahr  =   90 -  DateTime::Now.Hour *30-( DateTime::Now.Minute / 12) *6;
    amin  =  90 - DateTime::Now.Minute *6;
	asec  =  90 - DateTime::Now.Second *6;

    timer1->Interval =  1000; // период сигнал от таймера 1 сек
    timer1->Enabled  =  true; // пуск таймера
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
			this->ClientSize = System::Drawing::Size(229, 225);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"  Часы";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion

private:
	// графическая поверхность
	Graphics^ g;

	int R;				// радиус циферблата
	int  x0, y0;        // центр циферблата
	int ahr,amin,asec;  // положение стрелок (угол)	
		
private:
// сигнал от таймера
System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
{
	// нарисовать стрелки
	DrawClock();
}	
	
private:
System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
{

	int x, y;  // координаты маркера на циферблате
    int a;     // угол между OX и прямой (x0,yo) (x,y)
    int h;     // метка часовой риски

    a = 0; // метки ставим от 3-х часов, против часовой стрелки
    h = 3; // угол 0 градусов - это 3 часа

#define TORAD 0.0174532

    // циферблат
    while ( a < 360 )
    {
		x = x0 +  R * Math::Cos(a * TORAD);
        y = x0 -  R * Math::Sin(a * TORAD);
        //   Form1->Canvas->MoveTo(x,y);
        if ( (a % 30) == 0 )
        {
			g->DrawEllipse(Pens::Black,x-2,y-2,3,3); //x+3,y+3);
            // цифры по большему радиусу
            x = x0 +  (R+15) * Math::Cos(a * TORAD);
            y = x0 -  (R+15) * Math::Sin(a * TORAD);
			g->DrawString(h.ToString(),this->Font,Brushes::Black,x-5,y-7);
            h--;
            if ( h == 0 ) h = 12;
        }
        else
            g->DrawEllipse(Pens::Black,x-1,y-1,1,1); //x+1,y+1);
        a = a + 6; // 1 минута - 6 градусов
    }
	
	// стрелки
	DrawClock(); 

}

// рисует вектор из точки (x0,y0) под
// углом a относительно оси X
// Длинна вектора L
void Vector(float x0, float y0, float a, float l, System::Drawing::Pen^ aPen)
{
	// x0,y0 - начало вектора
    // a - угол между осью x и вектором
    // l - длина вектора
    #define TORAD 0.0174532  // коэффициент пересчета угла из градусов в радианы

  float x, y;       // координаты конца вектора

  
  x  =  x0 + l * Math::Cos(a*TORAD);
  y  =  y0 - l * Math::Sin(a*TORAD);
	
  g->DrawLine(aPen,x0,y0,x,y);

}


void DrawClock(void)
{
	// карандаши для рисования стрелок
	Pen^ hPen = gcnew Pen(Color::LightBlue,3);
	Pen^ mPen = gcnew Pen(Color::LightBlue,3);
	Pen^ sPen = gcnew Pen(Color::Black,2);
	
	// карандаш для стирания стрелок
	Pen^ cPen = gcnew Pen(SystemColors::Control,4);
	
	// шаг секундной и минутной стрелок 6 градусов,
	// часовой - 30.

	// стереть изображение стрелок:
	Vector(x0,y0, ahr, R-20, cPen);  // часовую
	Vector(x0,y0, amin, R-15, cPen); // минутную
	Vector(x0,y0, asec, R-7, cPen);  // секундную
  
	// новое положение стрелок
	ahr  =   90 -  DateTime::Now.Hour *30-( DateTime::Now.Minute / 12) *6;
    amin  =  90 - DateTime::Now.Minute *6;
	asec  =  90 - DateTime::Now.Second *6;

	// нарисовать стрелки:
    // часовую
	Vector(x0,y0, ahr, R-20, hPen);

	// минутную
	Vector(x0,y0, amin, R-15, mPen);

	// секундную
	Vector(x0,y0, asec, R-7, sPen);

	//g->DrawEllipse(Pens::Black,x0-2,y0-2,4,4);
	g->FillEllipse(Brushes::Black,x0-3,y0-3,6,6);
}







	};
}

