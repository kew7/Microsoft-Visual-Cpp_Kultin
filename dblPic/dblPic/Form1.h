// ���� "������ ��������"
// (�) ������ �������, 2009.


#include "About.h"

#pragma once


namespace dblPic {

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
            // ��������� ���� � ����������
			pics = gcnew Bitmap(Application::StartupPath + 
				               "\\pictures.bmp");
        }
        catch (Exception^ )
        {
			MessageBox::Show("����� 'pictures.bmp' �� ������.\n",
                             "������ ��������",
			                 MessageBoxButtons::OK,
			                 MessageBoxIcon::Error);	  
			
			this->���������ToolStripMenuItem->Enabled = false;

          return;
        }

		// ������� ������� ��������� ������� Click �� �����.
		// ���� ������� ��������� ������ ������� �������,
		// �� � ��������� drawCell ����
		// ��������������, ��������� �� ��������.
		// ��� �����.
		this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseClick);

        // ���������� ������ �������� � �������������
        // ������ ������ �������� ����
        cw = (int)(pics->Width / np);
        ch = pics->Height;

        // ���������� ������ ���������� ������� �����
        // � ������������ � �������� �������� � �� �����������
        // (��. ����������� �������� cw � ch)
        this->ClientSize =
			System::Drawing::Size(nw * (cw + 2) + 1,
                      nh * (ch + 2) + 1 + menuStrip1->Height);

        // ������� ����������� �����������
        g = this->CreateGraphics();
        
        // ������� ������ timer1
        timer1 = gcnew Timer();

		timer1->Tick +=
			gcnew System::EventHandler(this, &Form1::timer1_Tick);
        
		timer1->Interval = 200;
       
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
	private: System::Windows::Forms::ToolStripMenuItem^  ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  ����������ToolStripMenuItem;


	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->���������ToolStripMenuItem, 
				this->�������ToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(284, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(81, 20);
			this->���������ToolStripMenuItem->Text = L"����� ����";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::���������ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->�������ToolStripMenuItem1, 
				this->����������ToolStripMenuItem});
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->�������ToolStripMenuItem->Text = L"�������";
			// 
			// �������ToolStripMenuItem1
			// 
			this->�������ToolStripMenuItem1->Enabled = false;
			this->�������ToolStripMenuItem1->Name = L"�������ToolStripMenuItem1";
			this->�������ToolStripMenuItem1->Size = System::Drawing::Size(149, 22);
			this->�������ToolStripMenuItem1->Text = L"�������";
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->����������ToolStripMenuItem->Text = L"� ���������";
			this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::����������ToolStripMenuItem_Click);
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
			this->Text = L"������ ��������";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private:

    static int nw = 4; // ���-�� ������ �� �����������
    static int nh = 4; // ���-�� ������ �� ���������
                   
    static int np = (nw * nh) / 2;  // ���-�� ��� ��������

    // ������� ����������� �����������
	System::Drawing::Graphics^ g;

    // �������� (����������� �� �����) 
    Bitmap^ pics;

    // ������ (������ � ������) ������ (��������)
    int cw, ch;

    // ������� ����: 
	static array<int,2>^ field  = gcnew array<int,2>(4,4); 
    // field[i,j] == 1 ... k - ������ �������
    //                         (k-����� ��������);
    // field[i,j] == 101 ... (100+k) - ������ �������
    //                       (����� ����� ��������);
    // field[i,j] == 201 ... (200+k) � � ������ ��������,
    //                        ��� ������� ������� ���� 
    
    // ���-�� �������� (���������) ��� ��������
    static int nOpened = 0;

    // ���������� �������� � ������ ������ ������
    static int cOpened = 0;

	// ���������� 1-� �������� ������
    static array<int>^ open1 = gcnew array<int>(2);

    // ���������� 2-� �������� ������
	static array<int>^ open2 = gcnew array<int>(2);

    // ������
	System::Windows::Forms::Timer^ timer1;


