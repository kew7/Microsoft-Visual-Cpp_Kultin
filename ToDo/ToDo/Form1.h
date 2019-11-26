#pragma once


namespace ToDo {

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
				
			int dow = System::Convert::ToInt16(DateTime::Now.DayOfWeek);
			label2->Text = "Сегодня " + DateTime::Now.ToLongDateString() + ", " +  
			Application::CurrentCulture->DateTimeFormat->DayNames[dow];
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

	protected: 


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Data::OleDb::OleDbConnection^  oleDbConnection1;

	private: System::Data::DataSet^  dataSet1;
	private: System::Data::OleDb::OleDbCommand^  oleDbSelectCommand1;
	private: System::Data::OleDb::OleDbCommand^  oleDbInsertCommand1;
	private: System::Data::OleDb::OleDbCommand^  oleDbUpdateCommand1;
	private: System::Data::OleDb::OleDbCommand^  oleDbDeleteCommand1;
	private: System::Data::OleDb::OleDbDataAdapter^  oleDbDataAdapter1;

	private: System::Data::DataTable^  dataTable1;
	private: System::Data::DataColumn^  dataColumn1;
	private: System::Data::DataColumn^  dataColumn2;
	private: System::Data::DataColumn^  dataColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  tIDDataGridViewTextBoxColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  aDateDataGridViewTextBoxColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  aTaskDataGridViewTextBoxColumn;

	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::CheckBox^  checkBox1;

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->tIDDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->aDateDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->aTaskDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataSet1 = (gcnew System::Data::DataSet());
			this->dataTable1 = (gcnew System::Data::DataTable());
			this->dataColumn1 = (gcnew System::Data::DataColumn());
			this->dataColumn2 = (gcnew System::Data::DataColumn());
			this->dataColumn3 = (gcnew System::Data::DataColumn());
			this->oleDbConnection1 = (gcnew System::Data::OleDb::OleDbConnection());
			this->oleDbSelectCommand1 = (gcnew System::Data::OleDb::OleDbCommand());
			this->oleDbInsertCommand1 = (gcnew System::Data::OleDb::OleDbCommand());
			this->oleDbUpdateCommand1 = (gcnew System::Data::OleDb::OleDbCommand());
			this->oleDbDeleteCommand1 = (gcnew System::Data::OleDb::OleDbCommand());
			this->oleDbDataAdapter1 = (gcnew System::Data::OleDb::OleDbDataAdapter());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataSet1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataTable1))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(23, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 15);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Сегодня";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(26, 285);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Сегодня";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(116, 285);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Завтра";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(206, 285);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Эта неделя";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(394, 285);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Все";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoGenerateColumns = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->tIDDataGridViewTextBoxColumn, 
				this->aDateDataGridViewTextBoxColumn, this->aTaskDataGridViewTextBoxColumn});
			this->dataGridView1->DataMember = L"Tasks";
			this->dataGridView1->DataSource = this->dataSet1;
			this->dataGridView1->Location = System::Drawing::Point(20, 41);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 30;
			this->dataGridView1->Size = System::Drawing::Size(449, 198);
			this->dataGridView1->TabIndex = 7;
			// 
			// tIDDataGridViewTextBoxColumn
			// 
			this->tIDDataGridViewTextBoxColumn->DataPropertyName = L"TID";
			this->tIDDataGridViewTextBoxColumn->HeaderText = L"TID";
			this->tIDDataGridViewTextBoxColumn->Name = L"tIDDataGridViewTextBoxColumn";
			this->tIDDataGridViewTextBoxColumn->Visible = false;
			// 
			// aDateDataGridViewTextBoxColumn
			// 
			this->aDateDataGridViewTextBoxColumn->DataPropertyName = L"aDate";
			this->aDateDataGridViewTextBoxColumn->FillWeight = 45.68528F;
			this->aDateDataGridViewTextBoxColumn->HeaderText = L"Дата";
			this->aDateDataGridViewTextBoxColumn->Name = L"aDateDataGridViewTextBoxColumn";
			this->aDateDataGridViewTextBoxColumn->ToolTipText = L"Дата задачи (меропиятия)";
			// 
			// aTaskDataGridViewTextBoxColumn
			// 
			this->aTaskDataGridViewTextBoxColumn->DataPropertyName = L"aTask";
			this->aTaskDataGridViewTextBoxColumn->FillWeight = 154.3147F;
			this->aTaskDataGridViewTextBoxColumn->HeaderText = L"Задача";
			this->aTaskDataGridViewTextBoxColumn->Name = L"aTaskDataGridViewTextBoxColumn";
			// 
			// dataSet1
			// 
			this->dataSet1->DataSetName = L"NewDataSet";
			this->dataSet1->Tables->AddRange(gcnew cli::array< System::Data::DataTable^  >(1) {this->dataTable1});
			// 
			// dataTable1
			// 
			this->dataTable1->Columns->AddRange(gcnew cli::array< System::Data::DataColumn^  >(3) {this->dataColumn1, this->dataColumn2, 
				this->dataColumn3});
			this->dataTable1->TableName = L"Tasks";
			// 
			// dataColumn1
			// 
			this->dataColumn1->ColumnName = L"TID";
			// 
			// dataColumn2
			// 
			this->dataColumn2->ColumnName = L"aTask";
			// 
			// dataColumn3
			// 
			this->dataColumn3->ColumnName = L"aDate";
			this->dataColumn3->DataType = System::DateTime::typeid;
			// 
			// oleDbConnection1
			// 
			this->oleDbConnection1->ConnectionString = L"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=D:\\Database\\todo.mdb";
			// 
			// oleDbSelectCommand1
			// 
			this->oleDbSelectCommand1->CommandText = L"SELECT        TID, aTask, aDate\r\nFROM            Tasks\r\nWHERE        (aDate >= \?)" 
				L" AND (aDate <= \?)\r\nORDER BY aDate";
			this->oleDbSelectCommand1->Connection = this->oleDbConnection1;
			this->oleDbSelectCommand1->Parameters->AddRange(gcnew cli::array< System::Data::OleDb::OleDbParameter^  >(2) {(gcnew System::Data::OleDb::OleDbParameter(L"aDateFrom", 
				System::Data::OleDb::OleDbType::Date, 10, System::Data::ParameterDirection::Input, false, static_cast<System::Byte>(0), static_cast<System::Byte>(0), 
				L"aDate", System::Data::DataRowVersion::Current, L"")), (gcnew System::Data::OleDb::OleDbParameter(L"aDateTo", System::Data::OleDb::OleDbType::Date, 
				10, System::Data::ParameterDirection::Input, false, static_cast<System::Byte>(0), static_cast<System::Byte>(0), L"aDate", 
				System::Data::DataRowVersion::Current, L""))});
			// 
			// oleDbInsertCommand1
			// 
			this->oleDbInsertCommand1->CommandText = L"INSERT INTO Tasks (aTask, aDate)\r\n VALUES (\?, \?)";
			this->oleDbInsertCommand1->Connection = this->oleDbConnection1;
			this->oleDbInsertCommand1->Parameters->AddRange(gcnew cli::array< System::Data::OleDb::OleDbParameter^  >(2) {(gcnew System::Data::OleDb::OleDbParameter(L"aTask", 
				System::Data::OleDb::OleDbType::WChar, 50, L"aTask")), (gcnew System::Data::OleDb::OleDbParameter(L"aDate", System::Data::OleDb::OleDbType::Date, 
				0, L"aDate"))});
			// 
			// oleDbUpdateCommand1
			// 
			this->oleDbUpdateCommand1->CommandText = L"UPDATE Tasks SET aTask=\?, aDate=\? WHERE (TID=\?)";
			this->oleDbUpdateCommand1->Connection = this->oleDbConnection1;
			this->oleDbUpdateCommand1->Parameters->AddRange(gcnew cli::array< System::Data::OleDb::OleDbParameter^  >(3) {(gcnew System::Data::OleDb::OleDbParameter(L"aTask", 
				System::Data::OleDb::OleDbType::WChar, 50, L"aTask")), (gcnew System::Data::OleDb::OleDbParameter(L"aDate", System::Data::OleDb::OleDbType::Date, 
				0, L"aDate")), (gcnew System::Data::OleDb::OleDbParameter(L"Original_TID", System::Data::OleDb::OleDbType::Integer, 0, System::Data::ParameterDirection::Input, 
				false, static_cast<System::Byte>(0), static_cast<System::Byte>(0), L"TID", System::Data::DataRowVersion::Original, nullptr))});
			// 
			// oleDbDataAdapter1
			// 
			this->oleDbDataAdapter1->DeleteCommand = this->oleDbDeleteCommand1;
			this->oleDbDataAdapter1->InsertCommand = this->oleDbInsertCommand1;
			this->oleDbDataAdapter1->SelectCommand = this->oleDbSelectCommand1;
			this->oleDbDataAdapter1->UpdateCommand = this->oleDbUpdateCommand1;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(299, 285);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 9;
			this->button5->Text = L"След. нед.";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(29, 256);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(106, 17);
			this->checkBox1->TabIndex = 10;
			this->checkBox1->Text = L"с текущей даты";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(490, 321);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Ежедневник";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataSet1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataTable1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

