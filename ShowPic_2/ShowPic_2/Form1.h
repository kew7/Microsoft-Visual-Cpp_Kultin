#pragma once


namespace ShowPic_2 {

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
			//
			// запомнить размер 
            // и положение pictureBox1
            pbh = pictureBox1->Height;
            pbw = pictureBox1->Width;
			pbX = pictureBox1->Location.X;
            pbY = pictureBox1->Location.Y;
            
            // получить имя каталога "Мои рисунки"
			DirectoryInfo^ di; // каталог
			di = gcnew DirectoryInfo(Environment::GetFolderPath(
				Environment::SpecialFolder::MyPictures));
            aPath = di->FullName;
            this->Text = aPath;

			imgList = gcnew System::Collections::Generic::List<String^>;

			// сформировать список иллюстраций
			FillList(aPath);
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
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::ToolTip^  toolTip1;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(23, 280);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Обзор";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(171, 280);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(43, 23);
			this->button2->TabIndex = 1;
			this->toolTip1->SetToolTip(this->button2, L"Предыдущая");
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button3.Image")));
			this->button3->Location = System::Drawing::Point(220, 280);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(43, 23);
			this->button3->TabIndex = 2;
			this->toolTip1->SetToolTip(this->button3, L"Следующая");
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(23, 13);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(389, 256);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(433, 312);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Слайд-шоу (просмотр иллюстраций)";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	

private:  
	String^ aPath;	  // путь к файлам картинок
	int pbw, pbh;     // первоначальный размер
    int pbX, pbY;     // и положение pictureBox

	// список иллюстраций				
	System::Collections::Generic::List<String^> ^imgList;
	
    int cImg; // номер отображаемой иллюстрации				


private: void ShowPicture(String^ aPicture)

{
	double mh, mw;   // коэффициенты масштабирования по ширине и высот

    pictureBox1->Visible = false;
    pictureBox1->Left = pbX;

    // загружаем изображение в pictureBox1
    pictureBox1->SizeMode =
		PictureBoxSizeMode::AutoSize;
    
	pictureBox1->Image =
                gcnew Bitmap( aPath + "\\" + 
                            imgList[cImg]);

	// масштабируем, если нужно
    if ((pictureBox1->Image->Width > pbw) ||
        (pictureBox1->Image->Height > pbh))
    {
		pictureBox1->SizeMode =
			PictureBoxSizeMode::StretchImage;

        mh = (double)pbh /
                          (double)pictureBox1->Image->Height;
                mw = (double)pbw /
                          (double)pictureBox1->Image->Width;

        if (mh < mw)
        {
			// масштабируем по ширине
			pictureBox1->Width = Convert::ToInt16(
                            pictureBox1->Image->Width * mh);
                    pictureBox1->Height = pbh;
        }
		else
        {
			// масштабируем по высоте
            pictureBox1->Width = pbw;
			pictureBox1->Height = Convert::ToInt16(
                            pictureBox1->Image->Height * mw);
         }
	}

    // разместить картинку в центре области
    // отображения иллюстраций
	pictureBox1->Left =
                    pbX + (pbw - pictureBox1->Width) / 2;
    pictureBox1->Top =
                    pbY + (pbh - pictureBox1->Height) / 2;

    pictureBox1->Visible = true; 
}
	
	
	
private: System::Boolean FillList(String^ aPath)
{
	// информация о каталоге
    DirectoryInfo^ di =
    gcnew DirectoryInfo(aPath);

	// информация о файлах
	array<FileInfo^> ^fi = di->GetFiles("*.jpg");

    // очистить список 
	imgList->Clear();

	button2->Enabled = true;
	button3->Enabled = true;

    // добавляем в список имена jpg-файлов,
    // содержащихся в каталоге aPath
    for each (FileInfo^ fc in fi)
    {
		imgList->Add(fc->Name);
    }

    this->Text = aPath;

	if ( imgList->Count == 0)
		  return false;
    else
    {
                cImg = 0;
                ShowPicture(aPath + "\\" + imgList[cImg]);

                // сделать недоступной кнопку Предыдущая 
                button2->Enabled = false;

                // если в каталоге один jpg-файл,
                // сделать недоступной кнопку Следующая 
                if (imgList->Count == 1)
                    button3->Enabled = false;

                this->Text = aPath;

                return true;
    }
}



// щелчок на кнопке Обзор
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
// FolderBrowserDialog - окно Обзор папок
    FolderBrowserDialog^ fb
			= gcnew FolderBrowserDialog();

	fb->Description =
                 "Выберите папку,\n" +
                 "в которой находятся иллюстрации";
    fb->ShowNewFolderButton = false;

	fb->SelectedPath = aPath;

    // отобразить окно Обзор папок
	// и проверить, щелчком на какой кнопке
	// пользователь закрыл его
	if (fb->ShowDialog() == System::Windows::Forms::DialogResult::OK)
    {
		// пользователь выбрал каталог и
        // щелкнул на кнопке OK
        aPath = fb->SelectedPath;
        this->Text = aPath;

        if ( !FillList(fb->SelectedPath))
           // в каталоге нет файлов иллюстраций
		   pictureBox1->Image = nullptr;
     }
}


// щелчок на кнопке Предыдущая картинка
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	// если кнопка "Следующая" недоступна,
    // сделаем ее доступной
    if (!button3->Enabled)
		button3->Enabled = true;

    if (cImg > 0)
    {
		cImg--;
        ShowPicture(aPath + "\\" + imgList[cImg]);

        // отображается первая иллюстрация 
        if (cImg == 0)
        {
			// теперь кнопка Предыдущая недоступна 
            button2->Enabled = false;
         }
     }
}

// щелчок на кнопке Следующая картинка
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
if (!button2->Enabled)
       button2->Enabled = true;

     if (cImg < imgList->Count)
     {
		cImg++;
        ShowPicture(aPath + "\\" + imgList[cImg]);
        if (cImg == imgList->Count -1)
        {
			button3->Enabled = false;
        }
     }		 
}



};
}

