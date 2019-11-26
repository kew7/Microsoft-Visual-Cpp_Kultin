#pragma once


namespace osago {

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
			// Настройка компонентов
			//
			
			
			// базовый тариф
			textBox1->Text = "1980";
			
			checkBox1->Checked = true;
			
			// список регионов
			for ( int i = 0; i < reg->Length; i++)
			{
				comboBox1->Items->Add(reg[i]);
			}
			comboBox1->SelectedItem = 2;
			comboBox1->DropDownStyle = 
				  System::Windows::Forms::ComboBoxStyle::DropDownList;

			/* можно и так:
			comboBox1->Items->Add("Ленинградская обл.");
			comboBox1->Items->Add("Москва");
			comboBox1->Items->Add("Московская обл.");
			comboBox1->Items->Add("Мурманск");
			comboBox1->Items->Add("Нижний Новгород");
			comboBox1->Items->Add("Ростов-на-Дону");
			comboBox1->Items->Add("Самара");
			comboBox1->Items->Add("Санкт-Петербург");
			*/

			// возраст и стаж
			comboBox2->Items->Add("до 22 лет, стаж менее 2-х лет");
			comboBox2->Items->Add("до 22 лет, стаж свыше 2-х лет");
			comboBox2->Items->Add("от 22 лет, стаж менее 2-х лет");
			comboBox2->Items->Add("от 22 лет, стаж свыше 2-х лет");
			comboBox2->DropDownStyle = 
				  System::Windows::Forms::ComboBoxStyle::DropDownList;


		    // мощность двигателя
			comboBox3->Items->Add("до 50 включитедьно");
			comboBox3->Items->Add("свыше 50 до 70 включительно");
			comboBox3->Items->Add("свыше 70 до 95 включительно");
			comboBox3->Items->Add("свыше 95 до 120 включительно");
			comboBox3->Items->Add("свыше 120 до 160 включительно");
			comboBox3->Items->Add("свыше 160 до 200 включительно");
			comboBox3->Items->Add("свыше 200");
			comboBox3->DropDownStyle = 
				  System::Windows::Forms::ComboBoxStyle::DropDownList;

			
			// период использования
			comboBox4->Items->Add("6 месяцев");
			comboBox4->Items->Add("7 месяцев");
			comboBox4->Items->Add("8 месяцев");
			comboBox4->Items->Add("9 месяцев");
			comboBox4->Items->Add("более 9 месяцев");
			comboBox4->DropDownStyle = 
				  System::Windows::Forms::ComboBoxStyle::DropDownList;

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
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::ComboBox^  comboBox4;
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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(21, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(375, 47);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Расчет тарифа по обязательному страхованию  гражданской ответственности владельца" 
				L" транспортного средства  (физического лица владельца  легкового автомобиля)\r\n";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 72);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(246, 14);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Базовая ставка страхового тарифа (руб.):";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(22, 100);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(290, 14);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Территория преимущественного использования:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(24, 128);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(153, 14);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Класс предыдущего года:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(246, 128);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(189, 14);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Количество страховых случаев:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(24, 156);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(98, 14);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Возраст и стаж:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(68, 182);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(356, 14);
			this->label7->TabIndex = 6;
			this->label7->Text = L"ограничение количества лиц, допущенных к управлению ТС";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(24, 212);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(165, 14);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Мощность двигателя (л.с.):";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(24, 240);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(162, 14);
			this->label9->TabIndex = 8;
			this->label9->Text = L"Период использования ТС:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(27, 289);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(276, 69);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 10;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(183, 125);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(48, 22);
			this->textBox2->TabIndex = 11;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(441, 125);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(48, 22);
			this->textBox3->TabIndex = 12;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(317, 97);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(172, 22);
			this->comboBox1->TabIndex = 13;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(128, 153);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(214, 22);
			this->comboBox2->TabIndex = 14;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(33, 182);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(15, 14);
			this->checkBox1->TabIndex = 15;
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(204, 209);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(203, 22);
			this->comboBox3->TabIndex = 16;
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Location = System::Drawing::Point(204, 237);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(162, 22);
			this->comboBox4->TabIndex = 17;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 14);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(509, 340);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ОСАГО";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private:

