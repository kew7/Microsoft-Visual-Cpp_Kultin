#pragma once


namespace puzzle {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� Form1
	///
	/// ��������! ��� ��������� ����� ����� ������ ���������� ����� ��������
	///          �������� ����� ����� �������� ("Resource File Name") ��� �������� ���������� ������������ �������,
	///          ���������� �� ����� ������� � ����������� .resx, �� ������� ������� ������ �����. � ��������� ������,
	///          ������������ �� ������ ��������� �������� � ���������������
	///          ���������, ��������������� ������ �����.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			
			try
			{
				// ��������� ���� ��������
				pics = gcnew Bitmap(Application::StartupPath + "\\puzzle.bmp");
			}
			catch (Exception^ )
			{
				MessageBox::Show("���� 'puzzle.bmp' �� ������.\n",
					"Puzzle game",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
				
				return;
			}

			// ���������� ������ � ������ ������ (�����)
			cw = (int)(pics->Width / nw);
			ch = (int)(pics->Height / nh);

			// ���������� ������ ���������� ������� �����
			this->ClientSize =
				System::Drawing::Size(cw * nw + 1,
                            ch * nh + 1 + menuStrip1->Height);

			// ������� ����������� �����������
			g = this->CreateGraphics();

			newGame();
	}


	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  MenuItem1;
	protected: 


	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->MenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->MenuItem1});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(284, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// MenuItem1
			// 
			this->MenuItem1->Name = L"MenuItem1";
			this->MenuItem1->Size = System::Drawing::Size(81, 20);
			this->MenuItem1->Text = L"����� ����";
			this->MenuItem1->Click += gcnew System::EventHandler(this, &Form1::MenuItem1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 264);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Puzzle";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseClick);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private:
	// 4�4 - ������ �������� ����
    static int nw = 4, nh = 4;

    // ����������� �����������
	System::Drawing::Graphics^ g;

    // ��������
    Bitmap^ pics;

    // ������ (������ � ������) ������
    int cw, ch;

    // ������� ���� - ������ 4�4.
	// ������ ������ ���������� ��������
	static array<int,2>^ field = gcnew array<int,2>(4,4);

    // ���������� ������ ������
    int ex, ey;

    // ���������� ������ �����
    static Boolean showNumbers = false; 


// ����� ����
void newGame()
{
	// ����������� ����� � ���������� �������
    for (int j = 0; j < nh; j++)
        for (int i = 0; i < nw; i++)
             field[i, j] = j * nw + i + 1;

    // ��������� ����� - ������
    field[nw - 1, nh - 1] = 0;
    ex = nw - 1; ey = nh - 1;

    this->mix();        // ������������ �����
    this->drawField();   // ������ ������� ����
}

// ������������ �����
void mix()
{
	int d; // ��������� (������������ ������) ������������
           // �����: 0 - �����; 1 - ������;
           //         2 - ������; 3 - �����.

    int x, y; // ���������� ������������ ����� 

    // ��������� ��������� �����
    Random^ rnd = gcnew Random();

    
	// ������� 160 �������
	for (int i = 0; i < 160; i++)
    {
		x = ex;
        y = ey;

        // ������� �����, ������� �����
		// "�������" � ������ ������
		d = rnd->Next(4);
        switch (d)
        {
                case 0: if (x > 0) x--; break;
                case 1: if (x < nw - 1) x++; break;
                case 2: if (y > 0) y--; break;
                case 3: if (y < nh - 1) y++; break;
         }

         // ����� ���������� �����, �������
         // ����� ����������� � ������ ������
         field[ex, ey] = field[x, y];
         field[x, y] = 0;

         // ���������� ���������� ������ ������
         ex = x;
		 ey = y;
     }
}

// ������ ����
void drawField()
{
	// ������ ������
    for (int i = 0; i < nw; i++)
		for (int j = 0; j < nh; j++)
            {
                if (field[i, j] != 0)
				{
                    // ������ �������� ��������:	
					// �������� �������� � ����� �����������
					// ����������� �� ������
			
					// ����		
					Rectangle r1 =
						   Rectangle(i * cw,
                                  j * ch + menuStrip1->Height,
                                  cw, ch);
					// ������
				    Rectangle r2 = Rectangle(
                            ((field[i, j] - 1) % nw) * cw,
                            ((field[i, j] - 1) / nw) * ch,
                            cw, ch);

					// ��������
					g->DrawImage(pics,r1,r2,GraphicsUnit::Pixel);
				}
				else
                    // ������� ������ �����
					g->FillRectangle(SystemBrushes::Control,
                        i * cw, j * ch + menuStrip1->Height,
                         cw, ch);

                // ������ �������
				g->DrawRectangle(Pens::Black,
                    i * cw, j * ch + menuStrip1->Height,
                    cw, ch);

                // ����� �����
                if ((showNumbers) && field[i, j] != 0)
                    g->DrawString(
					      Convert::ToString(field[i, j]),
				          // Font,
					      gcnew System::Drawing::Font("Tahoma", 12, FontStyle::Regular),
						  Brushes::Black,
						  (float)i * cw + 5,
                          (float)j * ch + 5 + menuStrip1->Height);
            }
}

// ���������, ����������� �� ����� � ���������� �������
private: Boolean finish()
{
	// ���������� ������
    int i = 0;
    int j = 0;

    int c;       // ����� � ������

    // ����� ����������� ���������, ����
    // ����� � ��� �������� �������:
    //   1  2  3  4
    //   5  6  7  8
    //   9 10 11 12
    //  13 14 15

    for (c = 1; c < nw * nh; c++)
    {
        if (field[i, j] != c) return false;

            // � ��������� ������
            if (i < nw - 1) i++;
            else { i = 0; j++; }
    }
    return true;
}

// ���������� �����, �� ������� ������ ������,
// � �������� ������ ������:
// (cx, cy) - ������, � ������� ������ ������,
// (ex, ey) - ������ ������
private: void move(int cx, int cy)
{
	// ��������, �������� �� �����
	if (!(((Math::Abs(cx - ex) == 1) && (cy - ey == 0)) ||
		((Math::Abs(cy - ey) == 1) && (cx - ex == 0))))
            return;

     // �����. ���������� ����� �� (x, y) � (ex, ey)
     field[ex, ey] = field[cx, cy];
     field[cx, cy] = 0;

     ex = cx; ey = cy;

     // ������������ ����
     this->drawField();

     // ���������, �������� ����� ���������
	 // � ���������� �������
	 if (this->finish())
     {
            field[nw - 1, nh - 1] = nh * nw;
            this->drawField();

            // ���� ���������. ������� ��� ���?
            // No  - ��������� ������ ���������,
            // Yes - ����� ����
			if (MessageBox::Show(
                   "�� ���������� � ������������ �������!\n" +
                   "��� ���?", "Puzzle game",
				   MessageBoxButtons::YesNo,
				   MessageBoxIcon::Question)
				   == System::Windows::Forms::DialogResult::No)
                this->Close();
            else this->newGame();
        }
    }



	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
			 {
				 drawField();
			 }


// ������ ������� ���� �� ������� ����
private: System::Void Form1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
        // ����������� ���������� ���� � ���������� ������
        move( e->X/cw, (e->Y-menuStrip1->Height)/ch);

}


// ������� ����� ����
private: System::Void MenuItem1_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 this->newGame();
		 }
};
}

