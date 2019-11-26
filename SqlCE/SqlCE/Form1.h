#pragma once


namespace SqlCE {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/*  
    Чтобы пространство имен System::Data::SqlServerCe
	стало доступно, надо в проект добавить ссылку
	на файл сборки, в котором оно определено.
	Для этого надо: в меню Project (Проект)
    выбрать команду Свойства; в открывшемся окне
	сделать щелчок на кнопке Add Reference (Добавить
	новую ссылку); раскрыть кладку .NET и указать имя
	сборки. Если нужная сборка находится не в GAC, то
	необходимо раскрыть вкладку Обзор и указать
	файл сборки там. Следует обратить внимание на то,
	что в последнем случае файл сборки во время компиляции
	будет скопирован в файл проекта.
    */

	using namespace System::Data::SqlServerCe;

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
			//
			// настройка компонента ListView:
			// увеличим ширину компонента 
			// на ширину полосы прокрутки
			int w = 0;
			for (int i = 0; i < listView1->Columns->Count; i++)
			{
				w += listView1->Columns[i]->Width;
			}
        
			if (listView1->BorderStyle == BorderStyle::Fixed3D)
				w += 4;
        
			listView1->Width = w+17; // 17 – ширина полосы прокрутки 
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
	private: System::Windows::Forms::ListView^  listView1;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::ColumnHeader^  columnHeader4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;

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
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {this->columnHeader1, this->columnHeader2, 
				this->columnHeader3, this->columnHeader4});
			this->listView1->FullRowSelect = true;
			this->listView1->GridLines = true;
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(14, 14);
			this->listView1->MultiSelect = false;
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(405, 111);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->ItemSelectionChanged += gcnew System::Windows::Forms::ListViewItemSelectionChangedEventHandler(this, &Form1::listView1_ItemSelectionChanged);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"cid";
			this->columnHeader1->Width = 35;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Имя";
			this->columnHeader2->Width = 130;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Телефон";
			this->columnHeader3->Width = 110;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"E-mail";
			this->columnHeader4->Width = 110;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(46, 150);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 15);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Имя:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(18, 174);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 15);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Телефон:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(35, 199);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 15);
			this->label3->TabIndex = 3;
			this->label3->Text = L"E-mail:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(87, 147);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 21);
			this->textBox1->TabIndex = 4;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(87, 171);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 21);
			this->textBox2->TabIndex = 5;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(87, 196);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 21);
			this->textBox3->TabIndex = 6;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Form1::textBox_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(224, 147);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 21);
			this->textBox4->TabIndex = 7;
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(24, 242);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(126, 242);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Найти";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(223, 242);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Изменить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(321, 242);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 11;
			this->button4->Text = L"Удалить";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(470, 280);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listView1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SQL Server Compact Edition";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


// отображает базу данных (таблицу)
private: void ShowDB()
{
        SqlCeEngine^ engine =
           gcnew SqlCeEngine("Data Source='contacts.sdf';");
        SqlCeConnection^ connection =
			gcnew SqlCeConnection(engine->LocalConnectionString);
        connection->Open();
        SqlCeCommand^ command = connection->CreateCommand();
        command->CommandText =
             "SELECT * FROM contacts ORDER BY name";
        SqlCeDataReader^ dataReader = command->ExecuteReader();

        String^ st;  // значение поля БД
        int itemIndex = 0;

        listView1->Items->Clear();

        while (dataReader->Read())
        {
          for (int i = 0; i < dataReader->FieldCount; i++)
          {
              st = dataReader->GetValue(i)->ToString();
              switch (i)
              {
                case 0:  // поле cid
                    listView1->Items->Add(st);
                    break;
                case 1:  // поле name
                  listView1->Items[itemIndex]->SubItems->Add(st);
                  break;
                case 2:  // поле phone
                  listView1->Items[itemIndex]->SubItems->Add(st);
                  break;
                case 3:  // поле email
                  listView1->Items[itemIndex]->SubItems->Add(st);
                   break;
              };
            }
            itemIndex++;
        }
        connection->Close();
    }

