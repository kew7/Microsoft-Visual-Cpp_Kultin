//
//	������� �����������. ������������� �������� ����������� � ����. 
//
//
//
//

#pragma once


namespace calc {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	
	private: 
	    
		static int bw = 40, bh = 22; // ������ ������
        
		// ���������� ����� �������� �� � � Y
        static int dx = 5, dy = 5;   

        // ������
		array<System::Windows::Forms::Button^>  ^btn; 
    
        // ����� �� �������
        static array<String^> ^btnText = {"7","8","9","+",
                          "4","5","6","-",
                          "1","2","3","=",
                          "0",",","c"};
        
        // ��� ������� ������ ����� ����������������
        // �� �������� �������� Tag
        static array<int^> ^btnTag =
		               {7,8,9,-3,
                        4,5,6,-4,
                        1,2,3,-2,
                        0,-1,-5};

        double ac; // �����������
        int op;    // ��� ��������
       
		bool fd; 
        // fd == true - ���� ������ ����� �����,
        // ��������, ����� ������� ������ "+"
        // fd == false - ���� ��������� �����

	public:
		Form1(void)
		{
			InitializeComponent();
		
			// ���������� ������ ����� (���������� �������) 
           int cw = 4*bw + 5*dx;
		   int ch = 5*bh + 7*dy;
           this->ClientSize = System::Drawing::Size(cw,ch);

           // ������ ������ � ��������� ����������
           label1->SetBounds(dx, dy, 4*bw + 3*dx, bh);
           label1->Text = "0";
		   
		   int x, y;// ���������� ������

		   y = label1->Bottom + dy ;

		   // ������ ������������ ���������� � ������
		   btn = gcnew array<System::Windows::Forms::Button^>(15);
			
           int k =0;    // ����� ������������� ������
          
	       for ( int i=0; i < 4; i++)
           {
			    x = dx;
                for (int j = 0; j < 4; j++)
                {
                    if ( !((i == 3 ) && (j == 0)))
                    {
                        // ������� ������
                        btn[k] = gcnew System::Windows::Forms::Button;

						// ��������� ������
                        btn[k]->SetBounds(x, y, bw, bh);
                        btn[k]->Tag = btnTag[k];
                        btn[k]->Text = btnText[k];
                        
						if ( Convert::ToInt32(btn[k]->Tag) > 0) {
							// ������ � ������
							btn[k]->BackColor =
								SystemColors::ButtonFace;
						}                        
						else {
                            // ������ ��������
                            btn[k]->BackColor =
								//System::Drawing::Color::Red;
								SystemColors::ControlLight;
                       }

                        x = x + bw + dx;
                    }
                    else // ������ "����" ���� ���������
                    {
                      // ������� � ��������� ������
                      btn[k] = gcnew System::Windows::Forms::Button;
                      btn[k]->SetBounds(x, y, bw * 2 + dx, bh);
                      btn[k]->Tag = btnTag[k];
                      btn[k]->Text = btnText[k];//.ToString();

                      x = x + 2*bw + 2*dx;
                     
                      j++;
                    }

                    // ��������� ������ �� �����
                    this->Controls->Add(btn[k]);
						
					// ������ ������� ��������� ������� Click
					btn[k]->Click += gcnew System::EventHandler(this, &Form1::btn_Click);

					k++; // ��������� ����� ������

                }
                y = y + bh + dy;
			}
			
			ac = 0;		// �����������
			fd = true;  // ���� ������ �����

		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	
	private:
		System::Windows::Forms::Label^  label1;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(176, 23);
			this->label1->TabIndex = 0;
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(201, 152);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"  �����������";
			this->ResumeLayout(false);

		}
#pragma endregion
	
private: System::Void btn_Click(System::Object^  sender, System::EventArgs^  e)
{
	
	System::Windows::Forms::Button^  btn;
	
	btn = (Button^)sender;

    // ������ 1..9
	if ( Convert::ToInt32(btn->Tag) > 0)
    {
		if ( fd )
        {
			// �� ���������� ����, �.�.
            // ��� ������ ����� 
            label1->Text = btn->Text;
            fd = false;
        }
        else
			label1->Text += btn->Text;
            return;
        }

        // ����
		if (Convert::ToInt32(btn->Tag) == 0)
        {
			if (fd) label1->Text = btn->Text;
            if (label1->Text != "0")
                        label1->Text += btn->Text;
            return;
        }

        // �������
		if ( Convert::ToInt32(btn->Tag) == -1 )
        {
			if (fd)
            {
				label1->Text = "0,";
                fd = false;
            }
            else
				if (label1->Text->IndexOf(",") == -1)
                        label1->Text += btn->Text;
                return;
        }

        // "�" - ��������
		if (Convert::ToInt32(btn->Tag) == -5 )
        {
                ac = 0; // �������� �����������
                op = 0;
                label1->Text = "0";
            
                fd = true; // ����� ���� ������ �����
                return;
        }

        // ������ "+","-","="
		if (Convert::ToInt32(btn->Tag) < -1)
        {
			double n; // ����� �� ����������

			n = Convert::ToDouble(label1->Text);

            // ������� ������� �������� �������� ���
            // ������������ ���� �������. ���� �
            //������������ ���� �����, �� ��������
            // ��������. ���� ��� �� ���, �������� 
            // ��������, ����� ��������� �� ��� ���������
            // ������� ������� ��������.
            if (ac != 0) 
            {
                    switch (op)
                    {
                        case -3: ac += n;
                            break;
                        case -4: ac -= n;
                            break;
                        case -2: ac = n;
                            break;
                    }
					label1->Text = ac.ToString("N");
            }
            else 
				ac = n;
                
			op = Convert::ToInt32(btn->Tag);
            fd = true; // ���� ��������� �����
        }
	}
};
}