// ���������� ������:
    // - ��������, ���� ������ �������;
    // - �������, ���� ������ �������;
    // - ���, ���� � ������ ��������, ��� ������� ������� ����
    void drawCell(int i, int j)
    {
        int x,y;  // ���������� ������ �������� ���� ������

        // ����� ���� ����������
        // ��������� ���������� � 1 �������
        x = i * (cw + 2);
        y = j * (ch + 2) + menuStrip1->Height;

        if (field[i,j] > 200)
            // ��� ���� ������ ������� ����,
            // �������� ���������� �� ����
			g->FillRectangle(SystemBrushes::Control,
                x, y, cw + 2, ch + 2);

        if ((field[i, j] > 100) && (field[i, j] < 200))
        {
            // ������ ������� - ���������� ��������:
			// ����������� �������� � ����� �����������
			// ����������� �� ������
			Rectangle r1 = Rectangle(x + 1, y + 1, cw, ch);
			Rectangle r2 = Rectangle
				           ((field[i, j] - 101) * cw, 0, cw, ch);
            
			g->DrawImage (pics, r1,r2,
			  GraphicsUnit::Pixel);
				
				g->DrawRectangle(Pens::Black,
                x + 1, y + 1, cw, ch);
        }

        if ((field[i, j] > 0) && (field[i, j] < 100))
        {
            // ������ �������. ������ ������
			g->FillRectangle(SystemBrushes::Control,
                x + 1, y + 1, cw, ch);
			g->DrawRectangle(Pens::Black,
                x + 1, y + 1, cw, ch);
        }
    }

    // ���������� ����
    void drawField()
    {
        for (int i = 0; i < nw; i++)
            for (int j = 0; j < nh; j++)
                drawCell(i, j);
    }

    // ����� ����
    void newGame()
    {
        // ��������� ���� �������� �� �������� ����:
        // ������� � ������ field ��������� �����
        // �� 1 �� k, ��� � - ���������� ��������.
        // ������ ����� ������ ���� ��������
        // � ������ field ��� ����.
        
        Random^ rnd; // ��������� ��������� �����
        int rndN;   // ��������� �����
        
		rnd = gcnew Random(); 

        array<int>^ buf = gcnew array<int>(np);
        // np - ���-�� ��������;
        // � buf[i] ����������, ������� i ����� 
        // (���������������� ��������) �������� � ������ field

        for (int i = 0; i < nw; i++)
            for (int j = 0; j < nh; j++)
            {
                do
                {
					rndN = rnd->Next(np) + 1;
                } while (buf[rndN - 1] == 2);

                field[i, j] = rndN;
                buf[rndN - 1]++;
            }

        nOpened = 0;
        cOpened = 0;

        this->drawField();
    }

    // ��������� ������� �������
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
    
    {
        // ���������� ������
        drawCell(open1[0], open1[1]);
        drawCell(open2[0], open2[1]);

        // ���������� ������
        timer1->Enabled = false;

        if (nOpened == np)
        {
			MessageBox::Show
                    ("�� ���������� � ������������ �������!",
					 "������ ��������");               
        }
    }

// ��������� ������� Click �� �����
private: System::Void Form1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
    {
            int i,j; // ������� �������� ������� field,
                     // ���������������� ������, � ���.
                     // ������ ������

            i = e->X / (cw +3);  
			j = (e->Y - menuStrip1->Height) / (ch+3);  

            // ���� ������ ��������, ��� ������ ��� � ������ 
            // ������ ������� ��� �������, � ������� ���������
            // ���������� ��������, �� ��� ��� �� "������".
            // ���� ������ ������ � ����� �� ���� ��������,
            // �� �� ���� ������ �� ����.
            if ((timer1->Enabled) && (field[i,j] > 200))
           {
               return;
           }

            // ������ �� ����� ����� �� ���� ��� ���������
            // ������ ��������
            if (field[i, j] > 200) return;

            // �������� ������ ���
            if (cOpened == 0)
            {
                cOpened++;

                // ���������� ���������� 1-� �������� ������
                open1[0] = i; open1[1] = j;

                // ������ ���������� ��� ��������
                field[i, j] += 100;

                // ���������� ������
                drawCell(i, j);

                return;
            }

            // ������� ���� ������, ���� ������� ������
            if (cOpened == 1)
            {
                // ���������� ���������� 2-� �������� ������
                open2[0] = i; open2[1] = j;

                // ���� ������� ���� ������, � ������ ������
                // � ��� �� ������, ������ �� ����������
                if ((open1[0] == open2[0]) &&
                                      (open1[1] == open2[1]))
                    return;
                else
                {
                    // ������ ������� ��� ������
                    cOpened++;

                    // ������ ���������� ��� ��������
                    field[i, j] += 100;

                    // ���������� ������
                    drawCell(i, j);

                    // ������� 2 ���������� ��������
                    if (field[open1[0], open1[1]] ==
                        field[open2[0], open2[1]])
                    {
                      nOpened++;

                      // ������� ������ ��� ���������
                      field[open1[0], open1[1]] += 100;
                      field[open2[0], open2[1]] += 100;

                      cOpened = 0;

                      // ��������� ������. ��������� ���������
                      // ������� �� ������� "������" ������� ������,
                      // ������, � ����������� ����������
                      timer1->Enabled = true;
                    }
                }
                return;
            }

            // ������� 2 ������ �� � ��� ������ ����������,
            // ������� �� � ������� �� ������, � �������
            //  ������ ������
            if (cOpened == 2)
            {
                // ��������� �������� ������
                field[open1[0], open1[1]] -= 100;
                field[open2[0], open2[1]] -= 100;

                drawCell(open1[0], open1[1]);
                drawCell(open2[0], open2[1]);

                // ���������� � open1 ����� ������� ������
                open1[0] = i; open1[1] = j;

                cOpened = 1;        // ������� �������� ������

                // ������� ������, � ������� ������ ������
                field[i, j] += 100;
                drawCell(i, j);
            }
        }
}

// ����� � ���� ������� "����� ����"
private: System::Void ���������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 this->newGame();
		 }

// ��������� ������� Paint
private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
		 {
			 this->drawField();
		 }

private: System::Void ����������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {

			 About^ frm = gcnew About();

			 frm->ShowDialog();

		 }


};
}