// начало работы программы - загрузка формы
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
{
        
        SqlCeEngine^ engine;
        
        engine = 
           gcnew SqlCeEngine("Data Source='contacts.sdf';");
        
		// проверим, доступен ли файл БД
		if (!(File::Exists("contacts.sdf")))
        {
            // Cоздать БД SQL Server Compact Edition.
            // Путь к файлу не указан (см. выше),
			// поэтому БД будет создана в каталоге приложения.
			// При запуске программы из среды разработки,
			// текущим является каталоп Debug или Relese
			engine->CreateDatabase();
            SqlCeConnection^ connection =
            gcnew SqlCeConnection(engine->LocalConnectionString);
            connection->Open();
            SqlCeCommand^ command = connection->CreateCommand();
            command->CommandText =
                "CREATE TABLE contacts (cid int IDENTITY(1,1), name nvarchar(50) NOT NULL, phone nvarchar(50), email nvarchar(50))";
            command->ExecuteScalar();
            connection->Close();
        }
        else
        {
            ShowDB();
        }
    }


// щелчок на кнопке Добавить
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
    {
		SqlCeConnection^ conn =
           gcnew SqlCeConnection("Data Source ='contacts.sdf'");
        conn->Open();
        SqlCeCommand^ command = conn->CreateCommand();
        command->CommandText =
      "INSERT INTO contacts(name, phone,email) VALUES(?,?,?)";
        command->Parameters->Add("name", textBox1->Text);
        command->Parameters->Add("phone", textBox2->Text);
        command->Parameters->Add("email", textBox3->Text);
        command->ExecuteScalar();
        conn->Close();

        // очистить поля ввода
        textBox1->Clear();
        textBox2->Clear();
        textBox3->Clear();

        ShowDB();

        // установить курсор в поле textBox1
        textBox1->Focus();
    }
		 

// щелчок на кнопке Найти
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	  SqlCeEngine^ engine =
           gcnew SqlCeEngine("Data Source='contacts.sdf';");
        SqlCeConnection^ connection =
           gcnew SqlCeConnection(engine->LocalConnectionString);
        connection->Open();
        
        SqlCeCommand^ command = connection->CreateCommand();

        command->CommandText =
             "SELECT * FROM contacts WHERE (name LIKE ?)";
        command->Parameters->Add("name",
                                "%" + textBox1->Text + "%");
        
        SqlCeDataReader^ dataReader = command->ExecuteReader();

        String^ st;  // значение поля БД
        int itemIndex = 0;

        listView1->Items->Clear();

        while (dataReader->Read())
        {
            for (int i = 0; i < dataReader->FieldCount; i++)
            {
              st = dataReader->GetValue(i)->ToString();
              switch (i)
              {
                case 0:  // поле cid
                    listView1->Items->Add(st);
                    break;
                case 1:  // поле name
                  listView1->Items[itemIndex]->SubItems->Add(st);
                    break;
                case 2:  // поле phone
                  listView1->Items[itemIndex]->SubItems->Add(st);
                    break;
                case 3:  // поле email
                  listView1->Items[itemIndex]->SubItems->Add(st);
                    break;
              };
            }
            itemIndex++;
        }
        connection->Close();
}

