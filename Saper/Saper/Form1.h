// ���� �����
// (c) ������ �������
// ������ �� �����: ������� �.�. Microsoft Visual C++ � ������� � ��������
#pragma once

#include "AboutForm.h"

namespace Saper {

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
			// � �������������� ��-�� �������, ���������������
      // ������� ������� �������� ���� ������� ����� -3.
      // ��� �������� ������������ ���������� open()
      // ��� ���������� ������������ �������� ��������
      // �������� ������ ������
      for(int row = 0; row <= MR+1; row++)
      {
          Pole[row,0] = -3;
          Pole[row,MC+1] = -3;
      }
          
      for(int col = 0; col <= MC+1; col++)
      {
          Pole[0,col] = -3;
          Pole[MR+1,col] = -3;            
      }

      // ������������� ������ ����� � ������������
      // � �������� �������� ����
	  this->ClientSize = System::Drawing::Size(W*MC + 1,
                     H*MR +  menuStrip1->Height +  1);

      newGame(); // ����� ����

      // ����������� �����������
      g = panel1->CreateGraphics();

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
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::ToolStripMenuItem^  ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���������������ToolStripMenuItem;
	private: System::Windows::Forms::HelpProvider^  helpProvider1;
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
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->helpProvider1 = (gcnew System::Windows::Forms::HelpProvider());
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
			this->�������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->�������ToolStripMenuItem, 
				this->���������������ToolStripMenuItem});
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->�������ToolStripMenuItem->Text = L"�������";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(186, 22);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�������ToolStripMenuItem_Click);
			// 
			// ���������������ToolStripMenuItem
			// 
			this->���������������ToolStripMenuItem->Name = L"���������������ToolStripMenuItem";
			this->���������������ToolStripMenuItem->Size = System::Drawing::Size(186, 22);
			this->���������������ToolStripMenuItem->Text = L"� ��������� �����";
			this->���������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::���������������ToolStripMenuItem_Click);
			// 
			// panel1
			// 
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 24);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(284, 240);
			this->panel1->TabIndex = 1;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel1_Paint);
			this->panel1->Click += gcnew System::EventHandler(this, &Form1::panel1_Click);
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel1_MouseClick);
			// 
			// helpProvider1
			// 
			this->helpProvider1->HelpNamespace = L"E:\\Users\\������\\Documents\\Visual Studio 2008\\CppProjects\\Saper\\help\\saper.chm";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 264);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"�����";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private:

  static int
    MR = 10, // ���-�� ������ �� ���������
    MC = 10, // ���-�� ������ �� �����������
    NM = 10, // ���-�� ���
    W = 40,  // ������ ������
    H = 40;  // ������ ������

  // ������� (������) ����
  static array<int,2>^ Pole = gcnew array<int,2>(MR + 2,MC + 2);
  // �������� �������� �������:
  // 0..8 - ���������� ��� � �������� �������
  // 9 - � ������ ����
  // 100..109 - ������ �������
  // 200..209 - � ������ ��������� ����

  int nMin;  // ���-�� ��������� ���
  int nFlag; // ���-�� ������������ ������

  // ������ ����
  int status;
  // 0 - ������ ����,
  // 1 - ����,
  // 2 � ���������

  // ����������� ����������� �����
  System::Drawing::Graphics^ g;


