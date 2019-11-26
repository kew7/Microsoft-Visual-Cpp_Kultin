#pragma once


namespace Contacts_3 {

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

			dbPath = Application::StartupPath;
            imFolder =  dbPath + "\\Images\\";
        	oleDbDataAdapter1->Fill(dataTable1);

			textBox1->DataBindings->Add((gcnew System::Windows::Forms::Binding(L"Text", dataSet1, L"contacts.name", true)));
		    this->textBox2->DataBindings->Add((gcnew System::Windows::Forms::Binding(L"Text", this->dataSet1, L"contacts.phone", true)));
			this->textBox3->DataBindings->Add((gcnew System::Windows::Forms::Binding(L"Text", this->dataSet1, L"contacts.email", true)));
			this->textBox4->DataBindings->Add((gcnew System::Windows::Forms::Binding(L"Text", this->dataSet1, L"contacts.img", true)));
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
	private: System::Data::OleDb::OleDbConnection^  oleDbConnection1;
	protected: 
	private: System::Data::OleDb::OleDbCommand^  oleDbSelectCommand1;
	private: System::Data::OleDb::OleDbCommand^  oleDbInsertCommand1;
	private: System::Data::OleDb::OleDbCommand^  oleDbUpdateCommand1;
	private: System::Data::OleDb::OleDbCommand^  oleDbDeleteCommand1;
	private: System::Data::OleDb::OleDbDataAdapter^  oleDbDataAdapter1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Data::DataSet^  dataSet1;
	private: System::Data::DataTable^  dataTable1;


	private: System::Data::DataColumn^  dataColumn1;
	private: System::Data::DataColumn^  dataColumn2;
	private: System::Data::DataColumn^  dataColumn3;
	private: System::Data::DataColumn^  dataColumn4;
	private: System::Data::DataColumn^  dataColumn5;




	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;




