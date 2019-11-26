#pragma once


namespace Timer1 {

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
			// настройка компонентов numericUpDown
            numericUpDown1->Maximum = 59;
            numericUpDown1->Minimum = 0;
            // чтобы при появлении окна
            // курсор не мигал в поле редактирования
            numericUpDown1->TabStop = false;

            numericUpDown2->Maximum = 59;
            numericUpDown2->Minimum = 0;
            numericUpDown2->TabStop = false;

            // кнопка Пуск/Стоп не доступна
            button1->Enabled = false;
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
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::TextBox^  textBox1;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(91, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"00:00";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->numericUpDown2);
			this->groupBox1->Controls->Add(this->numericUpDown1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Location = System::Drawing::Point(13, 45);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(235, 60);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Интервал";
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(172, 30);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(40, 21);
			this->numericUpDown2->TabIndex = 3;
			this->numericUpDown2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown1_ValueChanged);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(59, 30);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(40, 21);
			this->numericUpDown1->TabIndex = 2;
			this->numericUpDown1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown1_ValueChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(120, 32);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(50, 15);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Секунд:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 15);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Минут:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(96, 157);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Пуск";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 121);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(235, 21);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"Заданный интервал времени истек";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(260, 193);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"  Таймер";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private: DateTime^ t1; // время запуска таймера
private: DateTime^ t2; // время срабатывания таймера


// обработка события ValueChanged компонентов
// numericUpDown1 и numericUpDown1
private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	if ((numericUpDown1->Value == 0) &&
        (numericUpDown2->Value == 0))
		button1->Enabled = false;
    else
		button1->Enabled = true;
}

// щелчок на кнопке Пуск/Стоп
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (!timer1->Enabled)
    {
		// пуск таймера

        // t1 - текущее время
        // t2 = t1 + интервал

		
		t1 = gcnew DateTime(DateTime::Now.Year,
			DateTime::Now.Month, DateTime::Now.Day);
        
		t2 = t1->AddMinutes((double)numericUpDown1->Value);
        t2 = t2->AddSeconds((double)numericUpDown2->Value);

       groupBox1->Enabled = false;
       button1->Text = "Стоп";

       if (t2->Minute < 10)
          label1->Text = "0"+t2->Minute.ToString()+":";
       else
          label1->Text = t2->Minute.ToString() + ":";

       if (t2->Second < 10)
          label1->Text += "0" + t2->Second.ToString();
       else
          label1->Text += t2->Second.ToString();

       // период возникновения события Tick - 1 секундf
       timer1->Interval = 1000;

       // пуск таймера
       timer1->Enabled = true;

	   groupBox1->Enabled = false;
	}
    else
    {
		// таймер работает, останавливаем
        timer1->Enabled = false;
        button1->Text = "Пуск";
        groupBox1->Enabled = true;
        numericUpDown1->Value = t2->Minute;
        numericUpDown2->Value = t2->Second;
     }

}

// обработка сигнала от таймера
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
		 {
            t2 = t2->AddSeconds(-1);

            if (t2->Minute < 10)
               label1->Text = "0" + t2->Minute.ToString() + ":";
            else
               label1->Text = t2->Minute.ToString() + ":";

            if (t2->Second < 10)
                label1->Text += "0" + t2->Second.ToString();
            else
                label1->Text += t2->Second.ToString();

            if (Equals(t1, t2))
            {
                timer1->Enabled = false;


				this->Activate();
			
				MessageBox::Show(
                    textBox1->Text,
                    "Таймер",
					MessageBoxButtons::OK,
					MessageBoxIcon::Information);
               
                button1->Text = "Пуск";
                groupBox1->Enabled = true;
                numericUpDown1->Value = 0;
                numericUpDown2->Value = 0;
            }
}


};
}