// ����� ����
void newGame()
{
    int row, col;    // ������� ������
    int n = 0;       // ���������� ������������ ���
    int k;           // ���-�� ��� � �������� �������

    // �������� ����
    for(row = 1; row <= MR; row++)
        for(col = 1; col <= MC; col++)
            Pole[row,col] = 0;

    // ��������� ��������� �����
    Random^ rnd = gcnew Random();

    // ��������� ����
    do
    {
        row = rnd->Next(MR) + 1;
        col = rnd->Next(MC) + 1;

        if (Pole[row,col] != 9)
        {
            Pole[row,col] = 9;
            n++;
        }
    }
    while (n != NM);

    // ��� ������ ������ �������� ���-�� 
    // ��� � �������� �������
    for(row = 1; row <= MR; row++)
        for(col = 1; col <= MC; col++)
            if (Pole[row,col] != 9)
            {
                k = 0;

                if (Pole[row-1,col-1] == 9) k++;
                if (Pole[row-1,col]   == 9) k++;
                if (Pole[row-1,col+1] == 9) k++;
                if (Pole[row,col-1]   == 9) k++;
                if (Pole[row,col+1]   == 9) k++;
                if (Pole[row+1,col-1] == 9) k++;
                if (Pole[row+1,col]   == 9) k++;
                if (Pole[row+1,col+1] == 9) k++;

                Pole[row,col] = k;
            }

    status = 0;      // ������ ����
    nMin   = 0;      // ��� ������������ ���
    nFlag  = 0;      // ��� ������������ ������
  }

// ������ ����
void showPole(Graphics^ g, int status)
{
    for(int row = 1; row <= MR; row++)
        for(int col = 1; col <= MC; col++)
            this->kletka(g, row, col, status);
}

// ������ ������
void kletka(Graphics^ g,
    int row, int col, int status)
{
    int x,y;// ���������� ������ �������� ���� ������
    
    x = (col - 1) * W + 1;
    y = (row-1)* H + 1;

    // �� �������� ������ - �����
    if (Pole[row,col] < 100)
		g->FillRectangle(SystemBrushes::ControlLight,
            x-1, y-1, W, H);

    // �������� ��� ���������� ������
    if (Pole[row,col] >= 100) {

        // ��������� ������, �������� - �����
        if (Pole[row,col] != 109)
			g->FillRectangle(Brushes::White,
                x-1, y-1, W, H);
        else
            // �� ���� ���� �����������!
			g->FillRectangle(Brushes::Red,
                x-1, y-1, W, H);

        // ���� � �������� ������� ���� ����,
        // ��������� �� ����������
        if ((Pole[row,col] >= 101) && (Pole[row,col] <= 108))
			g->DrawString((Pole[row,col]-100).ToString(),
			gcnew System::Drawing::Font("Tahoma", 10,
				System::Drawing::FontStyle::Regular),
				Brushes::Blue, (float)x+3, (float)y+2);
    }

    // � ������ ��������� ����
    if (Pole[row,col] >= 200)
        this->flag(g, x, y);

    // ������ ������� ������
	g->DrawRectangle(Pens::Black,
        x-1, y-1, W, H);

    // ���� ���� ��������� (status = 2),
    // ���������� ����
    if ((status == 2) && ((Pole[row,col] % 10) == 9))
        this->mina(g, x, y);
  }

  // ��������� ������� � ��� �������� � ��� ������,
  // � ������� ��� ���
  void open(int row, int col)
  {
    // ���������� ������� ������
    int x = (col-1)* W + 1,
        y = (row-1)* H + 1;
    
    if (Pole[row,col] == 0)
    {
        Pole[row,col] = 100;

        // ���������� ���������� ������
        this->kletka(g, row, col, status);

        // ������� ����������� ������
        // �����, ������, ������, �����
        this->open(row, col-1);
        this->open(row-1, col);
        this->open(row, col+1);
        this->open(row+1, col);

        //����������� �����������
        this->open(row-1,col-1);
        this->open(row-1,col+1);
        this->open(row+1,col-1);
        this->open(row+1,col+1);
    }
    else
        if ((Pole[row,col] < 100) &&
             (Pole[row,col] != -3))
        {
            Pole[row,col] += 100;
            // ���������� ���������� ������
            this->kletka(g, row, col, status);
        }
  }

  // ������ ����
  void mina(Graphics^ g, int x, int y)
  {
    // ������
	  g->FillRectangle(Brushes::Green,
        x+16, y+26, 8, 4);
	  g->FillRectangle(Brushes::Green,
        x+8, y+30, 24, 4);
	  g->DrawPie(Pens::Black,
        x+6, y+28, 28, 16, 0, -180);
	  g->FillPie(Brushes::Green,
        x+6, y+28, 28, 16, 0, -180);

    // ������ �� �������
	  g->DrawLine(Pens::Black,
        x+12, y+32, x+28, y+32);

    // ������������ "��"
	  g->DrawLine(Pens::Black,
        x+20, y+22, x+20, y+26);

    // ������� "���"
	  g->DrawLine(Pens::Black,
        x+8, y+30, x+6, y+28);
	  g->DrawLine(Pens::Black,
        x+32, y+30, x+34, y+28);
  }

  // ������ ����
  void flag(Graphics^ g, int x, int y)
  {
    array<Point>^ p = gcnew array<Point>(3);
    array<Point>^ m = gcnew array<Point>(5);
    //Point[] m = new Point[5];            

    // ������
    p[0].X = x+4;   p[0].Y = y+4;
    p[1].X = x+30;  p[1].Y = y+12;
    p[2].X = x+4;   p[2].Y = y+20;
	g->FillPolygon(Brushes::Red, p);

    // ������
	g->DrawLine(Pens::Black,
        x+4, y+4, x+4, y+35);

    // ����� M �� ������
    m[0].X = x+8;   m[0].Y = y+14;
    m[1].X = x+8;   m[1].Y = y+8;
    m[2].X = x+10;  m[2].Y = y+10;
    m[3].X = x+12;  m[3].Y = y+8;
    m[4].X = x+12;  m[4].Y = y+14;
	g->DrawLines(Pens::White, m);
  }