	private: System::Windows::Forms::ToolTip^  toolTip1;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;




	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  cidDataGridViewTextBoxColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  nameDataGridViewTextBoxColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  phoneDataGridViewTextBoxColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  emailDataGridViewTextBoxColumn;





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
			this->oleDbConnection1 = (gcnew System::Data::OleDb::OleDbConnection());
			this->oleDbSelectCommand1 = (gcnew System::Data::OleDb::OleDbCommand());
			this->oleDbInsertCommand1 = (gcnew System::Data::OleDb::OleDbCommand());
			this->oleDbUpdateCommand1 = (gcnew System::Data::OleDb::OleDbCommand());
			this->oleDbDeleteCommand1 = (gcnew System::Data::OleDb::OleDbCommand());
			this->oleDbDataAdapter1 = (gcnew System::Data::OleDb::OleDbDataAdapter());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->cidDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nameDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->phoneDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->emailDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataSet1 = (gcnew System::Data::DataSet());
			this->dataTable1 = (gcnew System::Data::DataTable());
			this->dataColumn1 = (gcnew System::Data::DataColumn());
			this->dataColumn2 = (gcnew System::Data::DataColumn());
			this->dataColumn3 = (gcnew System::Data::DataColumn());
			this->dataColumn4 = (gcnew System::Data::DataColumn());
			this->dataColumn5 = (gcnew System::Data::DataColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataSet1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataTable1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// oleDbConnection1
			// 
			this->oleDbConnection1->ConnectionString = L"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=D:\\Database\\contacts.mdb";
			// 
			// oleDbSelectCommand1
			// 
			this->oleDbSelectCommand1->CommandText = L"SELECT        cid, name, phone, email, img\r\nFROM            contacts";
			this->oleDbSelectCommand1->Connection = this->oleDbConnection1;
			// 
			// oleDbInsertCommand1
			// 
			this->oleDbInsertCommand1->CommandText = L"INSERT INTO contacts\r\n                         (name, phone, email, img)\r\nVALUES " 
				L"       (\?, \?, \?, \?)";
			this->oleDbInsertCommand1->Connection = this->oleDbConnection1;
			this->oleDbInsertCommand1->Parameters->AddRange(gcnew cli::array< System::Data::OleDb::OleDbParameter^  >(4) {(gcnew System::Data::OleDb::OleDbParameter(L"name", 
				System::Data::OleDb::OleDbType::WChar, 50, L"name")), (gcnew System::Data::OleDb::OleDbParameter(L"phone", System::Data::OleDb::OleDbType::WChar, 
				50, L"phone")), (gcnew System::Data::OleDb::OleDbParameter(L"email", System::Data::OleDb::OleDbType::WChar, 50, L"email")), (gcnew System::Data::OleDb::OleDbParameter(L"img", 
				System::Data::OleDb::OleDbType::WChar, 50, L"img"))});
			// 
			// oleDbUpdateCommand1
			// 
			this->oleDbUpdateCommand1->CommandText = L"UPDATE       contacts\r\nSET                name = \?, phone = \?, email = \?, img = \?" 
				L"\r\nWHERE        (cid = \?)";
			this->oleDbUpdateCommand1->Connection = this->oleDbConnection1;
			this->oleDbUpdateCommand1->Parameters->AddRange(gcnew cli::array< System::Data::OleDb::OleDbParameter^  >(5) {(gcnew System::Data::OleDb::OleDbParameter(L"name", 
				System::Data::OleDb::OleDbType::WChar, 50, L"name")), (gcnew System::Data::OleDb::OleDbParameter(L"phone", System::Data::OleDb::OleDbType::WChar, 
				50, L"phone")), (gcnew System::Data::OleDb::OleDbParameter(L"email", System::Data::OleDb::OleDbType::WChar, 50, L"email")), (gcnew System::Data::OleDb::OleDbParameter(L"img", 
				System::Data::OleDb::OleDbType::WChar, 50, L"img")), (gcnew System::Data::OleDb::OleDbParameter(L"Original_cid", System::Data::OleDb::OleDbType::Integer, 
				0, System::Data::ParameterDirection::Input, false, static_cast<System::Byte>(0), static_cast<System::Byte>(0), L"cid", System::Data::DataRowVersion::Original, 
				nullptr))});
			// 
			// oleDbDeleteCommand1
			// 
			this->oleDbDeleteCommand1->CommandText = L"DELETE FROM contacts\r\nWHERE        (cid = \?)";
			this->oleDbDeleteCommand1->Connection = this->oleDbConnection1;
			this->oleDbDeleteCommand1->Parameters->AddRange(gcnew cli::array< System::Data::OleDb::OleDbParameter^  >(1) {(gcnew System::Data::OleDb::OleDbParameter(L"cid", 
				System::Data::OleDb::OleDbType::Integer, 0, System::Data::ParameterDirection::Input, false, static_cast<System::Byte>(0), 
				static_cast<System::Byte>(0), L"cid", System::Data::DataRowVersion::Original, nullptr))});
			// 
			// oleDbDataAdapter1
			// 
			this->oleDbDataAdapter1->DeleteCommand = this->oleDbDeleteCommand1;
			this->oleDbDataAdapter1->InsertCommand = this->oleDbInsertCommand1;
			this->oleDbDataAdapter1->SelectCommand = this->oleDbSelectCommand1;
			this->oleDbDataAdapter1->UpdateCommand = this->oleDbUpdateCommand1;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoGenerateColumns = false;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->cidDataGridViewTextBoxColumn, 
				this->nameDataGridViewTextBoxColumn, this->phoneDataGridViewTextBoxColumn, this->emailDataGridViewTextBoxColumn});
			this->dataGridView1->DataMember = L"contacts";
			this->dataGridView1->DataSource = this->dataSet1;
			this->dataGridView1->Location = System::Drawing::Point(22, 134);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 28;
			this->dataGridView1->RowTemplate->DefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->dataGridView1->RowTemplate->Height = 20;
			this->dataGridView1->Size = System::Drawing::Size(405, 143);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->UserDeletingRow += gcnew System::Windows::Forms::DataGridViewRowCancelEventHandler(this, &Form1::dataGridView1_UserDeletingRow);
			// 
			// cidDataGridViewTextBoxColumn
			// 
			this->cidDataGridViewTextBoxColumn->DataPropertyName = L"cid";
			this->cidDataGridViewTextBoxColumn->HeaderText = L"cid";
			this->cidDataGridViewTextBoxColumn->Name = L"cidDataGridViewTextBoxColumn";
			this->cidDataGridViewTextBoxColumn->Visible = false;
			// 
			// nameDataGridViewTextBoxColumn
			// 
			this->nameDataGridViewTextBoxColumn->DataPropertyName = L"name";
			this->nameDataGridViewTextBoxColumn->HeaderText = L"Имя";
			this->nameDataGridViewTextBoxColumn->Name = L"nameDataGridViewTextBoxColumn";
			this->nameDataGridViewTextBoxColumn->Width = 120;
			// 
			// phoneDataGridViewTextBoxColumn
			// 
			this->phoneDataGridViewTextBoxColumn->DataPropertyName = L"phone";
			this->phoneDataGridViewTextBoxColumn->HeaderText = L"Телефон";
			this->phoneDataGridViewTextBoxColumn->Name = L"phoneDataGridViewTextBoxColumn";
			this->phoneDataGridViewTextBoxColumn->Width = 120;
			// 
			// emailDataGridViewTextBoxColumn
			// 
			this->emailDataGridViewTextBoxColumn->DataPropertyName = L"email";
			this->emailDataGridViewTextBoxColumn->HeaderText = L"Эл. почта";
			this->emailDataGridViewTextBoxColumn->Name = L"emailDataGridViewTextBoxColumn";
			this->emailDataGridViewTextBoxColumn->Width = 120;
			// 
			// dataSet1
			// 
			this->dataSet1->DataSetName = L"NewDataSet";
			this->dataSet1->Tables->AddRange(gcnew cli::array< System::Data::DataTable^  >(1) {this->dataTable1});
			// 
			// dataTable1
			// 
			this->dataTable1->Columns->AddRange(gcnew cli::array< System::Data::DataColumn^  >(5) {this->dataColumn1, this->dataColumn2, 
				this->dataColumn3, this->dataColumn4, this->dataColumn5});
			cli::array< System::String^ >^ __mcTemp__1 = gcnew cli::array< System::String^  >(1) {L"cid"};
			this->dataTable1->Constraints->AddRange(gcnew cli::array< System::Data::Constraint^  >(1) {(gcnew System::Data::UniqueConstraint(L"Constraint1", 
				__mcTemp__1, true))});
			this->dataTable1->PrimaryKey = gcnew cli::array< System::Data::DataColumn^  >(1) {this->dataColumn1};
			this->dataTable1->TableName = L"contacts";
			// 
			// dataColumn1
			// 
			this->dataColumn1->AllowDBNull = false;
			this->dataColumn1->ColumnName = L"cid";
			// 
			// dataColumn2
			// 
			this->dataColumn2->ColumnName = L"name";
			// 
			// dataColumn3
			// 
			this->dataColumn3->ColumnName = L"phone";
			// 
			// dataColumn4
			// 
			this->dataColumn4->ColumnName = L"email";
			// 
			// dataColumn5
			// 
			this->dataColumn5->ColumnName = L"img";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(48, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 15);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Имя:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(22, 47);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 15);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Телефон:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 77);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 15);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Эл. почта:";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(327, 14);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 100);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			this->toolTip1->SetToolTip(this->pictureBox1, L"Щелкните, чтобы изменить картинку");
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(89, 14);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(165, 21);
			this->textBox1->TabIndex = 4;
			// 
			// textBox2
			// 
			this->textBox2->DataBindings->Add((gcnew System::Windows::Forms::Binding(L"Text", this->dataSet1, L"contacts.phone", true)));
			this->textBox2->Location = System::Drawing::Point(89, 44);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(165, 21);
			this->textBox2->TabIndex = 5;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(89, 74);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(165, 21);
			this->textBox3->TabIndex = 6;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(352, 47);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(75, 21);
			this->textBox4->TabIndex = 7;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Form1::textBox4_TextChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(454, 295);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Контакты-3";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataSet1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataTable1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


			 