// в поле компонента listView пользователь выбрал другую строку 
private: System::Void listView1_ItemSelectionChanged(System::Object^  sender, System::Windows::Forms::ListViewItemSelectionChangedEventArgs^  e)
{
	/*
	     При выборе строки событие ItemSelectionChanged
         возникает два раза: первый раз, когда выделенная в
         данный момент строка теряет фокус, второй – когда
         строка, в которой сделан щелчок, получает фокус.
         Нас интересует строка, которая получает фокус.
     */
     if (e->IsSelected)
     {
		// строка выбрана, т.е. она получила фокус
        textBox4->Text = listView1->Items[e->ItemIndex]->Text;

        // сдублируем содержимое полей текущей
		// записи в поля textBox
		for (int i = 1;
             i < listView1->Items[e->ItemIndex]->SubItems->Count;
                       i++)
        {
              switch (i)
              {
                case 1:
                    textBox1->Text =
               listView1->Items[e->ItemIndex]->SubItems[i]->Text;
                    break;
                case 2:
                    textBox2->Text =
                listView1->Items[e->ItemIndex]->SubItems[i]->Text;
                    break;
                case 3:
                    textBox3->Text =
                listView1->Items[e->ItemIndex]->SubItems[i]->Text;
                    break;
              }
            }
        }
}

// щелчок на кнопке Удалить
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (listView1->SelectedItems->Count != 0)
    {
		SqlCeEngine^ engine =
				gcnew SqlCeEngine("Data Source='contacts.sdf';");
         
		SqlCeConnection^ connection =
				gcnew SqlCeConnection(engine->LocalConnectionString);
        
		connection->Open();

        SqlCeCommand^ command = connection->CreateCommand();

        command->CommandText = 
                  "DELETE FROM contacts WHERE (cid = ?)";
        command->Parameters->Add("cid", textBox4->Text);
            
        command->ExecuteScalar(); // выполнить команду

        ShowDB();

        textBox1->Clear();
        textBox2->Clear();
        textBox3->Clear();
        textBox4->Clear();
	}
}

// щелчок на кнопке Изменить
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
{
        if (listView1->SelectedItems->Count != 0)
        {
            SqlCeEngine^ engine =
              gcnew SqlCeEngine("Data Source='contacts.sdf';");
            
			SqlCeConnection^ connection = gcnew
              SqlCeConnection(engine->LocalConnectionString);
            
			connection->Open();

            SqlCeCommand^ command = connection->CreateCommand();

            command->CommandText =
               "UPDATE contacts " + 
               "SET name = ?, phone =?, email=? " + 
               "WHERE cid = ?";
            
			command->Parameters->Add("name", textBox1->Text);
            command->Parameters->Add("phone", textBox2->Text);
            command->Parameters->Add("email", textBox3->Text);
            command->Parameters->Add("cid", textBox4->Text);

            command->ExecuteScalar(); // выполнить команду

            ShowDB();

            textBox1->Clear();
            textBox2->Clear();
            textBox3->Clear();
            textBox4->Clear();

/*
 SqlCeEngine engine = new SqlCeEngine("Data Source='contacts.sdf';");
                SqlCeConnection connection = new SqlCeConnection(engine.LocalConnectionString);
                connection.Open();

                SqlCeCommand command = connection.CreateCommand();

                command.CommandText = "UPDATE contacts SET name = ?, phone =?, email=? WHERE cid = ?";
                command.Parameters.Add("name", textBox1.Text);
                command.Parameters.Add("phone", textBox2.Text);
                command.Parameters.Add("email", textBox3.Text);
                command.Parameters.Add("cid", textBox4.Text);

                command.ExecuteScalar(); // выполнить команду

                ShowDB();

                textBox1.Clear();
                textBox2.Clear();
                textBox3.Clear();
                textBox4.Clear();
*/


        }		 
}

// Обработка события TextChanged компонентов
// textBox1 - textBox3. Одна функция обрабатывает
// событие от трех компонентов.
private: System::Void textBox_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	    // кнопка Добавить становится доступной,
        //  если информация введена в поле Имя и в
        //  какое-либо из полей Телефон или E-mail
        if ((textBox1->TextLength > 0) &&
            ((textBox2->TextLength > 0) || 
                  (textBox3->TextLength > 0)))
            button1->Enabled = true;
        else
        {
            button1->Enabled = false;
        }
}


};
}