// ��������� ������� Paint
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
			 {

				 showPole(g, status);
			 }


		 
		 
		 
// ������ � ������ �������� ����
private: System::Void panel1_Click(System::Object^  sender, System::EventArgs^  e)
{	    

}

// ������ � ������ �������� ����
private: System::Void panel1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{

	if (status == 2)
		// ���� ���������
		return;

    if (status == 0)
		// ������ ������
		status = 1;
        
    // ����������� ���������� ���� � �������
    // ������ ����, � ������� ��� ������ ������;
    // (e.X, e.Y) - ���������� ����� �����,
    // � ������� ���� ������ ������ ����
    int row,col;
	
	
	row = e->Y/H + 1;
    col = e->X/W + 1;

    // ���������� ������� ������
    int x = (col-1)* W + 1,
        y = (row-1)* H + 1;

    // ������ ����� ������ ����
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
    {                
        // ������� ������, � ������� ���� ����
        if (Pole[row,col] == 9)
        {                
            Pole[row,col] += 100;

            // ���� ���������
            status = 2;

            // ������������ �����
            this->panel1->Invalidate();
        }
        else
            if (Pole[row,col] < 9)
				// ������� ������
                this->open(row,col);
    }

    // ������ ������ ������ ����
	if (e->Button == System::Windows::Forms::MouseButtons::Right) {

        // � ������ �� ���� �����, ������ ���
        if (Pole[row,col] <= 9) {
            nFlag += 1;

            if (Pole[row,col] == 9)
                nMin += 1;

            Pole[row,col] += 200;

            if ((nMin == NM) && (nFlag == NM)) {
                // ���� ���������
                status = 2;

                // �������������� ��� ������� ����
                this->Invalidate();
            }
            else
                // �������������� ������ ������
                this->kletka(g, row, col, status);
        }
        else
            // � ������ ��� ��������� ����,
            // ��������� ������ ������ ������ ����
            // ������� ��� � ��������� ������
            if (Pole[row,col] >= 200)
            {                                 
                nFlag -= 1;
                Pole[row,col] -= 200;

                // �������������� ������
                this->kletka(g, row, col, status);
            }
  }  
}

// ������� ����� ����
private: System::Void ���������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 newGame();
             showPole(g, status);

		 }

// ����� � ���� ������� ������� �������
private: System::Void �������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 { 
			 Help::ShowHelp(this,helpProvider1->HelpNamespace,"saper_02.htm");
			 
		 }

// ����� � ���� ������� ������� � ���������
private: System::Void ���������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			AboutForm^ frm = gcnew AboutForm();

			frm->ShowDialog();
		 }



};
}