private:
    String^ dbPath;   // папка приложениени
    String^ imFolder; // папка иллюстраций
			 
// начало работы программы
private:
System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
{				 
/*
	// загрузить путь к файлу БД  из файла конфигурации
	// dbPath = Settings.Default.DbPath;
	dbPath = Application::StartupPath;
        
    // открыть соединение с БД
    //oleDbConnection1->ConnectionString =
    //       "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" +
    //       dbPath + "\\Contacts.mdb";

    // папка иллюстраций
    imFolder =  dbPath + "\\Images\\";

    // получить информацию из БД
	oleDbDataAdapter1->Fill(dataTable1);
    //oleDbDataAdapter1->Fill(dataSet1->Tables[0]);
*/
}

// изменилось содержимое поля textBox4 - 
// отобразить иллюстрацию, имя файла которой
// находится в этом поле
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	String^ imageFile;
    String^ msg; // сообщение об ошибке

	if (textBox4->Text == String::Empty )
    {
          imageFile = imFolder + "nobody.jpg";
    }
    else
          imageFile = imFolder + textBox4->Text;

    // отобразить иллюстрацию
	try
    {
          msg = "";
          pictureBox1->Image =
		    System::Drawing::Bitmap::FromFile(imageFile);
    }
	catch (System::IO::FileNotFoundException^ e)
    {
          // вывести сообщение об ошибке в поле
          // компонента pictureBox1
          msg = "File nof found: " + imageFile;
		  pictureBox1->Image = nullptr;
          pictureBox1->Refresh();
    }
}



