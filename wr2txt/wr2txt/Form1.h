#pragma once


namespace wr2txt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::IO;

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
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;

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
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(27, 21);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 21);
			this->dateTimePicker1->TabIndex = 0;
			this->dateTimePicker1->TabStop = false;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &Form1::dateTimePicker1_ValueChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(27, 62);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 21);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox1_KeyPress);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(27, 108);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(295, 161);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dateTimePicker1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"USD (курс  ЦБ РФ)";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

// нажатие клавиши в поле редактирования
private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
{
	if ((e->KeyChar >= '0') && (e->KeyChar <= '9'))
                return;

    if (e->KeyChar == '.')
		e->KeyChar = ',';

    if (e->KeyChar == ',')
    {
		// в поле редактирования не может
        // быть больше одной запятой и запятая
        // не может быть первым символом
        if ((textBox1->Text->IndexOf(',') != -1) ||
             (textBox1->Text->Length == 0))
        {
			e->Handled = true;
        }
        return;
     }

	if (Char::IsControl(e->KeyChar))
    {
		// <Enter>, <Backspace>, <Esc>
		if (e->KeyChar == (char)Keys::Enter)
			// установить курсор на кнопку OK
            button1->Focus();
            return;
    }
    
	// остальные символы запрещены
    e->Handled = true;
}

	
// изменилось содержимое поля редактирования	
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e)
{

	if (textBox1->Text->Length == 0)
       button1->Enabled = false;
    else
        button1->Enabled = true;
}



// щелчок на кнопке Добавить
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	double kurs;   // курс
    DateTime date; // дата
      
    date = dateTimePicker1->Value;
	kurs =  System::Convert::ToDouble(textBox1->Text);
           
    // получить информацию о файле
	System::IO::FileInfo^ fi =
		gcnew System::IO::FileInfo(
		Application::StartupPath + "\\usd.txt");

    // поток для записи        
	System::IO::StreamWriter^ sw;
           
    if (fi->Exists) // файл данных существует?
        // откроем поток для добавления
        sw = fi->AppendText();
    else
		// создать файл и открыть поток для записи
        sw = fi->CreateText();
			
    // запись в файл
	sw->WriteLine(date.ToShortDateString());
    sw->WriteLine(kurs.ToString("N"));
      
    // закрыть поток
    sw->Close();

    // чтобы по ошибке не записать данные
    // второй раз, сделаем недоступным поле
    // ввода и кнопку
    button1->Enabled = false;
    textBox1->Enabled = false;
}


// пользователь выбрал другую дату
private: System::Void dateTimePicker1_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	// очистить и сделать доступным
    // поле ввода
    textBox1->Enabled = true;
    textBox1->Clear();
    
	// установить курсор в поле ввода
    textBox1->Focus();
}


};
}