// начало работы программы
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
{
	DateTime d = DateTime::Now;

    oleDbDataAdapter1->SelectCommand->CommandText =
		"SELECT TID, aTask, aDate FROM Tasks WHERE aDate = ?";

	// задать значение параметра команды SELECT
	oleDbDataAdapter1->SelectCommand->Parameters[0]->Value =
		         DateTime::Now.ToShortDateString();

	// У команды SELECT два параметра. В данном случае
	// используется только один. Но для того, чтобы
	// не возникло исключение, зададим значение
	// второго параметра.
	oleDbDataAdapter1->SelectCommand->Parameters[1]->Value = DateTime::Now.ToShortDateString();
	
	// выполнить команду
	oleDbDataAdapter1->Fill(dataSet1->Tables["Tasks"]);				 
}

// щелчок на кнопке Сегодня
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{		 
	int dow = System::Convert::ToInt16(DateTime::Now.DayOfWeek);
	
	// если пользователь внес изменения,
	// сохраним их
	if (dataSet1->HasChanges())
	{
		oleDbDataAdapter1->Update(dataSet1->Tables["Tasks"]);
	}

	label2->Text = "Сегодня " + DateTime::Now.ToLongDateString() + ", " +  
			Application::CurrentCulture->DateTimeFormat->DayNames[dow];
	

	oleDbDataAdapter1->SelectCommand->CommandText =
		"SELECT TID, aTask, aDate FROM Tasks WHERE aDate = ?";

	// задать значение параметра команды SELECT
	oleDbDataAdapter1->SelectCommand->Parameters[0]->Value =
		DateTime::Now.ToShortDateString();
	
	// удалить результат выполнения предыдущей
	// команды SELECT
	dataSet1->Clear(); 
	
	// выполнить команду
	oleDbDataAdapter1->Fill(dataSet1->Tables["Tasks"]);	
}