// щелчок на компоненте pictureBox
private:
System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e)
{
	openFileDialog1->Title = "Выберите иллюстрацию";
    openFileDialog1->InitialDirectory = imFolder;
    openFileDialog1->Filter = "фото|*.jpg|все файлы|*.*";
    openFileDialog1->FileName = "";
      
	if (openFileDialog1->ShowDialog() ==   System::Windows::Forms::DialogResult::OK)
    {
		// пользователь указал файл иллюстрации
          
        // проверим, находится ли выбранный файл
        // в каталоге imFolder
        bool r =
			openFileDialog1->FileName->ToLower()->Contains(
              openFileDialog1->InitialDirectory->ToLower());
        if (r == true)
        {
              // копировать не надо т.к. пользователь
              // указал иллюстрацию, которая
              // находится в imFolder
              textBox4->Text =
                       openFileDialog1->SafeFileName;
        }
        else
        {
			// Скопировать файл иллюстрации в папку Images
            // Если в каталоге-приемнике есть файл 
            // с таким же именем, что и копируемый,
            // возникает исключение
            try
            {
                // копировать файл
				System::IO::File::Copy(openFileDialog1->FileName,
					imFolder + openFileDialog1->SafeFileName);

                textBox4->Text = openFileDialog1->SafeFileName;
             }
			catch (System::Exception^ e)
             {
                 System::Windows::Forms::DialogResult dr;
				 dr = MessageBox::Show(e->Message +
                          " Заменить его?", "",
						  MessageBoxButtons::OKCancel,
						  MessageBoxIcon::Warning,
						  MessageBoxDefaultButton::Button2);
				 if (dr == System::Windows::Forms::DialogResult::OK)
                  {
                    // перезаписать файл
					  System::IO::File::Copy(
                      openFileDialog1->FileName,
                      imFolder + openFileDialog1->SafeFileName,
                      true);   
                   textBox4->Text =
                              openFileDialog1->SafeFileName;
                   }
                }
            }
        }

}


// пользователь выделил строку и нажал <Delete>
private: System::Void dataGridView1_UserDeletingRow(System::Object^  sender, System::Windows::Forms::DataGridViewRowCancelEventArgs^  e)
		 {
			 System::Windows::Forms::DialogResult dr =
				MessageBox::Show("Удалить запись?",
                            "Удаление записи",
							MessageBoxButtons::OKCancel,
							MessageBoxIcon::Warning,
							MessageBoxDefaultButton::Button2);
			
			 if (dr == System::Windows::Forms::DialogResult::Yes )
            {
                e->Cancel = true;
            }

		 }


// завершение работы программы
private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
		 {
			 // обновить данные
			 oleDbDataAdapter1->Update(dataSet1->Tables["contacts"]);
		 }


};
}

