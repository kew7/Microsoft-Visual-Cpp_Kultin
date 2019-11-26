#pragma once


namespace NPV {

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
			
		   // chm-файл получается путем компиляции htm-файлов,
           // в которых находится справочная информация.
           // Обычно каждый раздел справочной информации
           // помещают в отдельный файл. В дальнейшем
           // имя htm-файла используется в качестве
           // раздела идентификатора справочной информации.

            // файл справки приложения
            helpProvider1->HelpNamespace = "npv.chm";
            helpProvider1->SetHelpNavigator(this,
				HelpNavigator::Topic);
            helpProvider1->SetShowHelp(this, true);

            // задать раздел справки 
            // для textBox1 - Финансовые результаты
            helpProvider1->SetHelpKeyword(textBox1,
                                         "npv_02.htm");
            helpProvider1->SetHelpNavigator(textBox1,
				HelpNavigator::Topic);
            helpProvider1->SetShowHelp(textBox1, true);

            // задать раздел справки 
            // для textBox2 - Финансовые затраты
            helpProvider1->SetHelpKeyword(textBox2,
                                       "npv_03.htm");
            helpProvider1->SetHelpNavigator(textBox2,
				HelpNavigator::Topic);
            helpProvider1->SetShowHelp(textBox2, true);

            // задать раздел справки 
            // для textBox3 - Ставка дисконтирования
            helpProvider1->SetHelpKeyword(textBox3,
                                         "npv_04.htm");
            helpProvider1->SetHelpNavigator(textBox3,
				HelpNavigator::Topic);
            helpProvider1->SetShowHelp(textBox3, true);
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
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::HelpProvider^  helpProvider1;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->helpProvider1 = (gcnew System::Windows::Forms::HelpProvider());
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(157, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Финансовые результаты:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(31, 51);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(138, 15);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Финансовые затраты:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 78);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(158, 15);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Ставка дисконтирования:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(175, 20);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 21);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(175, 48);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 21);
			this->textBox2->TabIndex = 4;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(175, 75);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 21);
			this->textBox3->TabIndex = 5;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(15, 122);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Расчет";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(128, 122);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Справка";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(12, 161);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(355, 39);
			this->label4->TabIndex = 8;
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripStatusLabel1});
			this->statusStrip1->Location = System::Drawing::Point(0, 213);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(379, 22);
			this->statusStrip1->TabIndex = 9;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(76, 17);
			this->toolStripStatusLabel1->Text = L"F1 - Справка";
			// 
			// helpProvider1
			// 
			this->helpProvider1->HelpNamespace = L"npv.chm";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(379, 235);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Чистый дисконтированный доход";
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	// щелчок на кнопке Справка
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 Help::ShowHelp(this, helpProvider1->HelpNamespace,
                   "npv_01.htm");

			 }
// щелчок на кнопке Расчет
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		double p = 0; // поступления от продаж
        double r = 0; // расходы
        double d = 0; // ставка дисконтирования

        double npv = 0; // чистый дисконтированный доход

        try
        {
			p = Convert::ToDouble(textBox1->Text);
			r = Convert::ToDouble(textBox2->Text);
			d = Convert::ToDouble(textBox3->Text) / 100;

            npv = (p - r) / (1.0 + d);

            label4->Text =
                   "Чистый дисконтированный доход (NPV) =  " +
                    npv.ToString("c");
		}
		catch ( System::FormatException^ e)
        {
			//MessageBox::Show( e->Message);
			MessageBox::Show("Ошибка исходных данных.\nУбедитесь, что все поля заполнены, а так же в том, что в качестве десятичного разделителя используется запятая.","Чистый дисконтированный доход", MessageBoxButtons::OK,MessageBoxIcon::Exclamation);
        }
	}

};
}