// щелчок на кнопке Завтра
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
{
			 
    DateTime d = DateTime::Now.AddDays(1);

    // если пользователь внес изменения,
	// сохраним их
	if (dataSet1->HasChanges () )
		oleDbDataAdapter1->Update(dataSet1->Tables["Tasks"]);

    label2->Text = "Завтра (" +  d.ToShortDateString()+")";

	oleDbDataAdapter1->SelectCommand->CommandText =
		"SELECT TID, aTask, aDate FROM Tasks WHERE aDate = ?";

	// задать параметр команды SELECT
	oleDbDataAdapter1->SelectCommand->Parameters[0]->Value = d.ToShortDateString();

	dataSet1->Clear(); 
	
	// выполнить команду
	oleDbDataAdapter1->Fill(dataSet1->Tables["Tasks"]);	
}

// на этой неделе
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
{
			DateTime d1; // первый день (дата) недели
			DateTime d2; // последний день (дата) недели

			int dow; // сегодня (день недели)
			
            // если пользователь внес изменения,
	        // сохраним их
	        if ( dataSet1->HasChanges() )
		       oleDbDataAdapter1->Update(dataSet1->Tables["Tasks"]);

			dow = System::Convert::ToInt16(DateTime::Now.DayOfWeek);

			d1 = DateTime::Now.AddDays(1- dow); // .AddDays( -(dow -1) );
			d2 = DateTime::Now.AddDays(6);   

			if ( checkBox1->Checked )
				// не отображать задачи предыдущих дней
				d1 = DateTime::Now;
			
			label2->Text =  "На этой неделе (c " +  d1.ToShortDateString() + 
                   " по " + d2.ToShortDateString()+")";

			oleDbDataAdapter1->SelectCommand->CommandText =
		      "SELECT TID, aTask, aDate FROM Tasks WHERE (aDate >= ?) AND (aDate <= ?) ORDER BY aDate";

			oleDbDataAdapter1->SelectCommand->Parameters[0]->Value = d1.ToShortDateString();
			oleDbDataAdapter1->SelectCommand->Parameters[1]->Value = d2.ToShortDateString();
			
			dataSet1->Clear();
			oleDbDataAdapter1->Fill(dataSet1->Tables["Tasks"]);		
}

