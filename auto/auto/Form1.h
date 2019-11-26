#pragma once


namespace auto1 {

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
			
			this->pictureBox1->Image = Image::FromFile( Application::StartupPath+"\\Lacetti_r.jpg");
			
			//
			// System::Environment::GetFolderPath(System::Environment::SpecialFolder::MyPictures),
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

	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label2;




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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::MediumBlue;
			this->label1->Location = System::Drawing::Point(10, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(145, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Chevrolet LACETTI";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(12, 45);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(68, 17);
			this->checkBox1->TabIndex = 2;
			this->checkBox1->Text = L"коврики";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->Click += gcnew System::EventHandler(this, &Form1::checkBox1_Click);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(12, 66);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(108, 17);
			this->checkBox2->TabIndex = 3;
			this->checkBox2->Text = L"защита картера";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->Click += gcnew System::EventHandler(this, &Form1::checkBox1_Click);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(12, 88);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(95, 17);
			this->checkBox3->TabIndex = 4;
			this->checkBox3->Text = L"зимние шины";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->Click += gcnew System::EventHandler(this, &Form1::checkBox1_Click);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(12, 110);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(90, 17);
			this->checkBox4->TabIndex = 5;
			this->checkBox4->Text = L"литые диски";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->Click += gcnew System::EventHandler(this, &Form1::checkBox1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(14, 158);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(64, 20);
			this->button1->TabIndex = 6;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(150, 45);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(205, 108);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(12, 189);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(343, 56);
			this->label2->TabIndex = 8;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(378, 260);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Комплектация";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
    double cena;     // цена в базовой комплектации	
	double dop;      // сумма за доп. оборудование
    double discount; // скидка
    double total;    // общая сумма

    cena = 415000;
    dop = 0;
	
    if (checkBox1->Checked)
	{
		// коврики
        dop += 1200;
    }
            
    if (checkBox2->Checked)
    {
		// защита картера
        dop += 4500;
    }
            
    if (checkBox3->Checked)
    {
		// зимние шины
        dop += 12000;
    }

    if (checkBox4->Checked)
    {
		// литые диски
        dop += 12000;
    }
	
	total = cena + dop;

	System::String ^st;
    st = "Цена в выбранной комплектации: " +
                  total.ToString("C");
	if ( dop != 0)
	{ 
		st += "\nВ том числе доп. оборудование: " +
				dop.ToString("C");
	}        
    
	if ((checkBox1->Checked) && (checkBox2->Checked) &&
        (checkBox3->Checked) && (checkBox4->Checked))
    {
		// скидка предоставляется, если
        // выбраны все опции
        discount = dop * 0.1;
        total = total - discount;
        st += "\nСкидка на доп. оборудование (10%): " +
                       discount.ToString("C") +
                      "\nИтого: " + total.ToString("C");
     }

	label2->Text = st; 
}


// щелчок на компоненте CheckBox.
// Функция обрабатывает событие Click на
// компонентах checkBox1 - checkBox4
private: System::Void checkBox1_Click(System::Object^  sender, System::EventArgs^  e)
{
	label2->Text = "";
}

};
}