// регион
static array<String^>^ reg =
	{"Москва","Московская обл.","Санкт-Петербург",
     "Нижний новгород","Ленинградская обл.","Ростов-наДону",
	 "Самара","Мурманск"};

// коэфициент региона
static array<double>^ kt  = {1.8,1.6, 1.8,1.3,1,1,1,1};

/* таблица определения коэффициента страхового тарифа
Первый год - 3й класс, второй год (если не было страховых
случаев) 4й класс и т.д.). Если страховой случай был,
то класс в ячейке таблицы: строка - класс предыдущего
года, столбец - кол-во страховых случаев. */

// класс безаварийности - таблица 6х5 (6 строк, 5 столбцов)
static array<int,2>^ cb  /* [6][5] */ = {
{1,-1,-1,-1,-1},
{2,-1,-1,-1,-1},
{3,1,-1,-1,-1},
{4,1,-1,-1,-1},
{5,2,1,-1,-1},
{6,3,1,-1,-1}};

// коэффициент безаварийности
static array<double>^ kb = {2.3, 1.55, 1.4, 1, 0.95, 0.9};

// коэффициент водительского стажа
static array<double>^ kvs = {1.3, 1.2, 1.15, 1};

// коэффициент мощности двигателя
static array<double>^ km = {0.5, 0.7, 1.0, 1.3, 1.5, 1.7, 1.9};

// коэффициент периода использования ТС
static array<double>^ ks = {0.7, 0.8, 0.9, 0.95, 1.0};


// щелчок на кнопке OK
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	// расчет страховой "премии" :)
	double aTb;  // базовая ставка тарифа
    double aKt;  // коэф. тарифа
    double aKb;   // коэф. безаварийности
    double aKvs; // коэф. водительского стажа
    double aKo;  // коэф., учитывающий количество лиц, допущеных к управлению
    double aKm;  // коэф. мощности двигателя
    double aKs;  // коэф., учитывающий период использования ТС

    int pcb,ccb; // предыдущий и текущий класс безаваийности
    int nss;     // количество страховых случаев предыдущего периода


    // проверим, все ли поля формы заполенены
	if ( (comboBox1->SelectedIndex == -1) ||
		(comboBox2->SelectedIndex == -1) ||
		(comboBox3->SelectedIndex == -1) ||
		(comboBox4->SelectedIndex == -1) ||
		(textBox2->Text->Length == 0) ||
		(textBox3->Text->Length == 0)
		)
	{
		MessageBox::Show("Надо заполнить все поля формы",
			"ОСАГО",
			System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Warning);

		return;
	}
		

    // все поля формы заполнены

	aTb = System::Convert::ToDouble(textBox1->Text);
    aKt = kt[comboBox1->SelectedIndex];

    pcb = System::Convert::ToInt32(textBox2->Text); // пред. класс безаварийности
    nss = System::Convert::ToInt32(textBox3->Text); // кол-во страховых случаев 
   
	if ( pcb > 5)
		pcb = 5; // см. определение таблицы cb

	ccb =   cb[pcb-1,nss]; // текущий класс безаварийности
    if ( ccb != -1)
        aKb = kb[ccb];
    else aKb = 2.45;

    // коэфф. водительского стажа
	aKvs = kvs[comboBox2->SelectedIndex];
    
    // количество лиц, допущеных к управлению
    if (checkBox1->Checked)
        aKo = 1;
    else
        aKo = 1.5;

    // мощность двигателя
	aKm = km[comboBox3->SelectedIndex];
    
    // период использования ТС
	aKs = ks[comboBox4->SelectedIndex];
    
    // все коэффициенты определены - расчет

    double T; // тариф
	String ^st;

    T = aTb * aKt * aKb * aKvs * aKo * aKm *aKs;

	st = "Базовая ставка тарифа: " + aTb.ToString("c")+
		"\nКоэф. тарифа: " + aKt.ToString()+
		"\nКоэф. безаварийности: " + aKb.ToString()+
		"\nKоэф. водительского стажа: " + aKvs.ToString() +
		"\nКоэф. кол-ва лиц, допущеных к управлению: " + aKo.ToString() +
		"\nКоэф. мощности двигател: " + aKm.ToString() +
		"\nКоэф. периода использования ТС: " + aKs.ToString()+
		"\n\nТариф: " + T.ToString("c");

    MessageBox::Show(st,"Тариф ОСАГО");
}



};
}