// на следующей неделе
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e)
{
	DateTime d1; // первый день (дата) след. недели
	DateTime d2; // последний день (дата) след. недели

	int dow; // сегодня (день недели)
	

    // если пользователь внес изменения,
	// сохраним их
	if ( dataSet1->HasChanges() )
		oleDbDataAdapter1->Update(dataSet1->Tables["Tasks"]);

	dow= System::Convert::ToInt16(DateTime::Now.DayOfWeek);

	d1 = DateTime::Now.AddDays( 8 - dow ); // d1.AddDays( -(dow -1) + 7 );
	d2 = d1.AddDays(6);
			
	label2->Text =  "На следующей неделе (c " +  d1.ToShortDateString() + 
                   " по " + d2.ToShortDateString()+")";

	// задать параметры команды SELECT
	//oleDbDataAdapter1->SelectCommand->Parameters[0]->Value = d1.ToShortDateString();
	//oleDbDataAdapter1->SelectCommand->Parameters[1]->Value = d2.ToShortDateString();

	oleDbDataAdapter1->SelectCommand->CommandText =
		      "SELECT TID, aTask, aDate FROM Tasks WHERE (aDate >= ?) AND (aDate <= ?) ORDER BY aDate";

    
	// задать параметры команды SELECT
	oleDbDataAdapter1->SelectCommand->Parameters[0]->Value = d1.ToShortDateString();
	oleDbDataAdapter1->SelectCommand->Parameters[1]->Value = d2.ToShortDateString();
	
	dataSet1->Clear();

	oleDbDataAdapter1->Fill(dataSet1->Tables["Tasks"]);	
}

// Все, что намечено сделать
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e)
{
	label2->Text = "";

	// если пользователь внес изменения,
	// сохраним их
	if ( dataSet1->HasChanges() )
		dataSet1->AcceptChanges();


	if ( checkBox1->Checked )
	{
	    // не отображать задачи предыдущих дней

		oleDbDataAdapter1->SelectCommand->CommandText =
		     "SELECT TID, aTask, aDate FROM Tasks WHERE (aDate >= ?)ORDER BY aDate";

		// задать значение параметра команды SELECT
	    oleDbDataAdapter1->SelectCommand->Parameters[0]->Value =
					DateTime::Now.ToShortDateString();

	    oleDbDataAdapter1->SelectCommand->CommandText =
		      "SELECT TID, aTask, aDate FROM Tasks WHERE (aDate >= ?) AND (aDate <= ?) ORDER BY aDate";  
	}
	else
		// все задачи
        oleDbDataAdapter1->SelectCommand->CommandText =
		      "SELECT * FROM Tasks ORDER BY aDate";

	dataSet1->Clear();
	oleDbDataAdapter1->Fill(dataSet1->Tables["Tasks"]);	
}



// завершение работы программы
private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
{
	oleDbDataAdapter1->Update(dataSet1->Tables["Tasks"]);
}


};
}

