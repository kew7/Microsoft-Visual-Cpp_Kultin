#pragma once


namespace Contacts_1 {

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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  cidDataGridViewTextBoxColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  nameDataGridViewTextBoxColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  phoneDataGridViewTextBoxColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  emailDataGridViewTextBoxColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  imgDataGridViewTextBoxColumn;






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
			this->imgDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataSet1 = (gcnew System::Data::DataSet());
			this->dataTable1 = (gcnew System::Data::DataTable());
			this->dataColumn1 = (gcnew System::Data::DataColumn());
			this->dataColumn2 = (gcnew System::Data::DataColumn());
			this->dataColumn3 = (gcnew System::Data::DataColumn());
			this->dataColumn4 = (gcnew System::Data::DataColumn());
			this->dataColumn5 = (gcnew System::Data::DataColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataSet1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataTable1))->BeginInit();
			this->SuspendLayout();
			// 
			// oleDbConnection1
			// 
			this->oleDbConnection1->ConnectionString = L"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=D:\\Database\\contacts.mdb";
			this->oleDbConnection1->InfoMessage += gcnew System::Data::OleDb::OleDbInfoMessageEventHandler(this, &Form1::oleDbConnection1_InfoMessage);
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
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->cidDataGridViewTextBoxColumn, 
				this->nameDataGridViewTextBoxColumn, this->phoneDataGridViewTextBoxColumn, this->emailDataGridViewTextBoxColumn, this->imgDataGridViewTextBoxColumn});
			this->dataGridView1->DataMember = L"contacts";
			this->dataGridView1->DataSource = this->dataSet1;
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 32;
			this->dataGridView1->Size = System::Drawing::Size(435, 155);
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
			// 
			// phoneDataGridViewTextBoxColumn
			// 
			this->phoneDataGridViewTextBoxColumn->DataPropertyName = L"phone";
			this->phoneDataGridViewTextBoxColumn->HeaderText = L"Телефон";
			this->phoneDataGridViewTextBoxColumn->Name = L"phoneDataGridViewTextBoxColumn";
			// 
			// emailDataGridViewTextBoxColumn
			// 
			this->emailDataGridViewTextBoxColumn->DataPropertyName = L"email";
			this->emailDataGridViewTextBoxColumn->HeaderText = L"Эл. почта";
			this->emailDataGridViewTextBoxColumn->Name = L"emailDataGridViewTextBoxColumn";
			// 
			// imgDataGridViewTextBoxColumn
			// 
			this->imgDataGridViewTextBoxColumn->DataPropertyName = L"img";
			this->imgDataGridViewTextBoxColumn->HeaderText = L"img";
			this->imgDataGridViewTextBoxColumn->Name = L"imgDataGridViewTextBoxColumn";
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
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(462, 264);
			this->Controls->Add(this->dataGridView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Контакты";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataSet1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataTable1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void oleDbConnection1_InfoMessage(System::Object^  sender, System::Data::OleDb::OleDbInfoMessageEventArgs^  e) {
			 }

// начало работы программы
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
			 {
				 // загрузить данные
				 oleDbDataAdapter1->Fill(dataTable1);
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

