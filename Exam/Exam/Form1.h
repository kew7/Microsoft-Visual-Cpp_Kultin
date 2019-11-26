// Имя файла теста передается в программу через
// аргументы командной строки.
// Наличие аргументов проверяет функция main (см. Exam.cpp)
// В модуль формы имя файла теста и путь к нему передаются через
// параметры конструктора. 

#pragma once


namespace Exam {

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
		Form1(String^ fpath, String^ fname)
		{
			InitializeComponent();
			//
		  
		picpath = fpath; // путь к файлам иллюстраций

		radioButton1->Visible = false;
          radioButton2->Visible = false;
          radioButton3->Visible = false;

		  
	try
    {
          // прочитать xml-файл
          xmlReader =
			  gcnew System::Xml::XmlTextReader(fpath + fname);
          xmlReader->Read();

          mode = 0;
          n    = 0;

          // загрузить и показать заголовок теста
          this->showHead();

          // загрузить и показать описание теста
          this->showDescription();
      }
      
      catch(Exception^ e)
      {
          
		  MessageBox::Show( e->Message,
              "Экзаменатор",
			  MessageBoxButtons::OK,
			  MessageBoxIcon::Error);

          mode = 2;
      }

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
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::RadioButton^  radioButton4;

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(20, 24);
			this->label1->MaximumSize = System::Drawing::Size(500, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(45, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(23, 53);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(248, 161);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(25, 231);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(101, 20);
			this->radioButton1->TabIndex = 2;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"radioButton1";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->Click += gcnew System::EventHandler(this, &Form1::radioButton1_Click);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(24, 257);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(101, 20);
			this->radioButton2->TabIndex = 3;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"radioButton2";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->Click += gcnew System::EventHandler(this, &Form1::radioButton1_Click);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(25, 283);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(101, 20);
			this->radioButton3->TabIndex = 4;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"radioButton3";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->Click += gcnew System::EventHandler(this, &Form1::radioButton1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(33, 330);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(171, 333);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(101, 20);
			this->radioButton4->TabIndex = 6;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"radioButton4";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->Visible = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(551, 370);
			this->Controls->Add(this->radioButton4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Экзаменатор";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	


private:

	// String^ fpath; // путь к файлу теста
    // String^ fname; // файл теста


    // XmlReader обеспечивает чтение данных xml-файла
	System::Xml::XmlReader^ xmlReader;
     
    String^ qw;     // вопрос
      
    // варианты ответа - массив строк (указателей на строки)
    static array<String^>^ answ = gcnew array<String^>(3);

    
	String^ picpath; // путь к файлу иллюстрации
	String^ pic;     // файл иллюстрации

    int right; // правильный ответ (номер)
    int otv;   // выбранный ответ (номер)
    int n;     // количество правильных ответов
    int nv;    // общее количество вопросов
    int mode;  // состояние программы:
                         // 0 - начало работы;
                         // 1 - тестирование;
                         // 2 - завершение работы


// выводит название (заголовок) теста
void showHead()
{
  // ищем узел <head>
  do 
  {
	xmlReader->Read();
  }
  while(xmlReader->Name != "head");

  // считываем заголовок
  xmlReader->Read();

  // вывести название теста в заголовок окна
  this->Text = xmlReader->Value;

  // выходим из узла <head>
  xmlReader->Read();
}

  // выводит описание теста
  void showDescription()
  {
      // ищем узел <description>
      do
	  {
          xmlReader->Read();
	  }
      while(xmlReader->Name != "description");

      // считываем описание теста
      xmlReader->Read();

      // выводим описание теста
      label1->Text = xmlReader->Value;

      // выходим из узла <description>
      xmlReader->Read();

      // ищем узел вопросов <qw>
      do
          xmlReader->Read();
      while(xmlReader->Name != "qw");

      // входим в узел "qw"
      xmlReader->Read();
  }

// читает вопрос из файла теста
bool getQw()
{
	// считываем тэг <q>
    xmlReader->Read();

	if (xmlReader->Name == "q")
    {
		// здесь прочитан тэг <q>,
        // атрибут text которого содержит вопрос, а
        // атрибут src - имя файла иллюстрации.

        // извлекаем значение атрибутов:
        qw  = xmlReader->GetAttribute("text");
        pic = xmlReader->GetAttribute("src");
		if (!pic->Equals(String::Empty))
			pic = picpath + pic;

        // входим внутрь узла
        xmlReader->Read();
        int i = 0;

        // считываем данные узла вопроса <q>
        while (xmlReader->Name != "q")
        {
			xmlReader->Read();

            // варианты ответа
            if (xmlReader->Name == "a")
            {
				// если есть атрибут right, то это
                // правильный ответ
                if (xmlReader->GetAttribute("right") ==
                        "yes")
                      right = i;

                // считываем вариант ответа
                xmlReader->Read();
                if (i < 3) answ[i] = xmlReader->Value;

                // выходим из узла <a>
                xmlReader->Read();

                  i++;
             }
		}

		// выходим из узла вопроса <q>
		xmlReader->Read();

		return true;
	}
    // если считанный тэг не <q>
    else
          return false;
}

// выводит вопрос и варианты ответа
void showQw()
{
	// выводим вопрос
    label1->Text = qw;

    // иллюстрация
    if (pic->Length != 0)
    {
		try
        {
			pictureBox1->Image = gcnew Bitmap(pic);

            pictureBox1->Visible = true;

            radioButton1->Top = pictureBox1->Bottom + 16;
        }
		catch (Exception^ )
        {
              if (pictureBox1->Visible)
                  pictureBox1->Visible = false;

              label1->Text +=
                  "\n\n\nОшибка доступа к файлу " + pic + ".";

              radioButton1->Top = label1->Bottom + 8;
        }
      }
      else
      {
          if (pictureBox1->Visible)
              pictureBox1->Visible = false;

          radioButton1->Top = label1->Bottom + 16;
      }

      // показать варианты ответа
      radioButton1->Text = answ[0];
      radioButton2->Top  = radioButton1->Top + 24;;
      radioButton2->Text = answ[1];
      radioButton3->Top  = radioButton2->Top + 24;;
      radioButton3->Text = answ[2];

      radioButton4->Checked = true; 
      button1->Enabled = false;
}


// Щелчок на кнопке выбора ответа.
// Функция обрабатывает событие Click
// компонентов radioButton1 - radioButton3
private: System::Void radioButton1_Click(System::Object^  sender, System::EventArgs^  e)
{
	 if ((RadioButton^)sender == radioButton1) otv = 0;
     if ((RadioButton^)sender == radioButton2) otv = 1;
     if ((RadioButton^)sender == radioButton3) otv = 2;

      button1->Enabled = true;
}


// щелчок на кнопке OK
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	switch (mode)
      {
      case 0:
		  // Щелчок на кнопке OK 
		  // когда в окне отображается
		  // информация о тесте и задание
          radioButton1->Visible = true;
          radioButton2->Visible = true;
          radioButton3->Visible = true;

          getQw();
          showQw();

          mode = 1;

          button1->Enabled = false;
          radioButton4->Checked = true;
          break;

      case 1:
		  // щелчок, подтверждающий
		  // выбор ответа
          nv++;

          // правильный ли ответ выбран
          if (otv == right) n++;

          if (getQw())
			  showQw();
          else {
              // больше вопросов нет
              radioButton1->Visible = false;
              radioButton2->Visible = false;
              radioButton3->Visible = false;

              pictureBox1->Visible  = false;

              // обработка и вывод результата
              showLevel();

              // следующий щелчок на кнопке Ok
              // должен закрыть окно программы
              mode = 2;
          }
          break;
      
	  case 2:
		  // завершение работы программы
          this->Close(); // закрыть окно
          break;
      }
}


// выводит оценку 
void showLevel()
{
	// ищем узел <levels>
    do
		xmlReader->Read();
    while (xmlReader->Name != "levels");

    // входим внутрь узла
    xmlReader->Read();

    // читаем данные узла
    while (xmlReader->Name != "levels")
    {
		xmlReader->Read();

        if (xmlReader->Name == "level")
              // n - кол-во правильных ответов.
              // Для достижения уровня, кол-во
			  // правильных ответов должно быть
			  // равно или превышать значение,
			  // заданное атрибутом score 
		 	
			if (n >= Convert::ToInt32(
                  xmlReader->GetAttribute("score")))
              break;
		 
     }

     // выводим оценку
     label1->Text =
          "Тестирование завершено.\n" +
          "Всего вопросов: " + nv.ToString() + "\n" +
          "Правильных ответов: " + n.ToString() + "\n\n" +
          xmlReader->GetAttribute("text");
  
  }

  
  





};
}

