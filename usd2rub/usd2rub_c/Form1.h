#pragma once


namespace usd2rub_c {

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
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(28, 91);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(87, 27);
			this->button1->TabIndex = 0;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 15);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Цена:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(73, 19);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(116, 21);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox1_KeyPress);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(73, 46);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(116, 21);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox1_KeyPress);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(22, 50);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(36, 15);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Курс:";
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(25, 131);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(257, 40);
			this->label3->TabIndex = 5;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(331, 180);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Конвертор";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion






// щелчок на кнопке OK
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	double usd; // цена в долларах 
	double k;   // курс
	double rub; // цена в рублях
				
	usd =  System::Convert::ToDouble(textBox1->Text);
	k =  System::Convert::ToDouble(textBox2->Text);

	rub = usd * k;
		 
	label3->Text = usd.ToString("n") + "$ = " +
		           rub.ToString("c");
}
		 
				
// Эта функция обрабатывает нажатие клавиши в полях
// редактирования textBox1 (Курс) и textBox2 (Цена).
// Сначала надо обычным образом создать фукцию
// обработки события KeyPress для компонента
// textBox1, затем - указать ее в качестве
// обработчика этого же события для компонета textBox2
private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
{
	if ((e->KeyChar >= '0') && (e->KeyChar <= '9'))
         return;

    if (e->KeyChar == '.') e->KeyChar = ',';

    if (e->KeyChar == ',')
    {
		
		if (sender->Equals(textBox1)) {
			if ((textBox1->Text->IndexOf(',') != -1) ||
				(textBox1->Text->Length == 0))
			{
				e->Handled = true;
			}
		}
		else {
			if ((textBox2->Text->IndexOf(',') != -1) ||
				(textBox2->Text->Length == 0))
			{
				e->Handled = true;
			}
		}
        return;
	}

	if (Char::IsControl(e->KeyChar))
    {
		if (e->KeyChar == (char)Keys::Enter)
        {
			if (sender->Equals(textBox1))
               // клавиша <Enter> нажата в поле Курс    
               // переместить курсор в поле Цена
               textBox2->Focus();
            else
               // клавиша <Enter> нажата в поле Цена    
               // установить фокус на кнопку OK
               button1->Focus();
        }
        return;
     }

     // остальные символы запрещены
     e->Handled = true;
}

// Функция обрабатывает событие TextChanged (изменился
// текст в поле редактирования) обоих компонентов TextBox.
// Сначала надо обычным образом создать фукцию
// обработки события TextChanged для компонента
// textBox1, затем - указать ее в качестве
// обработчика события TextChanged для компонета textBox2
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	label3->Text = ""; // очистить поле отображения
                       // результата расчета

    if ((textBox1->Text->Length == 0) || (textBox2->Text->Length == 0))
        // в поле редактирования нет данных
        // сделать кнопку OK недоступной
        button1->Enabled = false;
    else
        // сделать кнопку OK доступной
        button1->Enabled = true;	 




}
	};
}

