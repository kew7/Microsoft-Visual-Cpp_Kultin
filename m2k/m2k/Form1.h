#pragma once


namespace m2k {

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
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(22, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Мили:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(70, 16);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 21);
			this->textBox1->TabIndex = 1;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox1_KeyPress);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(25, 58);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(22, 103);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(259, 24);
			this->label2->TabIndex = 3;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(308, 145);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Мили-километры";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

// щелчок на кнопке OK
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	double mile; // расстояние в миля
    double km;   // расстояние в километрах

    // Если в поле редактирования нет данных,
    // то при попытке преобразовать пустую
    // строку в число возникает исключение.
    try
    {
		mile = Convert::ToDouble(textBox1->Text);

        km = mile * 1.609344; 

        label2->Text = mile.ToString("n") + " miles - " +
			           km.ToString("n") + " км.";
    }
	
	catch (System::FormatException^ ex )
	{
		// обработка исключения:
        // - сообщение
		MessageBox::Show(
			"Надо ввести данные", "Мили-километры",
			MessageBoxButtons::OK,
			MessageBoxIcon::Exclamation);
		
		// - установить курсор в поле редактирования
        textBox1->Focus();
	}
}

// нажатие клавиши в поле textBox
private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
{
	// Правильными символами считаются цифры,
    // запятая, <Enter> и <Backspace>.
    // Будем считать правильным символом
    // также точку, но заменим ее запятой.
    // Остальные символы запрещены.
    // Чтобы запрещенный символ не отображался 
    // в поле редактирования, присвоим 
    // значение true свойству Handled параметра e

    if ((e->KeyChar >= '0') && (e->KeyChar <= '9'))
    {
		// цифра
        return;
    }

    
    if (e->KeyChar == '.')
    {
      // точку заменим запятой
      e->KeyChar = ',';
    }

    if (e->KeyChar == ',')
    {
		if (textBox1->Text->IndexOf(',') != -1)
        {
			// запятая уже есть в поле редактирования
            e->Handled = true;
        }
        return;
    }

    if (  Char::IsControl(e->KeyChar) )
    {
		// <Enter>, <Backspace>, <Esc>
		if ( e->KeyChar == (char) Keys::Enter)
			// нажата клавиша <Enter>
            // установить "фокус" на кнопку OK
            button1->Focus(); 
            return;
    }

    // остальные символы запрещены
    e->Handled = true;
}


};
}

